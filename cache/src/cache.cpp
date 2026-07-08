#include "cache.hpp"


template<typename T, typename U>
U Cache<T, U>::get(const T& key) {

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

template<typename T, typename U>
void Cache<T, U>::put(const T& key, const U& value) {
    
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

template<typename T, typename U>
bool Cache<T, U>::contains(const T& key) const {
    return item_map.find(key) != item_map.end();
}

template<typename T, typename U>
void Cache<T, U>::erase(const T& key) {
    auto link = item_map.find(key);
    if (link != item_map.end()) {
        auto item = link->second;
        items.erase(item);
        item_map.erase(link);
    }
    return;
}

template<typename T, typename U>
void Cache<T, U>::clear() {
    items.clear();
    item_map.clear();
}
