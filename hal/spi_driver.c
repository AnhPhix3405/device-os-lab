#include "spi_driver.h"
#include <stdio.h>
#include <string.h>

static uint32_t current_clock_speed = 0;
static uint8_t current_mode = 0;
static bool current_bit_order = true;

bool spi_init(uint32_t clock_speed, uint8_t mode, bool bit_order) {
    if (mode > 3) {
        printf("Error: Invalid SPI mode.\n");
        return false;
    }

    current_clock_speed = clock_speed;
    current_mode = mode;
    current_bit_order = bit_order;

    printf("SPI initialized with clock speed: %u Hz, mode: %u, bit order: %s\n",
           clock_speed, mode, bit_order ? "MSB first" : "LSB first");
    return true;
}

size_t spi_send(const uint8_t* data, size_t length) {
    if (data == NULL || length == 0) {
        printf("Error: Invalid data or length.\n");
        return 0;
    }

    printf("SPI sending data: ");
    for (size_t i = 0; i < length; ++i) {
        printf("%02X ", data[i]);
    }
    printf("\n");

    return length;
}

size_t spi_receive(uint8_t* buffer, size_t length) {
    if (buffer == NULL || length == 0) {
        printf("Error: Invalid buffer or length.\n");
        return 0;
    }

    // Simulate receiving data
    memset(buffer, 0xAB, length);
    printf("SPI received data: ");
    for (size_t i = 0; i < length; ++i) {
        printf("%02X ", buffer[i]);
    }
    printf("\n");

    return length;
}