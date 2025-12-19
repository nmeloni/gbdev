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
    if (PLAYER.last_boost) PLAYER.last_boost--;
    if (KEY_PRESSED(J_A)){
	if (!PLAYER.last_boost){
	    PLAYER.boost = BOOST_DURATION;
	    PLAYER.last_boost = BOOST_LAG;
	}
    }
    if (KEY_PRESSED(J_LEFT)){
	if (PLAYER.x > PLAYER.dxy+ (16<<8)) PLAYER.x -= PLAYER.dxy;
	else PLAYER.x = 16<<8;
    }
    if (KEY_PRESSED(J_RIGHT)){
	if (PLAYER.x < (120<<8) - PLAYER.dxy ) PLAYER.x += PLAYER.dxy;
	else PLAYER.x = ((uint16_t)120<<8);
    }
    if (KEY_PRESSED(J_UP)){
	if (PLAYER.y > PLAYER.dxy+ (24<<8)) PLAYER.y -= PLAYER.dxy;
	else PLAYER.y = 24<<8;
    }
    if (KEY_PRESSED(J_DOWN)){
	if (PLAYER.y < (144<<8) - PLAYER.dxy ) PLAYER.y += PLAYER.dxy;
	else PLAYER.y = ((uint16_t)144<<8);
    }
    if (KEY_PRESSED(J_B)){
	if (PLAYER.last_shot) PLAYER.last_shot--;
	else shoot();
    }
}

/*
uint8_t player_collision(uint16_t x, uint16_t y, uint8_t *bbox){
    int16_t ax = (PLAYER.x >> 6) - (spaceship_sprite_PIVOT_X>>1) + spaceship_bounding_box[0];
    int16_t ay = (PLAYER.y >> 6) - (spaceship_sprite_PIVOT_Y>>1) + spaceship_bounding_box[1];
    int16_t aw = spaceship_bounding_box[2];
    int16_t ah = spaceship_bounding_box[3];

    int16_t bx = (x >> 6) + bbox[0];
    int16_t by = (y >> 6) + bbox[1];
    int16_t bw = bbox[2];
    int16_t bh = bbox[3];
    if( (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by) ) {
	return 1;
    }
    return 0;
}

void handle_collisions(void){
    for (uint8_t i=0; i<MAX_POWERUPS; i++){
	if (POWERUPS[i].isactive){
	    if (player_collision(POWERUPS[i].x, POWERUPS[i].y,powerup_bounding_box)){
		POWERUPS[i].isactive = 0;
		if (PLAYER.power < 3){
		    PLAYER.power++;
		}
	    }
	}
    }
    for (uint8_t i=0; i<MAX_ENNEMY; i++){
	if (ENNEMIES[i].isactive){
	    if (player_collision(ENNEMIES[i].x, ENNEMIES[i].y, ennemy_1_bounding_box)){
		EMU_printf("Player hit!\n");
		RESET_PLAYER();
		ENNEMIES[i].isactive = 0;
		PLAYER.lives--;
	    }
	}
    }
}
*/


void shoot(void){
    uint8_t nb_bullets = PLAYER.power;
    if (PLAYER.last_shot){
	PLAYER.last_shot--;
	return;
    } 
    //on recupère les sprite disponible
    for (uint8_t i=0; i<MAX_BULLETS; i++){
	if (!BULLETS[i][0].isactive){
	    PLAYER.last_shot = SHOOT_LAG;
	    switch (PLAYER.power){
	    case 1:
		BULLETS[i][0].isactive = 1;
		BULLETS[i][0].x = PLAYER.x;
		BULLETS[i][0].y = PLAYER.y;
		break;
	    case 2:	
		BULLETS[i][0].isactive = 1;
		BULLETS[i][0].x = PLAYER.x - (4<<8);
		BULLETS[i][0].y = PLAYER.y;
	
		BULLETS[i][1].isactive = 1;
		BULLETS[i][1].x = PLAYER.x + (4<<8);
		BULLETS[i][1].y = PLAYER.y;
		break;
	    case 3:	
		BULLETS[i][0].isactive = 1;
		BULLETS[i][0].x = PLAYER.x - (6<<8);
		BULLETS[i][0].y = PLAYER.y;
	
		BULLETS[i][1].isactive = 1;
		BULLETS[i][1].x = PLAYER.x + (6<<8);
		BULLETS[i][1].y = PLAYER.y;
	
		BULLETS[i][2].isactive = 1;
		BULLETS[i][2].x = PLAYER.x;
		BULLETS[i][2].y = PLAYER.y;
		break;
	    default:
		break;
	    }
	    return;
	}
    }
}

void draw_player(void){
    oam+=move_metasprite_ex(spaceship_sprite_metasprites[0],
			    SPACESHIP_TILE_OFFSET,0,oam,
			    PLAYER.x>>8, PLAYER.y>>8);
    
   }
