#include "catch.hpp"
#include "hal_gpio.h"

TEST_CASE("GPIO helpers - Pin initialization", "[gpio]") {
    hal_gpio_t pin = HAL_GPIO_PIN_NONE;

    SECTION("Initialize GPIO pin") {
        REQUIRE(hal_gpio_init(&pin, HAL_GPIO_MODE_OUTPUT) == 0);
        REQUIRE(pin != HAL_GPIO_PIN_NONE);
    }
}

TEST_CASE("GPIO helpers - Pin state manipulation", "[gpio]") {
    hal_gpio_t pin = HAL_GPIO_PIN_NONE;
    hal_gpio_init(&pin, HAL_GPIO_MODE_OUTPUT);

    SECTION("Set GPIO pin high") {
        REQUIRE(hal_gpio_write(&pin, 1) == 0);
        REQUIRE(hal_gpio_read(&pin) == 1);
    }

    SECTION("Set GPIO pin low") {
        REQUIRE(hal_gpio_write(&pin, 0) == 0);
        REQUIRE(hal_gpio_read(&pin) == 0);
    }
}

TEST_CASE("GPIO helpers - Pin cleanup", "[gpio]") {
    hal_gpio_t pin = HAL_GPIO_PIN_NONE;
    hal_gpio_init(&pin, HAL_GPIO_MODE_OUTPUT);

    SECTION("Deinitialize GPIO pin") {
        REQUIRE(hal_gpio_deinit(&pin) == 0);
        REQUIRE(pin == HAL_GPIO_PIN_NONE);
    }
}

TEST_CASE("GPIO helpers - Debounce logic", "[gpio]") {
    hal_gpio_t pin = HAL_GPIO_PIN_NONE;
    hal_gpio_init(&pin, HAL_GPIO_MODE_INPUT);

    SECTION("Debounce stable high state") {
        // Simulate stable high state
        simulate_gpio_input(&pin, 1);
        REQUIRE(hal_gpio_read_debounced(&pin) == 1);
    }

    SECTION("Debounce stable low state") {
        // Simulate stable low state
        simulate_gpio_input(&pin, 0);
        REQUIRE(hal_gpio_read_debounced(&pin) == 0);
    }

    SECTION("Debounce unstable state") {
        // Simulate bouncing input
        simulate_gpio_input_sequence(&pin, {1, 0, 1, 0, 1});
        REQUIRE(hal_gpio_read_debounced(&pin) == 1); // Final stable state
    }
}