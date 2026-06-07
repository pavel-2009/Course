#include "matrix.h"
#include <iostream>
#include <stdexcept>


Matrix create_matrix(size_t rows, size_t cols, int initial_value) {
    Matrix m;

    m.rows = rows;
    m.cols = cols;

    m.data.resize(rows);

    for (size_t i = 0; i < rows; i++)
    {
        m.data[i].resize(cols, initial_value);
    };

    return m;
};

Matrix add(const Matrix& a, const Matrix& b) {

    if (a.rows != b.rows || a.cols != b.cols) {
        throw std::invalid_argument("Matrix dimensions must match for addition!");
    }

    Matrix result = create_matrix(a.rows, a.cols);

    for (size_t i = 0; i < a.rows; i++)
    {
        for (size_t j = 0; j < a.cols; j++)
        {
            result.data.at(i).at(j) = a.data.at(i).at(j) + b.data.at(i).at(j);
        }; 
    };

    return result;
    
}

Matrix transpose(const Matrix& m) {
    
    Matrix result = create_matrix(m.cols, m.rows);

    for (size_t i = 0; i < m.rows; ++i) {
        for (size_t j = 0; j < m.cols; ++j) {
            
            result.data.at(j).at(i) = m.data.at(i).at(j);
        }
    }

    return result;
}

Matrix multiply(const Matrix& a, const Matrix& b) {

    if (a.cols != b.rows) {
        throw std::invalid_argument("Matrix A columns must equal Matrix B rows for multiplication!");
    }

    Matrix result = create_matrix(a.rows, b.cols);

    for (size_t i = 0; i < a.rows; ++i) { 
        for (size_t j = 0; j < b.cols; ++j) {
            int sum = 0;
            for (size_t k = 0; k < a.cols; ++k) { 
                sum += a.data.at(i).at(k) * b.data.at(k).at(j);
            }
            result.data.at(i).at(j) = sum;
        }
    }

    return result;
}

Matrix multiply_scalar(const Matrix& m, int scalar) {
    Matrix result = create_matrix(m.rows, m.cols);

    for (size_t i = 0; i < m.rows; ++i)
    {
        for (size_t j = 0; j < m.cols; ++j)
        {
            result.data.at(i).at(j) = m.data.at(i).at(j) * scalar;
        };
    };

    return result;
    
}

void print(const Matrix& m) {

    for (size_t i = 0; i < m.rows; ++i) {
        std::cout << "[ ";
        for (size_t j = 0; j < m.cols; ++j) {
            std::cout << m.data.at(i).at(j) << " ";
        }
        std::cout << "]\n";
    }

    std::cout << "\n";
}
