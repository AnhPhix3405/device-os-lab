#ifndef COMMUNICATION_CRC_H
#define COMMUNICATION_CRC_H
#include <stddef.h>
#include <stdint.h>

// Tính CRC-16 cho buffer
uint16_t crc16(const uint8_t* data, size_t length);
// Kiểm tra CRC-16
int crc16_check(const uint8_t* data, size_t length, uint16_t expected_crc);

#endif // COMMUNICATION_CRC_H
