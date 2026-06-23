#include <vector>
#include <iostream>
#include <algorithm>
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

        // Возвращает сырой указатель на данные для NDView
        T* data() {
            return data_;
        }

        const std::vector<size_t>& shape() const {
            return shape_;
        }

        const std::vector<size_t>& strides() const {
            return strides_;
        }

        // Оптимизированный оператор доступа через свертку (Fold Expressions)
        template<typename... Args>
        T& operator()(Args... indices) {
            static_assert((std::is_convertible_v<Args, size_t> && ...), "All indices must be convertible to size_t.");
            
            std::array<size_t, sizeof...(Args)> idx{static_cast<size_t>(indices)...};
            
            if (idx.size() != shape_.size()) {
                throw std::invalid_argument("Dimension mismatch.");
            }
            
            size_t offset = 0;
            for (size_t i = 0; i < idx.size(); ++i) {
                if (idx[i] >= shape_[i]) {
                    throw std::out_of_range("Index out of bounds");
                }
                offset += idx[i] * strides_[i];
            }

            return data_[offset];
        }

        // Реализовываем получения отдельных строк с NDView
        NDView<T> slice(size_t row_index) {
            if (shape_.size() != 2) {
                throw std::invalid_argument("Slice is only defined for 2D arrays.");
            }
            if (row_index >= shape_[0]) {
                throw std::out_of_range("Row index out of bounds.");
            }

            T* new_data = data_ + row_index * strides_[0];
            std::vector<size_t> new_shape = {shape_[1]};
            std::vector<size_t> new_strides = {strides_[1]};

            return NDView<T>(new_data, new_shape, new_strides);
        }

};
