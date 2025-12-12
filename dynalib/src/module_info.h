#ifndef MODULE_INFO_H
#define MODULE_INFO_H
#include <stdint.h>

typedef struct {
    uint32_t platform_id;
    uint32_t version;
    uint32_t module_type;
    uint32_t dependencies;
    // Thêm trường mới
    uint32_t build_timestamp;
    uint8_t flags;
} module_info_t;

#endif // MODULE_INFO_H
