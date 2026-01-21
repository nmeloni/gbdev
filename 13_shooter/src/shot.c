#include "shot.h"

inline void check_shot_bounds(uint8_t i);
inline void draw_shot(uint8_t i);
inline void kill_active_shot(uint8_t j);

shot_t SHOTS_POOL[MAX_SHOTS];
uint8_t ACTIVE_SHOTS[MAX_SHOTS];
uint8_t active_shot_index = 0;

const uint8_t shot_bbox[3][2] = {
    {1, 2},   // POWER_1_SHOT
    {3,2},   // POWER_2_SHOT
    {3,3}   // POWER_3_SHOT
};

const uint8_t shot_power_table[3] = {
	1,  // POWER_1_SHOT
	2,  // POWER_2_SHOT
	4   // POWER_3_SHOT
};

const uint8_t shot_tile_offsets[] = {
	SHOT_TILE_OFFSET,
	SHOT_TILE_OFFSET + 2,
	SHOT_TILE_OFFSET + 4
};

void init_shots(void) {
    for (uint8_t i = 0; i < MAX_SHOTS; i++) {
	SHOTS_POOL[i].active = 0;
    }
}

void fire_shot(uint8_t x, uint8_t y, int8_t dx, int8_t dy) {
    for (uint8_t i = 0; i < MAX_SHOTS; i++) {
	if (!SHOTS_POOL[i].active) {
	    SHOTS_POOL[i].active = 1;
	    SHOTS_POOL[i].body.x = x;
	    SHOTS_POOL[i].body.y = y;
	    SHOTS_POOL[i].body.dx = dx;
	    SHOTS_POOL[i].body.dy = dy;
	    SHOTS_POOL[i].body.fx = 0;
	    SHOTS_POOL[i].body.fy = 0;
	    ACTIVE_SHOTS[active_shot_index++] = i;
	    break; // Tiré un seul tir à la fois
	}
    }
}

void update_shots(void) {
    for (uint8_t j = 0; j < active_shot_index; j++) {
	uint8_t i = ACTIVE_SHOTS[j];
	// Mettre à jour la position du tir
	update_body_position(&SHOTS_POOL[i].body);
	// Vérification des limites de l'écran
	check_shot_bounds(i);
    
	if (SHOTS_POOL[i].active) {	    // Dessiner le tir
	    draw_shot(i);
	} else {
	    // Supprimer le tir inactif de la liste des tirs actifs
	    kill_active_shot(j);
	}
    }
}

inline void check_shot_bounds(uint8_t i) {
    // Limitation aux bords de l'écran de jeu
    SHOTS_POOL[i].active = is_inside_bounds(SHOTS_POOL[i].body.y,
					      GAMESCREEN_Y_ORIGIN,
					      GAMESCREEN_Y_END) &
			   is_inside_bounds(SHOTS_POOL[i].body.x,
					    GAMESCREEN_X_ORIGIN,
					    GAMESCREEN_X_END);
    	
}

inline void draw_shot(uint8_t i) {
    // Mise à jour du sprite du tir
    // Chaque tir utilise un seul sprite choisi en fonction de shoot_power du joueur
    set_sprite_tile(oam, shot_tile_offsets[PLAYER.shoot_power]);
    move_sprite(oam++,
		SHOTS_POOL[i].body.x+SHOT_ONSCREEN_OFFSET,
		SHOTS_POOL[i].body.y+SHOT_ONSCREEN_OFFSET);
}

inline void kill_active_shot(uint8_t j){
    SHOTS_POOL[ACTIVE_SHOTS[j]].active = 0;
    ACTIVE_SHOTS[j] = ACTIVE_SHOTS[--active_shot_index];
}
