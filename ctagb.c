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
#include "gameOverMap.h"
#include "numbers.h"
#include "basketSprite.h"
#include "appleSprite.h"

GameState currentState = START;

bool isInit = false;
bool timeOut;

uint8_t input = 0;

uint8_t basketX;
uint8_t basketY;

uint8_t appleX;
uint8_t appleY;

uint8_t score;

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
            case GAMEOVER:
                if (isInit == false){
                    initGameOverTiles();
                    isInit = true;
                }
                initGameOverLogic();
                break;
        }
        wait_vbl_done();
    }
} // Ends main/driver