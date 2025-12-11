#ifndef MODULE_DATA_H
#define MODULE_DATA_H

#include <string>
#include <fstream>
#include "bootloader.h"

/**
 * @brief Structure to hold module data.
 *
 * This structure contains fields for storing module-specific data such
 * as the module ID and name.
 */
struct ModuleData {
    int id; ///< The unique identifier for the module.
    std::string name; ///< The name of the module.
};

/**
 * @brief Validates the firmware version.
 *
 * @param version The firmware version to validate.
 * @return true if the version is valid, false otherwise.
 */
bool validate_firmware_version(const FirmwareVersion& version);

/**
 * @brief Retrieves the firmware version as a string.
 *
 * @return A string representation of the firmware version.
 */
std::string get_firmware_version_string();

/**
 * @brief Prints the firmware version to the console.
 */
void print_firmware_version();

/**
 * @brief Loads module data from a file.
 *
 * @param filePath The path to the module data file.
 * @param data The ModuleData structure to populate.
 * @return true if the data was loaded successfully, false otherwise.
 */
bool load_module_data(const std::string& filePath, ModuleData& data);

#endif // MODULE_DATA_H
