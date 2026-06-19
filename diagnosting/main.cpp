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
    for (int i = 0; i < 10; ++i) {
        slowFunction();  // 90% времени здесь
    }
    fastFunction();      // 10% времени здесь
    return 0;
}