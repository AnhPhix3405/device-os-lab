#ifndef BOOTLOADER_H
#define BOOTLOADER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdalign.h>

typedef enum {
    BOOTLOADER_OK = 0,
    BOOTLOADER_ERROR_SYSTEM_INIT = -1,
    BOOTLOADER_ERROR_SECURE_BOOT = -2,
    BOOTLOADER_ERROR_VERSION_INVALID = -3,
    BOOTLOADER_ERROR_NULL_POINTER = -4,
    BOOTLOADER_ERROR_MEMORY = -5
} BootloaderError;

typedef struct {
    alignas(4) int major;
    alignas(4) int minor;
    alignas(4) int patch;
} FirmwareVersion;

int bootloader_set_version(int major, int minor, int patch);
FirmwareVersion bootloader_get_version(void);
int bootloader_print_version(void);
int bootloader_init(void);
int bootloader_secure_boot(void);
const char* bootloader_error_string(int error_code);

/**
 * @brief Initializes the memory pool allocator.
 *
 * This function sets up a memory pool for the bootloader to use for
 * dynamic memory allocation, ensuring efficient and predictable memory usage.
 *
 * @param pool_size The size of the memory pool in bytes.
 * @return BOOTLOADER_OK if successful, or an error code otherwise.
 */
int bootloader_memory_pool_init(size_t pool_size);

/**
 * @brief Allocates memory from the bootloader's memory pool.
 *
 * This function provides a simple memory allocation mechanism using the
 * pre-allocated memory pool.
 *
 * @param size The size of the memory block to allocate in bytes.
 * @return A pointer to the allocated memory, or NULL if allocation failed.
 */
void* bootloader_memory_alloc(size_t size);

/**
 * @brief Frees memory allocated from the bootloader's memory pool.
 *
 * This function returns memory to the pool, making it available for future
 * allocations.
 *
 * @param ptr A pointer to the memory block to free.
 */
void bootloader_memory_free(void* ptr);

#ifdef __cplusplus
}
#endif

#endif // BOOTLOADER_H
