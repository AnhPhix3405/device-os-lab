#include "reset.h"
#include <cassert>
#include <stdio.h>

void test_system_reset() {
    printf("Testing system reset...\n");
    // Gọi hàm reset (sẽ kết thúc chương trình)
    system_reset();
    // Nếu chương trình tiếp tục chạy đến đây là lỗi
    assert(false && "System did not reset as expected");
}

int main() {
    test_system_reset();
    return 0;
}
