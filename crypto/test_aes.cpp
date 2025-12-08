#include "aes.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

void test_aes() {
    uint8_t key[16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    uint8_t input[16] = "HelloAES1234567";
    uint8_t encrypted[16];
    uint8_t decrypted[16];
    aes_encrypt(input, encrypted, 16, key, 16);
    aes_decrypt(encrypted, decrypted, 16, key, 16);
    assert(memcmp(input, decrypted, 16) == 0);
    printf("AES test passed!\n");
}

int main() {
    test_aes();
    return 0;
}
