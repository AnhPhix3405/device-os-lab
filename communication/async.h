#ifndef COMMUNICATION_ASYNC_H
#define COMMUNICATION_ASYNC_H

#include <cstdint>
#include <chrono>

struct AsyncComm {
    uint32_t timeout_ms;
    std::chrono::steady_clock::time_point last_activity_time;
};

bool async_init(AsyncComm& comm, uint32_t timeout_ms);
bool async_check_timeout(const AsyncComm& comm);
void async_simulate_activity(AsyncComm& comm);

#endif // COMMUNICATION_ASYNC_H

// ...existing code...