#ifndef BUFFER_MANAGER_H
#define BUFFER_MANAGER_H

#include <cstddef>
#include <cstdint>

/**
 * @brief Initializes the communication buffer manager.
 *
 * This function sets up the buffer manager for handling communication buffers.
 *
 * @param buffer_size The size of each buffer in bytes.
 * @param buffer_count The total number of buffers to manage.
 * @return true if initialization was successful, false otherwise.
 */
bool buffer_manager_init(size_t buffer_size, size_t buffer_count);

/**
 * @brief Allocates a buffer for communication.
 *
 * This function provides a buffer from the pool for communication purposes.
 *
 * @return A pointer to the allocated buffer, or nullptr if no buffers are available.
 */
uint8_t* buffer_manager_allocate(void);

/**
 * @brief Frees a previously allocated buffer.
 *
 * This function returns a buffer to the pool, making it available for reuse.
 *
 * @param buffer A pointer to the buffer to free.
 */
void buffer_manager_free(uint8_t* buffer);

#endif // BUFFER_MANAGER_H