# Code Examples for Common Use Cases

This document provides code examples for common use cases when working with Device OS.

## Table of Contents
1. [Logging Power Consumption](#1-logging-power-consumption)
2. [Setting Custom LED Blink Patterns](#2-setting-custom-led-blink-patterns)
3. [Handling Network State Transitions](#3-handling-network-state-transitions)
4. [Debugging Wi-Fi Signal Strength](#4-debugging-wi-fi-signal-strength)
5. [Timer-based Operations](#5-timer-based-operations)
6. [Error Handling Best Practices](#6-error-handling-best-practices)

## 1. Logging Power Consumption

```cpp
#include "spark_wiring_power.h"
#include "spark_wiring_logging.h"

void logPowerConsumption() {
    int batteryLevel = System.batteryCharge();
    if (batteryLevel != -1) {
        Log.info("Battery Level: %d%%", batteryLevel);
    } else {
        Log.warn("Battery level information is not available.");
    }
}
```

## 2. Setting Custom LED Blink Patterns

```cpp
#include "spark_wiring_led.h"

void setCustomLEDBlinkPattern(const char* pattern) {
    for (const char* p = pattern; *p != '\0'; ++p) {
        if (*p == '1') {
            // Turn LED on
        } else if (*p == '0') {
            // Turn LED off
        }
        // Add delay logic here
    }
}
```

## 3. Handling Network State Transitions

```cpp
#include "spark_wiring_network.h"
#include "spark_wiring_logging.h"

void handleNetworkStateTransition(network_state_t currentState, network_state_t newState) {
    Log.info("Transitioning network state from %d to %d", currentState, newState);
    switch (newState) {
        case NETWORK_STATE_CONNECTED:
            Log.info("Network is now connected.");
            break;
        case NETWORK_STATE_DISCONNECTED:
            Log.warn("Network is now disconnected.");
            break;
        default:
            Log.info("Unhandled network state: %d", newState);
            break;
    }
}
```

## 4. Debugging Wi-Fi Signal Strength

```cpp
#include "spark_wiring_wifi.h"
#include "spark_wiring_logging.h"

int getWiFiSignalStrength() {
    if (WiFi.ready()) {
        return WiFi.RSSI();
    }
    return -1; // Wi-Fi not ready
}
```

## 5. Timer-based Operations

```cpp
#include "application.h"

Timer periodicTimer(5000, periodicCallback);

void periodicCallback() {
    Log.info("Timer callback executed every 5 seconds");
    // Add your periodic task here
}

void setup() {
    periodicTimer.start();
}
```

## 6. Error Handling Best Practices

```cpp
#include "application.h"

int safeSensorRead(int pin) {
    if (pin < 0 || pin > 20) {
        Log.error("Invalid pin number: %d", pin);
        return -1;
    }
    
    int value = analogRead(pin);
    if (value < 0) {
        Log.warn("Failed to read from pin %d", pin);
        return -1;
    }
    
    return value;
}
```

For more examples, refer to the [API documentation](docs/api_reference.md).