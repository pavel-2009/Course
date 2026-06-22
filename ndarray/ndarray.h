#ifndef NDARRAY_H
#define NDARRAY_H

#include <vector>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <type_traits>
#include <array>

template<typename T>
class NDArray {
    private:
        std::vector<T> data_;
        std::vector<size_t> shape_;
        std::vector<size_t> strides_;

        // Вспомогательная функция для вычисления strides
        std::vector<size_t> compute_strides(const std::vector<size_t>& shape) {
            std::vector<size_t> strides(shape.size());
            size_t stride = 1;
            for (int i = static_cast<int>(shape.size()) - 1; i >= 0; --i) {
                strides[i] = stride;
                stride *= shape[i];
            }
            return strides;
        }

    public:
        NDArray(const std::vector<size_t>& shape) : shape_(shape) {
            size_t total_size = 1;
            for (size_t dim : shape) {
                total_size *= dim;
            }
            data_.resize(total_size, T());
            strides_ = compute_strides(shape);
        }

        // Возвращает сырой указатель на данные (non-const версия)
        T* data() {
            return data_.data();
        }

        // Возвращает const указатель
        const T* data() const {
            return data_.data();
        }

        const std::vector<size_t>& shape() const {
            return shape_;
        }

        const std::vector<size_t>& strides() const {
            return strides_;
        }

        const size_t size() const {
            return data_.size();
        }

        void fill(const T& value) {
            std::fill(data_.begin(), data_.end(), value);
        }

        // Оператор доступа для 1D, 2D, 3D... индексов
        template<typename... Args>
        T& operator()(Args... indices) {
            static_assert((std::is_convertible_v<Args, size_t> && ...), "All indices must be convertible to size_t.");

            std::array<size_t, sizeof...(Args)> idx{static_cast<size_t>(indices)...};
            
            // Проверка количества индексов
            if (idx.size() != shape_.size()) {
                throw std::invalid_argument("Number of indices doesn't match array dimensions");
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
                throw std::invalid_argument("Number of indices doesn't match array dimensions");
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
};

#endif // NDARRAY_H
