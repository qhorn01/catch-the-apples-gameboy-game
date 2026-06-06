#include <gb/gb.h>
#include <stdbool.h>
#include <stdint.h>
#include <rand.h>
#include "loadScreens.h"

#ifndef FUNCTION_LIBRARY
#define FUNCTION_LIBRARY

bool collisionCheck(uint8_t basketX, uint8_t basketY, uint8_t basketLength, uint8_t appleX, uint8_t appleY);
void scoreText(uint8_t scoreNum, bool isGameOver);
void timer(void);
void resetGame(void);
void gameOverTimer(void);
void appleReset(const unsigned char mapData[], uint8_t *newX, uint8_t *newY );

#endif