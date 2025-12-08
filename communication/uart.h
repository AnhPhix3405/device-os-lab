#ifndef UART_H
#define UART_H
#include <stdint.h>
#include <stddef.h>

#define UART_BUFFER_SIZE 128

void uart_init();
int uart_write(uint8_t data);
int uart_read(uint8_t* data);
size_t uart_available();

#endif // UART_H
