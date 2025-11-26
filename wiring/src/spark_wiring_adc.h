#pragma once

#include <stdint.h>

/**
 * @brief Calibrates the ADC to ensure accurate analog readings.
 * 
 * This function compensates for hardware variations and should be called
 * during setup or after significant hardware changes.
 * 
 * @return true if calibration is successful, false otherwise.
 */
bool adcCalibrate();