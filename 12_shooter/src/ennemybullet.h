#ifndef ENNEMYBULLET_H
#define ENNEMYBULLET_H
#include <gb/gb.h>
#include <stdint.h>

#include <gbdk/platform.h>
#include <gbdk/metasprites.h>
#include <gbdk/emu_debug.h>

#include "ennemybullet_sprite.h"
#include "player.h"


#define ENNEMYBULLET_TILE_OFFSET      (10)
#define ENNEMYBULLET_SPEED            (4<<5)
#define MAX_ENNEMYBULLETS             (12)

typedef struct {
    uint16_t x,y;
    int16_t dx,dy;
    uint8_t isactive;
} ennemybullet_t;

void init_ennemy_bullets(void);
void add_ennemy_bullet(uint8_t x, uint8_t y, int16_t dx, int16_t dy);
void aim_at_player(uint8_t x, uint8_t y  );
void handle_ennemy_bullets(void); // Déplace les bullets actives et affiche

extern ennemybullet_t ENNEMYBULLETS[MAX_ENNEMYBULLETS];
extern uint8_t oam;
extern uint8_t quadrant;
extern uint8_t angle;
extern const int8_t dir16_vx[4][5];
extern const int8_t dir16_vy[4][5];
#endif
