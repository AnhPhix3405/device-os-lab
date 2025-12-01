#ifndef SERVICES_USER_AUTH_H
#define SERVICES_USER_AUTH_H

#include <string>

namespace services {

bool authenticateUser(const std::string& username, const std::string& password);

} // namespace services

#endif // SERVICES_USER_AUTH_H