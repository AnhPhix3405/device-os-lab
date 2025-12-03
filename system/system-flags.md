# Flags

## `SPARK_WLAN_SLEEP`
Indicates whether the WiFi module should remain inactive. When `false`, the WiFi module will be started by the WLAN loop.

- Default: `false` in AUTOMATIC mode, `true` in other modes.
- Set in `Spark.sleep(duration)` and `WiFi.off()`.
- Cleared in `WiFi.on()` and `WiFi.connect()`.
- Checked in `Spark_Send()` and `Spark_Receive()` to avoid cloud socket usage.
- Checked in `delay()` to avoid calling the WLAN loop when sleeping.
- Checked in the WLAN loop to determine WiFi start/reset conditions.

## `SPARK_WLAN_RESET`
Forces a reset of the WLAN subsystem during the next WLAN loop iteration. The reset occurs only if `SPARK_WLAN_STARTED` is set.

- Checked and cleared in the WLAN loop after a reset.
- Set after a threshold of failed connection attempts or internet failures.
- Avoids cloud socket usage during reset.

## `SPARK_WLAN_STARTED`
Indicates whether the WLAN subsystem is active. If not set, it triggers automatic start when not sleeping.

- Set in `WiFi.connect()` and `WiFi.on()`.
- Cleared during the WLAN reset procedure.
- Checked in `WiFi.connecting()` and `WiFi.ready()`.
- Necessary for WLAN reset and connection procedures.

## `WLAN_CONNECTING`
Indicates that the WLAN subsystem is attempting to connect to an AP. Cleared once connected.

This is used to prevent re-entrant calls to WiFi.connect().

## `WLAN_CONNECTED`
Flag set when the WiFi module has made a successful connection to the WAP.

- Cleared in Start_Smart_Config()
- Cleared in wlan loop when wlan subsystem is reset
- Cleared in the callback HAL_WLAN_notify_disconected()
- Set in the callback HAL_WLAN_notify_connected()
- Checked in wlan loop as a necessary condition for smart config cleanup.
- Checked in the callback HAL_WLAN_notify_disconnected() as a necessary condition to arm the network watchdog.

## `WLAN_DISCONNECT`
Flags that the wlan was deliberately disconnected.

- Cleared in `WiFi.connect()`
- Set in `WiFi.disconnect()`
- Checked in wlan loop, as a sufficient condition to not arm the network watchdog
- Checked in the wlan loop when disconnecting from the cloud, when not set, changes the LED to green
- Checked in the callback HAL_WLAN_notify_connected(), when false, arms the network watchdog

## `WLAN_DHCP`
Flags that wifi has been connected and a IP address received via DHCP.

- Cleared in wlan loop reset procedure
- Cleared in `HAL_WLAN_notify_disconnected()`
- Cleared in `Start_Smart_Config()`
- Set in `HAL_WLAN_notify_dhcp()`
- Checked in `WiFi.connecting()` and `WiFi.ready()`
- Checked in wlan loop as a sufficient condition to skip manual wlan connection.
- Checked in the wlan loop as a necessary condition to perform smart config cleanup.
- Checked in the wlan loop as a necessary condition to fetch the IP config details.
- Checked in the wlan loop as a necessary condition to connect to the cloud
- ?? not cleared in `WiFi.disconnect()` or `WiFi.off()`?
- ?? could be repaced with a function that checks preconditions - e.g. SPARK_WLAN_STARTED, WLAN_CONNECTED so the value of WLAN_DHCP is only used when relevant?
- ?? could be replaced with a wifi state enum - OFF, DISCONNECTED, CONNECTED, READY

## `SPARK_CLOUD_CONNECT`
Flags the desired state of the cloud connection. When set, the wlan loop will make the cloud connection, when cleared, will break the cloud connection.
- set for AUTOMATIC mode, cleared for other modes
- set in `Spark.connect()` to asynchronously start the cloud connection. (Although Wifi is started synchronously.)
- cleared in `Spark.disconnect()` to asynchronously stop the cloud connection.
- cleared in `Wifi.disconnect()`
- cleared in `WiFi.off()` if not being called as part of `Spark.sleep()`.
- checked in main as a necessary negated condition to run user code (so user code runs when the cloud is not required)
- checked in the wlan loop - when false disconnects the cloud if connected and exits, when true, continues
- ?? clearing this flag in WiFi.disconnect() seems to break the intent of AUTOMATIC mode?

## `SPARK_CLOUD_SOCKETED`

Flags that a socket connection to the cloud has been established.

- cleared in `Spark.process()` when the event loop returns false, indicating the connection is lost.
- cleared in `Start_Smart_Config()`
- cleared in the wlan loop when wifi is reset
- cleared in the wlan loop when the cloud is disconnected.
- set in the wlan loop when the cloud is connected
- checked in SysTick handler - toggles the LED every 50ms when set, 100ms when reset.
- checked in `Spark.connected()` as a necessary condition to return true
- checked in `Spark.process()` as a necessary condition to invoke the event loop.
- checked in the wlan loop as a sufficient condition to disconnect the cloud (when `SPARK_CLOUD_CONNECT` is reset)
- checked in the wlan loop as a necessary negated condition for the cloud to be connected
- ?? could be replaced by cloud connection state - DISCONNECTED, SOCKETED, CONNECTED

## WLAN_SMART_CONFIG_START

- checked in SysTick handler - stops setting the LED (just update tick counter and do LED override if needed.)
- checked and set in SysTick handler - if not set and mode button pressed for longer than 3 seconds, sets flag
- checked as a necessary condition for WiFi.listening() to return true

## WLAN_SMART_CONFIG_FINISHED
Asynchornous flag set when the SmartConfig/SoftAP process completes via interaction with the external device.

- cleared at the start of smart config
- checked at the end of smart config handler as a necessary condition to call `SPARK_WLAN_SmartConfigProcess()`
- checked as a sufficient condition to return false for `WiFi.listening()`
- set in `HAL_WLAN_notify_simple_config_done()`

## WLAN_SERIAL_CONFIG_DONE

Flag to indicate if serial config is done and listening mode should exit

- set in `wifi_add_profile_callback()`
- cleared in smart config start
- checked in WiFi.listening() as a sufficient condition to return false.

# Network States

Here's a state machine. Arcs between each number and the next largest. A/B are two separate branches.
To transition from a state in one branch to another, must backtrack to 2 and then up the target branch.
(E.g. to get from State B4 to A3: B4, B3, 2, A3.)

- 1. Network Off, white breathing LED
- 2- Network hardware initializing. (white flashing LED - to be consistent, this should be blue flashing LED,
- since the flashing indicates an "about to happen" action resolving in a breathing LED of the same color.)
- 2. Network On (but not connected), blue breathing LED. Why blue? That's confusing with listening mode.
- A3. Network setup, blue flashing LED
- A3*. Network action (e.g. clear credentials), fast flashing LED, return to A3
- B3-. Network connecting, green flashing LED
- B3. Network connected, (Cloud disconnected), Green breathing LED
- B4-. Cloud connecting, cyan flashing LED
- B4-. Cloud error, red flashing LED
- B4. Cloud connected, cyan breathing LED

States with a -/+ after are transient states moving forward or backwards. They are not directly reachable via program code.

For maximum flexibility, we may define -/+ transitions for every state, since some network types may require them.

Rather than maintaining many state flags (WLAN_DISCONNECT, SPARK_WLAN_SLEEP, WLAN_CONNECTED etc..) it's less error prone
to have a single state. And have the system manage how to get to that state.

The implementation of these methods make a transition to the desired connectivity state() if the current state is less
than or equal the desired state.
- Network.off(): disconnect the cloud, disconnect the network, deinitialize the network
- Network.on(): enable network if off otherwise do nothing
- Network.disconnect(): Turn the network on if it's off?? Not sure (but implied by the strict state rule.)
 - better would be return to the disconnected state if it's on, otherwise leave off.
- Network.setup() - disconnect the cloud, disconnect the network, turn network on, enter setup mode
 - this is consistent with Network.disconnect() strict version
 - Spark.disconnect(): - transition to network connected if on, otherwise no-op if off?
 - Spark.connect(): exit listening, network on, network connect, cloud connect

This needs working through a bit more. Are the original Network.xxx() methods states or actions?

