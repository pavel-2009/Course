#include "string.h"

#include <cstring>
#include <utility>


String::String(const char* str) {
    if (str == nullptr) {
        m_size = 0;
        m_data = new char[1];
        m_data[0] = '\0';
    } else {
        m_size = std::strlen(str);
        m_data = new char[m_size + 1];
        std::strcpy(m_data, str);
    }

    std::cout << "[CONSTRUCTOR] Alloc at: " << (void*)m_data << " (\"" << m_data << "\")\n";
};

String::~String() {
    if (m_data) {
        std::cout << "[DESTRUCTOR] Free at: " << (void*)m_data << " (\"" << m_data << "\")\n";
        delete[] m_data;
    } else {
        std::cout << "[DESTRUCTOR] Nothing to free (nullptr)\n";
    }
}

String::String(const String& other) {
    m_size = other.m_size;
    m_data = new char[m_size + 1];

    std::strcpy(m_data, other.m_data);

    std::cout << "[COPY CONSTRUCTOR] Deep Copy to: " << (void*)m_data << "\n";
}

String& String::operator=(const String& other) {
    std::cout << "[COPY ASSIGNMENT] Request\n";
    if (this == &other) return *this;

    String temp(other);

    std::swap(m_data, temp.m_data);
    std::swap(m_size, temp.m_size);

    return *this;
}

String::String(String&& other) noexcept {
    m_data = other.m_data;
    m_size = other.m_size;

    std::cout << "[MOVE CONSTRUCTOR] Stealing pointer: " << (void*)m_data << "\n";

    other.m_data = nullptr;
    other.m_size = 0;
}

String& String::operator=(String&& other) noexcept {
    std::cout << "[MOVE ASSIGNMENT] Request\n";

    if (this == &other) return *this;

    std::swap(m_data, other.m_data);
    std::swap(m_size, other.m_size);

    std::cout << "[MOVE ASSIGNMENT] Swapped pointer to: " << (void*)m_data << "\n";

    // Опустошаем донора
    other.m_data = nullptr;
    other.m_size = 0;

    return *this;

}

void String::print() const {
    if (m_data) std::cout << m_data << "\n";
    else std::cout << "(nullptr)\n";
}
