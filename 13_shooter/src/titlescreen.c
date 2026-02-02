#include "titlescreen.h"

void init_title_screen(void){
    DISPLAY_OFF;
    set_bkg_data(0, spaceboost_title_TILE_COUNT, spaceboost_title_tiles);
    set_bkg_tiles(0,0,20,18,spaceboost_title_map);
    BGP_REG = 0xE4;
    move_bkg(0,0);
    DISPLAY_ON;

}

void show_title_screen(void){

    if (KEY_RELEASED(J_START)){
	game_state = GAME_STATE_PLAY;
	DISPLAY_OFF;
	
	gfx_init();
	audio_init();
	init_player();
	init_shots();
	init_background();
	init_bullets();
	init_enemies();
	init_powerup();
	init_background();
	init_explosions();
	init_level(level_demo_events);
	reset_player(PLAYER_START_X, PLAYER_START_y);
	DISPLAY_ON;
	SHOW_SPRITES;

    }
}
