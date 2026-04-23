#ifndef PLAYER_H
#define PLAYER_H

#include <gb/gb.h>
#include <stdint.h>
#include <gbdk/metasprites.h>

#include "game_types.h"
#include "constants.h"

#define PLAYER_ANIMATION_FRAME_CENTER 0
#define PLAYER_ANIMATION_FRAME_LEFT   1
#define PLAYER_ANIMATION_FRAME_RIGHT  2

typedef struct {
    body_t  body;
    uint8_t active;
    uint8_t boost;
    uint8_t invincibility_timer;
    const metasprite_t * const * metasprites;
} player_t;

extern player_t PLAYER;

void player_init(void);
void player_update(void);

#endif // PLAYER_H
