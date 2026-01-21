#include "bullet.h"

inline void check_bullet_bounds(uint8_t i);
inline void draw_bullet(uint8_t i);
inline void kill_active_bullet(uint8_t j);

bullet_t BULLETS_POOL[MAX_BULLETS];
uint8_t ACTIVE_BULLETS[MAX_BULLETS];
uint8_t active_bullet_index = 0;

const uint8_t bullet_bbox[2][2] = {
    {3, 3},   // BULLET_TYPE_SMALL
    {5, 5}     // BULLET_TYPE_LARGE
};

void init_bullets(void) {
    for (uint8_t i = 0; i < MAX_BULLETS; i++) {
	BULLETS_POOL[i].active = 0;
    }
}

void fire_bullet(uint8_t type, uint8_t x, uint8_t y, int8_t dx, int8_t dy) {
    for (uint8_t i = 0; i < MAX_BULLETS; i++) {
	if (!BULLETS_POOL[i].active) {
	    BULLETS_POOL[i].active = 1;
	    BULLETS_POOL[i].type = type;
	    BULLETS_POOL[i].body.x = x;
	    BULLETS_POOL[i].body.y = y;
	    BULLETS_POOL[i].body.dx = dx;
	    BULLETS_POOL[i].body.dy = dy;
	    ACTIVE_BULLETS[active_bullet_index++] = i;
	    break; // Tiré un seul tir à la fois
	}
    }
}

void update_bullets(void) {
    for (uint8_t j = 0; j < active_bullet_index; j++) {
	
	uint8_t i = ACTIVE_BULLETS[j];
	// Gestion des tirs tous les deux frames pour alléger le CPU
	if ( (frame_counter - j) & 1 ) continue;
	// Mettre à jour la position du tir
	update_body_position(&BULLETS_POOL[i].body);
	
	// Verification des collisions et des limites toutes les 4 frames
	// pour alléger le CPU
	if ( (frame_counter - j) % 4 == 0)
	{ 
	    
	    // Vérification des limites de l'écran
	    check_bullet_bounds(i);
	    // Vérification de collision avec le joueur
	    uint8_t type = BULLETS_POOL[i].type;
	    if (check_collision_box(BULLETS_POOL[i].body.x, BULLETS_POOL[i].body.y,
				    bullet_bbox[type][0], bullet_bbox[type][1],
				    PLAYER.body.x, PLAYER.body.y, 0, 0) ) {
		// Collision détectée avec le joueur
		if (PLAYER.shield) {
		    PLAYER.shield = 0;
		    PLAYER.invincibility_timer = PLAYER_INVINCIBILITY_FRAMES;
		}
		if (PLAYER.invincibility_timer == 0) {
		    kill_player();
		}
		kill_active_bullet(j);
		continue; // Passer au tir suivant	    
	    }
	}
	    
	if (BULLETS_POOL[i].active) {	    // Dessiner le tir
	    draw_bullet(i);
	} else {
	    // Supprimer le tir inactif de la liste des tirs actifs
	    kill_active_bullet(j);
	}
    }
}

inline void check_bullet_bounds(uint8_t i) {
    // Désactiver le tir s'il sort de l'écran
    if (is_outside_bounds(BULLETS_POOL[i].body.x,
			  GAMESCREEN_X_ORIGIN, GAMESCREEN_X_END) ||
	is_outside_bounds(BULLETS_POOL[i].body.y,
			  GAMESCREEN_Y_ORIGIN, GAMESCREEN_Y_END)){
	BULLETS_POOL[i].active = 0;
    }
}

inline void draw_bullet(uint8_t i) {
    // Mise à jour du sprite du tir
    switch (BULLETS_POOL[i].type) {
    case BULLET_TYPE_SMALL:
	set_sprite_tile(oam, BULLET_TYPE_SMALL_SPRITE);
	break;
    default:
	set_sprite_tile(oam, BULLET_TYPE_LARGE_SPRITE);
	break;
    }
    move_sprite(oam,
		BULLETS_POOL[i].body.x + BULLET_SPRITE_X_OFFSET,
		BULLETS_POOL[i].body.y + BULLET_SPRITE_Y_OFFSET);
    oam++;
}

inline void kill_active_bullet(uint8_t j) {
    BULLETS_POOL[ACTIVE_BULLETS[j]].active = 0;
    // Supprimer le tir inactif de la liste des tirs actifs
    ACTIVE_BULLETS[j] = ACTIVE_BULLETS[--active_bullet_index];
}

