#include "crypto.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

// Simple AES-like block cipher placeholder for demonstration (not secure, just for structure)
namespace {
    constexpr size_t BLOCK_SIZE = 16;

    void xor_block(std::vector<uint8_t>& block, const std::vector<uint8_t>& key) {
        for (size_t i = 0; i < block.size(); ++i) {
            block[i] ^= key[i % key.size()];
        }
    }
}

std::string encrypt(const std::string& plaintext, const std::string& key) {
    std::vector<uint8_t> data(plaintext.begin(), plaintext.end());
    std::vector<uint8_t> k(key.begin(), key.end());
    std::string encrypted;
    for (size_t i = 0; i < data.size(); i += BLOCK_SIZE) {
        std::vector<uint8_t> block(data.begin() + i, data.begin() + std::min(i + BLOCK_SIZE, data.size()));
        block.resize(BLOCK_SIZE, 0); // pad block
        xor_block(block, k);
        for (auto b : block) {
            encrypted += static_cast<char>(b);
        }
    }
    return encrypted;
}

std::string decrypt(const std::string& ciphertext, const std::string& key) {
    std::vector<uint8_t> data(ciphertext.begin(), ciphertext.end());
    std::vector<uint8_t> k(key.begin(), key.end());
    std::string decrypted;
    for (size_t i = 0; i < data.size(); i += BLOCK_SIZE) {
        std::vector<uint8_t> block(data.begin() + i, data.begin() + std::min(i + BLOCK_SIZE, data.size()));
        xor_block(block, k);
        for (auto b : block) {
            decrypted += static_cast<char>(b);
        }
    }
    return decrypted;
}
