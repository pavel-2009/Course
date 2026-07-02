#include "text_sanitizer.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

std::string TextSanitizer::sanitize(std::string word) {
    // Безопасный перевод в нижний регистр (только для латиницы)
    std::transform(word.begin(), word.end(), word.begin(), [](unsigned char c) {
        if (c <= 127) {
            return static_cast<unsigned char>(std::tolower(c));
        }
        return c; // Кириллицу возвращаем как есть, не трогая байты
    });

    // Безопасное удаление пунктуации (только из ASCII-диапазона)
    word.erase(
        std::remove_if(word.begin(), word.end(), [](unsigned char c) {
            if (c <= 127) {
                return std::ispunct(c) || std::isdigit(c); // Удаляем знаки препинания и цифры
            }
            return false; // Любые многобайтовые символы (кириллицу) не трогаем
        }), 
        word.end()
    );

    return word;
}