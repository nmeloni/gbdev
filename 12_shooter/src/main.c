#include <gb/gb.h>
#include <stdint.h>

#include <gbdk/platform.h>
#include <gbdk/emu_debug.h>

#include "global.h"
#include "player.h"
#include "explosion.h"
#include "ennemybullet.h"

#include "space_bkg_map.h"
#include "early_gameboyfont.h"
#include "space_bkg_tileset.h"

uint8_t oam = 0;
uint16_t level_framecounter = 0;

const uint8_t white_tile[]={
    0x00,    0x00,    0x00,    0x00,
    0x00,    0x00,    0x00,    0x00,
    0x00,    0x00,    0x00,    0x00,
    0x00,    0x00,    0x00,    0x00
};
    
void main(void){
    //Initialisation des gfx
    uint8_t sprite_offset=0;
    set_sprite_data(SPACESHIP_TILE_OFFSET, spaceship_sprite_TILE_COUNT, spaceship_sprite_tiles);
    set_sprite_data(SHIELD_TILE_OFFSET, shield_sprite_TILE_COUNT, shield_sprite_tiles);
    set_sprite_data(BOOSTER_TILE_OFFSET, booster_sprite_TILE_COUNT, booster_sprite_tiles);
    
    set_sprite_data(BULLET_LVL1_TILE_OFFSET, bullet_lvl1_sprite_TILE_COUNT, bullet_lvl1_sprite_tiles);
    set_sprite_data(BULLET_LVL2_TILE_OFFSET, bullet_lvl2_sprite_TILE_COUNT, bullet_lvl2_sprite_tiles);
    set_sprite_data(BULLET_LVL3_TILE_OFFSET, bullet_lvl3_sprite_TILE_COUNT, bullet_lvl3_sprite_tiles);
    set_sprite_data(POWERUP_TILE_OFFSET, powerup_sprite_TILE_COUNT, powerup_sprite_tiles);
    set_sprite_data(EXPLOSION_TILE_OFFSET, explosion_sprite_TILE_COUNT, explosion_sprite_tiles);

    set_sprite_data(ENNEMY_1_TILE_OFFSET, ennemy_1_sprite_TILE_COUNT, ennemy_1_sprite_tiles);
    set_sprite_data(ENNEMY_2_TILE_OFFSET, ennemy_2_sprite_TILE_COUNT, ennemy_2_sprite_tiles);
    set_sprite_data(ENNEMY_3_TILE_OFFSET, ennemy_3_sprite_TILE_COUNT, ennemy_3_sprite_tiles);
    set_sprite_data(ENNEMYBULLET_TILE_OFFSET, ennemybullet_sprite_TILE_COUNT, ennemybullet_sprite_tiles);
    set_sprite_data(ENNEMYLARGEBULLET_TILE_OFFSET, ennemylargebullet_sprite_TILE_COUNT, ennemylargebullet_sprite_tiles);
    set_sprite_data(ENNEMYLASER_TILE_OFFSET, ennemylaser_sprite_TILE_COUNT, ennemylaser_sprite_tiles);
    
    //set_bkg_data(0x0, space_bkg_tileset_TILE_COUNT, space_bkg_tileset_tiles);
    //set_bkg_tiles(0, 0, 20, 32, space_bkg_map_map);

    set_bkg_data(0X80, early_gameboyfont_TILE_COUNT, early_gameboyfont_tiles);
    
    fill_win_rect( 0,0,20,4,0x80);

    /*
    uint8_t * vramaddress = get_win_xy_addr( 1, 0);
    set_vram_byte(vramaddress++, 0x81+('s'-'a'));
    set_vram_byte(vramaddress++, 0x81+('c'-'a'));
    set_vram_byte(vramaddress++, 0x81+('o'-'a'));
    set_vram_byte(vramaddress++, 0x81+('r'-'a'));
    set_vram_byte(vramaddress++, 0x81+('e'-'a'));
    set_vram_byte(vramaddress++, 0xA4);
    for (uint8_t i; i<8;i++)    set_vram_byte(vramaddress++, 0x81+('o'-'a'));
    vramaddress++;
    set_vram_byte(vramaddress++, 0xA8);
    set_vram_byte(vramaddress++, 0xA7);
    set_vram_byte(vramaddress++, 0x9D);
    */
    
    move_win(8,17*8);
    
    
    BGP_REG = DMG_PALETTE(DMG_WHITE, DMG_LITE_GRAY, DMG_DARK_GRAY, DMG_BLACK);
    OBP0_REG = DMG_PALETTE(DMG_DARK_GRAY,DMG_WHITE, DMG_LITE_GRAY,  DMG_BLACK); 
    OBP1_REG = DMG_PALETTE(DMG_WHITE, DMG_LITE_GRAY, DMG_LITE_GRAY, DMG_LITE_GRAY); 
    
    //int8_t ix,iy;
    uint8_t spi=0,spx,spy;
    const uint8_t starting_points[16][2]= {
	{0,0}, {0,32}, {0,64}, {0,128},
	{0,144}, {32,0}, {64,0}, {96,0},
	{128,0}, {144,0},{168,32}, {168,64},
	{168,128}, {32,160}, {96,160}, {128,160} 
    };
    SPRITES_8x16;
    SHOW_SPRITES;
    SHOW_BKG;
    SHOW_WIN;
    DISPLAY_ON;
    
    init_player();
    init_enemies();
    init_ennemy_bullets();
    while(1) {
	// On attend la prochaine frame
        vsync();

	oam = 0;
	level_framecounter++;
	// Mise à jour des entrées
	UPDATE_KEYS();
	if (KEY_RELEASED(J_START)){
	    //add_ennemy(120,16,ENNEMY_1, 1, 1<<6, 1);
	    //add_ennemy(20,16,ENNEMY_2, 2, 1<<6, 2);
	    add_ennemy(80,16,ENNEMY_3, 3, 1<<6, 3);
	    //EMU_printf("position: %d, %d\n",  PLAYER.px, PLAYER.column);
	}
	if (KEY_RELEASED(J_SELECT)){
	    add_powerup(80,10, 0);
	    //add_exploision(80,80);
	}
	    
	//Gestion du niveau

	/*
	spx = starting_points[spi][0];
	if (level_framecounter % 8 == 0){
	    spi = (spi+7)%16;
	    spx = starting_points[spi][0];
	    spy = starting_points[spi][1];
	    aim_at_player(spx,spy);
	    add_ennemy_bullet(spx,spy,
			      dir16_vx[quadrant][angle]<<2,
			      dir16_vy[quadrant][angle]<<2);
			      }
	*/
	
	//level_events();
	//Gestion des ennemis
	
	handle_player();
	handle_ennemies();
	handle_explosions();
	handle_ennemy_bullets();
	handle_bullets();
	handle_powerup();
	//Physique
	//handle_collisions();
	
	//Affichage
	draw_player();
	//if (level_framecounter%8 == 0) scroll_bkg(0,-1);
	
	//On cache les sprites non utilisés
	hide_sprites_range(oam,MAX_HARDWARE_SPRITES);
    }
    
}

