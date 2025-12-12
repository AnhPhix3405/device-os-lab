#include "gpio.h"
#include <stdint.h>
#include <stdbool.h>
#include "interrupt.h"

// Debounce configuration structure
typedef struct {
    uint32_t debounce_time_ms;
    uint32_t last_stable_time;
    bool last_stable_state;
} GPIO_DebounceConfig;

static void (*gpio_interrupt_handler)(void) = NULL;

void gpio_register_interrupt_handler(void (*handler)(void)) {
    gpio_interrupt_handler = handler;
}

void gpio_trigger_interrupt() {
    if (gpio_interrupt_handler) {
        gpio_interrupt_handler();
    }
}

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