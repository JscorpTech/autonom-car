#include "config.h"
#include "drive.h"
#include "esp32-hal-ledc.h"
#include "sensor.h"
#include <Arduino.h>
#include <Wire.h>
#include <utility>

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22, 100000); // SDA = 21, SCL = 22, 100kHz
  Wire1.begin(17, 16, 100000);

  leftPrevAngle = leftReadRawAngle();   // Boshlang‘ich burchak
  rightPrevAngle = rightReadRawAngle(); // Boshlang‘ich burchak
  beginChannels();
}

void loop() {
  uint16_t leftAngle = leftReadRawAngle();
  uint16_t rightAngle = rightReadRawAngle();

  if (leftPrevAngle > 3000 && leftAngle < 1000) {
    leftRotationCount++;
  } else if (leftPrevAngle < 1000 && leftAngle > 3000) {
    leftRotationCount++;
  }
  if (rightPrevAngle > 3000 && rightAngle < 1000) {
    rightRotationCount++;
  } else if (rightPrevAngle < 1000 && rightAngle > 3000) {
    rightRotationCount++;
  }

  forward(100);
  delay(1);
}
