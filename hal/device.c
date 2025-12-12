#include <stdio.h>
#include "spi.h"
#include "adc.h"
#include "watchdog.h"

void hal_device_setup() {
    printf("HAL device setup...\n");
    spi_init();
    spi_enable_dma();
    adc_init();
    adc_calibrate();
    watchdog_init(5000); // Initialize watchdog with 5-second timeout
    watchdog_start();
    // TODO: Thêm logic setup thiết bị
}
