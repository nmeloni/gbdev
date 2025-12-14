#ifndef POWERUP_H
#define POWERUP_H

#include <gb/gb.h>
#include <stdint.h>

#include <gbdk/platform.h>
#include <gbdk/metasprites.h>
#include <gbdk/emu_debug.h>

#include "powerup_sprite.h"

#define POWERUP_TILE_OFFSET     (6)
#define MAX_POWERUPS            (3)
#define POWERUP_PATTERN_COUNT   (12)

typedef struct {
    uint16_t x,y;
    uint8_t isactive;
    uint8_t activepattern;
    uint16_t framecount;
} powerup_t;  

extern powerup_t POWERUPS[MAX_POWERUPS];
extern uint8_t powerup_bounding_box[];
extern uint8_t oam;

void init_powerups(void);
void handle_powerups(void);
void add_powerup(uint8_t x, uint8_t y);
void draw_powerups(void);


#endif
