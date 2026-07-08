#pragma once

#include <list>
#include <unordered_map>
#include <string>
#include <stdexcept>


template<typename T, typename U>
class Cache {
    private:
        size_t capacity;
        std::list<std::pair<T, U>> items;
        std::unordered_map<T, typename std::list<std::pair<T, U>>::iterator> item_map;

    public:
        Cache(size_t capacity) : capacity(capacity) {}

        ~Cache() = default;

        Cache(const Cache&) = delete;
        Cache& operator=(const Cache&) = delete;

        Cache(Cache&&) = delete;
        Cache& operator=(Cache&&) = delete;

        U get(const T& key) {

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
            return item_map.find(key) != item_map.end();
        }

        void erase(const T& key) {
            auto link = item_map.find(key);
            if (link != item_map.end()) {
                auto item = link->second;
                items.erase(item);
                item_map.erase(link);
            }
            return;
        }

        void clear() {
            items.clear();
            item_map.clear();
        }

        size_t size() const {
            return items.size();
        }
        bool empry() const {
            return items.empty();
        }
};
