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


#endif // BULLET_H
