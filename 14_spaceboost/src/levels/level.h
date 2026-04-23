#ifndef LEVEL_H
#define LEVEL_H

#include <stdint.h>

#include "boss.h"
#include "patterns.h"
#include "bullet.h"
#include "powerup.h"
#include "enemy.h"
#include "level1.h"

typedef enum {
    EVENT_NONE = 0,
    EVENT_INIT_LEVEL,
    EVENT_LEVEL_INTRO,
    EVENT_MOVE_PLAYER,
    EVENT_ACTIVATE_PLAYER,
    EVENT_SPAWN_ENEMY,
    EVENT_SPAWN_POWERUP_SHOT,
    EVENT_SPAWN_BOSS,
    EVENT_END_LEVEL
} level_event_type_t;

extern const uint8_t (*LEVEL_EVENTS)[5];
extern const uint8_t (*ENEMY_SPAWN_LIST)[6];

void load_level(uint8_t level_id);
void update_level(void);

#endif // LEVEL_H
