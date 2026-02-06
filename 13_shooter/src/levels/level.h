#ifndef LEVEL_H
#define LEVEL_H

#include <gb/gb.h>
#include <stdint.h>

#include "game.h"
#include "enemy.h"
#include "boss.h"
#include "patterns.h"
#include "bullet.h"
#include "powerup.h"

#include "level1.h"

enum enemy_spawn_list_types {
    ENEMY_1_DOWN_NO_SHOOT = 0,
    ENEMY_1_DOWN_FAST_NO_SHOOT ,
    ENEMY_1_STRAIGHT_SHOOT_DOWN ,
    ENEMY_2_ZIGZAG_SHOOT_AIMED ,
    ENEMY_2_LATERAL_SHOOT_CIRCULAR_RIGHT ,
    ENEMY_2_LATERAL_SHOOT_CIRCULAR_LEFT 
};

enum level_event_types {
	EVENT_NONE = 0,
	EVENT_INIT_LEVEL,
	EVENT_LEVEL_INTRO,
	EVENT_MOVE_PLAYER,
	EVENT_ACTIVATE_PLAYER,
	EVENT_SPAWN_ENEMY,
	EVENT_SPAWN_POWERUP_SHOT,
	EVENT_SPAWN_BOSS,
	EVENT_END_LEVEL
};

void load_level(uint8_t level_id);
void update_level(void);

extern const uint8_t  (*LEVEL_EVENTS)[5];
extern const uint8_t  (*ENEMY_SPAWN_LIST)[6];

#endif // LEVEL_H
