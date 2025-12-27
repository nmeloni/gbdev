#ifndef EXPLOSION_H
#define EXPLOSION_H

#include <gb/gb.h>
#include <stdint.h>

#include <gbdk/platform.h>
#include <gbdk/metasprites.h>
#include <gbdk/emu_debug.h>

#include "player.h"
#include "ennemy.h"

#include "explosion_sprite.h"

#define EXPLOSION_TILE_OFFSET (0x70)
#define MAX_EXPLOSIONS        (8)
#define NB_EXPLOSION_FRAME    (32)

typedef struct {
    uint8_t px,py;
    uint8_t framecount;
} explosion_t;

void init_explosions(void);
void add_exploision(uint8_t x, uint8_t y);
void handle_explosions(void);

extern explosion_t EXPLOSIONS[MAX_EXPLOSIONS];
extern uint8_t queue_start, queue_end;
extern uint8_t oam;

#endif
