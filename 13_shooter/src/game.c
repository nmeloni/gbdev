#include "game.h"

uint8_t oam = 0;
uint16_t frame_counter = 0;

game_state_t game_state;

void game_init(void) {
    game_state = GAME_STATE_LOGO;
    oam = 0;
    frame_counter = 0;
    hide_sprites_range(oam,MAX_HARDWARE_SPRITES);
    init_logo();
}

void pause(void){
    if ( KEY_RELEASED(J_START) ){
	game_state = GAME_STATE_PLAY;
    }
}

void game_over(void){
    if (frame_counter){
	oam = 0;
	update_shots();
	update_enemies();
	update_boss();
	update_bullets();
	update_powerup();
	update_explosions();
	scroll_background();
	hide_sprites_range(oam,MAX_HARDWARE_SPRITES);
	frame_counter--;
    } else {
	game_init();
    }
}

void game_update(void) {

    UPDATE_KEYS();
    
    switch (game_state) {
    case GAME_STATE_LOGO:
	show_logo();
	break;
    case GAME_STATE_TITLE_SCREEN:
	show_title_screen();
	break;
    case GAME_STATE_PLAY:
	frame_counter++;
	oam = 0;
	
	update_shots();
	update_enemies();
	update_boss();
	update_bullets();
	update_powerup();
	update_explosions();
	update_player();
	scroll_background();

	// Mise à jour du niveau
	update_level();
	hide_sprites_range(oam,MAX_HARDWARE_SPRITES);
	break;
    case GAME_STATE_PAUSE:
	// Handle pause state
	pause();
	break;
    case GAME_STATE_GAME_OVER:
	// Handle game over state
	game_over();
	break;
    }

    
}
