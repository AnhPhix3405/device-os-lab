#include "crypto.h"
#include "aes.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

// Encrypt with minimal heap usage
void crypto_encrypt_buffer(const uint8_t* input, uint8_t* output, size_t length, const uint8_t* key, size_t key_len) {
    aes_encrypt(input, output, length, key, key_len);
}

// Decrypt with minimal heap usage
void crypto_decrypt_buffer(const uint8_t* input, uint8_t* output, size_t length, const uint8_t* key, size_t key_len) {
    aes_decrypt(input, output, length, key, key_len);
}
