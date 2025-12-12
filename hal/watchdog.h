#ifndef WATCHDOG_H
#define WATCHDOG_H

/**
 * @brief Starts the watchdog timer.
 *
 * @param timeout_ms Timeout in milliseconds before the watchdog triggers a reset.
 */
void watchdog_start(int timeout_ms);

/**
 * @brief Resets the watchdog timer to prevent a reset.
 */
void watchdog_kick();

/**
 * @brief Stops the watchdog timer.
 */
void watchdog_stop();

#endif // WATCHDOG_H