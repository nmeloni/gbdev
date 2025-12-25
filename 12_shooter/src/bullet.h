#ifndef BULLET_H
#define BULLET_H

#include <gb/gb.h>
#include <stdint.h>

#include <gbdk/platform.h>
#include <gbdk/metasprites.h>
#include <gbdk/emu_debug.h>

#include "player.h"
#include "ennemy.h"
#include "bullet_sprite.h"
#include "bullet_lvl1_sprite.h"
#include "bullet_lvl2_sprite.h"
#include "bullet_lvl3_sprite.h"

#define BULLET_LVL1_TILE_OFFSET      (5)
#define BULLET_LVL2_TILE_OFFSET      (6)
#define BULLET_LVL3_TILE_OFFSET      (8)
#define LASER_TILE_OFFSET            (10)
#define BULLET_SPEED            (6<<7)
#define MAX_BULLETS             (4)


typedef struct {
    uint16_t x,y;
    uint8_t px, py;
    uint8_t isactive;
} bullet_t;


void init_bullets(void);
void handle_bullets(void);
void kill_active_bullet(uint8_t j);

extern bullet_t BULLETS[MAX_BULLETS];
extern uint8_t ACTIVE_BULLETS[MAX_BULLETS];
extern uint8_t active_bullet_index;

extern uint8_t oam;

#endif
