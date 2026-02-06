#include "logo.h"

uint8_t logo_y;

void init_logo(void){
    DISPLAY_OFF;
    frame_counter = 600;
    logo_y = LOGO_Y_START;
    clear_bkg();
    
    set_bkg_data(LOGO_TILE_OFFSET, logo_img_TILE_COUNT, logo_img_tiles);
    set_bkg_tiles(0,0,20,4, logo_img_map);

    DISPLAY_ON;
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
	game_change_state(GAME_STATE_TITLE_SCREEN);
    }
    
}
