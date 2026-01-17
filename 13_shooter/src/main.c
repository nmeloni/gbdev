#include <gb/gb.h>
#include <stdint.h>
#include <gbdk/platform.h>
#include <gbdk/metasprites.h>
#include <gbdk/emu_debug.h>

uint8_t oam; // OAM index

void main(void){
    while(1) {
	// Boucle principale

	// On attend la prochaine frame
	vsync();
	oam = 0;

	
	
	// On cache les sprites non utilises	
	hide_sprites_range(oam,MAX_HARDWARE_SPRITES);
    }
}
