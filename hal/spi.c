
#include "spi.h"
#include <stdio.h>

void spi_init() {
    // Khởi tạo SPI
    printf("SPI initialized.\n");
}

void spi_send(uint8_t data) {
    // Gửi dữ liệu qua SPI
    printf("SPI send: %02X\n", data);
}

uint8_t spi_receive() {
    // Nhận dữ liệu từ SPI
    printf("SPI receive.\n");
    return 0xAB;
}

uint8_t spi_transfer(uint8_t data) {
    // Gửi và nhận dữ liệu qua SPI
    printf("SPI transfer send: %02X\n", data);
    return 0xCD;
}
