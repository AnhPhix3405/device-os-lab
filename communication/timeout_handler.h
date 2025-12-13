#ifndef TIMEOUT_HANDLER_H
#define TIMEOUT_HANDLER_H

#include <cstdint>
#include <functional>

/**
 * @brief Initializes the timeout handler.
 *
 * This function sets up the timeout handler for managing communication timeouts.
 */
void timeout_handler_init(void);

/**
 * @brief Sets a timeout for a communication operation.
 *
 * This function schedules a timeout callback to be executed after the specified duration.
 *
 * @param duration_ms The timeout duration in milliseconds.
 * @param callback The callback function to execute on timeout.
 */
void set_timeout(uint32_t duration_ms, const std::function<void()>& callback);

/**
 * @brief Cancels a previously set timeout.
 *
 * This function cancels any pending timeout callbacks.
 */
void cancel_timeout(void);

#endif // TIMEOUT_HANDLER_H