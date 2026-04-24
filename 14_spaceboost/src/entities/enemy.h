#ifndef ENEMY_H
#define ENEMY_H

#include <stdint.h>

#include "game_types.h"
#include "constants.h"

extern Enemy ENEMY_POOL[MAX_ENEMIES];
extern uint8_t ACTIVE_ENEMY_POOL[MAX_ENEMIES];
extern uint8_t active_enemy_count;

void init_enemies(void);
void add_enemy(uint8_t x, uint8_t y, EnemyType type, uint8_t hp, uint8_t speed);
void update_enemies(void);

#endif // ENEMY_H
