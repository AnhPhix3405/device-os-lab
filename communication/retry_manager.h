#ifndef RETRY_MANAGER_H
#define RETRY_MANAGER_H

#include <cstdint>
#include <functional>

/**
 * @brief Initializes the retry manager.
 *
 * This function sets up the retry manager for handling failed transmissions.
 */
void retry_manager_init(void);

/**
 * @brief Schedules a retry for a failed transmission.
 *
 * This function schedules a retry operation with a specified delay and maximum attempts.
 *
 * @param operation The operation to retry.
 * @param delay_ms The delay between retries in milliseconds.
 * @param max_attempts The maximum number of retry attempts.
 */
void schedule_retry(const std::function<bool()>& operation, uint32_t delay_ms, uint8_t max_attempts);

#endif // RETRY_MANAGER_H