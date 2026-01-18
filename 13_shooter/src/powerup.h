#ifndef POWERUP_H
#define POWERUP_H

#include <gb/gb.h>
#include <stdint.h>
#include <gbdk/metasprites.h>
#include "game.h"
#include "player.h"
#include "utils.h"
#include "patterns.h"
#include "powerup_sprite.h"

#define POWERUP_TILE_OFFSET        0x30
#define POWERUP_SHIELD_TILE_OFFSET (POWERUP_TILE_OFFSET + 4)
#define POWERUP_EXTRA_LIFE_TILE_OFFSET (POWERUP_TILE_OFFSET + 8)


#define POWERUP_TYPE_SHIELD        (1)
#define POWERUP_TYPE_EXTRA_LIFE    (2)
#define POWERUP_TYPE_POWER_UP      (0)

#define POWERUP_PATTERN_COUNT      (12)

typedef struct {
    uint8_t active;
    uint8_t x, y;
    int8_t dx, dy;
    int8_t fx, fy;
    uint8_t move_pattern;
    uint8_t move_activepattern;
    uint8_t move_framecounter;
    uint8_t type;
} powerup_t;

extern powerup_t POWERUP;
void init_powerup(void);
void spawn_powerup(uint8_t type, uint8_t x, uint8_t y);
void update_powerup(void);
#endif // POWERUP_H

