#include "titlescreen.h"

void init_title_screen(void){
    set_bkg_data(0, spaceboost_title_TILE_COUNT, spaceboost_title_tiles);
    set_bkg_tiles(0,0,20,18,spaceboost_title_map);
    BGP_REG = 0xE4;
    move_bkg(0,0);
    SHOW_BKG;
}

void show_title_screen(void){

    if (KEY_PRESSED(J_START)){
	game_state = GAME_STATE_PLAY;
	
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
    }
}
