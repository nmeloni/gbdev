#ifndef LEVEL_H
#define LEVEL_H

#include <gb/gb.h>
#include <stdint.h>

#include "game.h"
#include "enemy.h"
#include "patterns.h"
#include "bullet.h"
#include "powerup.h"

enum enemy_spawn_list_types {
    ENEMY_1_DOWN_NO_SHOOT = 0,
    ENEMY_1_DOWN_FAST_NO_SHOOT ,
    ENEMY_1_STRAIGHT_SHOOT_DOWN ,
    ENEMY_2_ZIGZAG_SHOOT_AIMED ,
    ENEMY_2_LATERAL_SHOOT_CIRCULAR_RIGHT ,
    ENEMY_2_LATERAL_SHOOT_CIRCULAR_LEFT ,
    ENEMY_MINI_BOSS_1_DOWN_SHOOT_AIMED
};

#define EVENT_NONE                0
#define EVENT_SPAWN_ENEMY         1
#define EVENT_SPAWN_POWERUP_SHOT  2
#define EVENT_END_LEVEL    255

void init_level(const uint8_t  (*level_events)[5]);
void update_level(void);

extern const uint8_t  (*LEVEL_EVENTS)[5];
extern const uint8_t level_demo_events[][5];

#endif // LEVEL_H
