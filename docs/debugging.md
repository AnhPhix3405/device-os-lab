
## Debug Build

The firmware includes a debugging aid that enables debug output, from the system and from your own application code.

To create a debug build, add `DEBUG_BUILD=y` to the `make` command line. If the previous build was not a debug build then
you should add `clean` to perform a clean build.

### Example: Creating a Debug Build

```bash
# Clean debug build for Boron
cd modules
make clean all DEBUG_BUILD=y PLATFORM=boron -s

# Flash to device
make program-dfu DEBUG_BUILD=y PLATFORM=boron
```

### Logging Framework

On the device, the system module(s) must also be rebuilt also with `DEBUG_BUILD` set.

Since 0.6.0 the firmware includes newer logging framework. The system API is described in the services/inc/logging.h file. The application API is described in the firmware reference: docs/reference/firmware.md

### Common Debug Scenarios

**1. Enable verbose logging:**
```cpp
Serial.begin(9600);
Log.level(LOG_LEVEL_ALL);
Log.info("Debug message");
```

**2. Memory debugging:**
```cpp
Log.info("Free memory: %d bytes", System.freeMemory());
```

**3. Network debugging:**
```cpp
Log.info("IP Address: %s", WiFi.localIP().toString().c_str());
```
