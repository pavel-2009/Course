#pragma once

#include <string>
#include <unordered_map>
#include <vector>
#include <utility>


class WordAnalyzer {
private:
    // Используем unordered_map для мгновенного подсчета частоты O(1)
    std::unordered_map<std::string, size_t> frequency_map;

public:
    // Добавляет слово в базу статистики
    void add_word(const std::string& word);

    // Метод, который берет сырые данные из хэш-таблицы,
    // переливает их в вектор пар (чтобы можно было отсортировать),
    // сортирует с помощью std::sort и выдает TOP-N элементов.
    std::vector<std::pair<std::string, size_t>> get_top_words(size_t top_n) const;
};
