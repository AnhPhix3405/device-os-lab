#include "hash.h"
#include <string.h>
#include <openssl/sha.h>
#include <openssl/md5.h>

bool hash_compute(HashAlgorithm algo, const uint8_t* input, size_t input_size, uint8_t* output, size_t* output_size) {
    if (algo == HASH_SHA256) {
        if (*output_size < SHA256_DIGEST_LENGTH) {
            return false; // Output buffer too small
        }
        SHA256(input, input_size, output);
        *output_size = SHA256_DIGEST_LENGTH;
        return true;
    } else if (algo == HASH_MD5) {
        if (*output_size < MD5_DIGEST_LENGTH) {
            return false; // Output buffer too small
        }
        MD5(input, input_size, output);
        *output_size = MD5_DIGEST_LENGTH;
        return true;
    }

    return false; // Unsupported algorithm
}

// ...existing code...