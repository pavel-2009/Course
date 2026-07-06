#include "log_level.hpp"
#include "log_message.hpp"

#include <fstream>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <filesystem>


class Logger {

    private:
        std::ofstream log_file_;
        
        std::queue<LogMessage> log_queue_;

        std::mutex lock_;

        std::condition_variable cv_;

        std::jthread worker_;

        bool stop_ = false;

    private:
        void workerLoop();

        std::string format(const LogMessage& message);

    public:
        explicit Logger(const std::filesystem::path& log_file_path);

        ~Logger();

        Logger(const Logger&) = delete;
        Logger& operator=(const Logger&) = delete;

        Logger(Logger&&) = delete;
        Logger& operator=(Logger&&) = delete;

        void log(LogLevel level, const std::string& text);

};
