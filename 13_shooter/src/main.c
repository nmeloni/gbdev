#include <gb/gb.h>
#include <stdint.h>
#include <gbdk/platform.h>
#include <gbdk/metasprites.h>
#include <gbdk/emu_debug.h>

#include "game.h"
#include "input.h"
#include "player.h"
#include "shot.h"
#include "background.h"
#include "gfx.h"

void main(void){
    // Initialisation du jeu
    gfx_init();
    game_init();
    init_player();
    init_shots();
    init_background();
    
    // Activation des sprites
    SHOW_SPRITES;
    
    while(1) {
	// On attend la prochaine frame
	vsync();
	// Mise à jour du jeu
	game_update();

    }
}
