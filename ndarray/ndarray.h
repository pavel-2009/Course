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
        std::vector<size_t> compute_strides(const std::vector<size_t>& shape) {}

    public:
        NDArray(const std::vector<size_t>& shape) : shape_(shape) {}

        // Возвращает сырой указатель на данные (non-const версия)
        T* data() {}

        // Возвращает const указатель
        const T* data() const {}

        const std::vector<size_t>& shape() const {}

        const std::vector<size_t>& strides() const {}

        const size_t size() const {}

        void fill(const T& value) {}

        // Оператор доступа для 1D, 2D, 3D... индексов
        template<typename... Args>
        T& operator()(Args... indices) {}

        template<typename... Args>
        const T& operator()(Args... indices) const {}
};

#endif // NDARRAY_H
