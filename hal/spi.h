#ifndef HAL_SPI_H
#define HAL_SPI_H
#include <stdint.h>

// Khởi tạo SPI
void spi_init();
// Gửi một byte qua SPI
void spi_send(uint8_t data);
// Nhận một byte từ SPI
uint8_t spi_receive();
// Gửi và nhận một byte qua SPI
uint8_t spi_transfer(uint8_t data);

#endif // HAL_SPI_H
