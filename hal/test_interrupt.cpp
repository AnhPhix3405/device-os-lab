#include "interrupt.h"
#include <iostream>

void my_handler() {
    std::cout << "Interrupt handler called!" << std::endl;
}

int main() {
    hal_register_interrupt_handler(my_handler);
    hal_enable_interrupt();
    std::cout << "Interrupt flag: " << hal_interrupt_flag() << std::endl;
    hal_trigger_interrupt();
    std::cout << "Interrupt flag after trigger: " << hal_interrupt_flag() << std::endl;
    hal_clear_interrupt_flag();
    std::cout << "Interrupt flag after clear: " << hal_interrupt_flag() << std::endl;
    hal_disable_interrupt();
    return 0;
}
