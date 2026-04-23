#include <gb/gb.h>
#include "game.h"

void main(void) {
    game_init();
    while (1) {
        vsync();
        game_update();
    }
}
