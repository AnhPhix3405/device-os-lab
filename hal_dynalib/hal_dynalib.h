#ifndef HAL_DYNALIB_H
#define HAL_DYNALIB_H
#include "hal/spi.h"

// Export SPI API for dynalib
void dynalib_spi_init();
void dynalib_spi_send(uint8_t data);
uint8_t dynalib_spi_receive();
uint8_t dynalib_spi_transfer(uint8_t data);

#endif // HAL_DYNALIB_H
