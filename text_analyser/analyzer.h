#pragma once
#include <string>

struct TextStats {
    size_t lines = 0;
    size_t words = 0;
    size_t characters = 0;
};

TextStats analyze_file(const std::string& filename);
