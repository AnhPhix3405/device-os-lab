#include "crypto.h"
#include <iostream>
#include <cstring>

int main() {
    uint8_t input[8] = {1,2,3,4,5,6,7,8};
    uint8_t key[4] = {0xAA, 0xBB, 0xCC, 0xDD};
    uint8_t encrypted[8] = {0};
    uint8_t decrypted[8] = {0};

    crypto_encrypt_buffer(input, encrypted, 8, key, 4);
    crypto_decrypt_buffer(encrypted, decrypted, 8, key, 4);

    std::cout << "Input: ";
    for (int i = 0; i < 8; ++i) std::cout << (int)input[i] << " ";
    std::cout << "\nEncrypted: ";
    for (int i = 0; i < 8; ++i) std::cout << (int)encrypted[i] << " ";
    std::cout << "\nDecrypted: ";
    for (int i = 0; i < 8; ++i) std::cout << (int)decrypted[i] << " ";
    std::cout << std::endl;
    return 0;
}
