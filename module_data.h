#ifndef MODULE_DATA_H
#define MODULE_DATA_H

#include <string>
#include <fstream>
#include "bootloader.h"

struct ModuleData {
    // Example fields
    int id;
    std::string name;
};

bool validate_firmware_version(const FirmwareVersion& version);
std::string get_firmware_version_string();
void print_firmware_version();
bool load_module_data(const std::string& filePath, ModuleData& data);

#endif // MODULE_DATA_H
