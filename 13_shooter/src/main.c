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
    init_powerup();
    init_background();

    game_init();
    // Activation des sprites
    SHOW_SPRITES;
    SHOW_BKG;

    PLAYER.shield = 1;
    add_enemy(80, 20, ENEMY_TYPE_1, 3, MOVE_PATTERN_STRAIGHT, SHOOT_PATTERN_AIMED);
    while(1) {
	// On attend la prochaine frame
	vsync();
	if (KEY_RELEASED(J_START)){
	    add_enemy(80, 20, ENEMY_TYPE_1, 3, MOVE_PATTERN_STRAIGHT, SHOOT_PATTERN_AIMED);
	}
	if (KEY_RELEASED(J_SELECT)){
	    spawn_powerup(POWERUP_TYPE_POWER_UP, 80, 20);
	}
	// Mise à jour du jeu
	game_update();
	
    }
}
