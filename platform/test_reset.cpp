#include "reset.h"
#include <assert.h>
#include <stdio.h>

void test_reset() {
    printf("Testing system reset...\n");
    system_reset();
    // Nếu chương trình tiếp tục chạy đến đây là lỗi
    assert(0 && "System did not reset as expected");
}

int main() {
    test_reset();
    return 0;
}
