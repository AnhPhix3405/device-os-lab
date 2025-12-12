#include "communication.h"
#include "message_queue.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_RETRY_COUNT 3

void communication_init() {
    message_queue_init();
    printf("Communication module initialized.\n");
}

int communication_send(const char* data, size_t length) {
    if (data == NULL || length == 0) {
        printf("Invalid data to send.\n");
        return -1;
    }

    int retry_count = 0;
    bool success = false;

    while (retry_count < MAX_RETRY_COUNT) {
        printf("Attempt %d to send data: %s\n", retry_count + 1, data);
        // Simulate sending logic
        success = true; // Assume success for now

        if (success) {
            printf("Data sent successfully: %s\n", data);
            return 0;
        }

        retry_count++;
        printf("Retrying to send data...\n");
    }

    printf("Failed to send data after %d attempts.\n", MAX_RETRY_COUNT);
    return -1;
}

bool communication_queue_push(const char* message) {
    return message_queue_push(message);
}

bool communication_queue_pop(char* buffer) {
    return message_queue_pop(buffer);
}