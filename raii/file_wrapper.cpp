#include "file_wrapper.h"

#include <iostream>
#include <stdexcept>


FileWrapper::FileWrapper(const std::string& filename, const std::string& mode) {
    std::cout << "[RAII] Constructor: Attempting to open file: " << filename;

    file_handle = std::fopen(filename.c_str(), mode.c_str());

    if (file_handle == nullptr) {
        throw std::runtime_error("CRITICAL: Failed to open file: " + filename);
    };

    std::cout << "[RAII] Constructor: File opened successfully. Resource handle allocated." << std::endl;
};

FileWrapper::~FileWrapper() {
    if (file_handle != nullptr) {
        std::cout << "[RAII] Destructor TRIGGERED: Automatically closing the resource..." << std::endl;

        std::fclose(file_handle);

        file_handle = nullptr;

        std::cout << "[RAII] Destructor FINISHED: Resource safely freed. No leaks!" << std::endl;
    };
};

void FileWrapper::write_line(const std::string& text) {
    if (file_handle == nullptr) {
        throw std::runtime_error("Attempted to write to an uninitialized or closed file!");
    };

    int result = std::fputs(text.c_str(), file_handle);

    if (result == EOF) {
        throw std::runtime_error("Failed to write data to file.");
    };
};


FileWrapper::FileWrapper(FileWrapper&& other) noexcept {
    std::cout << "[MOVE] Move Constructor: Stealing file handle from other object..." << std::endl;

    this->file_handle = other.file_handle;

    other.file_handle = nullptr;
};

FileWrapper& FileWrapper::FileWrapper::operator=(FileWrapper&& other) noexcept {
    std::cout << "[MOVE] Move Assignment Operator: Releasing old and stealing new handle..." << std::endl;

    if (this != &other) {
        if (this->file_handle != nullptr) {
            std::fclose(this->file_handle);
        };

        this->file_handle = other.file_handle;

        other.file_handle = nullptr;
    }

    return *this;
}
