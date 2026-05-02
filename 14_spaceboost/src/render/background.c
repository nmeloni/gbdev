#include <gb/gb.h>
#include "background.h"
#include "constants.h"

Background BACKGROUND;

void init_background(void) {
    BACKGROUND.dx = 0;
    BACKGROUND.fx = 0;
    BACKGROUND.dy = BACKGROUND_SCROLL_SPEED_Y;
    BACKGROUND.fy = 0;
}

void scroll_background(void) {
    BACKGROUND.fx += BACKGROUND.dx;
    BACKGROUND.fy += BACKGROUND.dy;

    scroll_bkg(BACKGROUND.fx >> FRAC_SHIFT, BACKGROUND.fy >> FRAC_SHIFT);

    BACKGROUND.fx &= FRAC_MASK;
    BACKGROUND.fy &= FRAC_MASK;
}
