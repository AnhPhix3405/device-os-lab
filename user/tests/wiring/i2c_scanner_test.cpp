#include "spark_wiring_i2c.h"
#include "unit_test.h"

test(I2C_Scanner) {
    uint8_t addresses[10];
    int result = I2CScan(addresses, 10);

    assertTrue(result >= 0); // Ensure no error occurred
    for (int i = 0; i < result; i++) {
        printf("Found device at address: 0x%02X\n", addresses[i]);
    }
}