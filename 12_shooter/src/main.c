#include <gb/gb.h>
#include <stdint.h>

#include <gbdk/platform.h>
#include <gbdk/emu_debug.h>

#include "player.h"
#include "ennemybullet.h"

uint8_t oam = 0;
uint16_t level_framecounter = 0;
uint16_t level_next_event = 0;

#define LEVEL_EVENT_COUNT 3

const uint8_t level[LEVEL_EVENT_COUNT][4] = {
    {60,80,0,ENNEMY_1},
    {60,80,0,ENNEMY_1},
    {60,80,0,ENNEMY_1}
};

void level_events(void);

void main(void){
    //Initialisation des gfx
    set_sprite_data(SPACESHIP_TILE_OFFSET, spaceship_sprite_TILE_COUNT, spaceship_sprite_tiles);
    set_sprite_data(ENNEMYBULLET_TILE_OFFSET, ennemybullet_sprite_TILE_COUNT, ennemybullet_sprite_tiles);    
    set_sprite_data(BULLET_TILE_OFFSET, bullet_sprite_TILE_COUNT, bullet_sprite_tiles);
    set_sprite_data(POWERUP_TILE_OFFSET, powerup_sprite_TILE_COUNT, powerup_sprite_tiles);
    //set_sprite_data(ENNEMY_1_TILE_OFFSET, ennemy16x16_sprite_TILE_COUNT, ennemy16x16_sprite_tiles);
    
    //int8_t ix,iy;
    uint8_t spi = 0,spx,spy;
    const uint8_t starting_points[16][2]= {
	{0,0}, {0,32}, {0,64}, {0,128},
	{0,144}, {32,0}, {64,0}, {96,0},
	{128,0}, {144,0},{168,32}, {168,64},
	{168,128}, {32,160}, {96,160}, {128,160}
    };
    SPRITES_8x8;
    SHOW_SPRITES;
    DISPLAY_ON;
    
    init_player();
    init_ennemy_bullets();
    while(1) {
	// On attend la prochaine frame
        vsync();
	oam = 0;
	level_framecounter++;
	// Mise à jour des entrées
	UPDATE_KEYS();
	if (KEY_RELEASED(J_START)){
	    RESET_PLAYER();
	}
	if (KEY_RELEASED(J_SELECT)){
	    add_powerup(80,10,POWERUP_FLAG_POWER_UP);
	}
	    
	//Gestion du niveau
	
	if (level_framecounter % 16 == 0){
	    spi = (spi+7)%16;
	    spx = starting_points[spi][0];
	    spy = starting_points[spi][1];
	    aim_at_player(spx,spy);
	    add_ennemy_bullet(spx,spy,
			      dir16_vx[quadrant][angle]<<2,
			      dir16_vy[quadrant][angle]<<2);
			      }

	//level_events();
	//Gestion des ennemis
	//handle_ennemies();
	handle_player();
	handle_ennemy_bullets();
	handle_bullets();
	handle_powerup();
	//Physique
	//handle_collisions();
	
	//Affichage
	draw_player();
	//draw_bullets();
	//draw_powerups();
	//draw_ennemies();
	//On cache les sprites non utilisés
	hide_sprites_range(oam,MAX_HARDWARE_SPRITES);
    }
    
}

void level_events(void){
    level_framecounter++;
    if (level_next_event >= LEVEL_EVENT_COUNT) return;
    if (level_framecounter == level[level_next_event][0]){
	add_ennemy(level[level_next_event][1],
		    level[level_next_event][2],
		    level[level_next_event][3]);
	level_framecounter = 0;
	level_next_event++;
    } 
    
}
