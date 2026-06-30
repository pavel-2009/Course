#include "file_wrapper.h"
#include <iostream>
#include <vector>

int main() {
    std::cout << "--- [Move Semantics Test] ---" << std::endl;

    // 1. Создаем объект a
    FileWrapper file_A("file_A.txt", "w");
    file_A.write_line("Hello from A\n");

    // 2. Перемещаем file_A в новый объект file_B
    FileWrapper file_B = std::move(file_A); 

    // file_B может спокойно писать в файл:
    file_B.write_line("Now File B owns this file!\n");

    std::cout << "Ending main program..." << std::endl;
    
    return 0;
}