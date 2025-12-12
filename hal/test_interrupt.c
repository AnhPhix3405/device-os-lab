#include "interrupt.h"
#include "gpio.h"
#include <assert.h>
#include <stdio.h>

static int interrupt_count = 0;
static int gpio_interrupt_count = 0;

void test_handler() {
    interrupt_count++;
    printf("Interrupt handled!\n");
}

void gpio_test_handler() {
    gpio_interrupt_count++;
    printf("GPIO Interrupt handled!\n");
}

void test_interrupt() {
    hal_register_interrupt_handler(test_handler);
    hal_enable_interrupt();
    interrupt_count = 0;
    // Kích hoạt ngắt 3 lần
    for (int i = 0; i < 3; ++i) {
        extern void hal_trigger_interrupt();
        hal_trigger_interrupt();
    }
    assert(interrupt_count == 3);
    hal_disable_interrupt();
    hal_trigger_interrupt(); // Không nên tăng interrupt_count
    assert(interrupt_count == 3);
    printf("Interrupt test passed!\n");
}

void test_gpio_interrupt() {
    gpio_register_interrupt_handler(gpio_test_handler);
    gpio_interrupt_count = 0;

    // Simulate GPIO interrupts
    for (int i = 0; i < 3; ++i) {
        gpio_trigger_interrupt();
    }

    assert(gpio_interrupt_count == 3);
    printf("GPIO Interrupt test passed!\n");
}

int main() {
    test_interrupt();
    test_gpio_interrupt();
    return 0;
}
