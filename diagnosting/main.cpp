#include <iostream>
#include <vector>

// Медленная функция — много вычислений
void slowFunction() {
    volatile int sum = 0;  // volatile запрещает оптимизацию
    for (int i = 0; i < 100000000; ++i) {
        sum += i;
    }
}

// Быстрая функция
void fastFunction() {
    std::cout << "Быстро!" << std::endl;
}

int main() {
    for (int i = 0; i < 1000; ++i) {
        slowFunction();
    }
    
    for (int i = 0; i < 1000; ++i) {
        fastFunction();
    }

    return 0;
}