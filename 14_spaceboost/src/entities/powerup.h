#ifndef POWERUP_H
#define POWERUP_H

#include <stdint.h>

#include "game_types.h"
#include "constants.h"

#define POWERUP_TYPE_SHOT       0
#define POWERUP_TYPE_SHIELD     1
#define POWERUP_TYPE_EXTRA_LIFE 2

// Sprite tile offsets pour les 3 types de powerup
#define POWERUP_SHOT_TILE_OFFSET       (POWERUP_TILE_OFFSET)
#define POWERUP_SHIELD_TILE_OFFSET     (POWERUP_TILE_OFFSET + 4)
#define POWERUP_EXTRA_LIFE_TILE_OFFSET (POWERUP_TILE_OFFSET + 8)

typedef struct {
    Body  body;
    uint8_t active;
    uint8_t type;
    uint8_t move_pattern;
    uint8_t move_activepattern;
    uint8_t move_framecounter;
} powerup_t;

extern powerup_t POWERUP;

void init_powerup(void);
void spawn_powerup(uint8_t type, uint8_t x, uint8_t y);
void update_powerup(void);

#endif // POWERUP_H
