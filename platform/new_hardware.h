#ifndef NEW_HARDWARE_H
#define NEW_HARDWARE_H

#include "hal/hal.h"
#include "system/system.h"

class NewHardware {
public:
    static void initialize();
    static void reset();
};

#endif // NEW_HARDWARE_H