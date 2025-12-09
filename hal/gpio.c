#include "gpio.h"
#include <stdint.h>
#include <stdbool.h>

// Debounce configuration structure
typedef struct {
    uint32_t debounce_time_ms;
    uint32_t last_stable_time;
    bool last_stable_state;
} GPIO_DebounceConfig;

// Example debounce implementation
bool gpio_read_with_debounce(GPIO_Pin pin, GPIO_DebounceConfig* config) {
    uint32_t current_time = system_get_time_ms(); // Assume this function exists
    bool current_state = gpio_read(pin);

    if (current_state != config->last_stable_state) {
        if ((current_time - config->last_stable_time) >= config->debounce_time_ms) {
            config->last_stable_state = current_state;
            config->last_stable_time = current_time;
        }
    }

    return config->last_stable_state;
}

// ...existing code...