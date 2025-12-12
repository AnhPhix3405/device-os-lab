#ifndef HAL_DYNALIB_H
#define HAL_DYNALIB_H

#include "gpio.h"
#include "i2c_hal.h"

// Export GPIO debounce functionality
bool gpio_read_with_debounce(GPIO_Pin pin, GPIO_DebounceConfig* config);

// Export I2C multi-master support
bool i2c_handle_arbitration_loss(void);
void i2c_reset_bus(void);

#endif // HAL_DYNALIB_H

// ...existing code...