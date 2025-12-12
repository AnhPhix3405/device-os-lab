#include "platform/platform.h"
#include "services/logger.h"

void platform_init(void) {
    log_info("Platform initialized.");
}

void platform_error(const char* msg) {
    log_error(std::string("Platform error: ") + msg);
}
