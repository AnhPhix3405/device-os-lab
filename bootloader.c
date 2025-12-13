#include "bootloader.h"
#include "system.h"
#include "crypto.h"
#include "logging.h"
#include <stdio.h>
#include <stdalign.h>
#include <stdlib.h>
#include <string.h>

static alignas(4) FirmwareVersion current_fw_version = {1, 0, 0};
static int bootloader_initialized = 0;

static void* memory_pool = NULL;
static size_t memory_pool_size = 0;
static size_t memory_pool_used = 0;

const char* bootloader_error_string(int error_code) {
    switch (error_code) {
        case BOOTLOADER_OK:
            return "Success";
        case BOOTLOADER_ERROR_SYSTEM_INIT:
            return "System initialization failed";
        case BOOTLOADER_ERROR_SECURE_BOOT:
            return "Secure boot verification failed";
        case BOOTLOADER_ERROR_VERSION_INVALID:
            return "Invalid firmware version";
        case BOOTLOADER_ERROR_NULL_POINTER:
            return "Null pointer detected";
        case BOOTLOADER_ERROR_MEMORY:
            return "Memory allocation failed";
        default:
            return "Unknown error";
    }
}

int bootloader_set_version(int major, int minor, int patch) {
    if (major < 0 || minor < 0 || patch < 0) {
        log_error("Invalid version parameters: negative values not allowed");
        return BOOTLOADER_ERROR_VERSION_INVALID;
    }
    
    if (major > 255 || minor > 255 || patch > 255) {
        log_error("Invalid version parameters: values exceed maximum");
        return BOOTLOADER_ERROR_VERSION_INVALID;
    }
    
    current_fw_version.major = major;
    current_fw_version.minor = minor;
    current_fw_version.patch = patch;
    
    log_info("Firmware version set successfully");
    return BOOTLOADER_OK;
}

FirmwareVersion bootloader_get_version(void) {
    return current_fw_version;
}

int bootloader_print_version(void) {
    char version_str[64];
    int result = snprintf(version_str, sizeof(version_str), 
                         "Firmware Version: v%d.%d.%d",
                         current_fw_version.major, 
                         current_fw_version.minor, 
                         current_fw_version.patch);
    
    if (result < 0 || result >= sizeof(version_str)) {
        log_error("Failed to format version string");
        return BOOTLOADER_ERROR_MEMORY;
    }
    
    printf("%s\n", version_str);
    log_info(version_str);
    return BOOTLOADER_OK;
}

static int bootloader_fast_init(void) {
    log_info("Starting fast initialization");
    
    int result = bootloader_set_version(1, 0, 0);
    if (result != BOOTLOADER_OK) {
        log_error("Fast init failed: version set error");
        return result;
    }
    
    log_info("Fast initialization completed");
    return BOOTLOADER_OK;
}

int bootloader_secure_boot(void) {
    const char* boot_key = "secure_boot_key";
    const char* boot_signature = "boot_signature";
    
    log_info("Starting secure boot verification");
    
    if (boot_key == NULL || boot_signature == NULL) {
        log_error("Secure boot failed: NULL pointer in boot credentials");
        return BOOTLOADER_ERROR_NULL_POINTER;
    }

    if (!crypto_verify_signature(boot_key, boot_signature)) {
        log_error("Secure boot failed: Invalid signature");
        return BOOTLOADER_ERROR_SECURE_BOOT;
    }

    log_info("Secure boot verification passed");
    return BOOTLOADER_OK;
}

int bootloader_init(void) {
    int result;
    
    log_info("Bootloader initialization started");
    
    if (bootloader_initialized) {
        log_warn("Bootloader already initialized");
        return BOOTLOADER_OK;
    }
    
    // System initialization
    result = system_init();
    if (result != 0) {
        log_error("System initialization failed with error code");
        return BOOTLOADER_ERROR_SYSTEM_INIT;
    }
    log_info("System initialization successful");
    
    // Secure boot verification
    result = bootloader_secure_boot();
    if (result != BOOTLOADER_OK) {
        log_error(bootloader_error_string(result));
        return result;
    }
    
    // Fast initialization
    result = bootloader_fast_init();
    if (result != BOOTLOADER_OK) {
        log_error("Fast initialization failed");
        return result;
    }
    
    // Print version
    result = bootloader_print_version();
    if (result != BOOTLOADER_OK) {
        log_warn("Version print failed, continuing...");
    }
    
    bootloader_initialized = 1;
    log_info("Bootloader initialization completed successfully");
    
    return BOOTLOADER_OK;
}

int bootloader_memory_pool_init(size_t pool_size) {
    if (memory_pool != NULL) {
        log_warn("Memory pool already initialized.");
        return BOOTLOADER_OK;
    }

    memory_pool = malloc(pool_size);
    if (memory_pool == NULL) {
        log_error("Failed to allocate memory pool.");
        return BOOTLOADER_ERROR_MEMORY;
    }

    memory_pool_size = pool_size;
    memory_pool_used = 0;
    log_info("Memory pool initialized successfully.");
    return BOOTLOADER_OK;
}

void* bootloader_memory_alloc(size_t size) {
    if (memory_pool == NULL) {
        log_error("Memory pool not initialized.");
        return NULL;
    }

    if (memory_pool_used + size > memory_pool_size) {
        log_error("Memory pool exhausted.");
        return NULL;
    }

    void* ptr = (char*)memory_pool + memory_pool_used;
    memory_pool_used += size;
    log_info("Memory allocated from pool.");
    return ptr;
}

void bootloader_memory_free(void* ptr) {
    // Simplified memory pool does not support freeing individual blocks.
    log_warn("Memory pool does not support freeing individual blocks.");
}
