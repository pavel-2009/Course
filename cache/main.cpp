#include "cache.hpp"

#include <iostream>
#include <thread>


int main() {
    Cache<std::string, int> cache(3);

    std::jthread t1([&cache]() {
        for (int i = 0; i < 5; ++i) {
            cache.put("key" + std::to_string(i), i);
            std::cout << "Thread 1: Put key" << i << " with value " << i << std::endl;
        }
    });
    std::jthread t2([&cache]() {
        for (int i = 0; i < 5; ++i) {
            try {
                int value = cache.get("key" + std::to_string(i));
                std::cout << "Thread 2: Got value " << value << " for key" << i << std::endl;
            } catch (const std::out_of_range& e) {
                std::cout << "Thread 2: Key" << i << " not found in cache." << std::endl;
            }
            // std::this_thread::sleep_for(std::chrono::milliseconds(150));
        }
    });

    t1.join();
    t2.join();
    return 0;
}
