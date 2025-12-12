#include "crypto_dynalib.h"
#include "aes.h"
#include <string.h>
#include <stdlib.h>

// Exported dynalib encrypt function
const char* dynalib_encrypt(const char* plaintext, const char* key) {
    size_t len = strlen(plaintext);
    size_t key_len = strlen(key);
    char* output = (char*)malloc(len + 1);
    if (!output) return NULL;
    for (size_t i = 0; i < len; ++i) {
        output[i] = plaintext[i] ^ key[i % key_len];
    }
    output[len] = '\0';
    return output;
}

// Exported dynalib decrypt function
const char* dynalib_decrypt(const char* ciphertext, const char* key) {
    // XOR is symmetric
    return dynalib_encrypt(ciphertext, key);
}
