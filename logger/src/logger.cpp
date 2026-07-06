#include "logger.hpp"

#include <condition_variable>
#include <sstream>


Logger::Logger(const std::filesystem::path& log_file_path) 
    : log_file_(log_file_path, std::ios::out | std::ios::app), 
      worker_([this]() { this->workerLoop(); }) {
    if (!log_file_.is_open()) {
        throw std::runtime_error("Failed to open log file: " + log_file_path.string());
    }
}

Logger::~Logger() {
    {
        std::lock_guard<std::mutex> guard(lock_);
        stop_ = true;
    }

    log_file_.flush();

    cv_.notify_all();
    worker_.join();
}


void Logger::workerLoop() {

    while(true) {
        
        LogMessage message;

        {
            std::unique_lock<std::mutex> lock(lock_);
            cv_.wait(lock, [this]() { return !log_queue_.empty() || stop_; });

            if (stop_ && log_queue_.empty()) {
                break;
            }

            message = log_queue_.front();
            log_queue_.pop();
        }

        log_file_ << format(message) << std::endl;
    }

}


std::string Logger::format(const LogMessage& message) {
    std::time_t time = std::chrono::system_clock::to_time_t(message.timestamp);
    std::tm tm = *std::localtime(&time);

    char time_buffer[20];
    std::strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d %H:%M:%S", &tm);

    std::string level_str;
    switch (message.level) {
        case LogLevel::Trace: level_str = "TRACE"; break;
        case LogLevel::Debug: level_str = "DEBUG"; break;
        case LogLevel::Info: level_str = "INFO"; break;
        case LogLevel::Warning: level_str = "WARNING"; break;
        case LogLevel::Error: level_str = "ERROR"; break;
        case LogLevel::Fatal: level_str = "FATAL"; break;
    }

    std::ostringstream oss;
    oss << "[" << time_buffer << "] "
        << "[" << level_str << "] "
        << "[" << message.thread_id << "] "
        << message.text;

    return oss.str();
    
}

void Logger::log(LogLevel level, const std::string& text) {
    LogMessage message;
    message.timestamp = std::chrono::system_clock::now();
    message.level = level;
    message.thread_id = std::this_thread::get_id();
    message.text = text;

    {
        std::lock_guard<std::mutex> guard(lock_);
        log_queue_.push(message);
    }

    cv_.notify_one();
}
