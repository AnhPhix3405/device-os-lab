#ifndef CRYPTO_AES_H
#define CRYPTO_AES_H
#include <stddef.h>
#include <stdint.h>

// Memory-optimized AES (no heap allocation)
void aes_encrypt(const uint8_t* input, uint8_t* output, size_t length, const uint8_t* key, size_t key_len);
void aes_decrypt(const uint8_t* input, uint8_t* output, size_t length, const uint8_t* key, size_t key_len);

#endif // CRYPTO_AES_H
