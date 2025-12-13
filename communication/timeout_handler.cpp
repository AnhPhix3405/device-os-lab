#include "timeout_handler.h"
#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>

static std::atomic<bool> timeout_active(false);
static std::thread timeout_thread;

void timeout_handler_init(void) {
    timeout_active = false;
    std::cout << "Timeout handler initialized." << std::endl;
}

void set_timeout(uint32_t duration_ms, const std::function<void()>& callback) {
    if (timeout_active) {
        std::cerr << "Error: Timeout already active." << std::endl;
        return;
    }

    timeout_active = true;
    timeout_thread = std::thread([duration_ms, callback]() {
        std::this_thread::sleep_for(std::chrono::milliseconds(duration_ms));
        if (timeout_active) {
            callback();
        }
    });
    timeout_thread.detach();
}

void cancel_timeout(void) {
    if (!timeout_active) {
        std::cerr << "Error: No active timeout to cancel." << std::endl;
        return;
    }

    timeout_active = false;
    std::cout << "Timeout canceled." << std::endl;
}