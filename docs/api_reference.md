# API Reference

## Overview

This document provides a quick reference for the most commonly used APIs in Device OS.

## Table of Contents

- [Digital I/O](#digital-io)
- [Analog I/O](#analog-io)
- [Serial Communication](#serial-communication)
- [WiFi](#wifi)
- [Cloud Functions](#cloud-functions)
- [Time](#time)
- [System](#system)
- [Logging API Examples](#logging-api-examples)

## Digital I/O

### pinMode()

```cpp
pinMode(pin, mode);
```

Configure pin as INPUT, OUTPUT, or INPUT_PULLUP/INPUT_PULLDOWN.

### digitalWrite()

```cpp
digitalWrite(pin, value);
```

Write HIGH or LOW to a digital pin.

### digitalRead()

```cpp
int value = digitalRead(pin);
```

Read the value from a digital pin.

## Analog I/O

### analogRead()

```cpp
int value = analogRead(pin);
```

Reads analog value (0-4095) from specified pin.

### analogWrite()

```cpp
analogWrite(pin, value);
```

Write PWM value (0-255) to pin.

## Serial Communication

### Serial.begin()

```cpp
Serial.begin(9600);
```

Initialize serial communication at specified baud rate.

### Serial.print() / println()

```cpp
Serial.println("Hello World");
```

Print data to serial port.

## WiFi

### WiFi.on()

```cpp
WiFi.on();
```

Turn on WiFi module.

### WiFi.connect()

```cpp
WiFi.connect();
```

Connect to WiFi network.

### WiFi.ready()

```cpp
if (WiFi.ready()) {
    // Connected
}
```

## Cloud Functions

### Particle.function()

```cpp
Particle.function("functionName", handlerFunction);
```

Register a cloud-callable function.

### Particle.variable()

```cpp
Particle.variable("varName", &variable);
```

Expose a variable to the cloud.

### Particle.publish()

```cpp
Particle.publish("eventName", "data");
```

Publish an event to the cloud.

## Time

### Time.now()

```cpp
time_t timestamp = Time.now();
```

Get current Unix timestamp.

### Time.format()

```cpp
String timeStr = Time.format(Time.now(), TIME_FORMAT_ISO8601_FULL);
```

## System

### System.freeMemory()

```cpp
int free = System.freeMemory();
```

Get available heap memory in bytes.

### System.version()

```cpp
String version = System.version();
```

Get Device OS version.

### System.reset()

```cpp
System.reset();
```

Reset the device.

## Logging API Examples

### Example 1: Basic Logging

```cpp
#include "logging.h"

void setup() {
    Log.info("System initialized");
}

void loop() {
    Log.debug("Loop iteration");
    delay(1000);
}
```

### Example 2: Conditional Logging

```cpp
#include "logging.h"

void setup() {
    Log.info("Starting conditional logging example");
}

void loop() {
    if (millis() % 5000 == 0) {
        Log.warn("5 seconds elapsed");
    }
}
```

## Best Practices

1. Always check return values for error conditions
2. Use appropriate data types to avoid overflow
3. Implement proper error handling
4. Follow power management guidelines
5. Use const correctness where applicable

## See Also

- [Code Examples](code_examples.md)
- [Troubleshooting Guide](troubleshooting.md)
- [Official Firmware Reference](https://docs.particle.io/reference/)
