#ifndef SERVICES_DATA_HANDLER_H
#define SERVICES_DATA_HANDLER_H
#include <stddef.h>
#include <stdint.h>

void data_handler_init();
int data_handler_process(const uint8_t* data, size_t len);

#endif // SERVICES_DATA_HANDLER_H
