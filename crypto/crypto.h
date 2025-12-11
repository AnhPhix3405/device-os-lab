/**
 * @file crypto.h
 * @brief Cryptographic algorithm definitions.
 *
 * This file contains the declarations of cryptographic algorithms for Device OS.
 */

#pragma once

#include <string>
#include <mutex>

#include <stdint.h>
#include <stddef.h>

/**
 * @brief Encrypts the given plaintext using the specified key.
 *
 * This function logs the plaintext, key, and encrypted result for debugging purposes.
 *
 * @param plaintext The input text to encrypt.
 * @param key The encryption key.
 * @return std::string The encrypted text.
 */
std::string encrypt(const std::string& plaintext, const std::string& key);

// Encrypt buffer (memory optimized)
void crypto_encrypt_buffer(const uint8_t* input, uint8_t* output, size_t length, const uint8_t* key, size_t key_len);
// Decrypt buffer (memory optimized)
void crypto_decrypt_buffer(const uint8_t* input, uint8_t* output, size_t length, const uint8_t* key, size_t key_len);

/**
 * @brief Decrypts the given ciphertext using the specified key.
 *
 * This function logs the ciphertext, key, and decrypted result for debugging purposes.
 *
 * @param ciphertext The input text to decrypt.
 * @param key The decryption key.
 * @return std::string The decrypted text.
 */
std::string decrypt(const std::string& ciphertext, const std::string& key);
