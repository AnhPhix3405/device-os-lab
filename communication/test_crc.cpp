#include "crc.h"
#include "uart.h"
#include <iostream>

int main() {
    uint8_t data[4] = {0x01, 0x02, 0x03, 0x04};
    uint16_t crc = crc16(data, 4);
    std::cout << "CRC16: " << std::hex << crc << std::endl;

    uart_init();
    // Gửi dữ liệu kèm CRC
    if (uart_send_with_crc(data, 4) == 0) {
        std::cout << "Send with CRC success" << std::endl;
    } else {
        std::cout << "Send with CRC failed" << std::endl;
    }

    uint8_t recv[4];
    int res = uart_receive_with_crc(recv, 4);
    if (res == 0) {
        std::cout << "Receive with CRC success" << std::endl;
    } else if (res == -2) {
        std::cout << "CRC mismatch" << std::endl;
    } else {
        std::cout << "Receive with CRC failed" << std::endl;
    }
    return 0;
}
