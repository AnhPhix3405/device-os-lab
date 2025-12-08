#include "interrupt.h"
#include <stdio.h>

static void (*interrupt_handler)(void) = 0;
static int interrupt_enabled = 0;

static volatile int interrupt_flag = 0;

void hal_register_interrupt_handler(void (*handler)(void)) {
    interrupt_handler = handler;
}

void hal_enable_interrupt() {
    interrupt_enabled = 1;
    printf("Interrupt enabled\n");
}

void hal_disable_interrupt() {
    interrupt_enabled = 0;
    printf("Interrupt disabled\n");
}

// Hàm mô phỏng xảy ra ngắt
void hal_trigger_interrupt() {
    if (interrupt_enabled && interrupt_handler) {
        interrupt_handler();
        interrupt_flag = 1;
    }
}

void hal_clear_interrupt_flag() {
    interrupt_flag = 0;
}

int hal_interrupt_flag() {
    return interrupt_flag;
}
