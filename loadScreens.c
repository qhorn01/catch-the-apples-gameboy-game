#include <gb/gb.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <rand.h>

#include "functionLibrary.h"
#include "startTiles.h"
#include "startMap.h"
#include "ctagbTiles.h"
#include "ctagbMap.h"
#include "gameOverMap.h"
#include "numbers.h"
#include "basketSprite.h"
#include "appleSprite.h"

#include "loadScreens.h"

extern GameState currentState;

extern bool isInit;
extern bool timeOut;
extern uint8_t input;

extern uint8_t basketX;
extern uint8_t basketY;
extern uint8_t appleX;
extern uint8_t appleY;
extern uint8_t score;
extern bool isCollision;

void initStartTiles(void) {
    wait_vbl_done();
    DISPLAY_OFF;

    set_bkg_data(29, 87, startTiles);
    set_bkg_tiles(0, 0, 32, 32, startMap);
    
    HIDE_SPRITES;
    SHOW_BKG;
    DISPLAY_ON;
}

void initStartLogic(void) {
    if (input & J_START) {
        currentState = LEVEL;

        isInit = false;
    }
}

void initLevelTiles(void) {
    wait_vbl_done();
    DISPLAY_OFF;
    // Loads the background tile data, 
    // kinda like adding items on a menu to pick from
    set_bkg_data(10, 19, ctagbTiles);
    set_bkg_data(0, 10, numbers);

    // Orders the tiles from the menu (some more than others)
    // and lays them out on the plate (screen)
    set_bkg_tiles(0, 0, 32, 32, ctagbMap);

    // Basket Sprite setup
    set_sprite_data(0, 3, basketSprite);

    // Since sprites on the GB have to be one tile,
    // the workaround is to create multiple that move at the same time
    set_sprite_tile(0, 0);
    set_sprite_tile(1, 1);
    set_sprite_tile(2, 2);

    move_sprite(0, basketX, basketY);
    move_sprite(1, basketX + 8, basketY);
    move_sprite(2, basketX + 16, basketY);

    // Apple Sprite
    set_sprite_data(3, 1, appleSprite);

    set_sprite_tile(3, 3);

    move_sprite(3, appleX, appleY);

    resetGame();

    SHOW_SPRITES;
    SHOW_BKG;
    DISPLAY_ON;
}

void initLevelLogic(void) {
        scoreText(score, false);
        timeOut = timer();

        if (timeOut == true) {
            currentState = GAMEOVER;

            isInit = false;
        }

        // Stands for Joypad (d-pad) left
        if (input & J_LEFT) {
            if (basketX > 8) {
                basketX -= 1; // only move by one pixel to the left if not on edge of screen 
            }
        }

        if (input & J_RIGHT) {
            if (basketX < 144) {
                basketX += 1; // only move by one pixel to the right if not on edge of screen 
            }
        }

        // Draws sprites on screen with specific coordinates
        move_sprite(0, basketX, basketY);
        move_sprite(1, basketX + 8, basketY);
        move_sprite(2, basketX + 16, basketY);

        appleY += 1;
        isCollision = collisionCheck(basketX, basketY, 24, appleX, appleY);

        if (isCollision == true){
            appleReset(ctagbMap, &appleX, &appleY);
            
            score++;
        } else if (isCollision == false && appleY > 168) { // Resets the apple to its original position if it leaves the screen
            appleReset(ctagbMap, &appleX, &appleY);
        }

        move_sprite(3, appleX, appleY);
}

void initGameOverTiles(void) {
    wait_vbl_done();
    DISPLAY_OFF;

    set_bkg_data(10, gameOverMap_TILE_COUNT, gameOverMap_tiles);
    set_bkg_data(10, gameOverMap_TILE_COUNT, gameOverMap_tiles);
    set_bkg_based_tiles(0, 0, gameOverMap_WIDTH / 8, gameOverMap_HEIGHT / 8, gameOverMap_map, 10);
    
    SHOW_BKG;
    HIDE_SPRITES;
    DISPLAY_ON;
}

void initGameOverLogic(void) {
    scoreText(score, true);
    if (input & J_SELECT) {
        currentState = START;

        isInit = false;
    }
}