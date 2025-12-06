#include "interrupt.h"
#include <assert.h>
#include <stdio.h>

static int interrupt_count = 0;

void test_handler() {
    interrupt_count++;
    printf("Interrupt handled!\n");
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

int main() {
    test_interrupt();
    return 0;
}
