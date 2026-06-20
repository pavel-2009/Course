#include <vector>
#include <stdexcept>
#include <iostream>


std::vector<std::vector<int>> createMatrix(int rows, int cols) {
    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = i * cols + j;
        }
    }
    return matrix;
}


std::vector<std::vector<int>> multiplyMatrices(const std::vector<std::vector<int>>& a, const std::vector<std::vector<int>>& b) {
    int rowsA = a.size();
    int colsA = a[0].size();
    int rowsB = b.size();
    int colsB = b[0].size();

    if (colsA != rowsB) {
        throw std::invalid_argument("Matrix dimensions do not allow multiplication.");
    }

    std::vector<std::vector<int>> result(rowsA, std::vector<int>(colsB, 0));
    for (int i = 0; i < rowsA; ++i) {
        for (int k = 0; k < colsA; ++k) {
            for (int j = 0; j < colsB; ++j) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return result;
}


int main() {
    int rowsA = 1000;
    int colsA = 1000;
    int rowsB = 1000;
    int colsB = 1000;

    auto matrixA = createMatrix(rowsA, colsA);
    auto matrixB = createMatrix(rowsB, colsB);

    try {
        auto resultMatrix = multiplyMatrices(matrixA, matrixB);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
