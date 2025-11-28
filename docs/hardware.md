# Hardware Support

## Supported Platforms

### WiFi Devices

- Photon
- P1
- Argon

### Cellular Devices

- Electron
- E-Series
- Boron
- B-Series

### Tracker

- Tracker One
- Tracker SoM

## Pin Mappings

### Photon/P1

- D0-D7: Digital I/O
- A0-A7: Analog Input
- DAC: A6 (DAC1), A3 (DAC2)
- PWM: D0, D1, D2, D3, A4, A5, WKP, RX, TX

### Boron

- D0-D8: Digital I/O
- A0-A5: Analog Input
- PWM: D2, D3, D4, D5, D6, D7, A0, A1

## Communication Interfaces

### I2C

- Wire (D0/D1)
- Wire1 (D2/D3) - select devices

### SPI

- SPI (A2-A5)
- SPI1 - select devices

### UART

- Serial1 (TX/RX)
- Serial2 - select devices

## Power Requirements

### Input Voltage

- USB: 5V
- VIN: 3.6V - 5.5V (Photon)
- Li-Po: 3.7V (Boron, Electron)

### Current Draw

- Active (WiFi): ~80mA
- Active (Cellular): ~180mA
- Sleep: <1mA
- Deep Sleep: <100µA

## See Also

- [Pin Diagrams](https://docs.particle.io/)
- [Datasheets](https://docs.particle.io/datasheets/)
