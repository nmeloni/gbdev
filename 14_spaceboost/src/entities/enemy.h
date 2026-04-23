#ifndef ENEMY_H
#define ENEMY_H

#include <gb/gb.h>
#include <stdint.h>
#include <gbdk/metasprites.h>

#include "game_types.h"
#include "constants.h"

// Marges de détection hors-écran (permet de sortir légèrement)
#define ENEMY_X_MARGIN  4u
#define ENEMY_Y_MARGIN  8u

#define SPRITE_FRAME_DURATION      8u
#define SPRITE_FRAME_DURATION_LOG2 3u

typedef enum {
    ENEMY_TYPE_1,
    ENEMY_TYPE_2,
    ENEMY_TYPE_3,
    ENEMY_TYPE_MINI_BOSS_1
} enemy_type_t;

typedef struct {
    Body    body;
    uint8_t active;
    uint8_t type;
    uint8_t weapon;
    uint8_t move_pattern;
    uint8_t shoot_pattern;
    uint8_t shoot_pattern_speed;
    uint8_t move_activepattern;
    uint8_t shoot_activepattern;
    uint8_t move_framecounter;
    uint8_t shoot_framecounter;
    uint8_t frame_timer;
    int8_t  hp;
    uint8_t ishit;
} enemy_t;

extern enemy_t ENEMY_POOL[MAX_ENEMIES];
extern uint8_t ACTIVE_ENEMY_POOL[MAX_ENEMIES];
extern uint8_t active_enemy_index;

void init_enemies(void);
void add_enemy(uint8_t x, uint8_t y, uint8_t type, uint8_t weapon, uint8_t hp,
               uint8_t move_pattern, uint8_t shoot_pattern, uint8_t shoot_pattern_speed);
void update_enemies(void);

#endif // ENEMY_H
