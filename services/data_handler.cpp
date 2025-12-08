#include "data_handler.h"
#include <stdio.h>

static int last_sum = 0;

void data_handler_init() {
    last_sum = 0;
}

int data_handler_process(const uint8_t* data, size_t len) {
    int sum = 0;
    for (size_t i = 0; i < len; ++i) {
        sum += data[i];
    }
    last_sum = sum;
    printf("Data sum: %d\n", sum);
    return sum;
}
