#ifndef TIMER_HAL_H
#define TIMER_HAL_H

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief Initializes the timer hardware.
 *
 * This function sets up the timer hardware with the specified configuration.
 *
 * @param timer_id The ID of the timer to initialize.
 * @param frequency The frequency at which the timer should operate (in Hz).
 * @return true if initialization was successful, false otherwise.
 */
bool timer_init(uint8_t timer_id, uint32_t frequency);

/**
 * @brief Starts the timer.
 *
 * This function starts the specified timer.
 *
 * @param timer_id The ID of the timer to start.
 */
void timer_start(uint8_t timer_id);

/**
 * @brief Stops the timer.
 *
 * This function stops the specified timer.
 *
 * @param timer_id The ID of the timer to stop.
 */
void timer_stop(uint8_t timer_id);

/**
 * @brief Resets the timer.
 *
 * This function resets the specified timer to its initial state.
 *
 * @param timer_id The ID of the timer to reset.
 */
void timer_reset(uint8_t timer_id);

/**
 * @brief Gets the current value of the timer.
 *
 * This function retrieves the current counter value of the specified timer.
 *
 * @param timer_id The ID of the timer to query.
 * @return The current counter value of the timer.
 */
uint32_t timer_get_value(uint8_t timer_id);

#endif // TIMER_HAL_H