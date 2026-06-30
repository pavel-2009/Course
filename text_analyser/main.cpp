#include <iostream>
#include "analyzer.h"


int main() {
    std::string filename;
    std::cout << "Enter the path to the text file (e.g., input.txt): ";
    std::cin >> filename;

    try
    {
        TextStats stats = analyze_file(filename);

        std::cout << "\n--- Text Statistics ---\n";
        std::cout << "Lines:      " << stats.lines << "\n";
        std::cout << "Words:      " << stats.words << "\n";
        std::cout << "Characters: " << stats.characters << "\n";
    } catch(const std::exception& e) {
        std::cerr << "Runtime error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
    
}
