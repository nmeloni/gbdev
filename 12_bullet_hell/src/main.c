#include "global.h"

uint8_t current_joypad, previous_joypad;
uint8_t oam = 0;
uint16_t level_framecounter = 0;

void main(void){
    set_sprite_data(SPACESHIP_TILE_OFFSET, spaceship_sprite_TILE_COUNT, spaceship_sprite_tiles);
    set_sprite_data(ENEMYBULLET_TILE_OFFSET, enemybullet_sprite_TILE_COUNT, enemybullet_sprite_tiles);
    set_sprite_data(ENEMY_1_TILE_OFFSET, enemy_1_sprite_TILE_COUNT, enemy_1_sprite_tiles);

    
    OBP0_REG = DMG_PALETTE(DMG_DARK_GRAY,DMG_WHITE, DMG_LITE_GRAY,  DMG_BLACK); 
    SPRITES_8x16;
    SHOW_SPRITES;
    DISPLAY_ON;

    init_player();
    init_enemy_bullets();
    init_enemies();
    
    quadrant = 0;
    angle = 0;
    uint8_t enemy_spawn = 0;
    add_enemy(84, 20, 1, enemy_spawn, enemy_spawn);
    while(1) {
	// On attend la prochaine frame
        vsync();
	oam = 0;
	level_framecounter++;
	UPDATE_KEYS();

	if (level_framecounter % 256 == 0){
	    add_enemy(84, 20, 1, enemy_spawn, enemy_spawn);
	    enemy_spawn = (enemy_spawn + 1)%4;
	}

	handle_player();
	handle_enemies();
	handle_enemy_bullets();
	hide_sprites_range(oam,MAX_HARDWARE_SPRITES);
    }
}
