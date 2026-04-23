#ifndef BULLET_H
#define BULLET_H

#include <stdint.h>

#include "game_types.h"
#include "constants.h"

#define BULLET_SPRITE_X_OFFSET  (-4)
#define BULLET_SPRITE_Y_OFFSET  (-8)

typedef enum {
    BULLET_TYPE_NONE  = 255,
    BULLET_TYPE_SMALL = 0,
    BULLET_TYPE_LARGE = 1,
    BULLET_TYPE_LASER = 2
} bullet_type_t;

typedef struct {
    uint8_t active;
    uint8_t type;
    Body    body;
} bullet_t;

extern bullet_t BULLETS_POOL[MAX_BULLETS];
extern uint8_t  ACTIVE_BULLETS[MAX_BULLETS];
extern uint8_t  active_bullet_index;

void init_bullets(void);
void fire_bullet(uint8_t type, uint8_t x, uint8_t y, int8_t dx, int8_t dy);
void update_bullets(void);

#endif // BULLET_H
