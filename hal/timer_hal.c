#include "timer_hal.h"
#include <stdio.h>

static uint32_t timer_values[256] = {0}; // Simulated timer values for up to 256 timers

bool timer_init(uint8_t timer_id, uint32_t frequency) {
    if (timer_id >= 256) {
        printf("Error: Invalid timer ID.\n");
        return false;
    }

    printf("Timer %d initialized with frequency %u Hz.\n", timer_id, frequency);
    timer_values[timer_id] = 0;
    return true;
}

void timer_start(uint8_t timer_id) {
    if (timer_id >= 256) {
        printf("Error: Invalid timer ID.\n");
        return;
    }

    printf("Timer %d started.\n", timer_id);
}

void timer_stop(uint8_t timer_id) {
    if (timer_id >= 256) {
        printf("Error: Invalid timer ID.\n");
        return;
    }

    printf("Timer %d stopped.\n", timer_id);
}

void timer_reset(uint8_t timer_id) {
    if (timer_id >= 256) {
        printf("Error: Invalid timer ID.\n");
        return;
    }

    timer_values[timer_id] = 0;
    printf("Timer %d reset.\n", timer_id);
}

uint32_t timer_get_value(uint8_t timer_id) {
    if (timer_id >= 256) {
        printf("Error: Invalid timer ID.\n");
        return 0;
    }

    printf("Timer %d current value: %u\n", timer_id, timer_values[timer_id]);
    return timer_values[timer_id];
}