#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H

#include <gb/gb.h>
#include <stdint.h>

#include <gbdk/platform.h>
#include <gbdk/metasprites.h>
#include <gbdk/emu_debug.h>

#include "global.h"

#include "enemybullet_sprite.h"

#define ENEMYBULLET_TILE_OFFSET      (48)
#define MAX_ENEMYBULLETS             (16)

typedef struct {
    uint8_t x, y;
    int8_t dx, dy;
    int8_t fx, fy;
    uint8_t isactive;
    uint8_t type;
} enemybullet_t;

void init_enemy_bullets(void);
void add_enemy_bullet(uint8_t x, uint8_t y, int8_t dx, int8_t dy, uint8_t type);
void aim_at_player(uint8_t x, uint8_t y  );
void handle_enemy_bullets(void);
void kill_active_enemybullet(uint8_t j);

extern enemybullet_t ENEMYBULLET_POOL[MAX_ENEMYBULLETS];
extern uint8_t ACTIVE_ENEMYBULLET_POOL[MAX_ENEMYBULLETS];
extern uint8_t quadrant;
extern uint8_t angle;
extern const int8_t dir16_vx[4][5];
extern const int8_t dir16_vy[4][5];

extern uint8_t oam;
extern uint16_t level_framecounter;
#endif
