#include "crypto.h"
#include <cassert>
#include <iostream>

void test_aes() {
    std::string plaintext = "Hello, AES!";
    std::string key = "mysecretkey12345";
    std::string encrypted = encrypt(plaintext, key);
    std::string decrypted = decrypt(encrypted, key);
    std::cout << "Plaintext:  " << plaintext << std::endl;
    std::cout << "Encrypted:  ";
    for (unsigned char c : encrypted) std::cout << std::hex << (int)(unsigned char)c << " ";
    std::cout << std::endl;
    std::cout << "Decrypted:  " << decrypted << std::endl;
    assert(plaintext == decrypted);
    std::cout << "AES test passed!" << std::endl;
}

int main() {
    test_aes();
    return 0;
}
