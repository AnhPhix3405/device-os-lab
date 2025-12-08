#include "reset.h"
#include <stdio.h>
#include <stdlib.h>

void system_reset() {
    printf("System is resetting...\n");
    exit(0); // Giả lập reset bằng exit
}
