#include <gb/gb.h>
#include <stdint.h>

#include <gbdk/platform.h>
#include <gbdk/metasprites.h>
#include <gbdk/emu_debug.h>

#include "spaceship.h"


#define UPDATE_KEYS()   previous_joypad = current_joypad; current_joypad = joypad()
#define KEY_PRESSED(K)  (current_joypad & (K))
uint8_t current_joypad, previous_joypad;

void init_gfx(void) {
    //set_sprite_data(_TILE_OFFSET, _TILE_COUNT, _tiles);
    SPRITES_8x16;
    SHOW_SPRITES;
    DISPLAY_ON;
}

void main(void){
    init_gfx();
    
    while(1) {
	// On attend la prochaine frame
        vsync();

	// Mise à jour des entrées
	UPDATE_KEYS();
	// Déplacement de l'entité carti en fonction des entrées
	
	if (KEY_PRESSED(J_LEFT)) {
	    
	}
	if (KEY_PRESSED(J_RIGHT)) {
	    
	}
	if (KEY_PRESSED(J_UP)) {
	    
	}
	if (KEY_PRESSED(J_DOWN)) {
	    
	}
    }
}
