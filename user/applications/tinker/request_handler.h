#pragma once

#include "system_control.h"
#include "spark_wiring_wifi.h"

namespace particle {

// Handler for fqc requests
class RequestHandler {
public:
    RequestHandler();
    ~RequestHandler();

    int init();
    void destroy();

    void process(ctrl_request* ctrlReq);

    static RequestHandler* instance();

private:
    class Request;

    bool inited_;

    int request(ctrl_request* ctrlReq);
    int request(Request* req);
};

int getWiFiSignalStrength();
int getBatteryLevel();

} // namespace particle
