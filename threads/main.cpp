#include "executor.h"

#include <thread>
#include <vector>
#include <iostream>


int main() {
    std::vector<int> list = {1, 2, 3, 4, 5};

    Executor executor(list);

    { 
        executor.calculateMultithread(); 
    }

    std::cout << "Sum: " << executor.getSum() << std::endl;
    std::cout << "Max: " << executor.getMax() << std::endl;

    return 0;
}