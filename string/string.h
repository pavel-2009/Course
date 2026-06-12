#pragma once

#include <iostream>


class String {
    private:
        char* m_data;
        size_t m_size;

    public:

        String(const char* str = "");
        ~String() noexcept;

        String(const String& other);
        String& operator=(const String& other);

        String(String&& other) noexcept;
        String& operator=(String&& other) noexcept;

        void print() const;
        size_t length() const noexcept { return m_size; };
        const char* c_str() const noexcept { return m_data; };
};
