/**
 * @file crypto_dynalib.h
 * @brief Dynamic library API definitions for cryptographic algorithms.
 *
 * This file contains the declarations of dynamic library support for cryptographic algorithms.
 */

#ifndef CRYPTO_DYNALIB_H
#define CRYPTO_DYNALIB_H

#ifdef __cplusplus
extern "C" {
#endif

// Exported dynalib crypto functions
const char* dynalib_encrypt(const char* plaintext, const char* key);
const char* dynalib_decrypt(const char* ciphertext, const char* key);

#ifdef __cplusplus
}
#endif

#endif // CRYPTO_DYNALIB_H
