#include "new_hardware.h"
#include "hal/hal.h"
#include "system/system.h"

void NewHardware::initialize() {
    // Initialize hardware-specific components
    hal_initialize();
    system_initialize();
    Log.info("New hardware platform initialized successfully.");
}

void NewHardware::reset() {
    // Reset hardware-specific components
    hal_reset();
    Log.info("New hardware platform reset successfully.");
}