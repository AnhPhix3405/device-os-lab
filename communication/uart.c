#include "uart.h"
#include <stdio.h>

static uint8_t uart_buffer[UART_BUFFER_SIZE];
static size_t head = 0, tail = 0;

void uart_init() {
    head = tail = 0;
}

int uart_write(uint8_t data) {
    size_t next_head = (head + 1) % UART_BUFFER_SIZE;
    if (next_head == tail) {
        // Buffer đầy, không ghi thêm
        printf("UART buffer overflow!\n");
        return -1;
    }
    uart_buffer[head] = data;
    head = next_head;
    return 0;
}

int uart_read(uint8_t* data) {
    if (head == tail) {
        // Buffer rỗng
        return -1;
    }
    *data = uart_buffer[tail];
    tail = (tail + 1) % UART_BUFFER_SIZE;
    return 0;
}

size_t uart_available() {
    if (head >= tail) return head - tail;
    return UART_BUFFER_SIZE - tail + head;
}
