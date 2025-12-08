#include "main/config.h"
#include "services/services.h"
#include "services/logger.h"
#include "system.h"
#include <iostream>

int main() {
    set_log_level(LOG_DEBUG);
    set_log_format("%TIME% [%LEVEL%] %MSG%");
    log_info("System starting...");
    system_init();
    DeviceConfig config;
    if (!config.load("device.cfg")) {
        log_warn("No config found, creating default.");
        config.set("device_id", "12345");
        config.set("mode", "default");
        config.save("device.cfg");
    }
    log_debug("Device ID: " + config.get("device_id"));
    log_debug("Mode: " + config.get("mode"));
    Service::initialize();
    Service::execute();
    system_kick_watchdog();
    log_info("System finished.");
    return 0;
}
