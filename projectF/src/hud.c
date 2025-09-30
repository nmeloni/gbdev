#include "hud.h"

hud_t HUD;



void init_hud(void) {
    // Initialize HUD elements here
    set_score(0);
    
    HUD.score_string[4] = TILE_0; // 
    HUD.score_string[5] = TILE_0; // 
    HUD.score_string[6] = 0; // Null terminator
    
    HUD.lives = 3;
    HUD.level = 1;
    // Load and set font
    font_init();
    HUD.font = font_load(font_min);
    font_set(HUD.font);

    move_win(0,16*8); // Position window at bottom of screen
}

void update_hud(void) {
    // Update HUD elements based on game state
}

void draw_hud(void) {
    // Draw HUD elements on the screen
    // Draw the "score" label
    uint8_t SCORE_STRING[] = {'S','C','O','R','E'};
    for (uint8_t i = 0; i < 5; i++)
	set_win_tile_xy( 1+i, 1, SCORE_STRING[i] - 'A' + TILE_A);
				      
    // Update the display with HUD.score_string
    for (uint8_t i = 0; i < 6; i++)
	set_win_tiles( SCORE_X+i, SCORE_Y, 1, 1, HUD.score_string +i);
    
}

void set_score(uint16_t score) {
    // Set the score display
    HUD.score =  score < 10000 ? score : 9999; // Cap score at 9999
    // Convert score to string 
    uint16_t powers_of_10[] = {1000, 100, 10, 1};
    for (uint8_t i = 0; i < 4; i++) {
	uint8_t digit = 0;
	while (score >= powers_of_10[i]) {
	    score -= powers_of_10[i];
	    digit++;
	}
	HUD.score_string[i] = digit+TILE_0; // Convert to tile index
    }
    
}

void set_lives(uint8_t lives) {
	// Set the lives display
}

void set_level(uint8_t level) {
	// Set the level display
}
