#ifndef SPI_DRIVER_H
#define SPI_DRIVER_H

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief Initializes the SPI driver.
 *
 * This function sets up the SPI hardware with the specified configuration.
 *
 * @param clock_speed The SPI clock speed in Hz.
 * @param mode The SPI mode (0, 1, 2, or 3).
 * @param bit_order The bit order (true for MSB first, false for LSB first).
 * @return true if initialization was successful, false otherwise.
 */
bool spi_init(uint32_t clock_speed, uint8_t mode, bool bit_order);

/**
 * @brief Sends data over SPI.
 *
 * This function transmits the specified data over the SPI interface.
 *
 * @param data A pointer to the data buffer to send.
 * @param length The length of the data buffer in bytes.
 * @return The number of bytes successfully sent.
 */
size_t spi_send(const uint8_t* data, size_t length);

/**
 * @brief Receives data over SPI.
 *
 * This function reads data from the SPI interface into the specified buffer.
 *
 * @param buffer A pointer to the buffer to store received data.
 * @param length The maximum number of bytes to receive.
 * @return The number of bytes successfully received.
 */
size_t spi_receive(uint8_t* buffer, size_t length);

#endif // SPI_DRIVER_H