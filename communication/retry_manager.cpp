#include "retry_manager.h"
#include "logging.h"
#include <thread>
#include <chrono>
#include <iostream>

void retry_manager_init(void) {
    log_info("Retry manager initialized.");
}

void schedule_retry(const std::function<bool()>& operation, uint32_t delay_ms, uint8_t max_attempts) {
    std::thread([operation, delay_ms, max_attempts]() {
        for (uint8_t attempt = 1; attempt <= max_attempts; ++attempt) {
            log_info("Attempt " + std::to_string(attempt) + " of " + std::to_string(max_attempts));
            if (operation()) {
                log_info("Operation succeeded on attempt " + std::to_string(attempt));
                return;
            }
            log_warn("Operation failed on attempt " + std::to_string(attempt));
            std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms));
        }
        log_error("Operation failed after " + std::to_string(max_attempts) + " attempts.");
    }).detach();
}