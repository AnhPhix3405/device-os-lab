#ifndef I2C_HAL_H
#define I2C_HAL_H

#include <stdint.h>
#include <stdbool.h>

// Function prototypes
bool i2c_handle_arbitration_loss(void);
void i2c_reset_bus(void);

/**
 * @brief Initializes the I2C peripheral.
 *
 * This function sets up the I2C hardware with the specified configuration.
 *
 * @param clock_speed The I2C clock speed in Hz.
 * @return true if initialization was successful, false otherwise.
 */
bool i2c_init(uint32_t clock_speed);

/**
 * @brief Sends data over I2C.
 *
 * This function transmits the specified data to a given I2C address.
 *
 * @param address The I2C address of the target device.
 * @param data A pointer to the data buffer to send.
 * @param length The length of the data buffer in bytes.
 * @return The number of bytes successfully sent.
 */
size_t i2c_send(uint8_t address, const uint8_t* data, size_t length);

/**
 * @brief Receives data over I2C.
 *
 * This function reads data from a given I2C address into the specified buffer.
 *
 * @param address The I2C address of the target device.
 * @param buffer A pointer to the buffer to store received data.
 * @param length The maximum number of bytes to receive.
 * @return The number of bytes successfully received.
 */
size_t i2c_receive(uint8_t address, uint8_t* buffer, size_t length);

#endif // I2C_HAL_H