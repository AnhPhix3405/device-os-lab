#ifndef CRYPTO_DYNALIB_H
#define CRYPTO_DYNALIB_H

#include "crypto/aes.h"
#include "crypto/hash.h"

// Export AES-256 encryption and decryption functions
bool aes256_encrypt(const uint8_t* key, const uint8_t* plaintext, uint8_t* ciphertext, size_t length);
bool aes256_decrypt(const uint8_t* key, const uint8_t* ciphertext, uint8_t* plaintext, size_t length);

// Export unified hashing algorithm interface
bool hash_compute(HashAlgorithm algo, const uint8_t* input, size_t input_size, uint8_t* output, size_t* output_size);

#endif // CRYPTO_DYNALIB_H

// ...existing code...