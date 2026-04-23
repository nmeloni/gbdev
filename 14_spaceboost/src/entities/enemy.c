#include "enemy.h"
// Stub Phase 1 — implémentation complète en Phase 3

enemy_t ENEMY_POOL[MAX_ENEMIES];
uint8_t ACTIVE_ENEMY_POOL[MAX_ENEMIES];
uint8_t active_enemy_index = 0;

void init_enemies(void) {}
void add_enemy(uint8_t x, uint8_t y, uint8_t type, uint8_t weapon, uint8_t hp,
               uint8_t move_pattern, uint8_t shoot_pattern, uint8_t shoot_pattern_speed) {
    (void)x; (void)y; (void)type; (void)weapon; (void)hp;
    (void)move_pattern; (void)shoot_pattern; (void)shoot_pattern_speed;
}
void update_enemies(void) {}
