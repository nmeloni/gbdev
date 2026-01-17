#include "player.h"

player_t PLAYER;

const uint16_t boost_speeds[24] = {
    10<<2, 10<<2, 10<<2, 10<<2,
    12<<2, 12<<2, 12<<2, 12<<2,
    12<<2, 12<<2, 10<<3, 10<<3,
    10<<3, 12<<3, 12<<4, 12<<5,
    12<<5, 10<<6, 12<<6, 14<<6,
    14<<7, 20<<7, 20<<6, 18<<5
};

void init_player(void){
    PLAYER.x = PLAYER_INIT_X<<8;
    PLAYER.y = PLAYER_INIT_Y<<8;
    PLAYER.dx = 0;
    PLAYER.dy = 0;
    PLAYER.px = PLAYER_INIT_X;
    PLAYER.py = PLAYER_INIT_Y;
    PLAYER.last_boost = 0;
    PLAYER.boost = 0;
    PLAYER.metasprites = spaceship_sprite_metasprites;
}

void handle_player(void){

    uint16_t speed = NORMAL_SPEED;
    //Gestion du boost
    if (PLAYER.boost){
	PLAYER.boost--;
	// On évalue la durée du boost
	speed = boost_speeds[((PLAYER.boost & 62)>>1)];
	
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

	
	if (PLAYER.dx && PLAYER.dy){
	    //On normalise la vitesse en diagonale
	    PLAYER.dx = (PLAYER.dx >> 1) + (PLAYER.dx >> 2);
	    PLAYER.dy = (PLAYER.dy >> 1) + (PLAYER.dy >> 2);
	}
	
    } else {
	
	//Mouvement selon les touches
	PLAYER.dx = 0;
	PLAYER.dy = 0;
	
	if (KEY_RELEASED(J_A)){
	    PLAYER.boost = BOOST_DURATION;
	    PLAYER.last_boost = BOOST_LAG;
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

    //Mouvement du vaisseau
    PLAYER.x += PLAYER.dx;
    PLAYER.y += PLAYER.dy;
    
    PLAYER.px = PLAYER.x >> 8;
    PLAYER.py = PLAYER.y >> 8;

    if (PLAYER.px < PLAYER_MIN_X){
	PLAYER.px = PLAYER_MIN_X;
	PLAYER.x = PLAYER.px << 8;
    }
    if (PLAYER.px > PLAYER_MAX_X){
	PLAYER.px = (uint8_t)PLAYER_MAX_X;
	PLAYER.x = PLAYER.px << 8;
    }
    if (PLAYER.py < PLAYER_MIN_Y){
	PLAYER.py = PLAYER_MIN_Y;
	PLAYER.y = PLAYER.py << 8;
    }
    if (PLAYER.py > PLAYER_MAX_Y){
	PLAYER.py = (uint8_t)PLAYER_MAX_Y;
	PLAYER.y = PLAYER.py << 8;
    }
    
    
    
    //Affichage du vaisseau
    oam+=move_metasprite_ex(PLAYER.metasprites[0],
			    SPACESHIP_TILE_OFFSET,0,oam,
			    PLAYER.px, PLAYER.py);


}
