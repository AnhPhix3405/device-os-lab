#ifndef HAL_INTERRUPT_H
#define HAL_INTERRUPT_H
#include <stdint.h>

// Đăng ký hàm xử lý ngắt
void hal_register_interrupt_handler(void (*handler)(void));
// Kích hoạt ngắt
void hal_enable_interrupt();
// Vô hiệu hóa ngắt
void hal_disable_interrupt();

#endif // HAL_INTERRUPT_H
