#include "data_handler.h"
#include <assert.h>
#include <stdio.h>

void test_data_handler() {
    data_handler_init();
    uint8_t data1[] = {1,2,3,4};
    int sum1 = data_handler_process(data1, sizeof(data1));
    assert(sum1 == 10);
    uint8_t data2[] = {10,20,30};
    int sum2 = data_handler_process(data2, sizeof(data2));
    assert(sum2 == 60);
    printf("Data handler unit test passed!\n");
}

int main() {
    test_data_handler();
    return 0;
}
