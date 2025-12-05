/**
 * @file hal.h
 * @brief HAL API definitions.
 *
 * This file contains the declarations of hardware abstraction layer (HAL) functions.
 */

#pragma once

/**
 * @brief Initializes the hardware abstraction layer.
 *
 * This function initializes hardware resources and logs any errors encountered during initialization.
 */
void hal_init();

/**
 * @brief Performs a hardware operation.
 *
 * This function performs a hardware operation and logs any errors encountered during execution.
 *
 * @return int Returns 0 on success, or -1 on failure.
 */
int hal_perform_operation();
