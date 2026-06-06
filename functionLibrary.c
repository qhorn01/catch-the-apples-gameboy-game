#include <gb/gb.h>
#include <stdbool.h>
#include <stdint.h>
#include <rand.h>

#include "functionLibrary.h"

#include "startTiles.h"
#include "startMap.h"
#include "ctagbTiles.h"
#include "ctagbMap.h"
#include "numbers.h"
#include "basketSprite.h"
#include "appleSprite.h"

static uint8_t frames = 0;
static uint8_t seconds = 5;
static uint8_t lastSeconds = 61;

// Defining collision function
bool collisionCheck(uint8_t basketX, uint8_t basketY, uint8_t basketLength, uint8_t appleX, uint8_t appleY){
    uint8_t left = basketX;
    uint8_t right = basketX+basketLength;
    uint8_t applePixTarget = appleX + 4;

    if (left <= applePixTarget && right >= applePixTarget){
        if (appleY == basketY-6){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

// Defining score function
void scoreText(uint8_t scoreNum){
    uint8_t hundreds = 0;
    uint8_t tens = 0;
    uint8_t ones = scoreNum;

    while (ones >= 100) {
        hundreds++;
        ones -= 100;
    }

    while (ones >= 10) {
        tens++;
        ones -= 10;
    }

    set_bkg_tile_xy(6, 0, hundreds);
    set_bkg_tile_xy(7, 0, tens);
    set_bkg_tile_xy(8, 0, ones);
}

bool timer(void){
    uint8_t tens, ones;

    if (seconds > 0) {
        frames++;
        if (frames >= 60) {
            frames = 0;
            seconds--;
        }
    }

    if (seconds != lastSeconds) {
            lastSeconds = seconds;

            tens = seconds / 10;
            ones = seconds % 10;

            set_bkg_tile_xy(18, 0, tens);
            
            set_bkg_tile_xy(19, 0, ones);
        }

    if (seconds == 0) {
        return true;
    }else{
        return false;
    }
}

void resetGame(void) {
    frames = 0;
    seconds = 60;
    lastSeconds = 61;
}

void appleReset(const unsigned char mapData[], uint8_t *newX, uint8_t *newY ){
    uint16_t randomNum = rand() % (338 - 103 +1) + 103;
    uint16_t tileIndex = mapData[randomNum];

    while (tileIndex != 14){
        randomNum = rand() % (338 - 103 +1) + 103;
        tileIndex = mapData[randomNum];
    }

    *newX = (randomNum % 32) * 8 + 8;
    *newY = (randomNum / 32) * 8 + 16;
}