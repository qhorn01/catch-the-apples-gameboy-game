#include <gb/gb.h>
#include <stdio.h>

#include "ctagbTiles.h"
#include "ctagbMap.h"
#include "basketSprite.h"

// Got coordinates from GB Map Builder by multiplying coordinates by 8
uint8_t basketX = 72;
uint8_t basketY = 136;

void main() {

    // Loads the background tile data, 
    // kinda like adding items on a menu to pick from
    set_bkg_data(0, 9, ctagbTiles);

    // Orders the tiles from the menu (some more than others)
    // and lays them out on the plate (screen)
    set_bkg_tiles(0, 0, 32, 32, ctagbMap);

    // Sprite setup
    set_sprite_data(0, 3, basketSprite);

    // Since sprites on the GB have to be one tile,
    // the workaround is to create multiple that move at the same time
    set_sprite_tile(0, 0);
    set_sprite_tile(1, 1);
    set_sprite_tile(2, 2);

    // Draws sprites on screen with specific coordinates
    move_sprite(0, basketX, basketY);
    move_sprite(1, basketX + 8, basketY);
    move_sprite(2, basketX + 16, basketY);

    SHOW_SPRITES;
    SHOW_BKG;
    DISPLAY_ON;

    while(1) 
    {
        wait_vbl_done();
    }
}