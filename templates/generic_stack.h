#pragma once

#include <vector>
#include <optional>
#include <stdexcept>


template<typename T>
class GenericStack {
    private:
        std::vector<T> data;

    public:
        void push(const T& value) {
            data.push_back(value);
        }

        void push(T&& value) {
            data.push_back(std::move(value));
        }

        std::optional<T> top() const {
            if (data.empty()) {
                return std::nullopt;
            }
            return data.back();
        }
        
        bool pop() {
            if (data.empty()) {
                return false;
            }

            data.pop_back();
            return true;
        }

        bool empty() const { return data.empty(); }
        size_t size() const { return data.size(); }
};
