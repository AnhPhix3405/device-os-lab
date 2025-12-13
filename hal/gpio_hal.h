#ifndef GPIO_HAL_H
#define GPIO_HAL_H

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief GPIO pin modes.
 */
typedef enum {
    GPIO_MODE_INPUT,
    GPIO_MODE_OUTPUT,
    GPIO_MODE_ALT,
    GPIO_MODE_ANALOG
} GPIO_Mode;

/**
 * @brief Configures a GPIO pin.
 *
 * This function sets the mode and initial state of a GPIO pin.
 *
 * @param pin The GPIO pin number.
 * @param mode The mode to configure the pin (input, output, etc.).
 * @param initial_state The initial state of the pin (true for high, false for low).
 * @return true if the configuration was successful, false otherwise.
 */
bool gpio_configure(uint8_t pin, GPIO_Mode mode, bool initial_state);

/**
 * @brief Writes a value to a GPIO pin.
 *
 * This function sets the output state of a GPIO pin.
 *
 * @param pin The GPIO pin number.
 * @param value The value to write (true for high, false for low).
 */
void gpio_write(uint8_t pin, bool value);

/**
 * @brief Reads the value of a GPIO pin.
 *
 * This function reads the current state of a GPIO pin.
 *
 * @param pin The GPIO pin number.
 * @return The current state of the pin (true for high, false for low).
 */
bool gpio_read(uint8_t pin);

#endif // GPIO_HAL_H