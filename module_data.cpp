#include "module_data.h"
#include "bootloader.h"
#include <string>
#include <iostream>

std::string get_firmware_version_string() {
    FirmwareVersion v = bootloader_get_version();
    return "v" + std::to_string(v.major) + "." + std::to_string(v.minor) + "." + std::to_string(v.patch);
}

void print_firmware_version() {
    std::cout << "Firmware Version: " << get_firmware_version_string() << std::endl;
}
