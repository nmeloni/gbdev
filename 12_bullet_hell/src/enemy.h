#ifndef ENEMY_H
#define ENEMY_H

#include "global.h"
#include "enemy_1_sprite.h"

#define ENEMY_1_TILE_OFFSET             (64)
#define ENEMY_PATTERN_MOVE_DOWN_SLOW    (0)
#define ENEMY_PATTERN_MOVE_ZIGZAG       (1)
#define ENEMY_PATTERN_MOVE_LATERAL      (2)
#define MAX_ENEMIES                     (8)

typedef struct {
    uint8_t x, y, px, py;
    int8_t dx, dy, fx, fy;
    uint8_t isactive;
    uint8_t type;
    uint8_t move_pattern;
    uint8_t shoot_pattern;
    uint8_t move_activepattern;
    uint8_t shoot_activepattern;
    uint8_t move_framecounter;
    uint8_t shoot_framecounter;
    uint8_t hp;
    uint8_t ishit;
} enemy_t;

void init_enemies(void);
void add_enemy(uint8_t x, uint8_t y, uint8_t type, uint8_t move_pattern, uint8_t shoot_pattern);
void handle_enemies(void);
void kill_active_enemy(uint8_t j);

extern enemy_t ENEMY_POOL[MAX_ENEMIES];
extern uint8_t ACTIVE_ENEMY_POOL[MAX_ENEMIES];

#endif // ENEMY_H
