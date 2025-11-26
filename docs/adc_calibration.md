# ADC Calibration Guide

This guide explains the process of calibrating the Analog-to-Digital Converter (ADC) on your Particle device. Calibration ensures accurate analog readings by compensating for hardware variations.

## Why Calibrate?
- To ensure accurate analog readings.
- To compensate for hardware variations and environmental factors.
- To maintain long-term accuracy.

## When to Calibrate
- After manufacturing or hardware changes.
- When using a new device for the first time.
- Periodically, to maintain accuracy over time.

## How to Calibrate

### Using the Wiring API
The wiring API provides the `adcCalibrate()` function to perform ADC calibration. Follow these steps:

1. Ensure the ADC input pins are in a known state (e.g., connected to ground or a reference voltage).
2. Call the `adcCalibrate()` function in your setup code:

```cpp
#include "spark_wiring_adc.h"

void setup() {
    if (adcCalibrate()) {
        Serial.println("ADC Calibration Successful");
    } else {
        Serial.println("ADC Calibration Failed");
    }
}

void loop() {
    // Your code here
}
```

### Notes
- Calibration may take a few seconds to complete.
- Ensure stable power supply during calibration.
- Avoid external noise or interference during the process.

## Troubleshooting
- If calibration fails, ensure the ADC pins are properly connected to a known state.
- Check the power supply for stability.
- Retry the calibration process.

For further assistance, refer to the Particle documentation or contact support.