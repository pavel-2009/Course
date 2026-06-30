#pragma once

#include <string>
#include <cstdio>


class FileWrapper
{
private:
    FILE* file_handle;
public:
    FileWrapper(const std::string& filename, const std::string& mode);

    ~FileWrapper();

    // Интерфейс для работы с ресурсом
    void write_line(const std::string& text);

    FileWrapper(const FileWrapper&) = delete;
    FileWrapper& operator=(const FileWrapper&) = delete;

    FileWrapper(FileWrapper&& other) noexcept;
    FileWrapper& operator=(FileWrapper&& other) noexcept;
};
