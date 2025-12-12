#include "spi.h"
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

static bool dma_enabled = false;

void spi_init() {
    // Khởi tạo SPI
    printf("SPI initialized.\n");
}

void spi_enable_dma() {
    dma_enabled = true;
    printf("SPI DMA enabled.\n");
}

void spi_disable_dma() {
    dma_enabled = false;
    printf("SPI DMA disabled.\n");
}

void spi_send(uint8_t data) {
    if (dma_enabled) {
        printf("SPI DMA send: %02X\n", data);
        // Add DMA transfer logic here
    } else {
        printf("SPI send: %02X\n", data);
    }
}

uint8_t spi_receive() {
    if (dma_enabled) {
        printf("SPI DMA receive.\n");
        // Add DMA receive logic here
        return 0xAB;
    } else {
        printf("SPI receive.\n");
        return 0xAB;
    }
}

uint8_t spi_transfer(uint8_t data) {
    if (dma_enabled) {
        printf("SPI DMA transfer send: %02X\n", data);
        // Add DMA transfer logic here
        return 0xCD;
    } else {
        printf("SPI transfer send: %02X\n", data);
        return 0xCD;
    }
}
