#include "word_analyzer.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

// Если мы на Windows, подключаем заголовок для работы с консолью
#ifdef _WIN32
#include <windows.h>
#endif

int main() {
    // Настройка кодировки UTF-8 для консоли
#ifdef _WIN32
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
#else
    try {
        std::locale::global(std::locale("en_US.UTF-8"));
    } catch (...) {
        std::locale::global(std::locale(""));
    }
#endif

    // Ускоряем стандартные потоки ввода-вывода
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    WordAnalyzer analyzer;
    std::string line;
    std::ifstream file("../input.txt");

    if (!file.is_open()) {
        std::cerr << "Ошибка: Не удалось открыть файл input.txt\n";
        return 1;
    }

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string word;
        while (iss >> word) {
            analyzer.add_word(word);
        }
    }

    size_t top_n = 10;
    auto top_words = analyzer.get_top_words(top_n);

    std::cout << "\n=== Топ " << top_words.size() << " слов ===\n";
    for (const auto& pair : top_words) {
        std::cout << pair.first << ": " << pair.second << "\n";
    }

    return 0;
}