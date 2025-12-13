#include "buffer_manager.h"
#include <vector>
#include <iostream>
#include <cstring>

static std::vector<uint8_t*> buffer_pool;
static size_t buffer_size = 0;

bool buffer_manager_init(size_t size, size_t count) {
    if (size == 0 || count == 0) {
        std::cerr << "Error: Invalid buffer size or count." << std::endl;
        return false;
    }

    buffer_size = size;
    buffer_pool.reserve(count);

    for (size_t i = 0; i < count; ++i) {
        uint8_t* buffer = new (std::nothrow) uint8_t[size];
        if (!buffer) {
            std::cerr << "Error: Failed to allocate buffer." << std::endl;
            return false;
        }
        buffer_pool.push_back(buffer);
    }

    std::cout << "Buffer manager initialized with " << count << " buffers of size " << size << " bytes." << std::endl;
    return true;
}

uint8_t* buffer_manager_allocate(void) {
    if (buffer_pool.empty()) {
        std::cerr << "Error: No available buffers." << std::endl;
        return nullptr;
    }

    uint8_t* buffer = buffer_pool.back();
    buffer_pool.pop_back();
    std::memset(buffer, 0, buffer_size);
    return buffer;
}

void buffer_manager_free(uint8_t* buffer) {
    if (!buffer) {
        std::cerr << "Error: Attempt to free a null buffer." << std::endl;
        return;
    }

    buffer_pool.push_back(buffer);
}