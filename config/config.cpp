#include "config.hpp"

#include <nlohmann/json.hpp>
#include <fstream>


Config::Config(std::filesystem::path config_file) {

    std::ifstream file(config_file);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open config file: " + config_file.string());
    }

    nlohmann::json json_config;
    file >> json_config;

    file.close();

    try {
        host_ = json_config["host"].get<std::string>();
        port_ = json_config["port"].get<size_t>();
        log_level_ = static_cast<LogLevel>(json_config["log_level"].get<int>());
        log_file_ = json_config["log_file"].get<std::filesystem::path>();
        workers_ = json_config["workers"].get<size_t>();
    } catch (const nlohmann::json::exception& e) {
        throw std::runtime_error("Error parsing config file: " + std::string(e.what()));
    };
}
