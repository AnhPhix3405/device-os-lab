# Testing Guide

## Unit Testing

### Setup

```bash
cd user/tests
make test
```

### Writing Tests

```cpp
test(basic_math) {
    assertEqual(2 + 2, 4);
    assertNotEqual(2 + 2, 5);
}

test(string_operations) {
    String str = "Hello";
    assertEqual(str.length(), 5);
    assertTrue(str.startsWith("Hel"));
}
```

### Running Specific Tests

```bash
make test TEST=wiring/api
```

## Integration Testing

### Device Testing

```cpp
// Test GPIO
pinMode(D7, OUTPUT);
digitalWrite(D7, HIGH);
assertEqual(digitalRead(D7), HIGH);
```

## Best Practices

1. Test edge cases
2. Use descriptive test names
3. Keep tests independent
4. Clean up resources
5. Mock external dependencies

## See Also

- [Build Guide](build.md)
- [Debugging](debugging.md)
