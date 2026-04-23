#ifndef EXPLOSION_H
#define EXPLOSION_H

#include <stdint.h>
#include "constants.h"

typedef struct {
    uint8_t x;
    uint8_t y;
    uint8_t frame_counter;
} explosion_t;

extern explosion_t EXPLOSION_QUEUE[MAX_EXPLOSIONS];

void init_explosions(void);
void add_explosion(uint8_t x, uint8_t y);
void update_explosions(void);

#endif // EXPLOSION_H
