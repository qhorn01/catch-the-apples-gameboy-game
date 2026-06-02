#include <gb/gb.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "functionLibrary.h"
#include "loadScreens.h"

#include "ctagbTiles.h"
#include "ctagbMap.h"
#include "numbers.h"
#include "basketSprite.h"
#include "appleSprite.h"

// Got coordinates from GB Map Builder by multiplying coordinates by 8
uint8_t basketX = 72;
uint8_t basketY = 136;

uint8_t appleX = 104;
uint8_t appleY = 72;

uint8_t score = 0;

bool isCollision;

int main(void) {

    initLevelTiles();

    while(1) 
    {
        initLevelLogic();
        
        wait_vbl_done();
    }
} // Ends main/driver