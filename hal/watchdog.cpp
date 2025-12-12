#include "watchdog.h"
#include <iostream>
#include <thread>
#include <chrono>

static bool watchdog_running = false;
static std::thread watchdog_thread;

void watchdog_start(int timeout_ms) {
    watchdog_running = true;
    watchdog_thread = std::thread([timeout_ms]() {
        while (watchdog_running) {
            std::this_thread::sleep_for(std::chrono::milliseconds(timeout_ms));
            if (watchdog_running) {
                std::cerr << "[Watchdog] System reset triggered!" << std::endl;
                std::terminate();
            }
        }
    });
}

void watchdog_kick() {
    std::cout << "[Watchdog] Timer reset." << std::endl;
}

void watchdog_stop() {
    watchdog_running = false;
    if (watchdog_thread.joinable()) {
        watchdog_thread.join();
    }
    std::cout << "[Watchdog] Stopped." << std::endl;
}