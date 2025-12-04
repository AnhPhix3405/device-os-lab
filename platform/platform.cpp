#include "new_hardware.h"

void platform_initialize() {
    // Initialize existing platforms
    existing_platform_initialize();

    // Initialize new hardware platform
    NewHardware::initialize();
}