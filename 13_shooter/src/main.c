#include <gb/gb.h>
#include <stdint.h>
#include <gbdk/platform.h>
#include <gbdk/metasprites.h>
#include <gbdk/emu_debug.h>

#include "game.h"
#include "utils.h"
#include "input.h"
#include "player.h"
#include "shot.h"
#include "background.h"
#include "gfx.h"

void main(void){
    // Initialisation du jeu
    gfx_init();
    init_player();
    init_shots();
    init_background();
    init_bullets();
    init_enemies();
    
    game_init();
    // Activation des sprites
    SHOW_SPRITES;

    add_enemy(81, 16, ENEMY_TYPE_1, 12, MOVE_PATTERN_STRAIGHT, SHOOT_PATTERN_AIMED);
    
    while(1) {
	// On attend la prochaine frame
	vsync();
	// Mise à jour du jeu
	game_update();

    }
}
