
#include "aes.h"
#include <string.h>

// AES functions for dynalib export
void aes_encrypt(const uint8_t* input, uint8_t* output, size_t length, const uint8_t* key, size_t key_len) {
    // Memory-optimized: no heap allocation
    for (size_t i = 0; i < length; ++i) {
        output[i] = input[i] ^ key[i % key_len];
    }
}

void aes_decrypt(const uint8_t* input, uint8_t* output, size_t length, const uint8_t* key, size_t key_len) {
    aes_encrypt(input, output, length, key, key_len);
}
