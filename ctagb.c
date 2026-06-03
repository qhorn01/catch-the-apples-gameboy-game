#include <gb/gb.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <rand.h>

#include "functionLibrary.h"
#include "loadScreens.h"

#include "startTiles.h"
#include "startMap.h"
#include "ctagbTiles.h"
#include "ctagbMap.h"
#include "numbers.h"
#include "basketSprite.h"
#include "appleSprite.h"

GameState currentState = START;

bool isInit = false;

uint8_t input = 0;

uint8_t basketX = 72;
uint8_t basketY = 136;

uint8_t appleX = 104;
uint8_t appleY = 72;

uint8_t score = 0;

bool isCollision;

int main(void) {

    while(1) 
    {
        input = joypad();

        switch(currentState) {
            case START:
                if (isInit == false){
                    initStartTiles();
                    isInit = true;
                }
                initStartLogic();
                break;
            case LEVEL:
                if (isInit == false){
                    initLevelTiles();
                    isInit = true;
                }
                initLevelLogic();
                break;
        }

        wait_vbl_done();
    }
} // Ends main/driver