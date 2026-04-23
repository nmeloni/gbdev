#include "explosion.h"
// Stub Phase 1 — implémentation complète en Phase 4

explosion_t EXPLOSION_QUEUE[MAX_EXPLOSIONS];

void init_explosions(void) {
    uint8_t i;
    for (i = 0; i < MAX_EXPLOSIONS; i++) {
        EXPLOSION_QUEUE[i].frame_counter = 0;
    }
}

void add_explosion(uint8_t x, uint8_t y) { (void)x; (void)y; }
void update_explosions(void) {}
