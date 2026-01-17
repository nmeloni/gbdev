#ifndef PLAYER_H
#define PLAYER_H

#include "global.h"
#include "spaceship_sprite.h"

#define SPACESHIP_TILE_OFFSET   (0)

#define PLAYER_MIN_X            ((GAMESCREEN_X_ORIGIN+8))
#define PLAYER_MAX_X            ((GAMESCREEN_X_END-8))
#define PLAYER_MIN_Y            ((GAMESCREEN_Y_ORIGIN+8))
#define PLAYER_MAX_Y            ((GAMESCREEN_Y_END-8))

#define PLAYER_INIT_X           (84)
#define PLAYER_INIT_Y           ((uint16_t) 128)

#define NORMAL_SPEED            (12<<4)
#define BOOST_SPEED             (14<<4)
#define BOOST_LAG               (16)
#define BOOST_DURATION          (48)




typedef struct {
    uint16_t x,y;
    int16_t dx, dy;
    uint8_t px, py;
    uint8_t last_boost;
    uint8_t boost;

    const metasprite_t * const * metasprites;
} player_t;

extern player_t PLAYER;

void init_player(void);
void handle_player(void);

#endif // PLAYER_H
