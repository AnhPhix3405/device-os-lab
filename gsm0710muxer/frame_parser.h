#ifndef FRAME_PARSER_H
#define FRAME_PARSER_H

#include <stdint.h>
#include <stddef.h>

/**
 * @brief Initializes the GSM muxer frame parser.
 *
 * This function prepares the frame parser for processing incoming GSM frames.
 */
void frame_parser_init(void);

/**
 * @brief Parses a GSM muxer frame.
 *
 * This function processes a raw GSM muxer frame and extracts its content.
 *
 * @param frame A pointer to the raw frame data.
 * @param length The length of the frame data in bytes.
 * @return true if the frame was successfully parsed, false otherwise.
 */
bool parse_gsm_frame(const uint8_t* frame, size_t length);

#endif // FRAME_PARSER_H