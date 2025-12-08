#include "muxer.h"
#include <stdio.h>
#include <stdint.h>

void muxer_init() {
    // Khởi tạo muxer
    printf("Muxer initialized.\n");
}

void muxer_process(const uint8_t* data, size_t len) {
    // Tối ưu: xử lý dữ liệu nhanh hơn (demo: chỉ in ra độ dài)
    printf("Processing %zu bytes in muxer.\n", len);
}
