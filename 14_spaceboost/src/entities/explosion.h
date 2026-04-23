#ifndef EXPLOSION_H
#define EXPLOSION_H

#include <stdint.h>

#include "game_types.h"
#include "constants.h"

extern Explosion EXPLOSION_QUEUE[MAX_EXPLOSIONS];

void init_explosions(void);
void add_explosion(uint8_t x, uint8_t y);
void update_explosions(void);

#endif // EXPLOSION_H
