/**
 * @file crypto.cpp
 * @brief Implementation of cryptographic algorithms.
 *
 * This file contains the implementation of cryptographic algorithms for Device OS.
 */

#include "crypto.h"
#include <iostream>
#include <string>
#include <mutex>

std::mutex crypto_mutex;

extern "C" {
#include "aes.c"
}

/**
 * @brief AES encryption function.
 *
 * @param plaintext The input text to encrypt.
 * @param key The encryption key.
 * @return std::string The encrypted text.
 */
std::string encrypt(const std::string& plaintext, const std::string& key) {
    std::lock_guard<std::mutex> lock(crypto_mutex);
    // Using optimized AES from aes.c
    return ::encrypt(plaintext, key);
}

/**
 * @brief AES decryption function.
 *
 * @param ciphertext The input text to decrypt.
 * @param key The decryption key.
 * @return std::string The decrypted text.
 */
std::string decrypt(const std::string& ciphertext, const std::string& key) {
    std::lock_guard<std::mutex> lock(crypto_mutex);
    // Using optimized AES from aes.c
    return ::decrypt(ciphertext, key);
}


