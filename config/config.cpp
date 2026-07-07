#include "config.hpp"

#include <nlohmann/json.hpp>
#include <fstream>
#include <stdexcept>


Config::Config(std::filesystem::path config_file) {

    std::ifstream file(config_file);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open config file: " + config_file.string());
    }

    nlohmann::json json_config;
    file >> json_config;

    file.close();

    try {
        host_ = json_config.at("host").get<std::string>();
        port_ = json_config.at("port").get<size_t>();
        workers_ = json_config.at("workers").get<size_t>();

        std::string log_level_str = json_config.at("log_level").get<std::string>();
        if (log_level_str == "trace") {
            log_level_ = LogLevel::Trace;
        } else if (log_level_str == "debug") {
            log_level_ = LogLevel::Debug;
        } else if (log_level_str == "info") {
            log_level_ = LogLevel::Info;
        } else if (log_level_str == "warning") {
            log_level_ = LogLevel::Warning;
        } else if (log_level_str == "error") {
            log_level_ = LogLevel::Error;
        } else if (log_level_str == "fatal") {
            log_level_ = LogLevel::Fatal;
        } else {
            throw std::runtime_error("Invalid log level in config file: " + log_level_str);
        }

        log_file_ = json_config.at("log_file").get<std::filesystem::path>();

    } catch (const nlohmann::json::exception& e) {
        throw std::runtime_error("Error parsing config file: " + std::string(e.what()));
    }
}
