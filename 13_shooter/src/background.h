#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <gb/gb.h>
#include <stdint.h>

#include "game.h"
#include "gfx.h"

void init_background(void);
void scroll_background(void);

typedef struct {
    int8_t dx,fx;
    int8_t dy,fy;
} background_t;

extern background_t BACKGROUND;

#endif // BACKGROUND_H
