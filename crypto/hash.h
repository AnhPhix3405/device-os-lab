#ifndef CRYPTO_HASH_H
#define CRYPTO_HASH_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef enum {
    HASH_SHA256,
    HASH_MD5
} HashAlgorithm;

bool hash_compute(HashAlgorithm algo, const uint8_t* input, size_t input_size, uint8_t* output, size_t* output_size);

#endif // CRYPTO_HASH_H

// ...existing code...