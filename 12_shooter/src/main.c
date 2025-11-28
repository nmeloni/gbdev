#include <gb/gb.h>
#include <stdint.h>

#include <gbdk/platform.h>
#include <gbdk/metasprites.h>
#include <gbdk/emu_debug.h>

#include "spaceship.h"
#include "rock8x8.h"

#define SPACESHIP_TILE_OFFSET 0
#define ROCK8x8_TILE_OFFSET (SPACESHIP_TILE_OFFSET+spaceship_TILE_COUNT)

#define UPDATE_KEYS()   previous_joypad = current_joypad; current_joypad = joypad()
#define KEY_PRESSED(K)  (current_joypad & (K))
uint8_t current_joypad, previous_joypad;

typedef struct {
    uint8_t x,y;
    int8_t const * bounding_boxes;
    metasprite_t * const * sprites;
} spaceship;

typedef struct {
    uint8_t x,y;
    int8_t const * bounding_boxes;
    metasprite_t * const * sprites; 
} rock;

void init_gfx(void) {
    set_sprite_data(SPACESHIP_TILE_OFFSET, spaceship_TILE_COUNT, spaceship_tiles);
    set_sprite_data(ROCK8x8_TILE_OFFSET, rock8x8_TILE_COUNT, rock8x8_tiles);
    SPRITES_8x8;
    SHOW_SPRITES;
    DISPLAY_ON;
}

spaceship PLAYER;
rock ROCKS[4];

uint8_t ssbbox[] = {0,0,16,16};
uint8_t rockbbox[] = {0,0,8,8};

void init_player(void) {
    PLAYER.x = 120;
    PLAYER.y = 140;
    PLAYER.bounding_boxes = ssbbox;
    PLAYER.sprites = spaceship_metasprites;
}

void init_rocks(void){
    for (int i=0; i<4; i++){
	ROCKS[i].x = 10+i*40;
	ROCKS[i].y = i*20;
	ROCKS[i].bounding_boxes=rockbbox;
	ROCKS[i].sprites = rock8x8_metasprites;
    }
}

int oam;

void main(void){
    init_gfx();
    init_player();
    init_rocks();
    
    while(1) {
	// On attend la prochaine frame
	OBP0_REG = DMG_PALETTE(DMG_DARK_GRAY, DMG_WHITE, DMG_LITE_GRAY, DMG_BLACK); 
        vsync();

	// Mise à jour des entrées
	UPDATE_KEYS();
	// Déplacement de l'entité carti en fonction des entrées
	
	if (KEY_PRESSED(J_LEFT)) {
	    PLAYER.x -=1;
	}
	if (KEY_PRESSED(J_RIGHT)) {
	    PLAYER.x += 1;
	}
	//OBP0_REG = DMG_PALETTE(DMG_WHITE, DMG_LITE_GRAY, DMG_DARK_GRAY, DMG_BLACK);
	for (int8_t i=0; i<4;i++){
	    ROCKS[i].y+=i+1;
	}
	
	move_metasprite_ex(PLAYER.sprites[0],0,0,0,PLAYER.x, PLAYER.y);
	for (int8_t i=0; i<4; i++){
	    move_metasprite_ex(ROCKS[i].sprites[0],4,0,4+i,ROCKS[i].x, ROCKS[i].y);
	}
	
    }
}
