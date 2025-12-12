#include <stdio.h>
#include "spi.h"

void hal_device_setup() {
    printf("HAL device setup...\n");
    spi_init();
    spi_enable_dma();
    // TODO: Thêm logic setup thiết bị
}
