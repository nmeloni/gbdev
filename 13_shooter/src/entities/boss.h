#ifndef BOSS_H
#define BOSS_H

#include <gb/gb.h>
#include <gbdk/metasprites.h>
#include <stdint.h>

#include "level.h"
#include "game.h"
#include "body.h"

#include "mini_boss_1_sprite.h"
#include "mini_boss_2_sprite.h"

#define BOSS_GAMESCREEN_X_START  (80u)
#define BOSS_GAMESCREEN_Y_START  (48u)

#define BOSS_MIN_X  (16u)
#define BOSS_MAX_X  (160u)
#define BOSS_MIN_Y  (16u)
#define BOSS_MAX_Y  (144u)

#define BOSS_TILE_OFFSET 0x60
#define BOSS_FLAG_ENTERING 1u
#define BOSS_FLAG_HITTABLE 2u
#define BOSS_FLAG_PHASE_1  16u
#define BOSS_FLAG_PHASE_2  32u
#define BOSS_FLAG_PHASE_3  64u
#define BOSS_FLAG_DEFEATED 128u

#define BOSS_PATTERN_TIME_TRIGGER     1u
#define BOSS_PATTERN_REPEAT_TRIGGER   2u
#define BOSS_PATTERN_HEALTH_TRIGGER   4u
#define BOSS_PATTERN_DESTROY          8u


enum boss_ids {
    MINI_BOSS_1 = 0,
    MINI_BOSS_2
};

typedef struct {
    uint8_t active;
    uint8_t flag;
    uint8_t ishit;
    int16_t hp;
    body_t body;

    uint8_t current_pattern;
    uint8_t current_move_pattern;
    uint8_t current_shoot_pattern;
    uint8_t current_pattern_trigger;
    uint8_t pattern_framecounter;
    
    uint8_t move_framecounter;
    uint8_t move_activepattern;
    uint8_t nb_move_patterns;

    uint8_t shoot_framecounter;
    uint8_t shoot_pattern_speed;
    uint8_t shoot_activepattern;
    const uint8_t * weapons;
    const uint8_t (* move_patterns)[4];
    const  metasprite_t * const * metasprites;
} boss_t;

void init_boss(void);
void spawn_boss(uint8_t boss_id, uint8_t x, uint8_t y);
void update_boss(void);

extern boss_t BOSS;


#endif // BOSS_H
