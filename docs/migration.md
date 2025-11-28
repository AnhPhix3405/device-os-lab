# Migration Guide

## Migrating from Device OS 2.x to 3.x

### Overview

This guide helps you migrate your application from Device OS 2.x to 3.x.

### Breaking Changes

#### 1. Network API Changes

**Old (2.x):**
```cpp
WiFi.connect();
waitFor(WiFi.ready, 30000);
```

**New (3.x):**
```cpp
Network.connect();
waitFor(Network.ready, 30000);
```

#### 2. Cloud API Changes

**Old (2.x):**
```cpp
Particle.publish("event", data, PRIVATE);
```

**New (3.x):**
```cpp
Particle.publish("event", data, PublishFlags::PRIVATE);
```

### New Features in 3.x

1. **Enhanced Sleep Modes**
2. **Improved BLE Support**
3. **Better Threading Support**
4. **Enhanced Logging**

### Migration Checklist

- [ ] Update network connection code
- [ ] Update cloud publication flags
- [ ] Test all interrupt handlers
- [ ] Verify sleep mode behavior
- [ ] Update BLE code if used
- [ ] Check third-party library compatibility

## See Also

- [Release Notes](CHANGELOG.md)
- [API Reference](api_reference.md)
