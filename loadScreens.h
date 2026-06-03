#include <gb/gb.h>
#include <stdbool.h>
#include <stdint.h>
#include <rand.h>

#ifndef LOAD_SCREENS
#define LOAD_SCREENS

typedef enum {
    START,
    LEVEL
} GameState;

void initStartTiles(void);
void initStartLogic(void);

void initLevelTiles(void);
void initLevelLogic(void);

#endif