#ifndef ENEMY_H
#define ENEMY_H


#include <gb/gb.h>
#include <stdint.h>
#include <gbdk/metasprites.h>

#include "body.h"
#include "game.h"
#include "player.h"
#include "shot.h"
#include "utils.h"
#include "bullet.h"
#include "patterns.h"

#include "enemy_1_sprite.h"


#define HIT_FLASH_DURATION      6
#define ENEMY_TILE_OFFSET    0x40
#define ENEMY_1_TILE_OFFSET  ENEMY_TILE_OFFSET

#define MAX_ENEMIES          8


enum enemy_type {
    ENEMY_TYPE_1,
};

typedef struct {
    body_t body;
    uint8_t active;
    uint8_t type;
    uint8_t move_pattern;
    uint8_t shoot_pattern;
    uint8_t move_activepattern;
    uint8_t shoot_activepattern;
    uint8_t move_framecounter;
    uint8_t shoot_framecounter;
    int8_t hp;
    uint8_t ishit;
} enemy_t;

void init_enemies(void);
void add_enemy(uint8_t x, uint8_t y, uint8_t type, uint8_t hp, uint8_t move_pattern, uint8_t shoot_pattern);
void update_enemies(void);


extern enemy_t ENEMY_POOL[MAX_ENEMIES];
extern uint8_t ACTIVE_ENEMY_POOL[MAX_ENEMIES];
extern uint8_t active_enemy_index;

#endif // ENEMY_H
