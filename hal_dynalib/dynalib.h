#ifndef HAL_DYNALIB_H
#define HAL_DYNALIB_H

#include "gpio.h"

// Export GPIO debounce functionality
bool gpio_read_with_debounce(GPIO_Pin pin, GPIO_DebounceConfig* config);

#endif // HAL_DYNALIB_H

// ...existing code...