#include "game.h"

uint8_t oam = 0;
uint16_t frame_counter = 0;

game_state_t game_state;

void game_init(void) {
    game_state = GAME_STATE_PLAY;
    oam = 0;
    frame_counter = 0;

    reset_player(PLAYER_MIN_X + (PLAYER_MAX_X - PLAYER_MIN_X)/2, PLAYER_MAX_Y - 16);
}

void game_update(void) {

    UPDATE_KEYS();
    
    switch (game_state) {
    case GAME_STATE_PLAY:
	frame_counter++;
	oam = 0;
	
	update_shots();
	update_bullets();
	update_enemies();
	update_player();
	
	hide_sprites_range(oam,MAX_HARDWARE_SPRITES);
	break;
    case GAME_STATE_PAUSE:
	// Handle pause state
	update_player();
	break;
    case GAME_STATE_GAME_OVER:
	// Handle game over state
	update_player();
	break;
    }

    
}
