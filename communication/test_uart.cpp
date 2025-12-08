#include "uart.h"
#include <assert.h>
#include <stdio.h>

void test_uart_overflow() {
    uart_init();
    // Ghi vượt quá buffer
    int overflow_count = 0;
    for (int i = 0; i < UART_BUFFER_SIZE + 10; ++i) {
        if (uart_write((uint8_t)i) == -1) overflow_count++;
    }
    printf("Overflow count: %d\n", overflow_count);
    assert(overflow_count == 10);
    // Đọc lại dữ liệu
    int read_count = 0;
    uint8_t data;
    while (uart_read(&data) == 0) {
        read_count++;
    }
    printf("Read count: %d\n", read_count);
    assert(read_count == UART_BUFFER_SIZE);
    printf("UART buffer overflow test passed!\n");
}

int main() {
    test_uart_overflow();
    return 0;
}
