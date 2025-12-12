#include "at_command_parser.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_COMMAND_LENGTH 128

static char command_buffer[MAX_COMMAND_LENGTH];
static size_t buffer_index = 0;

void at_parser_init() {
    memset(command_buffer, 0, sizeof(command_buffer));
    buffer_index = 0;
    printf("AT command parser initialized.\n");
}

bool at_parser_process_char(char c) {
    if (c == '\n' || c == '\r') {
        if (buffer_index > 0) {
            command_buffer[buffer_index] = '\0';
            printf("Processing AT command: %s\n", command_buffer);
            buffer_index = 0;
            return true;
        }
    } else if (buffer_index < MAX_COMMAND_LENGTH - 1) {
        command_buffer[buffer_index++] = c;
    } else {
        printf("AT command buffer overflow.\n");
        buffer_index = 0;
    }
    return false;
}