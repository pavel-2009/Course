#include <iostream>
#include <vector>

std::vector<std::vector<int>> createMatrix(int rows, int cols) {
    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = i * cols + j;
        }
    }
    return matrix;
}

long long sum = 0;

void readMatrixByRows(const std::vector<std::vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            sum += matrix[i][j]; // Accumulate the sum of elements
        }
        std::cout << std::endl;
    }
}

void readMatrixByColumns(const std::vector<std::vector<int>>& matrix) {
    for (int i = 0; i < matrix[0].size(); ++i) {
        for (int j = 0; j < matrix.size(); ++j) {
            sum += matrix[j][i]; // Accumulate the sum of elements
        }
        std::cout << std::endl;
    }
}


int main() {
    int rows = 1000;
    int cols = 1000;
    auto matrix = createMatrix(rows, cols);

    std::cout << "Reading matrix by rows:" << std::endl;
    readMatrixByRows(matrix);

    std::cout << "Reading matrix by columns:" << std::endl;
    readMatrixByColumns(matrix);
    return 0;
}
