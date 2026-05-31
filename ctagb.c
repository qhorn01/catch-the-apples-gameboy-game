#include <gb/gb.h>
#include <stdio.h>

void main() {

    SHOW_BKG;
    DISPLAY_ON;

    while(1) 
    {
        wait_vbl_done();
    }
}