#include "player.h"

inline void update_player_input(void);
inline void update_player_position(void);
inline void check_player_bounds(void);
inline void draw_player(void);

player_t PLAYER;
void init_player(void) {
    PLAYER.x =  0;
    PLAYER.y =  0;
    PLAYER.dx = 0;
    PLAYER.dy = 0;
    PLAYER.fx = 0;
    PLAYER.fy = 0;
    PLAYER.shoot_cooldown = 0;
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
    uint8_t speed = PLAYER_SPEED;
    // Gestions des mouvements
    PLAYER.dx = 0;
    PLAYER.dy = 0;

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
    // Gestion du tir
    if (PLAYER.shoot_cooldown) {
	PLAYER.shoot_cooldown--;
    } else if (KEY_PRESSED(J_A)) {
	fire_shot(PLAYER.x, PLAYER.y-8, 0, -SHOT_SPEED);
	PLAYER.shoot_cooldown = PLAYER_SHOOT_COOLDOWN_FRAMES;
    }
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
    oam+=move_metasprite_ex(PLAYER.metasprites[0],
			    PLAYER_TILE_OFFSET,0,oam,
			    PLAYER.x, PLAYER.y);
}
