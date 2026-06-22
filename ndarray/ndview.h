#ifndef NDVIEW_H
#define NDVIEW_H

#include <vector>
#include <stdexcept>
#include <type_traits>
#include <array>

template<typename T>
class NDView {
    private:
        T* data_;
        std::vector<size_t> shape_;
        std::vector<size_t> strides_;

    public:
        NDView(T* data, const std::vector<size_t>& shape, const std::vector<size_t>& strides)
            : data_(data), shape_(shape), strides_(strides) {}

        T* data() {
            return data_;
        }

        const T* data() const {
            return data_;
        }

        const std::vector<size_t>& shape() const {
            return shape_;
        }

        const std::vector<size_t>& strides() const {
            return strides_;
        }

        // Оператор доступа для переменного числа индексов
        template<typename... Args>
        T& operator()(Args... indices) {
            static_assert((std::is_convertible_v<Args, size_t> && ...), "All indices must be convertible to size_t.");

            std::array<size_t, sizeof...(Args)> idx{static_cast<size_t>(indices)...};
            
            if (idx.size() != shape_.size()) {
                throw std::invalid_argument("Number of indices doesn't match view dimensions");
            }

            // Проверка границ
            for (size_t i = 0; i < idx.size(); ++i) {
                if (idx[i] >= shape_[i]) {
                    throw std::out_of_range("Index out of bounds");
                }
            }

            // Вычисление смещения
            size_t offset = 0;
            for (size_t i = 0; i < idx.size(); ++i) {
                offset += idx[i] * strides_[i];
            }

            return data_[offset];
        }

        template<typename... Args>
        const T& operator()(Args... indices) const {
            static_assert((std::is_convertible_v<Args, size_t> && ...), "All indices must be convertible to size_t.");

            std::array<size_t, sizeof...(Args)> idx{static_cast<size_t>(indices)...};
            
            if (idx.size() != shape_.size()) {
                throw std::invalid_argument("Number of indices doesn't match view dimensions");
            }

            for (size_t i = 0; i < idx.size(); ++i) {
                if (idx[i] >= shape_[i]) {
                    throw std::out_of_range("Index out of bounds");
                }
            }

            size_t offset = 0;
            for (size_t i = 0; i < idx.size(); ++i) {
                offset += idx[i] * strides_[i];
            }

            return data_[offset];
        }

        // Метод для получения view строки
        NDView<T> row(size_t row_index) {
            if (row_index >= shape_[0]) {
                throw std::out_of_range("Row index out of bounds");
            }

            std::vector<size_t> new_shape(shape_.begin() + 1, shape_.end());
            std::vector<size_t> new_strides(strides_.begin() + 1, strides_.end());

            T* row_data = data_ + row_index * strides_[0];
            return NDView<T>(row_data, new_shape, new_strides);
        }
};

#endif // NDVIEW_H
