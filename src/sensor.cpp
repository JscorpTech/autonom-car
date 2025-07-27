#include "config.h"
#include <Arduino.h>
#include <Wire.h>

uint16_t leftReadRawAngle() {
  Wire.beginTransmission(AS5600_ADDR);
  Wire.write(ANGLE_MSB);
  if (Wire.endTransmission(true) != 0) { // true = STOP condition
    return 0;
  }

  if (Wire.requestFrom(AS5600_ADDR, 2) != 2) {
    return 0;
  }

  uint8_t msb = Wire.read();
  uint8_t lsb = Wire.read();
  return ((msb << 8) | lsb) & 0x0FFF;
}

uint16_t rightReadRawAngle() {
  Wire1.beginTransmission(AS5600_ADDR);
  Wire1.write(ANGLE_MSB);
  if (Wire1.endTransmission(true) != 0) { // true = STOP condition
    return 0;
  }

  if (Wire1.requestFrom(AS5600_ADDR, 2) != 2) {
    return 0;
  }

  uint8_t msb = Wire1.read();
  uint8_t lsb = Wire1.read();
  return ((msb << 8) | lsb) & 0x0FFF;
}
