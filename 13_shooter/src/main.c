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
#include "enemy.h"
#include "bullet.h"
#include "powerup.h"
#include "explosion.h"
#include "level.h"

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
    init_explosions();
    init_level(level_demo_events);
    
    game_init();
    // Activation des sprites
    SHOW_SPRITES;
    SHOW_BKG;

    PLAYER.shield = 1;
    while(1) {
	// On attend la prochaine frame
	vsync();
	// Mise à jour du jeu
	game_update();
	
    }
}
