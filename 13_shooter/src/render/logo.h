#ifndef LOGO_H
#define LOGO_H

#include <gb/gb.h>

#include "game.h"
#include "logo_img.h"

#define LOGO_Y_START 80
#define LOGO_TILE_OFFSET 0x00

void init_logo(void);
void show_logo(void);

#endif
