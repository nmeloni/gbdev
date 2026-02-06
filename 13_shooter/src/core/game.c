#include "game.h"

inline void init_gameplay(void);
inline void update_gameplay(void);
inline void pause(void);
inline void init_game_over(void);
inline void game_over(void);

uint8_t oam = 0;
uint16_t frame_counter = 0;

game_state_t previous_state, game_state;

void game_init(void) {

    oam = 0;
    frame_counter = 0;
    hide_sprites_range(oam,MAX_HARDWARE_SPRITES);
    
    game_change_state(GAME_STATE_PLAY);
}



void game_change_state(game_state_t new_state) {
    previous_state = game_state;
    game_state = new_state;
    
    switch (game_state) {
    case GAME_STATE_INIT:
	// Initialisation générale du jeu
	game_init();
	break;
    case GAME_STATE_LOGO:
	init_logo();
	break;
    case GAME_STATE_TITLE_SCREEN:
	init_title_screen();
	break;
    case GAME_STATE_PLAY:
	// Initialisation du jeu
	if (previous_state == GAME_STATE_PAUSE) {
	    // Reprise du jeu depuis la pause
	} else {
	    init_gameplay();
	}
	break;
    case GAME_STATE_PAUSE:
	// Initialisation de la pause
	break;
    case GAME_STATE_GAME_OVER:
	// Initialisation du game over
	init_game_over();
	break;
    default:
	break;
    }
}


void game_update(void) {

    UPDATE_KEYS();
    
    switch (game_state) {
    case GAME_STATE_INIT:
	game_init();
	break;
    case GAME_STATE_LOGO:
	show_logo();
	break;
    case GAME_STATE_TITLE_SCREEN:
	show_title_screen();
	break;
    case GAME_STATE_PLAY:
	update_gameplay();
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

void init_gameplay(void){
    // Nouvelle partie
    gfx_init();
    init_player();
    init_shots();
    init_enemies();
    init_bullets();
    init_powerup();
    init_explosions();
    load_level(1);
    init_boss();
    init_background();
    init_audio();
}

void update_gameplay(void){
    frame_counter++;
    oam = 0;
	
    update_shots();
    update_bullets();
    update_enemies();
    if (BOSS.active) update_boss();
    update_powerup();
    update_explosions();
    update_player();
   
    scroll_background();

    // Mise à jour du niveau
    update_level();
    hide_sprites_range(oam,MAX_HARDWARE_SPRITES);
}

void pause(void){
    if ( KEY_RELEASED(J_START) ){
	game_state = GAME_STATE_PLAY;
    }
}

void init_game_over(void){
    frame_counter = 300;
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
	game_change_state(GAME_STATE_TITLE_SCREEN);
    }
}
