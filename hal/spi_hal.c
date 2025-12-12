#include "spi_hal.h"
#include <stdint.h>
#include <stdio.h>

// SPI clock divider calculation
uint32_t spi_calculate_clock_divider(uint32_t peripheral_clock, uint32_t desired_clock) {
    if (desired_clock == 0 || peripheral_clock == 0) {
        return 0; // Invalid clock
    }

    uint32_t divider = peripheral_clock / desired_clock;

    // Ensure the divider is a power of 2
    if (peripheral_clock % desired_clock != 0) {
        divider++;
    }

    // Clamp to the nearest power of 2
    uint32_t power_of_2 = 1;
    while (power_of_2 < divider) {
        power_of_2 <<= 1;
    }

    return power_of_2;
}

void spi_configure_dma(uint32_t dma_channel, uint32_t buffer_address, uint32_t buffer_size) {
    printf("Configuring SPI DMA: Channel %u, Buffer Address: 0x%08X, Size: %u\n", dma_channel, buffer_address, buffer_size);
    // Add DMA configuration logic here
}