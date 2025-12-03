#include "system_cloud.h"
#include "unit_test.h"

test(Cloud_Reconnection_Success) {
    cloud_reconnection_init();
    bool result = cloud_reconnect_with_retry();
    assertTrue(result);
}

test(Cloud_Reconnection_Failure) {
    // Simulate failure by overriding hal_network_connect
    extern int hal_network_connect();
    hal_network_connect = []() { return -1; }; // Force failure

    cloud_reconnection_init();
    bool result = cloud_reconnect_with_retry();
    assertFalse(result);
}

test(Cloud_Reconnection_NoNetwork) {
    // Simulate no network available
    cloud_reconnection_init();
    bool result = cloud_reconnect_with_retry();
    assertFalse(result);
}

test(Cloud_Reconnection_Timeout) {
    // Simulate timeout during reconnection
    cloud_reconnection_init();
    set_reconnection_timeout(5000); // Set a short timeout
    bool result = cloud_reconnect_with_retry();
    assertFalse(result);
}