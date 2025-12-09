#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>
#include <stdbool.h>

typedef int GPIO_Pin;

// Function prototypes
bool gpio_read(GPIO_Pin pin);
void gpio_write(GPIO_Pin pin, bool value);

// Debounce support
typedef struct {
    uint32_t debounce_time_ms;
    uint32_t last_stable_time;
    bool last_stable_state;
} GPIO_DebounceConfig;

bool gpio_read_with_debounce(GPIO_Pin pin, GPIO_DebounceConfig* config);

#endif // GPIO_H

// ...existing code...