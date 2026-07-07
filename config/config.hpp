#pragma once

#include "log_level.hpp"

#include <string>
#include <vector>
#include <thread>
#include <filesystem>


class Config {

    private:
        std::string host_;
        size_t port_;
        size_t workers_;
        LogLevel log_level_;
        std::filesystem::path log_file_;

    public:
        Config(std::filesystem::path config_file) {};

        ~Config() {};

        Config(const Config&) = delete;
        Config& operator=(const Config&) = delete;

        Config(Config&&) = delete;
        Config& operator=(Config&&) = delete;

        std::string host() const { return host_; };
        size_t port() const { return port_; };
        size_t workers() const { return workers_; };
        LogLevel logLevel() const { return log_level_; };
        std::filesystem::path logFile() const { return log_file_; };
};
