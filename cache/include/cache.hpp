#pragma once

#include <list>
#include <unordered_map>
#include <string>
#include <stdexcept>
#include <mutex>


template<typename T, typename U>
class Cache {
    private:
        size_t capacity;
        std::list<std::pair<T, U>> items;
        std::unordered_map<T, typename std::list<std::pair<T, U>>::iterator> item_map;
        std::mutex mtx;

    public:
        Cache(size_t capacity) : capacity(capacity) {}

        ~Cache() = default;

        Cache(const Cache&) = delete;
        Cache& operator=(const Cache&) = delete;

        Cache(Cache&&) = default;
        Cache& operator=(Cache&&) = default;

        U get(const T& key) {

            std::lock_guard<std::mutex> lock(mtx);

            auto link = item_map.find(key);
            if (link == item_map.end()) {
                throw std::out_of_range("Key not found in cache");
            }

            // Get the value via the link iterator
            auto item = link->second;
            U value = item->second;

            // Move the accessed item to the front of the list
            items.splice(items.begin(), items, item);

            return value;

        }

        void put(const T& key, const U& value) {
    
            std::lock_guard<std::mutex> lock(mtx);

            auto link = item_map.find(key);
            if (link != item_map.end()) {
                auto item = link->second;
                item->second = value;
                items.splice(items.begin(), items, item);
                return;
            } else {

                if (items.size() >= capacity) {
                    auto last_item = items.back();
                    item_map.erase(last_item.first);
                    items.pop_back();
                }

                items.emplace_front(key, value);
                item_map[key] = items.begin();
            }

        }

        bool contains(const T& key) const {
            std::lock_guard<std::mutex> lock(mtx);
            return item_map.find(key) != item_map.end();
        }

        void erase(const T& key) {
            std::lock_guard<std::mutex> lock(mtx);
            auto link = item_map.find(key);
            if (link != item_map.end()) {
                auto item = link->second;
                items.erase(item);
                item_map.erase(link);
            }
            return;
        }

        void clear() {
            std::lock_guard<std::mutex> lock(mtx);
            items.clear();
            item_map.clear();
        }

        size_t size() const {
            std::lock_guard<std::mutex> lock(mtx);
            return items.size();
        };

        bool empty() const {
            std::lock_guard<std::mutex> lock(mtx);
            return items.empty();
        };
};
