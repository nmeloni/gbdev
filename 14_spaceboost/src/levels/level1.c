#include "level1.h"
#include "level.h"
#include "constants.h"
#include "enemy.h"
#include "bullet.h"
#include "patterns.h"

// ─── Événements du niveau 1 ───────────────────────────────────────────────────
// Format : {frame_delay, event_type, param, x, y}
const uint8_t level_1_events[][5] = {
    {0,   EVENT_INIT_LEVEL,     0,  84u, 180u},
    {120, EVENT_LEVEL_INTRO,    0,  0,   0},
    {0,   EVENT_ACTIVATE_PLAYER,0,  0,   0},

    {20,  EVENT_SPAWN_ENEMY,    0,  40,  8},

    {240, EVENT_NONE,           0,  0,   0},
    {240, EVENT_NONE,           0,  0,   0},
    {240, EVENT_NONE,           0,  0,   0},

    {0,   EVENT_END_LEVEL,      0,  0,   0}
};

// ─── Liste de spawn ennemis ───────────────────────────────────────────────────
// Format : {type, hp, weapon, move_pattern, shoot_pattern, shoot_speed}
const uint8_t level_1_enemies[][6] = {
    {ENEMY_TYPE_1, 10, BULLET_TYPE_NONE,  MOVE_PATTERN_DOWN,   SHOOT_PATTERN_NONE,               SHOT_SPEED_SLOW},
    {ENEMY_TYPE_1, 10, BULLET_TYPE_LASER, MOVE_PATTERN_DOWN,   SHOOT_PATTERN_DOWN,               SHOT_SPEED_SLOW},
    {ENEMY_TYPE_2, 10, BULLET_TYPE_SMALL, MOVE_PATTERN_ZIGZAG, SHOOT_PATTERN_AIMED,              SHOT_SPEED_MEDIUM},
    {ENEMY_TYPE_3, 10, BULLET_TYPE_SMALL, MOVE_PATTERN_DOWN,   SHOOT_PATTERN_SEMI_CIRCULAR_RIGHT,SHOT_SPEED_MEDIUM},
    {ENEMY_TYPE_3, 10, BULLET_TYPE_SMALL, MOVE_PATTERN_DOWN,   SHOOT_PATTERN_SEMI_CIRCULAR_LEFT, SHOT_SPEED_MEDIUM}
};
