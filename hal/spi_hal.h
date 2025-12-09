#ifndef SPI_HAL_H
#define SPI_HAL_H

#include <stdint.h>

// Function prototypes
uint32_t spi_calculate_clock_divider(uint32_t peripheral_clock, uint32_t desired_clock);

#endif // SPI_HAL_H

// ...existing code...