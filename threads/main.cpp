#include "executor.h"

#include <thread>
#include <vector>
#include <iostream>
#include <chrono>


int main() {
    std::vector<int> list = {};

    for (int i = 0; i < 1000000; ++i) {
        list.push_back(i);
    }

    Executor executor(list);

    auto start = std::chrono::high_resolution_clock::now();
    {
        executor.calculateMultithread();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Execution time: " << duration.count() << " ms" << std::endl;

    std::cout << "Sum: " << executor.getSum() << std::endl;
    std::cout << "Max: " << executor.getMax() << std::endl;

    return 0;
}