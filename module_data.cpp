#include "module_data.h"
#include "bootloader.h"
#include <string>
#include <iostream>
#include <fstream>

bool validate_firmware_version(const FirmwareVersion& version) {
    return version.major >= 0 && version.minor >= 0 && version.patch >= 0;
}

std::string get_firmware_version_string() {
    FirmwareVersion v = bootloader_get_version();
    if (!validate_firmware_version(v)) {
        return "Invalid Version";
    }
    return "v" + std::to_string(v.major) + "." + std::to_string(v.minor) + "." + std::to_string(v.patch);
}

void print_firmware_version() {
    std::cout << "Firmware Version: " << get_firmware_version_string() << std::endl;
}

bool load_module_data(const std::string& filePath, ModuleData& data) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open module data file: " << filePath << std::endl;
        return false;
    }

    try {
        // Example parsing logic
        file >> data;
    } catch (const std::exception& e) {
        std::cerr << "Error: Failed to parse module data. Exception: " << e.what() << std::endl;
        return false;
    }

    file.close();
    return true;
}

bool system_health_check() {
    // Example health check logic
    std::cout << "Performing system health check..." << std::endl;
    return true; // Assume the system is healthy
}
