#include "bullet.h"

inline void update_bullet_position(uint8_t i);
inline void check_bullet_bounds(uint8_t i);
inline void draw_bullet(uint8_t i);
inline void kill_active_bullet(uint8_t j);

bullet_t BULLETS_POOL[MAX_BULLETS];
uint8_t ACTIVE_BULLETS[MAX_BULLETS];
uint8_t active_bullet_index = 0;

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
	    BULLETS_POOL[i].x = x;
	    BULLETS_POOL[i].y = y;
	    BULLETS_POOL[i].dx = dx;
	    BULLETS_POOL[i].dy = dy;
	    BULLETS_POOL[i].fx = 0;
	    BULLETS_POOL[i].fy = 0;
	    ACTIVE_BULLETS[active_bullet_index++] = i;
	    break; // Tiré un seul tir à la fois
	}
    }
}

void update_bullets(void) {
    for (uint8_t j = 0; j < active_bullet_index; j++) {
	uint8_t i = ACTIVE_BULLETS[j];
	// Mettre à jour la position du tir
	update_bullet_position(i);
	// Vérification des limites de l'écran
	check_bullet_bounds(i);
	// Vérification de collision avec le joueur
	
	
	if (BULLETS_POOL[i].active) {	    // Dessiner le tir
	    draw_bullet(i);
	} else {
	    // Supprimer le tir inactif de la liste des tirs actifs
	    kill_active_bullet(j);
	}
    }
}

inline void update_bullet_position(uint8_t i) {
    // Mise à jour des parties fractionnaires pour un mouvement plus fluide
    BULLETS_POOL[i].fx += BULLETS_POOL[i].dx;
    BULLETS_POOL[i].fy += BULLETS_POOL[i].dy;
	
    BULLETS_POOL[i].x += BULLETS_POOL[i].fx >> 4;
    BULLETS_POOL[i].y += BULLETS_POOL[i].fy >> 4;

    BULLETS_POOL[i].fx &= 0x0F;
    BULLETS_POOL[i].fy &= 0x0F;
}

inline void check_bullet_bounds(uint8_t i) {
    // Désactiver le tir s'il sort de l'écran
    if (BULLETS_POOL[i].x < GAMESCREEN_X_ORIGIN ||
	BULLETS_POOL[i].x > GAMESCREEN_X_END ||
	BULLETS_POOL[i].y < GAMESCREEN_Y_ORIGIN ||
	BULLETS_POOL[i].y > GAMESCREEN_Y_END) {
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
	set_sprite_tile(oam, BULLET_TYPE_SMALL_SPRITE);
	break;
    }
    move_sprite(oam,
		BULLETS_POOL[i].x + BULLET_SPRITE_X_OFFSET,
		BULLETS_POOL[i].y + BULLET_SPRITE_Y_OFFSET);
    oam++;
}

inline void kill_active_bullet(uint8_t j) {
    BULLETS_POOL[ACTIVE_BULLETS[j]].active = 0;
    // Supprimer le tir inactif de la liste des tirs actifs
    ACTIVE_BULLETS[j] = ACTIVE_BULLETS[--active_bullet_index];
}

