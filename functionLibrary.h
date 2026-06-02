#include <gb/gb.h>
#include <stdbool.h>
#include <stdint.h>

#ifndef HEADER_FILE
#define HEADER_FILE

bool collisionCheck(uint8_t basketX, uint8_t basketLength, uint8_t appleX, uint8_t appleY);
void scoreText(uint8_t scoreNum);

#endif