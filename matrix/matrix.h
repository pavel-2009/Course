#pragma once
#include <vector>
#include <cstddef>


struct Matrix {
    std::vector<std::vector<int>> data;
    size_t rows = 0;
    size_t cols = 0;
};


Matrix create_matrix(size_t rows, size_t cols, int initial_value = 0);

Matrix add(const Matrix& a, const Matrix& b);

Matrix multiply(const Matrix& a, const Matrix& b);

Matrix transpose(const Matrix& m);

Matrix multiply_scalar(const Matrix& m, int scalar);

void print(const Matrix& m);
