#ifndef BULLET_H
#define BULLET_H

#include <gb/gb.h>
#include <stdint.h>

#include <gbdk/platform.h>
#include <gbdk/metasprites.h>
#include <gbdk/emu_debug.h>

#include "bullet_sprite.h"


#define BULLET_TILE_OFFSET      (5)
#define BULLET_SPEED            (6<<5)
#define MAX_BULLETS             (9)


typedef struct {
    uint16_t x,y;
    uint8_t isactive;
} bullet_t;


void init_bullets(void);
void handle_bullets(void);
void draw_bullets(void);

extern uint8_t bullet_bounding_box[];
extern bullet_t BULLETS[MAX_BULLETS];
extern uint8_t oam;

#endif
