#ifndef BULLET_H
#define BULLET_H

#include <gb/gb.h>
#include <stdint.h>
#include <gbdk/metasprites.h>

#include "body.h"
#include "game.h"
#include "utils.h"
#include "bullet_sprite.h"


#define BULLET_TILE_OFFSET         32
#define BULLET_SPRITE_X_OFFSET     (-4)
#define BULLET_SPRITE_Y_OFFSET     (-8)

#define BULLET_TYPE_SMALL_SPRITE   BULLET_TILE_OFFSET
#define BULLET_TYPE_LARGE_SPRITE   (BULLET_TILE_OFFSET + 2)
#define BULLET_TYPE_LASER_SPRITE   (BULLET_TILE_OFFSET + 4)

#define MAX_BULLETS 16

enum bullet_type {
    BULLET_TYPE_NONE = 255,
    BULLET_TYPE_SMALL = 0,
    BULLET_TYPE_LARGE = 1,
    BULLET_TYPE_LASER = 2
};

typedef struct {
    uint8_t active;
    uint8_t type;
    body_t body;
} bullet_t;

extern bullet_t BULLETS_POOL[MAX_BULLETS];
extern uint8_t ACTIVE_BULLETS[MAX_BULLETS];
extern uint8_t active_bullet_index;

void init_bullets(void);
void fire_bullet(uint8_t type, uint8_t x, uint8_t y, int8_t dx, int8_t dy);
void update_bullets(void);


#endif // BULLET_H
