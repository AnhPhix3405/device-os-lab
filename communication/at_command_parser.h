#ifndef AT_COMMAND_PARSER_H
#define AT_COMMAND_PARSER_H

#include <stdbool.h>

/**
 * @brief Initializes the AT command parser.
 */
void at_parser_init();

/**
 * @brief Processes a single character for AT command parsing.
 *
 * @param c The character to process.
 * @return true if a complete command was parsed, false otherwise.
 */
bool at_parser_process_char(char c);

#endif // AT_COMMAND_PARSER_H