#pragma once

#include <stdint.h>
#include "hal_platform.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Scans the I2C bus for connected devices.
 * 
 * @param bus The I2C bus to scan.
 * @param addresses Pointer to an array to store detected addresses.
 * @param max_addresses Maximum number of addresses to store.
 * @return int The number of devices found, or a negative value on error.
 */
int hal_i2c_scan(int bus, uint8_t* addresses, size_t max_addresses);

#ifdef __cplusplus
}
#endif