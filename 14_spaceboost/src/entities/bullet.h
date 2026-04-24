#ifndef BULLET_H
#define BULLET_H

#include <stdint.h>

#include "game_types.h"
#include "constants.h"

extern Bullet BULLETS_POOL[MAX_BULLETS];
extern uint8_t  ACTIVE_BULLETS[MAX_BULLETS];
extern uint8_t  active_bullet_count;

void init_bullets(void);
void fire_bullet(uint8_t type, uint8_t x, uint8_t y, int8_t dx, int8_t dy);
void update_bullets(void);

#endif // BULLET_H
