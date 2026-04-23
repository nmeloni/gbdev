#ifndef BULLET_H
#define BULLET_H

#include <stdint.h>
#include "game_types.h"
#include "constants.h"

typedef struct {
    body_t  body;
    uint8_t active;
} bullet_t;

extern bullet_t BULLETS_POOL[MAX_BULLETS];
extern uint8_t  ACTIVE_BULLETS[MAX_BULLETS];
extern uint8_t  active_bullet_count;

void    bullets_init(void);
void    bullets_update(void);

// O(1) grâce à la liste active
uint8_t bullets_get_active_count(void);

// Retourne 1 si une bullet touche le rectangle (px, py, w, h)
uint8_t bullets_check_collision(uint8_t px, uint8_t py, uint8_t w, uint8_t h);

#endif // BULLET_H
