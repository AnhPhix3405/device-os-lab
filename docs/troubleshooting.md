# Troubleshooting Guide

This guide provides solutions to common issues encountered while working with Device OS.

## Common Issues

### 1. Build Failures
**Symptoms:**
- Compilation errors during the build process.
- Missing dependencies or tools.

**Solutions:**
- Ensure all required tools are installed (e.g., GCC, Make).
- Run the following command to install dependencies:
  ```bash
  ./ci/install_boost.sh
  ```
- Check the `build/` directory for detailed logs.

### 2. Device Not Connecting to Network
**Symptoms:**
- Device fails to connect to Wi-Fi or cellular network.
- Network state stuck in `DISCONNECTED`.

**Solutions:**
- Verify network credentials are correct.
- Check if the network is available and has sufficient signal strength.
- Use the following command to reset network settings:
  ```bash
  particle device wifi
  ```

### 3. LED Blink Patterns Not Working
**Symptoms:**
- Custom LED patterns are not applied.
- LED remains off or blinks unexpectedly.

**Solutions:**
- Ensure the pattern string is valid (e.g., `"1010"` for on/off sequence).
- Check the `spark_wiring_led.cpp` file for errors.

### 4. Power Consumption Logs Missing
**Symptoms:**
- No logs related to power consumption appear.
- Battery level always shows `-1`.

**Solutions:**
- Verify the device is running on battery power.
- Check the `spark_wiring_power.cpp` file for issues.

### 5. Common Error Codes
**Error Code: -1 (SYSTEM_ERROR_UNKNOWN)**
- General unknown error
- Check device logs for more details

**Error Code: -2 (SYSTEM_ERROR_BUSY)**
- System is busy processing another operation
- Wait and retry the operation

**Error Code: -3 (SYSTEM_ERROR_NOT_SUPPORTED)**
- Feature not supported on this device
- Check device capabilities

**Error Code: -4 (SYSTEM_ERROR_INVALID_ARGUMENT)**
- Invalid argument passed to function
- Verify function parameters

## Common Build Errors

### Error: Missing Dependencies
**Description**: Build fails due to missing dependencies.
**Solution**:
1. Ensure all required tools are installed (e.g., GCC, Make).
2. Run the appropriate setup script: `ci/install_gcc.sh` or `ci/install_boost.sh`.

### Error: Compilation Fails
**Description**: Compilation errors occur during the build process.
**Solution**:
1. Check the error message for details.
2. Ensure the code adheres to the style guide.
3. Run `make clean` and rebuild.

### Error: Linker Errors
**Description**: Linker errors occur during the build process.
**Solution**:
1. Verify that all required libraries are linked.
2. Check the `makefile` for missing dependencies.

### Error: CI Pipeline Fails
**Description**: Build fails in the CI pipeline.
**Solution**:
1. Review the CI logs for details.
2. Ensure all tests pass locally before pushing changes.

## Debugging Tips
- Use the `Log.info()` function to add debug logs in the code.
- Check the `logs/` directory for runtime logs.
- Use the Particle CLI for device diagnostics:
  ```bash
  particle device doctor
  ```
- Enable verbose logging with `Log.level(LOG_LEVEL_ALL)`
- Use `Serial.println()` for immediate console output during development

## Debugging Tools

Debugging tools can help identify and resolve issues in your application. Below are some recommended tools and their usage:

### GDB (GNU Debugger)
- **Description**: A powerful debugger for C/C++ applications.
- **Usage**:
  ```bash
  gdb <executable>
  ```
- **Features**: Breakpoints, stack traces, memory inspection.

### Valgrind
- **Description**: A tool for memory debugging, memory leak detection, and profiling.
- **Usage**:
  ```bash
  valgrind --leak-check=full <executable>
  ```
- **Features**: Detects memory leaks, invalid memory access, and more.

### Serial Debugging
- **Description**: Use serial output to debug embedded applications.
- **Usage**:
  ```bash
  screen /dev/ttyUSB0 115200
  ```
- **Features**: Real-time logging and debugging.

### Particle CLI
- **Description**: A command-line interface for Particle devices.
- **Usage**:
  ```bash
  particle serial monitor
  ```
- **Features**: Device monitoring, firmware flashing, and diagnostics.

By leveraging these tools, you can efficiently debug and resolve issues in your application.

## Additional Resources
- [Debugging Guide](debugging.md) - Comprehensive debugging documentation
- [Build Documentation](build.md) - Build system troubleshooting
- [Community Forum](https://community.particle.io/) - Ask questions and get help

## Contact Support
If the issue persists, please contact the support team with the following information:
- Device model and OS version.
- Steps to reproduce the issue.
- Relevant logs or error messages.

## Watchdog Timer Usage Guide

The watchdog timer is a critical feature to ensure system reliability by resetting the device in case of a software fault. Below is a guide on how to use the watchdog timer effectively:

### Enabling the Watchdog Timer

1. Initialize the watchdog timer in your setup function:

    ```cpp
    #include "hal/watchdog.h"

    void setup() {
        HAL_Watchdog_Init(30000); // Set timeout to 30 seconds
    }
    ```

2. Regularly reset the watchdog timer in your main loop to prevent unintended resets:

    ```cpp
    void loop() {
        HAL_Watchdog_Refresh();
        // Your application logic here
    }
    ```

### Troubleshooting Common Issues

- **Device Resets Unexpectedly**: Ensure that `HAL_Watchdog_Refresh()` is called frequently enough to prevent the timer from expiring.
- **Watchdog Timer Not Working**: Verify that the watchdog timer is properly initialized in the `setup` function.

By following these steps, you can ensure that the watchdog timer is used effectively to maintain system stability.