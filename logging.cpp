#include "logging.h"
#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>

static LogLevel currentLogLevel = LOG_INFO;
static std::string logFormat = "%TIME% [%LEVEL%] %MSG%";
static std::string timestampFormat = "%Y-%m-%d %H:%M:%S";

std::string get_current_time() {
    auto now = std::chrono::system_clock::now();
    auto time_t_now = std::chrono::system_clock::to_time_t(now);
    auto local_time = *std::localtime(&time_t_now);

    std::ostringstream oss;
    oss << std::put_time(&local_time, timestampFormat.c_str());
    return oss.str();
}

std::string log_level_to_string(LogLevel level) {
    switch (level) {
        case LOG_DEBUG: return "DEBUG";
        case LOG_INFO: return "INFO";
        case LOG_WARN: return "WARN";
        case LOG_ERROR: return "ERROR";
        default: return "UNKNOWN";
    }
}

void set_log_level(LogLevel level) {
    currentLogLevel = level;
}

void set_log_format(const std::string& format) {
    logFormat = format;
}

void set_log_timestamp_format(const std::string& format) {
    timestampFormat = format;
}

void log_message(LogLevel level, const std::string& message) {
    if (level < currentLogLevel) {
        return;
    }

    std::string log = logFormat;
    size_t pos;

    while ((pos = log.find("%TIME%")) != std::string::npos) {
        log.replace(pos, 6, get_current_time());
    }
    while ((pos = log.find("%LEVEL%")) != std::string::npos) {
        log.replace(pos, 7, log_level_to_string(level));
    }
    while ((pos = log.find("%MSG%")) != std::string::npos) {
        log.replace(pos, 5, message);
    }

    std::cout << log << std::endl;
}

void log_debug(const std::string& message) {
    log_message(LOG_DEBUG, message);
}

void log_info(const std::string& message) {
    log_message(LOG_INFO, message);
}

void log_warn(const std::string& message) {
    log_message(LOG_WARN, message);
}

void log_error(const std::string& message) {
    log_message(LOG_ERROR, message);
}

// C-compatible wrapper functions
extern "C" {
    void log_info_c(const char* message) {
        if (message) {
            log_info(std::string(message));
        }
    }
    
    void log_error_c(const char* message) {
        if (message) {
            log_error(std::string(message));
        }
    }
    
    void log_warn_c(const char* message) {
        if (message) {
            log_warn(std::string(message));
        }
    }
    
    void log_debug_c(const char* message) {
        if (message) {
            log_debug(std::string(message));
        }
    }
}