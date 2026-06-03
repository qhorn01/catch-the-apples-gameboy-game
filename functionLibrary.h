#include <gb/gb.h>
#include <stdbool.h>
#include <stdint.h>

#ifndef FUNCTION_LIBRARY
#define FUNCTION_LIBRARY

bool collisionCheck(uint8_t basketX, uint8_t basketY, uint8_t basketLength, uint8_t appleX, uint8_t appleY);
void scoreText(uint8_t scoreNum);

#endif