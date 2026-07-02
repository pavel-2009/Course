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

        T* data() {}

        const T* data() const { }

        const std::vector<size_t>& shape() const {}

        const std::vector<size_t>& strides() const {}

        // Оператор доступа для переменного числа индексов
        template<typename... Args>
        T& operator()(Args... indices) {}

        template<typename... Args>
        const T& operator()(Args... indices) const {}

        // Метод для получения view строки
        NDView<T> slice(size_t row_index) {}
};

#endif // NDVIEW_H
