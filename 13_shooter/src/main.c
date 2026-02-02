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
  
    
    game_init();
    // Activation des sprites
    PLAYER.shield = 1;
    while(1) {
	// On attend la prochaine frame
	vsync();
	// Mise à jour du jeu
	game_update();
	
    }
}
