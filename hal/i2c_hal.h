#ifndef I2C_HAL_H
#define I2C_HAL_H

#include <stdint.h>
#include <stdbool.h>

// Function prototypes
bool i2c_handle_arbitration_loss(void);
void i2c_reset_bus(void);

#endif // I2C_HAL_H

// ...existing code...