#include "constants.h"
#include "move_pattern.h"
#include "bullet_pattern.h"
#include "game_types.h"
#include "enemy_data.h"

#include "enemy_drone_sprite.h"
#include "enemy_scout_sprite.h"
#include "enemy_minion_sprite.h"
#include "enemy_sphere_sprite.h"
#include "enemy_probe_sprite.h"
#include "enemy_swarmer_sprite.h"
#include "enemy_rusher_sprite.h"

const static_manager_data enemy_pattern_data[] = {
    [ENEMY_DATA_DRONE_1] = {STATIC_PATTERN_TYPE_NONE, STATIC_PATTERN_TYPE_MOVE_DOWN, 0},
    [ENEMY_DATA_SCOUT_1] = {STATIC_PATTERN_TYPE_MOVE_LEFT, STATIC_PATTERN_TYPE_MOVE_DOWN},
    [ENEMY_DATA_SCOUT_2] = {STATIC_PATTERN_TYPE_MOVE_RIGHT, STATIC_PATTERN_TYPE_MOVE_DOWN}
};

const BulletPatternType bullet_pattern_data[] = {
    [ENEMY_DATA_DRONE_1] = BULLET_PATTERN_TYPE_NONE,
    [ENEMY_DATA_SCOUT_1] = BULLET_PATTERN_TYPE_SINGLE_DOWN,
    [ENEMY_DATA_SCOUT_2] = BULLET_PATTERN_TYPE_SINGLE_DOWN
};

const uint8_t enemy_hp[] = {
    [ENEMY_DATA_DRONE_1] = 5,
    [ENEMY_DATA_SCOUT_1] = 8,
    [ENEMY_DATA_SCOUT_2] = 8
};

const uint8_t enemy_speed[] = {
    [ENEMY_DATA_DRONE_1] = 0,
    [ENEMY_DATA_SCOUT_1] = 1,
    [ENEMY_DATA_SCOUT_2] = 1
};

const uint8_t enemy_bbox[][2] = {
    [ENEMY_DRONE]   = {8,8},
    [ENEMY_SCOUT]   = {8,8},
    [ENEMY_MINION]  = {8,8},
    [ENEMY_SPHERE]  = {8,8},
    [ENEMY_PROBE]   = {8,8},
    [ENEMY_SWARMER] = {8,8},
    [ENEMY_RUSHER]  = {8,8}
};

const const metasprite_t* const * enemy_metasprites[] = {
    enemy_drone_sprite_metasprites,
    enemy_scout_sprite_metasprites,
    enemy_minion_sprite_metasprites,
    enemy_sphere_sprite_metasprites,
    enemy_probe_sprite_metasprites,
    enemy_swarmer_sprite_metasprites,
    enemy_rusher_sprite_metasprites
};

const uint8_t enemy_tile_offset[]={
    [ENEMY_DRONE]   = ENEMY_1_TILE_OFFSET,
    [ENEMY_SCOUT]   = ENEMY_2_TILE_OFFSET,
    [ENEMY_MINION]  = ENEMY_3_TILE_OFFSET,
    [ENEMY_SPHERE]  = ENEMY_4_TILE_OFFSET,
    [ENEMY_PROBE]   = ENEMY_5_TILE_OFFSET,
    [ENEMY_SWARMER] = ENEMY_6_TILE_OFFSET,
    [ENEMY_RUSHER]  = ENEMY_7_TILE_OFFSET,
};
