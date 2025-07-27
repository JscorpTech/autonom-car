#ifndef UTILS_H
#define UTILS_H

#include <cstdint>
uint32_t leftRotationCount = 0;
uint16_t leftPrevAngle = 0;

uint16_t rightPrevAngle = 0;
uint32_t RightRotationCount = 0;

void forward(int distance);
void back(int distance);
void beginChannels();
void rotation(int angel);
#endif
