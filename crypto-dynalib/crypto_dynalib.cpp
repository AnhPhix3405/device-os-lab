/**
 * @file crypto_dynalib.cpp
 * @brief Dynamic library support for cryptographic algorithms.
 *
 * This file contains the implementation of dynamic library support for cryptographic algorithms.
 */

#include "crypto_dynalib.h"
#include "crypto.h"

/**
 * @brief Example dynamic library function for encryption.
 *
 * @param plaintext The input text to encrypt.
 * @param key The encryption key.
 * @return std::string The encrypted text.
 */
std::string dynalib_encrypt(const std::string& plaintext, const std::string& key) {
    return encrypt(plaintext, key);
}

/**
 * @brief Example dynamic library function for decryption.
 *
 * @param ciphertext The input text to decrypt.
 * @param key The decryption key.
 * @return std::string The decrypted text.
 */
std::string dynalib_decrypt(const std::string& ciphertext, const std::string& key) {
    return decrypt(ciphertext, key);
}
