/**
 * @file network_manager.h
 * @brief Network connection manager interface.
 *
 * This file contains the declarations for the network connection manager.
 */

#pragma once

#include <stdbool.h>

/**
 * @brief Initializes the network connection manager.
 */
void network_manager_init();

/**
 * @brief Connects to a network.
 *
 * @param ssid The SSID of the network.
 * @param password The password of the network.
 * @return true if the connection was successful, false otherwise.
 */
bool network_manager_connect(const char* ssid, const char* password);

/**
 * @brief Disconnects from the current network.
 */
void network_manager_disconnect();

/**
 * @brief Checks the connection status.
 *
 * @return true if connected, false otherwise.
 */
bool network_manager_is_connected();