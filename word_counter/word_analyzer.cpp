#include "word_analyzer.h"
#include "text_sanitizer.h"

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>


void WordAnalyzer::add_word(const std::string& word) {
    std::string sanitized = TextSanitizer::sanitize(word);
    if (!sanitized.empty()) {
        frequency_map[std::move(sanitized)]++;
    };
}

std::vector<std::pair<std::string, size_t>> WordAnalyzer::get_top_words(size_t top_n) const {
    if (frequency_map.empty()) {
        return {};
    };

    std::vector<std::pair<std::string, size_t>> frequency_vector;
    frequency_vector.reserve(frequency_map.size());

    for (const auto& pair : frequency_map) {
        frequency_vector.push_back(pair);
    }

    size_t actual_top = std::min(top_n, frequency_vector.size());

    std::partial_sort(
        frequency_vector.begin(), 
        frequency_vector.begin() + actual_top, 
        frequency_vector.end(), 
        [](const std::pair<std::string, size_t>& a, const std::pair<std::string, size_t>& b) {
            if (a.second != b.second) {
                return a.second > b.second; // Сортировка по частоте (убывание)
            }
            return a.first < b.first; // При равной частоте — алфавитный порядок (детерминированность!)
        }
    );

    frequency_vector.resize(actual_top);

    return frequency_vector;
}
