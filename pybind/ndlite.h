#pragma once
#include <vector>
#include <cmath>
#include <stdexcept>

template<typename T>
class Vector {
private:
    std::vector<T> data_;

public:
    Vector(std::vector<T> data) : data_(data) {}

    int size() const {
        return static_cast<int>(data_.size());
    }

    int norm() const {
        T sum_of_squares = 0;
        for (const auto& val : data_) {
            sum_of_squares += val * val;
        }
        return static_cast<int>(std::sqrt(sum_of_squares));
    }

    Vector<T> dot(const Vector<T>& other) const {
        if (data_.size() != other.data_.size()) {
            throw std::invalid_argument("Vectors must be of the same size for dot product.");
        }
        T result = 0;
        for (size_t i = 0; i < data_.size(); ++i) {
            result += data_[i] * other.data_[i];
        }
        return Vector<T>({result}); 
    }
};

// Для обычных функций оставляем только объявления (БЕЗ фигурных скобок)
double sum(std::vector<double> vec);
double mean(std::vector<double> vec);
