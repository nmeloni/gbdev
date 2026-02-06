#ifndef EXPLOSION_H
#define EXPLOSION_H

#include <gb/gb.h>
#include <stdint.h>
#include <gbdk/platform.h>
#include <gbdk/metasprites.h>
#include <gbdk/emu_debug.h>

#include "game.h"
#include "utils.h"
#include "gfx.h"
#include "audio.h"
#include "explosion_sprite.h"

#define EXPLOSION_TILE_OFFSET 128
#define EXPLOSION_FRAME_DURATION 32
#define EXPLOSION_ANIM_FRAMES 4
#define EXPLOSION_ANIM_SPEED  3
#define MAX_EXPLOSIONS 8

typedef struct {
    uint8_t x;
    uint8_t y;
    uint8_t frame_counter;
} explosion_t;

void init_explosions(void);
void add_explosion(uint8_t x, uint8_t y);
void update_explosions(void);

extern explosion_t EXPLOSION_QUEUE[MAX_EXPLOSIONS];

#endif // EXPLOSION_H
