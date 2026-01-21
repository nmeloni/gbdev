#include "player.h"

inline void update_player_input(void);
inline void check_player_bounds(void);
inline void draw_player(void);

const uint16_t boost_speed_table[24] = {
    1,1,1,1,
    2,2,2,2,
    3,3,4,4,
    4, 5, 12, 12,
    16, 16, 32, 64,
    80, 80 , 72, 48
};

const uint16_t boost_speed_table_normalized[24] = {
    1,1,0,1,
    2,1,2,1,
    2,2,2,3,
    3, 4, 8, 9,
    11, 11, 22, 45,
    56, 57 , 51, 34
};


player_t PLAYER;
void init_player(void) {
    init_body(&PLAYER.body, 0, 0);
    PLAYER.shoot_cooldown = 0;
    PLAYER.shoot_power = 0;
    PLAYER.invincibility_timer = 0;
    PLAYER.shield = 0;
    PLAYER.boost = 0;
    PLAYER.lives = 3;
    PLAYER.metasprites = player_sprite_metasprites;
}

void update_player(void){
    // gestion du joueur décomposée en plusieurs fonctions inline pour plus de clarté    
    update_player_input();
    update_body_position(&PLAYER.body);
    check_player_bounds();
    draw_player();     
}

inline void update_player_input(void) {

    if (PLAYER.invincibility_timer) {
	PLAYER.invincibility_timer--;
    }
    // Gestions des mouvements
    uint8_t speed = PLAYER_SPEED;
    // Si le boost est actif, on ignore les input
    if (PLAYER.boost) {
	PLAYER.boost--;
	if (PLAYER.body.dx && PLAYER.body.dy) {
	    // Mouvement diagonal, on normalise la vitesse
	    speed = boost_speed_table_normalized[ (PLAYER.boost & 62)>>1];
	} else {
	    speed = boost_speed_table[ (PLAYER.boost & 62)>>1];
	}
	if (PLAYER.body.dx > 0){
	    PLAYER.body.dx = speed;
	} else if (PLAYER.body.dx < 0){
	    PLAYER.body.dx = -speed;
	}
	
	if (PLAYER.body.dy > 0){
	    PLAYER.body.dy = speed;
	} else if (PLAYER.body.dy < 0){
	    PLAYER.body.dy = -speed;
	}
    } else {
	// Mouvement normal
	PLAYER.body.dx = 0;
	PLAYER.body.dy = 0;

	if (KEY_RELEASED(J_A)){
	    PLAYER.boost = PLAYER_BOOST_DURATION_FRAMES;
	    speed = BOOST_SPEED;
	}
	
	if (KEY_PRESSED(J_LEFT)){
	    PLAYER.body.dx = -speed;
	}
	if (KEY_PRESSED(J_RIGHT)){
	    PLAYER.body.dx = speed;
	}
	if (KEY_PRESSED(J_UP)){
	    PLAYER.body.dy = -speed;
	}
	if (KEY_PRESSED(J_DOWN)){
	    PLAYER.body.dy = speed;
	}

    }

    if (KEY_PRESSED(J_SELECT)){
	kill_player();
    }
    
    // Gestion du tir
    if (PLAYER.shoot_cooldown) {
	PLAYER.shoot_cooldown--;
    } else if (KEY_PRESSED(J_B)) {
	fire_shot(PLAYER.body.x, PLAYER.body.y-8, 0, -SHOT_SPEED);
	PLAYER.shoot_cooldown = PLAYER_SHOOT_COOLDOWN_FRAMES;
    }
    
}

void reset_player(uint8_t x, uint8_t y) {
	PLAYER.body.x = x;
	PLAYER.body.y = y;
	PLAYER.body.dx = 0;
	PLAYER.body.dy = 0;
	PLAYER.body.fx = 0;
	PLAYER.body.fy = 0;
	PLAYER.shoot_cooldown = 0;
	PLAYER.shoot_power = 0;
	PLAYER.invincibility_timer = 0;
	PLAYER.boost = 0;
}

void kill_player(void) {
    add_explosion(PLAYER.body.x, PLAYER.body.y);
    reset_player(PLAYER_MIN_X + (PLAYER_MAX_X - PLAYER_MIN_X)/2, PLAYER_MAX_Y - 16);
    PLAYER.invincibility_timer = PLAYER_INVINCIBILITY_FRAMES;
    PLAYER.lives--;
}


inline void check_player_bounds(void) {
    // Limitation aux bords de l'écran de jeu
    if (PLAYER.body.x < PLAYER_MIN_X) {
	PLAYER.body.x = PLAYER_MIN_X;
	PLAYER.body.fx = 0;

    }
    if (PLAYER.body.x > PLAYER_MAX_X) {
	PLAYER.body.x = PLAYER_MAX_X;
	PLAYER.body.fx = 0;

    }
    if (PLAYER.body.y < PLAYER_MIN_Y) {
	PLAYER.body.y = PLAYER_MIN_Y;
	PLAYER.body.fy = 0;
	
    }
    if (PLAYER.body.y > PLAYER_MAX_Y) {
	PLAYER.body.y = PLAYER_MAX_Y;
	PLAYER.body.fy = 0;
    }    	
}

inline void draw_player(void) {
    // Mise à jour du sprite du joueur
    if (PLAYER.invincibility_timer & 8) return;

    uint8_t frame = PLAYER_ANIMATION_FRAME_TOP;
    if (PLAYER.boost){
	if (PLAYER.body.dx < 0) {
	    frame = PLAYER_ANIMATION_FRAME_LEFT;
	} else if (PLAYER.body.dx > 0) {
	    frame = PLAYER_ANIMATION_FRAME_RIGHT;
	}
    }
    oam+=move_metasprite_ex(PLAYER.metasprites[frame],
			    PLAYER_TILE_OFFSET,0,oam,
			    PLAYER.body.x, PLAYER.body.y);
    if (PLAYER.shield && (frame_counter & 1)) {
	oam+=move_metasprite_ex(shield_sprite_metasprites[0],
				SHIELD_TILE_OFFSET,0,oam,
				PLAYER.body.x, PLAYER.body.y);
    }
}
