#include "bullet.h"
// Stub Phase 1 — implémentation complète en Phase 3

bullet_t BULLETS_POOL[MAX_BULLETS];
uint8_t  ACTIVE_BULLETS[MAX_BULLETS];
uint8_t  active_bullet_index = 0;

void init_bullets(void)  {}
void fire_bullet(uint8_t type, uint8_t x, uint8_t y, int8_t dx, int8_t dy) {
    (void)type; (void)x; (void)y; (void)dx; (void)dy;
}
void update_bullets(void) {}
