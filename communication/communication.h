/**
 * @file communication.h
 * @brief Communication module API definitions.
 *
 * This file contains the declarations of communication protocols.
 */

#pragma once

#include <cstddef>

/**
 * @brief Initializes the communication module.
 */
void communication_init();

/**
 * @brief Sends data using the new communication protocol.
 *
 * This function validates the input data and logs the operation.
 *
 * @param data The data to send (must not be null).
 * @param length The length of the data (must be greater than 0).
 * @return int Returns 0 on success, or -1 on failure.
 */
int communication_send(const char* data, size_t length);
