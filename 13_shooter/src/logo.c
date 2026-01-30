#include "logo.h"

uint8_t logo_y;

void init_logo(void){
    frame_counter = 600;
    logo_y = 80;
    set_bkg_data(0, melstudio_TILE_COUNT, melstudio_tiles);
    uint8_t x, y;

    for(y = 0; y < 18; y++) {
        for(x = 0; x < 20; x++) {
            set_bkg_tiles(x, y, 1, 1, 0);
        }
    }
    set_bkg_tiles(0,0,20,4,melstudio_map);
    
    move_bkg(0,logo_y);
    BGP_REG = 0xE4;
    SHOW_BKG;
}

void show_logo(void){
    if (frame_counter){
	if (frame_counter > 320){
	    if (frame_counter %2) logo_y--;
	    move_bkg(0,logo_y);
	} else {
	    if (frame_counter == 80) BGP_REG = DMG_PALETTE(DMG_WHITE, DMG_LITE_GRAY, DMG_LITE_GRAY, DMG_DARK_GRAY);
	    if (frame_counter == 70) BGP_REG =  DMG_PALETTE(DMG_WHITE, DMG_WHITE, DMG_LITE_GRAY, DMG_LITE_GRAY);;
	    if (frame_counter == 60) BGP_REG = 0x00;
	}
	frame_counter--;
	
    } else {
	init_title_screen();
	game_state = GAME_STATE_TITLE_SCREEN;
    }
    
}
