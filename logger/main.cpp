#include <logger.hpp>


int main() {

    Logger logger("log.txt");

    logger.log(LogLevel::Info, "Application started.");
    logger.log(LogLevel::Debug, "Debugging information.");
    logger.log(LogLevel::Warning, "This is a warning message.");
    logger.log(LogLevel::Error, "An error occurred.");
    logger.log(LogLevel::Fatal, "Fatal error! Application will terminate.");

    return 0;

}
