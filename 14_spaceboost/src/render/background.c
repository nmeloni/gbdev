#include <gb/gb.h>
#include "background.h"
#include "constants.h"

background_t BACKGROUND;

void init_background(void) {
    BACKGROUND.dx = 0;
    BACKGROUND.fx = 0;
    BACKGROUND.dy = -2;
    BACKGROUND.fy = 0;
}

void scroll_background(void) {
    BACKGROUND.fx += BACKGROUND.dx;
    BACKGROUND.fy += BACKGROUND.dy;

    scroll_bkg(BACKGROUND.fx >> FRAC_SHIFT, BACKGROUND.fy >> FRAC_SHIFT);

    BACKGROUND.fx &= FRAC_MASK;
    BACKGROUND.fy &= FRAC_MASK;
}
