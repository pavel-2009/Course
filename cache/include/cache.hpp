#pragma once

#include <list>
#include <unordered_map>
#include <string>


template<typename T, typename U>
class Cache {
    private:
        size_t capacity;
        std::list<std::pair<T, U>> items;
        std::unordered_map<T, std::list<std::pair<T, U>>::iterator> item_map;

    public:
        Cache(size_t capacity) : capacity(capacity) {}

        ~Cache() = default;

        Cache(const Cache&) = delete;
        Cache& operator=(const Cache&) = delete;

        Cache(Cache&&) = delete;
        Cache& operator=(Cache&&) = delete;

        U get(const T& key);
        void put(const T& key, const U& value);
        bool contains(const T& key) const;
        void erase(const T& key);
        void clear();

        size_t size() const {
            return items.size();
        }
        bool empry() const {
            return items.empty();
        }
};
