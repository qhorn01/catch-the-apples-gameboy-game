#include <gb/gb.h>
#include <stdbool.h>
#include <stdint.h>

#include "functionLibrary.h"

// Defining collision function
bool collisionCheck(uint8_t basketX, uint8_t basketLength, uint8_t appleX, uint8_t appleY){
    uint8_t left = basketX;
    uint8_t right = basketX+basketLength;
    uint8_t applePixTarget = appleX + 4;

    if (left < applePixTarget && right < applePixTarget){
        return false;
    }else if (left > applePixTarget && right > applePixTarget){
        return false;
    } else if (left <= applePixTarget && right >= applePixTarget){
        if (appleY == 130){
            return true;
        }else{
            return false;
        }
    }
    return false;
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