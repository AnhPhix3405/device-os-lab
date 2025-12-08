#ifndef GSM0710MUXER_MUXER_H
#define GSM0710MUXER_MUXER_H
#include <stddef.h>
#include <stdint.h>

void muxer_init();
void muxer_process(const uint8_t* data, size_t len);

#endif // GSM0710MUXER_MUXER_H
