#include "player.h"

uint8_t current_joypad, previous_joypad;
//const uint8_t spaceship_bounding_box[] = {6,1,4,14};


player_t PLAYER;

void init_player(void){
    RESET_PLAYER();
    PLAYER.lives = 3;
}

void handle_player(void){
    if (PLAYER.boost){ 
	PLAYER.dxy = BOOST_SPEED;
	PLAYER.boost --;
    } else {
	PLAYER.dxy = NORMAL_SPEED;
    }
    if (PLAYER.invinsibility_timer) PLAYER.invinsibility_timer--;
    
    if (KEY_PRESSED(J_A)){
	if (!PLAYER.last_boost){
	    PLAYER.boost = BOOST_DURATION;
	    PLAYER.last_boost = BOOST_LAG;
	}
    }
    if (PLAYER.last_boost) PLAYER.last_boost--;

    if (KEY_PRESSED(J_LEFT)){
	if (PLAYER.x > PLAYER.dxy+ (8<<8)) PLAYER.x -= PLAYER.dxy;
	else PLAYER.x = 8<<8;
    }
    if (KEY_PRESSED(J_RIGHT)){
	if (PLAYER.x < (135<<8) - PLAYER.dxy ) PLAYER.x += PLAYER.dxy;
	else PLAYER.x = ((uint16_t)135<<8);
    }
    if (KEY_PRESSED(J_UP)){
	if (PLAYER.y > PLAYER.dxy+ (24<<8)) PLAYER.y -= PLAYER.dxy;
	else PLAYER.y = 24<<8;
    }
    if (KEY_PRESSED(J_DOWN)){
	if (PLAYER.y < (160<<8) - PLAYER.dxy ) PLAYER.y += PLAYER.dxy;
	else PLAYER.y = ((uint16_t)160<<8);
    }
    if (KEY_PRESSED(J_B)){
	if (PLAYER.last_shot) PLAYER.last_shot--;
	else shoot();
    }
    PLAYER.px = PLAYER.x >> 8;
    PLAYER.py = PLAYER.y >> 8;
    PLAYER.column = (PLAYER.px + 8) >> 4;

}


void shoot(void){
    if (PLAYER.last_shot){
	PLAYER.last_shot--;
	return;
    } 
    //on recupère les sprite disponible
    for (uint8_t i=0; i<MAX_BULLETS; i++){
	if (!BULLETS[i].isactive){
	    PLAYER.last_shot = SHOOT_LAG;
	    BULLETS[i].isactive = 1;
	    BULLETS[i].x = PLAYER.x;
	    BULLETS[i].y = PLAYER.y;
	    BULLETS[i].px = PLAYER.px;
	    BULLETS[i].py = PLAYER.py;

	    ACTIVE_BULLETS[active_bullet_index++] = i;
	    return;
	}
    }
}

void draw_player(void){
    if (PLAYER.invinsibility_timer&8) return;
    oam+=move_metasprite_ex(spaceship_sprite_metasprites[0],
			    SPACESHIP_TILE_OFFSET,0,oam,
			    PLAYER.px, PLAYER.py);
    if ( (PLAYER.flags & PLAYER_FLAG_SHIELD) && (level_framecounter & 4) ){
	oam+=move_metasprite_ex(shield_sprite_metasprites[0],
				SHIELD_TILE_OFFSET,0,oam,
				PLAYER.px, PLAYER.py);
    }
    if (PLAYER.last_boost){
	oam+=move_metasprite_ex(booster_sprite_metasprites[(PLAYER.last_boost&12)>>2],
				BOOSTER_TILE_OFFSET,0,oam,
				PLAYER.px, PLAYER.py+6);
    }
    
}
