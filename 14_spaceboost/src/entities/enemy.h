#ifndef ENEMY_H
#define ENEMY_H

#include <stdint.h>

#include "game_types.h"
#include "constants.h"

extern Enemy ENEMY_POOL[MAX_ENEMIES];
extern uint8_t ACTIVE_ENEMY_POOL[MAX_ENEMIES];
extern uint8_t active_enemy_count;
extern const BulletPatternType bullet_pattern_data[];

void init_enemies(void);
void add_enemy(uint8_t x, uint8_t y, EnemyType type, EnemyDataType data_type,
	       uint8_t hp, uint8_t speed, PowerUpType powerup);
void update_enemies(void);

#endif // ENEMY_H
