#ifndef PLAYER_H
#define PLAYER_H

#include <gb/gb.h>
#include <stdint.h>
#include <gbdk/metasprites.h>

#include "game.h"
#include "input.h"

#include "player_sprite.h"

#define PLAYER_TILE_OFFSET 0
#define PLAYER_ANIMATION_FRAME_TOP   0
#define PLAYER_ANIMATION_FRAME_LEFT  1
#define PLAYER_ANIMATION_FRAME_RIGHT 2

#define PLAYER_MIN_X            ((uint8_t) (GAMESCREEN_X_ORIGIN+8))
#define PLAYER_MAX_X            ((uint8_t) (GAMESCREEN_X_END-8))
#define PLAYER_MIN_Y            ((uint8_t) (GAMESCREEN_Y_ORIGIN+8))
#define PLAYER_MAX_Y            ((uint8_t) (GAMESCREEN_Y_END-8))

#define PLAYER_SPEED            12

typedef struct {
    uint8_t x, y;
    int8_t dx, dy;
    int8_t fx, fy;
    const  metasprite_t * const * metasprites;
} player_t;

extern player_t PLAYER;

void init_player(void);
void handle_player(void);

#endif // PLAYER_H
