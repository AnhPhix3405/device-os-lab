/**
 * @file communication.cpp
 * @brief Implementation of communication module.
 *
 * This file contains the implementation of communication protocols.
 */

#include "communication.h"
#include <iostream>
#include <cstring>
#include <algorithm> // For std::min

const size_t MAX_BUFFER_SIZE = 1024;

/**
 * @brief Initializes the communication module.
 */
void communication_init() {
    // Initialize communication resources here
}

/**
 * @brief Sends data using the new communication protocol.
 *
 * @param data The data to send.
 * @param length The length of the data.
 * @return int Returns 0 on success, or an error code on failure.
 */
int communication_send(const char* data, size_t length) {
    if (data == nullptr || length == 0) {
        std::cerr << "Error: Invalid data or length." << std::endl;
        return -1;
    }

    if (length > MAX_BUFFER_SIZE) {
        std::cerr << "Warning: Data length exceeds maximum buffer size. Truncating data." << std::endl;
        length = std::min(length, MAX_BUFFER_SIZE);
    }

    // Simulate sending data
    char buffer[MAX_BUFFER_SIZE] = {0};
    std::memcpy(buffer, data, length);
    std::cout << "Sending data: " << std::string(buffer, length) << std::endl;

    return 0;
}
