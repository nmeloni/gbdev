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
#define ENENY_2_TILE_OFFSET  (ENEMY_TILE_OFFSET + 8)
#define ENEMY_3_TILE_OFFSET  (ENEMY_TILE_OFFSET + 16)

#define SPRITE_FRAME_DURATION 8
#define SPRITE_FRAME_DURATION_LOG2 3

#define MAX_ENEMIES          8


enum enemy_type {
    ENEMY_TYPE_1,
    ENEMY_TYPE_2,
    ENEMY_TYPE_3
};

typedef struct {
    body_t body;
    uint8_t weapon;
    uint8_t active;
    uint8_t type;
    uint8_t move_pattern;
    uint8_t shoot_pattern;
    uint8_t move_activepattern;
    uint8_t shoot_activepattern;
    uint8_t move_framecounter;
    uint8_t shoot_framecounter;
    uint8_t frame_timer;
    int8_t hp;
    uint8_t ishit;
} enemy_t;

void init_enemies(void);
void add_enemy(uint8_t x, uint8_t y, uint8_t type, uint8_t weapon, uint8_t hp, uint8_t move_pattern, uint8_t shoot_pattern);
void update_enemies(void);


extern enemy_t ENEMY_POOL[MAX_ENEMIES];
extern uint8_t ACTIVE_ENEMY_POOL[MAX_ENEMIES];
extern uint8_t active_enemy_index;

#endif // ENEMY_H
