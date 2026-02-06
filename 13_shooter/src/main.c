#include <gb/gb.h>

#include "game.h"

void main(void){
    // Initialisation du jeu
    game_init();
    while(1) {
	// On attend la prochaine frame
	vsync();
	// Mise à jour du jeu
	game_update();
    }
}
