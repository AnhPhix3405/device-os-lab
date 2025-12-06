#include "spi.h"
#include <stdio.h>

void spi_init() {
    // TODO: Thêm logic khởi tạo SPI thực tế
    printf("SPI initialized.\n");
}

void spi_send(uint8_t data) {
    // TODO: Thêm logic gửi dữ liệu qua SPI
    printf("SPI send: %02X\n", data);
}

uint8_t spi_receive() {
    // TODO: Thêm logic nhận dữ liệu từ SPI
    printf("SPI receive.\n");
    return 0xAB; // Giá trị mẫu
}

uint8_t spi_transfer(uint8_t data) {
    // TODO: Thêm logic gửi và nhận dữ liệu qua SPI
    printf("SPI transfer send: %02X\n", data);
    return 0xCD; // Giá trị mẫu
}
