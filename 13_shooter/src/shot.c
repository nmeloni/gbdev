#include "shot.h"

inline void update_shot_position(uint8_t i);
inline void check_shot_bounds(uint8_t i);
inline void draw_shot(uint8_t i);
inline void kill_active_shot(uint8_t j);

shot_t SHOTS_POOL[MAX_SHOTS];
uint8_t ACTIVE_SHOTS[MAX_SHOTS];
uint8_t active_shot_index = 0;

void init_shots(void) {
    for (uint8_t i = 0; i < MAX_SHOTS; i++) {
	SHOTS_POOL[i].active = 0;
    }
}

void fire_shot(uint8_t x, uint8_t y, int8_t dx, int8_t dy) {
    for (uint8_t i = 0; i < MAX_SHOTS; i++) {
	if (!SHOTS_POOL[i].active) {
	    SHOTS_POOL[i].active = 1;
	    SHOTS_POOL[i].x = x;
	    SHOTS_POOL[i].y = y;
	    SHOTS_POOL[i].dx = dx;
	    SHOTS_POOL[i].dy = dy;
	    SHOTS_POOL[i].fx = 0;
	    SHOTS_POOL[i].fy = 0;
	    ACTIVE_SHOTS[active_shot_index++] = i;
	    break; // Tiré un seul tir à la fois
	}
    }
}

void update_shots(void) {
    for (uint8_t j = 0; j < active_shot_index; j++) {
	uint8_t i = ACTIVE_SHOTS[j];
	// Mettre à jour la position du tir
	update_shot_position(i);
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


inline void update_shot_position(uint8_t i) {
    // Mise à jour des parties fractionnaires pour un mouvement plus fluide
    SHOTS_POOL[i].fx += SHOTS_POOL[i].dx;
    SHOTS_POOL[i].fy += SHOTS_POOL[i].dy;
	
    SHOTS_POOL[i].x += SHOTS_POOL[i].fx >> 4;
    SHOTS_POOL[i].y += SHOTS_POOL[i].fy >> 4;

    SHOTS_POOL[i].fx &= 0x0F;
    SHOTS_POOL[i].fy &= 0x0F;
}

inline void check_shot_bounds(uint8_t i) {
    // Limitation aux bords de l'écran de jeu
    if (SHOTS_POOL[i].x < GAMESCREEN_X_ORIGIN ||
	SHOTS_POOL[i].x > GAMESCREEN_X_END ||
	SHOTS_POOL[i].y < GAMESCREEN_Y_ORIGIN ||
	SHOTS_POOL[i].y > GAMESCREEN_Y_END) {
	SHOTS_POOL[i].active = 0;
    }    	
}

inline void draw_shot(uint8_t i) {
    // Mise à jour du sprite du tir
    // Chaque tir utilise un seul sprite choisi en fonction de shoot_power du joueur
    set_sprite_tile(oam, SHOT_TILE_OFFSET + PLAYER.shoot_power);
    move_sprite(oam++,
		SHOTS_POOL[i].x+SHOT_ONSCREEN_OFFSET,
		SHOTS_POOL[i].y+SHOT_ONSCREEN_OFFSET);
}

inline void kill_active_shot(uint8_t j){
    SHOTS_POOL[ACTIVE_SHOTS[j]].active = 0;
    for (uint8_t i=j; i<active_shot_index; i++){
	ACTIVE_SHOTS[i] = ACTIVE_SHOTS[i+1];
    }
    active_shot_index--;
}
