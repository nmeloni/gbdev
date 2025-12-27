#ifndef POWERUP_H
#define POWERUP_H

#include <gb/gb.h>
#include <stdint.h>

#include <gbdk/platform.h>
#include <gbdk/metasprites.h>
#include <gbdk/emu_debug.h>

#include "player.h"
#include "powerup_sprite.h"

#define POWERUP_TYPE_SHIELD        (1)
#define POWERUP_TYPE_EXTRA_LIFE    (2)
#define POWERUP_TYPE_POWER_UP      (0)
#define POWERUP_TILE_OFFSET        (32)
#define POWERUP_PATTERN_COUNT      (12)

typedef struct {
    uint16_t x,y;
    uint8_t px,py;
    uint8_t type;
    uint8_t isactive;
    uint8_t activepattern;
    uint16_t framecount;
} powerup_t;  

extern powerup_t POWERUP;
extern uint16_t level_framecounter;
extern uint8_t oam;

void handle_powerup(void);
void add_powerup(uint8_t x, uint8_t y, uint8_t flag);

#endif
