#include "analyzer.h"
#include <fstream>
#include <sstream>
#include <stdexcept>


TextStats analyze_file(const std::string& filename) {
    // Поток для чтения
    std::ifstream file(filename);

    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filename);
    };

    TextStats stat;
    std::string line;

    while (std::getline(file, line)) {
        stat.lines++;

        stat.characters += line.length() + 1;

        std::stringstream line_stream(line);
        std::string word;

        while (line_stream >> word) {
            stat.words++;
        };
    };

    return stat;
}
