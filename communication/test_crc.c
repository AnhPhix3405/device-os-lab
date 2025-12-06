#include "crc.h"
#include <assert.h>
#include <stdio.h>

void test_crc() {
    uint8_t data[] = {0x12, 0x34, 0x56, 0x78};
    uint16_t crc = crc16(data, sizeof(data));
    printf("CRC16: %04X\n", crc);
    assert(crc16_check(data, sizeof(data), crc));
    printf("CRC test passed!\n");
}

int main() {
    test_crc();
    return 0;
}
