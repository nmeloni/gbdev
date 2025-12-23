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


#define BULLET_TILE_OFFSET      (5)
#define BULLET_SPEED            (6<<7)
#define MAX_BULLETS             (3)


typedef struct {
    uint16_t x,y;
    uint8_t px, py;
    uint8_t isactive;
} bullet_t;


void init_bullets(void);
void handle_bullets(void);

extern const uint8_t bullet_bounding_box[];
extern bullet_t BULLETS[MAX_BULLETS][3];
extern uint8_t oam;

#endif
