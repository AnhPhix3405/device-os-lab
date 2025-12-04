/**
 * @file crypto_dynalib.h
 * @brief Dynamic library API definitions for cryptographic algorithms.
 *
 * This file contains the declarations of dynamic library support for cryptographic algorithms.
 */

#pragma once

#include <string>

/**
 * @brief Encrypts the given plaintext using the specified key (dynamic library).
 *
 * @param plaintext The input text to encrypt.
 * @param key The encryption key.
 * @return std::string The encrypted text.
 */
std::string dynalib_encrypt(const std::string& plaintext, const std::string& key);

/**
 * @brief Decrypts the given ciphertext using the specified key (dynamic library).
 *
 * @param ciphertext The input text to decrypt.
 * @param key The decryption key.
 * @return std::string The decrypted text.
 */
std::string dynalib_decrypt(const std::string& ciphertext, const std::string& key);
