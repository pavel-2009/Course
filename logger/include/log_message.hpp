#include <chrono>
#include <thread>

#include "log_level.hpp"


struct LogMessage {
    std::chrono::system_clock::time_point timestamp;

    LogLevel level;

    std::thread::id thread_id;

    std::string text;
};