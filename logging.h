#ifndef LOGGING_H
#define LOGGING_H

#include <string>
#include <chrono>

enum LogLevel {
    LOG_DEBUG,
    LOG_INFO,
    LOG_WARN,
    LOG_ERROR
};

void set_log_level(LogLevel level);
void set_log_format(const std::string& format);
void log_debug(const std::string& message);
void log_info(const std::string& message);
void log_warn(const std::string& message);
void log_error(const std::string& message);
void set_log_timestamp_format(const std::string& format);

#endif // LOGGING_H