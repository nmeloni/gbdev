#include <gb/gb.h>
#include <stdint.h>

#include <gbdk/platform.h>
#include <gbdk/emu_debug.h>

#include "player.h"
#include "ennemy.h"


uint8_t oam = 0;
uint16_t level_framecounter = 0;
uint16_t level_next_event = 0;
uint8_t level[][4] = {
    {1,80,0,ENNEMY_1},
    {2,80,0,ENNEMY_1},
    {3,80,0,ENNEMY_1},

    {8,80,0,ENNEMY_1},
    {9,80,0,ENNEMY_1},
    {10,80,0,ENNEMY_1},

};
void level_events(void);

void main(void){
    //Initialisation des gfx
    set_sprite_data(SPACESHIP_TILE_OFFSET, spaceship_sprite_TILE_COUNT, spaceship_sprite_tiles);
    set_sprite_data(BULLET_TILE_OFFSET, bullet_sprite_TILE_COUNT, bullet_sprite_tiles
	);
    set_sprite_data(POWERUP_TILE_OFFSET, powerup_sprite_TILE_COUNT, powerup_sprite_tiles
	);

    SPRITES_8x8;
    SHOW_SPRITES;
    DISPLAY_ON;
    
    init_player();
    while(1) {
	// On attend la prochaine frame
        vsync();
	oam = 0;
	// Mise à jour des entrées
	UPDATE_KEYS();
	if (KEY_RELEASED(J_SELECT)){
	    add_powerup(80,10);
	}
	//Mouvements
	handle_player();
	handle_bullets();
	handle_powerups();
	//Physique
	handle_collisions();
	
	//Affichage
	draw_player();
	draw_bullets();
	draw_powerups();
	
	hide_sprites_range(oam,MAX_HARDWARE_SPRITES);
    }
    
}

void level_events(void){
    level_framecounter++;
    if (level_framecounter == level_events[level_next_event][0]){
	add_ennemy(
	level_next_event++;
    }
}
