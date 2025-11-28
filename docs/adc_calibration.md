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

### Advanced Example

```cpp
#include "spark_wiring_adc.h"

void setup() {
    Serial.begin(9600);
    
    // Wait for serial connection
    while(!Serial.available()) {
        Particle.process();
    }
    
    Serial.println("Starting ADC calibration...");
    
    // Perform calibration
    if (adcCalibrate()) {
        Serial.println("✓ ADC Calibration Successful");
        
        // Test reading
        int value = analogRead(A0);
        Serial.printlnf("Sample reading from A0: %d", value);
    } else {
        Serial.println("✗ ADC Calibration Failed");
    }
}

void loop() {
    // Your application code
}
```

### Calibration with Multiple Pins

```cpp
void calibrateMultiplePins() {
    const int pins[] = {A0, A1, A2, A3};
    
    for (int i = 0; i < 4; i++) {
        pinMode(pins[i], INPUT);
        int reading = analogRead(pins[i]);
        Serial.printlnf("Pin A%d: %d", i, reading);
    }
}
```

## Troubleshooting
- If calibration fails, ensure the ADC pins are properly connected to a known state.
- Check the power supply for stability.
- Retry the calibration process.

For further assistance, refer to the Particle documentation or contact support.