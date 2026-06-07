#include "matrix.h"
#include <iostream>

int main() {
    try {
        Matrix a = create_matrix(2, 3);
        a.data[0] = {1, 2, 3};
        a.data[1] = {4, 5, 6};

        Matrix b = create_matrix(2, 3);
        b.data[0] = {7, 8, 9};
        b.data[1] = {10, 11, 12};

        std::cout << "Matrix A:\n";
        print(a);

        std::cout << "Matrix B:\n";
        print(b);

        Matrix c_add = add(a, b);
        std::cout << "Result of A + B:\n";
        print(c_add);

        Matrix a_transposed = transpose(a);
        std::cout << "Result of A Transposed (2x3 -> 3x2):\n";
        print(a_transposed);

        Matrix a_multiplied_scalar = multiply_scalar(a, 3);
        std::cout << "Result of A multiplied by 3:\n";
        print(a_multiplied_scalar);

        Matrix d = create_matrix(3, 2);
        d.data[0] = {1, 2};
        d.data[1] = {3, 4};
        d.data[2] = {5, 6};
        
        std::cout << "Matrix D (3x2):\n";
        print(d);

        Matrix c_mult = multiply(a, d);
        std::cout << "Result of A * D (2x2):\n";
        print(c_mult);

    } catch (const std::exception& e) {
        std::cerr << "Error occurred: " << e.what() << "\n";
        return 1;
    }

    return 0;
}