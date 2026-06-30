#include <iostream>
#include "calculator.h"


int main() {
    double num1, num2;
    char op;

    std::cout << "Enter expression (e.g., 12.5 + 2): ";

    if (!(std::cin >> num1 >> op >> num2)) {
        std::cerr << "Invalid input format" << std::endl;
    };

    try {
        double result = 0.0;

        switch (op)
        {
            case '+': result = add(num1, num2); break;
            case '-': result = subtract(num1, num2); break;
            case '*': result = multiply(num1, num2); break;
            case '/': result = divide(num1, num2); break;
            
            default:
                std::cerr << "Unknown operator: " << op << std::endl;
                return 1;
        }
        std::cout << "Result: " << result << std::endl;
    } catch (std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}