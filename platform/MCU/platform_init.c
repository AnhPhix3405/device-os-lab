#include "platform_init.h"

// Modularized platform initialization function
void platform_init() {
    // Initialize MCU-specific components
    mcu_init();

    // Optimize network initialization
    if (!net_init()) {
        Log.error("Network initialization failed");
        return;
    }

    // Additional modular initialization can be added here
    Log.info("Platform initialization completed successfully");
}