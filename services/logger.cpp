#include "logger.h"
#include <iostream>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <cstdarg>

static LogLevel current_level = LOG_INFO;
static std::string log_format = "%TIME% [%LEVEL%] %MSG%";

static std::string get_level_str(LogLevel level) {
    switch (level) {
        case LOG_DEBUG: return "DEBUG";
        case LOG_INFO: return "INFO";
        case LOG_WARN: return "WARN";
        case LOG_ERROR: return "ERROR";
        default: return "UNKNOWN";
    }
}

static std::string get_time_str() {
    std::ostringstream oss;
    std::time_t t = std::time(nullptr);
    oss << std::put_time(std::localtime(&t), "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

void set_log_level(LogLevel level) {
    current_level = level;
}

void set_log_format(const std::string& format) {
    log_format = format;
}

void log_message(LogLevel level, const char* fmt, ...) {
    if (level < current_level) return;
    char msg_buf[1024];
    va_list args;
    va_start(args, fmt);
    vsnprintf(msg_buf, sizeof(msg_buf), fmt, args);
    va_end(args);
    std::string out = log_format;
    size_t pos;
    while ((pos = out.find("%TIME%")) != std::string::npos) out.replace(pos, 6, get_time_str());
    while ((pos = out.find("%LEVEL%")) != std::string::npos) out.replace(pos, 8, get_level_str(level));
    while ((pos = out.find("%MSG%")) != std::string::npos) out.replace(pos, 5, msg_buf);
    if (level == LOG_ERROR)
        std::cerr << out << std::endl;
    else
        std::cout << out << std::endl;
}

void log_debug(const std::string& msg) {
    log_message(LOG_DEBUG, "%s", msg.c_str());
}

void log_info(const std::string& msg) {
    log_message(LOG_INFO, "%s", msg.c_str());
}

void log_error(const std::string& msg) {
    log_message(LOG_ERROR, "%s", msg.c_str());
}
