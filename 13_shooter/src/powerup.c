#include "powerup.h"

inline void handle_move_pattern_powerup(void);
inline void check_powerup_bounds(void);
inline void check_powerup_collision(void);
inline void draw_powerup(void);


powerup_t POWERUP;

const uint8_t power_up_bbox[2] = {7,7};

void init_powerup(void) {
	POWERUP.active = 0;
}

void spawn_powerup(uint8_t type, uint8_t x, uint8_t y) {
	POWERUP.active = 1;
	POWERUP.type = type;
	init_body(&POWERUP.body, x, y);
	POWERUP.move_pattern = MOVE_PATTERN_ZIGZAG;
	POWERUP.move_activepattern = 0;
	POWERUP.move_framecounter = move_patterns[POWERUP.move_pattern][0][0];
}

void update_powerup(void) {
	if (!POWERUP.active) return;

	//gestion du pattern de mouvement
	handle_move_pattern_powerup();

	// Mouvement du powerup
	update_body_position(&POWERUP.body);

	//Vérification des limites de l'écran
	check_powerup_bounds();

	//collision avec le joueur
	check_powerup_collision();

	// Dessiner le powerup
	draw_powerup();
}

inline void handle_move_pattern_powerup(void){
    uint8_t step;
    uint8_t current_move_pattern = POWERUP.move_pattern;
    uint8_t pattern_length = move_pattern_lengths[current_move_pattern];
    if (POWERUP.move_framecounter == 0){
	//On passe au step suivant
	POWERUP.move_activepattern++;
	if (POWERUP.move_activepattern >= pattern_length){
	    POWERUP.move_activepattern = 0;
	}
	//On applique le step
	step = POWERUP.move_activepattern;
	POWERUP.move_framecounter = move_patterns[current_move_pattern][step][0];
	POWERUP.body.dx = move_patterns[current_move_pattern][step][1];
	POWERUP.body.dy = move_patterns[current_move_pattern][step][2];
    }
    POWERUP.move_framecounter--;
}


inline void check_powerup_collision(void){
    // Vérification de collision avec le joueur

    if (check_collision_box(POWERUP.body.x, POWERUP.body.y, power_up_bbox[0], power_up_bbox[1],
			    PLAYER.body.x, PLAYER.body.y, 0, 0) ) {
	// Collision détectée avec le joueur
	switch (POWERUP.type) {
	case POWERUP_TYPE_POWER_UP:
	    if (PLAYER.shoot_power < 2) {
		PLAYER.shoot_power++;
	    }
	    break;
	case POWERUP_TYPE_SHIELD:
	    PLAYER.shield = 1;
	    break;
	case POWERUP_TYPE_EXTRA_LIFE:
	    // Implémenter la logique d'une vie supplémentaire ici
	    PLAYER.lives++;
	    break;
	}
	POWERUP.active = 0;
    }
}				
	
	
inline void check_powerup_bounds(void){
    POWERUP.active =
	is_inside_bounds(POWERUP.body.y,
				      GAMESCREEN_Y_ORIGIN,
				      GAMESCREEN_Y_END) &
	is_inside_bounds(POWERUP.body.x,
			 GAMESCREEN_X_ORIGIN,
			 GAMESCREEN_X_END);
}

inline void draw_powerup(void){
    // Mise à jour du sprite du powerup
    uint8_t tile_offset;
    switch (POWERUP.type) {
    case POWERUP_TYPE_POWER_UP:
	tile_offset = POWERUP_TILE_OFFSET;
	break;
    case POWERUP_TYPE_SHIELD:
	tile_offset = POWERUP_SHIELD_TILE_OFFSET;
	break;
    case POWERUP_TYPE_EXTRA_LIFE:
	tile_offset = POWERUP_EXTRA_LIFE_TILE_OFFSET;
	break;
    default:
	tile_offset = POWERUP_TILE_OFFSET;
	break;
    }
    oam+= move_metasprite_ex(powerup_sprite_metasprites[POWERUP.type],
			     POWERUP_TILE_OFFSET, 0 ,oam,
			     POWERUP.body.x,
			     POWERUP.body.y);
}
