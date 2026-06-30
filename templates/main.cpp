#include "generic_stack.h"
#include "smart_vector.h"

#include <iostream>


int main() {
    // Testing GenericStack
    GenericStack<int> intStack;

    for (int i = 0; i < 5; i++) {
        intStack.push(i);
    };

    try {
        while (!intStack.empty()) {
            std::cout << "Top of stack: " << intStack.top().value() << "\n";
            intStack.pop();
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    // Testing SmartVector
    SmartVector<std::string> strVec;

    strVec.push_back("Hello");
    strVec.push_back("World");
    for (size_t i = 0; i < strVec.size(); i++) {
        std::cout << "Element " << i << ": " << strVec[i] << "\n";
    }

    // Testing constexpr factorial
    constexpr unsigned int num = 5;
    constexpr unsigned long long result = compileTimeFactorial(num);
    std::cout << "Factorial of " << num << " is: " << result << "\n";

    return 0;
}
