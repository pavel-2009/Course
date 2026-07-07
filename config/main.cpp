#include "config.hpp"

#include <iostream>
#include <string>


int main() {
    Config config("config.json");

    // Use the loaded configuration
    std::cout << "Host: " << config.host() << std::endl;
    std::cout << "Port: " << config.port() << std::endl;
    std::cout << "Log Level: " << config.logLevel() << std::endl;
    std::cout << "Log File: " << config.logFile() << std::endl;
    std::cout << "Workers: " << config.workers() << std::endl;

    return 0;
}
