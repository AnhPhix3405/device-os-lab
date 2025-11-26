#include "hal_i2c.h"
#include "hal_pinmap.h"

// ...existing code...

int hal_i2c_scan(int bus, uint8_t* addresses, size_t max_addresses) {
    if (!addresses || max_addresses == 0) {
        return -1; // Invalid parameters
    }

    size_t count = 0;
    for (uint8_t addr = 1; addr < 127; addr++) {
        if (hal_i2c_write(bus, addr, nullptr, 0) == 0) { // Probe address
            if (count < max_addresses) {
                addresses[count++] = addr;
            } else {
                break; // Reached max_addresses
            }
        }
    }

    return count; // Return the number of devices found
}

// ...existing code...