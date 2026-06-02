#include <gb/gb.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "functionLibrary.h"
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

    // Loads the background tile data, 
    // kinda like adding items on a menu to pick from
    set_bkg_data(10, 15, ctagbTiles);
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

    SHOW_SPRITES;
    SHOW_BKG;
    DISPLAY_ON;

    while(1) 
    {
        uint8_t input = joypad();

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
        isCollision = collisionCheck(basketX, 24, appleX, appleY);
        scoreText(score);

        if (isCollision == true){
            appleY = 72;
            score++;
        } else if (isCollision == false && appleY > 168) { // Resets the apple to its original position if it leaves the screen
            appleY = 72;
        }

        move_sprite(3, appleX, appleY);
        

        wait_vbl_done();
    }
} // Ends main/driver

