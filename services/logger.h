#ifndef SERVICES_LOGGER_H
#define SERVICES_LOGGER_H
#include <string>

void log_debug(const std::string& msg);
void log_info(const std::string& msg);
void log_error(const std::string& msg);

#endif // SERVICES_LOGGER_H
