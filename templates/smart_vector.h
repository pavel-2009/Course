#pragma once

#include <iostream>
#include <concepts>
#include <stdexcept>


template<typename T>
concept LoggableAndComparable = std::copyable<T> && requires(T a, T b, std::ostream& os) {
    { a == b } -> std::convertible_to<bool>;
    { os << a } -> std::same_as<std::ostream&>;
};


template<typename T>
requires LoggableAndComparable<T> 
class SmartVector {
    private:
        T* array = nullptr;
        size_t vec_capacity = 0;
        size_t vec_size = 0;

        void reserve_impl(size_t new_cap) {
            if (new_cap <= vec_capacity) return;

            T* new_array = new T[new_cap];

            for (size_t i = 0; i < vec_size; i++)
            {
                new_array[i] = std::move(array[i]);
            }

            delete[] array;
            array = new_array;
            vec_capacity = new_cap;

            std::cout << "[Concept Vector] Capacity increased to: " << vec_capacity << "\n";
            
        };


        public:
            SmartVector() = default;

            ~SmartVector() {
                delete[] array;
            }

            void push_back(const T& value) {
                if (vec_size >= vec_capacity) {
                    reserve_impl(vec_capacity == 0 ? 1 : vec_capacity * 2);
                }
                array[vec_size] = value;
                std::cout << "[Concept Vector] Element added: " << array[vec_size] << "\n";
                vec_size++;
            }

            size_t size() const { return vec_size; }
            size_t capacity() const { return vec_capacity; }

            T& operator[](size_t index) {
                return array[index];
            };
};

constexpr unsigned long long compileTimeFactorial(unsigned int n) {
    return (n <= 1) ? 1 : n * compileTimeFactorial(n - 1);
};
