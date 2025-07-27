#include "config.h"
#include "esp32-hal-ledc.h"
#include <Arduino.h>

void createChannel(int channel, int pin) {
  ledcSetup(channel, 20000, 8);
  ledcAttachPin(pin, channel); // 5-pin misol uchun
}

void beginChannels() {
  createChannel(LEFT_FORWARD_CHANNEL, LEFT_FORWARD_PIN);
  createChannel(LEFT_BACK_CHANNEL, LEFT_BACK_PIN);

  createChannel(RIGHT_FORWARD_CHANNEL, RIGHT_FORWARD_PIN);
  createChannel(RIGHT_BACK_CHANNEL, RIGHT_BACK_PIN);
}

void forward(int distance) {
  ledcWrite(LEFT_FORWARD_CHANNEL, SPEED);
  ledcWrite(RIGHT_FORWARD_CHANNEL, SPEED);

  ledcWrite(LEFT_BACK_CHANNEL, 0);
  ledcWrite(RIGHT_BACK_CHANNEL, 0);
}

void back(int distance) {
  ledcWrite(LEFT_FORWARD_CHANNEL, 0);
  ledcWrite(RIGHT_FORWARD_CHANNEL, 0);

  ledcWrite(LEFT_BACK_CHANNEL, SPEED);
  ledcWrite(RIGHT_BACK_CHANNEL, SPEED);
}

void rotation(int angle) {}
