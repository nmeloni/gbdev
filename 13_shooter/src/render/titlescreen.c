#include "titlescreen.h"

void init_title_screen(void){
    HIDE_SPRITES;
    DISPLAY_OFF;
    set_bkg_data(TITLESCREEN_TILE_OFFSET, titlescreen_img_TILE_COUNT, titlescreen_img_tiles);
    set_bkg_tiles(0,0,20,18,titlescreen_img_map);
    BGP_REG = 0xE4;
    move_bkg(0,0);
    DISPLAY_ON;

}

void show_title_screen(void){
    if (KEY_RELEASED(J_START)){
	game_change_state(GAME_STATE_PLAY);
    }
}
