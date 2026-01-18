#include "player.h"

inline void update_player_input(void);
inline void update_player_position(void);
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
    PLAYER.x =  0;
    PLAYER.y =  0;
    PLAYER.dx = 0;
    PLAYER.dy = 0;
    PLAYER.fx = 0;
    PLAYER.fy = 0;
    PLAYER.shoot_cooldown = 0;
    PLAYER.shoot_power = 0;
    PLAYER.invincibility_timer = 0;
    PLAYER.boost = 0;
    PLAYER.metasprites = player_sprite_metasprites;
}

void update_player(void){
    // gestion du joueur décomposée en plusieurs fonctions inline pour plus de clarté    
    update_player_input();
    update_player_position();
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
	if (PLAYER.dx && PLAYER.dy) {
	    // Mouvement diagonal, on normalise la vitesse
	    speed = boost_speed_table_normalized[ (PLAYER.boost & 62)>>1];
	} else {
	    speed = boost_speed_table[ (PLAYER.boost & 62)>>1];
	}
	if (PLAYER.dx > 0){
	    PLAYER.dx = speed;
	} else if (PLAYER.dx < 0){
	    PLAYER.dx = -speed;
	}
	
	if (PLAYER.dy > 0){
	    PLAYER.dy = speed;
	} else if (PLAYER.dy < 0){
	    PLAYER.dy = -speed;
	}
    } else {
	// Mouvement normal
	PLAYER.dx = 0;
	PLAYER.dy = 0;

	if (KEY_RELEASED(J_A)){
	    PLAYER.boost = PLAYER_BOOST_DURATION_FRAMES;
	    speed = BOOST_SPEED;
	}
	
	if (KEY_PRESSED(J_LEFT)){
	    PLAYER.dx = -speed;
	}
	if (KEY_PRESSED(J_RIGHT)){
	    PLAYER.dx = speed;
	}
	if (KEY_PRESSED(J_UP)){
	    PLAYER.dy = -speed;
	}
	if (KEY_PRESSED(J_DOWN)){
	    PLAYER.dy = speed;
	}

    }

    if (KEY_PRESSED(J_SELECT)){
	kill_player();
    }
    
    // Gestion du tir
    if (PLAYER.shoot_cooldown) {
	PLAYER.shoot_cooldown--;
    } else if (KEY_PRESSED(J_B)) {
	fire_shot(PLAYER.x, PLAYER.y-8, 0, -SHOT_SPEED);
	PLAYER.shoot_cooldown = PLAYER_SHOOT_COOLDOWN_FRAMES;
    }
    
}

void reset_player(uint8_t x, uint8_t y) {
	PLAYER.x = x;
	PLAYER.y = y;
	PLAYER.dx = 0;
	PLAYER.dy = 0;
	PLAYER.fx = 0;
	PLAYER.fy = 0;
	PLAYER.shoot_cooldown = 0;
	PLAYER.shoot_power = 0;
	PLAYER.invincibility_timer = 0;
	PLAYER.boost = 0;
}

void kill_player(void) {
    reset_player(PLAYER_MIN_X + (PLAYER_MAX_X - PLAYER_MIN_X)/2, PLAYER_MAX_Y - 16);
    PLAYER.invincibility_timer = PLAYER_INVINCIBILITY_FRAMES;
}


inline void update_player_position(void) {
     // Mise à jour des parties fractionnaires pour un mouvement plus fluide
    PLAYER.fx += PLAYER.dx;
    PLAYER.fy += PLAYER.dy;
    
    PLAYER.x += PLAYER.fx >> 4;
    PLAYER.y += PLAYER.fy >> 4;

    PLAYER.fx &= 0x0F;
    PLAYER.fy &= 0x0F;
}

inline void check_player_bounds(void) {
    // Limitation aux bords de l'écran de jeu
    if (PLAYER.x < PLAYER_MIN_X) {
	PLAYER.x = PLAYER_MIN_X;
	PLAYER.fx = 0;

    }
    if (PLAYER.x > PLAYER_MAX_X) {
	PLAYER.x = PLAYER_MAX_X;
	PLAYER.fx = 0;

    }
    if (PLAYER.y < PLAYER_MIN_Y) {
	PLAYER.y = PLAYER_MIN_Y;
	PLAYER.fy = 0;
	
    }
    if (PLAYER.y > PLAYER_MAX_Y) {
	PLAYER.y = PLAYER_MAX_Y;
	PLAYER.fy = 0;
    }    	
}

inline void draw_player(void) {
    // Mise à jour du sprite du joueur
    if (PLAYER.invincibility_timer & 16) return;

    uint8_t frame = PLAYER_ANIMATION_FRAME_TOP;
    if (PLAYER.boost){
	if (PLAYER.dx < 0) {
	    frame = PLAYER_ANIMATION_FRAME_LEFT;
	} else if (PLAYER.dx > 0) {
	    frame = PLAYER_ANIMATION_FRAME_RIGHT;
	}
    }
    oam+=move_metasprite_ex(PLAYER.metasprites[frame],
			    PLAYER_TILE_OFFSET,0,oam,
			    PLAYER.x, PLAYER.y);
}
