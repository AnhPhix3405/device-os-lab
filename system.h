#ifndef SYSTEM_H
#define SYSTEM_H

#include "hal/hal_platform.h"
#include "logging.h"
#include "bootloader.h"
#include "crypto.h"
#include "hal/hal_thread.h"
#include "hal/gpio_hal.h"

#ifdef __cplusplus
extern "C" {
#endif

void system_init(void);
void system_kick_watchdog(void);
void system_stop_watchdog(void);
void system_secure_boot(void);

// System health monitoring
bool system_health_check(void);
void log_system_health(void);
void execute_with_watchdog(const std::function<void()>& task);

/**
 * @brief Validates the system configuration.
 *
 * This function checks if the system configuration is valid by ensuring
 * that all required components are initialized and operational.
 *
 * @return true if the configuration is valid, false otherwise.
 */
bool validate_system_configuration(void);

#ifdef __cplusplus
}
#endif

#endif // SYSTEM_H
