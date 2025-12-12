#include "hal_dynalib.h"
#include <iostream>

void dynalib_spi_init() {
    std::cout << "[HAL Dynalib] SPI initialized." << std::endl;
}

void dynalib_spi_send(uint8_t data) {
    std::cout << "[HAL Dynalib] SPI send: " << static_cast<int>(data) << std::endl;
}

uint8_t dynalib_spi_receive() {
    std::cout << "[HAL Dynalib] SPI receive." << std::endl;
    return 0xFF; // Example received data
}

uint8_t dynalib_spi_transfer(uint8_t data) {
    std::cout << "[HAL Dynalib] SPI transfer: " << static_cast<int>(data) << std::endl;
    return data; // Echo back the data for simplicity
}