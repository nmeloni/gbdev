#include "powerup.h"
// Stub Phase 1 — implémentation complète en Phase 5

powerup_t POWERUP;

void init_powerup(void)  { POWERUP.active = 0; }
void spawn_powerup(uint8_t type, uint8_t x, uint8_t y) { (void)type; (void)x; (void)y; }
void update_powerup(void) {}
