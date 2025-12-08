#ifndef SERVICES_LOGGER_H
#define SERVICES_LOGGER_H
#include <string>
#include <cstdarg>

enum LogLevel {
    LOG_DEBUG = 0,
    LOG_INFO = 1,
    LOG_WARN = 2,
    LOG_ERROR = 3
};

void set_log_level(LogLevel level);
void set_log_format(const std::string& format); // e.g. "%TIME% [%LEVEL%] %MSG%"
void log_message(LogLevel level, const char* fmt, ...);

void log_debug(const std::string& msg);
void log_info(const std::string& msg);
void log_error(const std::string& msg);

#endif // SERVICES_LOGGER_H
