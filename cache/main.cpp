#include "cache.hpp"

#include <iostream>


int main() {
    Cache<std::string, int> cache(3);

    cache.put("one", 1);
    cache.put("two", 2);
    cache.put("three", 3);

    if (cache.contains("two")) {
        std::cout << "Key 'two' found with value: " << cache.get("two") << std::endl;
    }

    cache.put("four", 4); // This should evict the least recently used item

    if (!cache.contains("one")) {
        std::cout << "Key 'one' has been evicted." << std::endl;
    }

    return 0;
}
