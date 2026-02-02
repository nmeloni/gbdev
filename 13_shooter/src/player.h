#ifndef PLAYER_H
#define PLAYER_H

#include <gb/gb.h>
#include <stdint.h>
#include <gbdk/metasprites.h>

#include "body.h"
#include "game.h"
#include "input.h"
#include "shot.h"

#include "player_sprite.h"
#include "shield_sprite.h"

#define PLAYER_TILE_OFFSET 0
#define SHIELD_TILE_OFFSET    0x12

#define PLAYER_ANIMATION_FRAME_TOP   0
#define PLAYER_ANIMATION_FRAME_LEFT  1
#define PLAYER_ANIMATION_FRAME_RIGHT 2

#define PLAYER_SHOOT_COOLDOWN_FRAMES 12
#define PLAYER_BOOST_DURATION_FRAMES 48
#define PLAYER_INVINCIBILITY_FRAMES  191u

#define PLAYER_MIN_X            ((uint8_t) (GAMESCREEN_X_ORIGIN+8u))
#define PLAYER_MAX_X            ((uint8_t) (GAMESCREEN_X_END-8u))
#define PLAYER_MIN_Y            ((uint8_t) (GAMESCREEN_Y_ORIGIN+8u))
#define PLAYER_MAX_Y            ((uint8_t) (GAMESCREEN_Y_END-8u))
#define PLAYER_START_X          (84u)
#define PLAYER_START_y          (128u)

#define PLAYER_SPEED            12
#define BOOST_SPEED             24

typedef struct {
    body_t body;
    uint8_t shoot_cooldown;
    uint8_t shoot_power;
    uint8_t shield;
    uint8_t invincibility_timer;
    uint8_t boost;
    uint8_t lives;
    const  metasprite_t * const * metasprites;
} player_t;

extern player_t PLAYER;

void init_player(void);
void update_player(void);
void reset_player(uint8_t x, uint8_t y);
void kill_player(void);

#endif // PLAYER_H
