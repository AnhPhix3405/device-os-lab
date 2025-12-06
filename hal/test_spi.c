#include "spi.h"
#include <assert.h>
#include <stdio.h>

void test_spi() {
    spi_init();
    spi_send(0x55);
    uint8_t r = spi_receive();
    printf("Received: %02X\n", r);
    uint8_t t = spi_transfer(0xAA);
    printf("Transfer result: %02X\n", t);
    // Đơn giản kiểm tra giá trị trả về mẫu
    assert(r == 0xAB);
    assert(t == 0xCD);
    printf("SPI test passed!\n");
}

int main() {
    test_spi();
    return 0;
}
