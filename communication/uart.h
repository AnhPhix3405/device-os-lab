#ifndef UART_H
#define UART_H
#include <stdint.h>
#include <stddef.h>

#define UART_BUFFER_SIZE 128

void uart_init();
int uart_write(uint8_t data);
int uart_read(uint8_t* data);
size_t uart_available();

// Gửi buffer dữ liệu kèm CRC
int uart_send_with_crc(const uint8_t* data, size_t length);
// Nhận buffer dữ liệu và kiểm tra CRC
int uart_receive_with_crc(uint8_t* buffer, size_t length);

#endif // UART_H
