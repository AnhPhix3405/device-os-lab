#include "frame_parser.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

static bool initialized = false;

void frame_parser_init(void) {
    initialized = true;
    printf("Frame parser initialized.\n");
}

bool parse_gsm_frame(const uint8_t* frame, size_t length) {
    if (!initialized) {
        printf("Error: Frame parser not initialized.\n");
        return false;
    }

    if (frame == NULL || length == 0) {
        printf("Error: Invalid frame data.\n");
        return false;
    }

    printf("Parsing GSM frame: ");
    for (size_t i = 0; i < length; ++i) {
        printf("%02X ", frame[i]);
    }
    printf("\n");

    // Example: Check for a specific frame header (0xF9)
    if (frame[0] != 0xF9) {
        printf("Error: Invalid frame header.\n");
        return false;
    }

    // Example: Extract payload (skipping header)
    printf("Frame payload: ");
    for (size_t i = 1; i < length; ++i) {
        printf("%02X ", frame[i]);
    }
    printf("\n");

    return true;
}