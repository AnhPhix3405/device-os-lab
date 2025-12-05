/**
 * @file communication_dynalib.cpp
 * @brief Dynamic library support for communication module.
 *
 * This file contains the implementation of dynamic library support for communication protocols.
 */

#include "communication_dynalib.h"
#include "communication.h"
#include <iostream>

/**
 * @brief Initializes the communication module (dynamic library).
 */
void communication_dynalib_init() {
    communication_init();
}

/**
 * @brief Sends data using the new communication protocol (dynamic library).
 *
 * This function wraps the communication_send function and adds additional logging.
 *
 * @param data The data to send.
 * @param length The length of the data.
 * @return int Returns 0 on success, or an error code on failure.
 */
int communication_dynalib_send(const char* data, size_t length) {
    std::cout << "[Dynalib] Sending data..." << std::endl;
    return communication_send(data, length);
}
