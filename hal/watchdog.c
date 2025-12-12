#include "watchdog.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

static bool watchdog_enabled = false;
static uint32_t watchdog_timeout_ms = 0;

void watchdog_init(uint32_t timeout_ms) {
    watchdog_timeout_ms = timeout_ms;
    printf("Watchdog initialized with timeout: %u ms\n", timeout_ms);
}

void watchdog_start() {
    if (!watchdog_enabled) {
        watchdog_enabled = true;
        printf("Watchdog started.\n");
    }
}

void watchdog_kick() {
    if (watchdog_enabled) {
        printf("Watchdog kicked.\n");
    }
}

void watchdog_stop() {
    if (watchdog_enabled) {
        watchdog_enabled = false;
        printf("Watchdog stopped.\n");
    }
}