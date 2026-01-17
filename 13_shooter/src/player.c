#include "player.h"

player_t PLAYER;
void init_player(void) {
    PLAYER.x =  0;
    PLAYER.y =  0;
    PLAYER.dx = 0;
    PLAYER.dy = 0;
    PLAYER.fx = 0;
    PLAYER.fy = 0;
    PLAYER.metasprites = player_sprite_metasprites;
}

void handle_player(void){

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

    // Mise à jour des parties fractionnaires pour un mouvement plus fluide
    PLAYER.fx += PLAYER.dx;
    PLAYER.fy += PLAYER.dy;
    
    PLAYER.x += PLAYER.fx >> 4;
    PLAYER.y += PLAYER.fy >> 4;

    PLAYER.fx &= 0x0F;
    PLAYER.fy &= 0x0F;
   
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
    
    // Mise à jour du sprite du joueur
    oam+=move_metasprite_ex(PLAYER.metasprites[0],
			    PLAYER_TILE_OFFSET,0,oam,
			    PLAYER.x, PLAYER.y);

}
