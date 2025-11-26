#pragma once

#include "application.h"

/**
 * @brief Scans the I2C bus for connected devices.
 * 
 * @param addresses Pointer to an array to store detected addresses.
 * @param max_addresses Maximum number of addresses to store.
 * @return int The number of devices found, or a negative value on error.
 */
int I2CScan(uint8_t* addresses, size_t max_addresses);