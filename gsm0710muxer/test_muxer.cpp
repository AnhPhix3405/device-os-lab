#include "muxer.h"
#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>

void test_muxer_performance() {
    muxer_init();
    uint8_t data[1000];
    for (int i = 0; i < 1000; ++i) data[i] = i % 256;
    clock_t start = clock();
    for (int i = 0; i < 10000; ++i) {
        muxer_process(data, sizeof(data));
    }
    clock_t end = clock();
    double elapsed = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Muxer processed 10,000 packets in %.2f seconds\n", elapsed);
    assert(elapsed < 2.0); // Giả sử tối ưu phải dưới 2 giây
    printf("Muxer performance test passed!\n");
}

int main() {
    test_muxer_performance();
    return 0;
}
