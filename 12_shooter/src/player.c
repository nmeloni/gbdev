#include "player.h"

uint8_t current_joypad, previous_joypad;
uint8_t spaceship_bounding_box[] = {6,1,4,14};

    
player_t PLAYER;

void init_player(void){
    RESET_PLAYER();
    PLAYER.lives = 3;
    PLAYER.bbx = spaceship_bounding_box;
    PLAYER.sprites = spaceship_sprite_metasprites;
}

void handle_player(void){
    if (PLAYER.boost) {
	PLAYER.dx = BOOST_SPEED;
	PLAYER.dy = BOOST_SPEED;
	PLAYER.boost --;
    } else {
	PLAYER.dx = NORMAL_SPEED;
	PLAYER.dy = NORMAL_SPEED;
    }
    if (PLAYER.last_boost) PLAYER.last_boost--;
    if (KEY_PRESSED(J_A)){
	if (!PLAYER.last_boost){
	    PLAYER.boost = BOOST_DURATION;
	    PLAYER.last_boost = BOOST_LAG;
	}
    }
    if (KEY_PRESSED(J_LEFT)){
	PLAYER.x -= PLAYER.dx;
    }
    if (KEY_PRESSED(J_RIGHT)){
	PLAYER.x += PLAYER.dx;
    }
    if (KEY_PRESSED(J_UP)){
	PLAYER.y -= PLAYER.dy;
    }
    if (KEY_PRESSED(J_DOWN)){
	PLAYER.y += PLAYER.dy;
    }
    if (KEY_PRESSED(J_B)){
	if (PLAYER.last_shot) PLAYER.last_shot--;
	else shoot();
    }
}

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
}



void shoot(void){
    uint8_t nb_bullets = PLAYER.power;
    uint8_t free_bullets[3]={255,255,255};

    //on recupère les sprite disponible
    for (uint8_t i=0; i<MAX_BULLETS; i++){
	
	if (!BULLETS[i].isactive){
	    free_bullets[nb_bullets-1]=i;
	    nb_bullets--;
	    
	}
	if (nb_bullets == 0) break;
    }
    //pas assez de sprites de libre
    if (nb_bullets) return;
    
    if (PLAYER.power == 1){
	BULLETS[free_bullets[0]].isactive = 1;
	BULLETS[free_bullets[0]].x = PLAYER.x;
	BULLETS[free_bullets[0]].y = PLAYER.y;
	PLAYER.last_shot = SHOOT_LAG;
    }
    if (PLAYER.power == 2){	
	BULLETS[free_bullets[0]].isactive = 1;
	BULLETS[free_bullets[0]].x = PLAYER.x - (4<<6);
	BULLETS[free_bullets[0]].y = PLAYER.y;
	
	BULLETS[free_bullets[1]].isactive = 1;
	BULLETS[free_bullets[1]].x = PLAYER.x + (4<<6);
	BULLETS[free_bullets[1]].y = PLAYER.y;
	PLAYER.last_shot = SHOOT_LAG;
    }
    if (PLAYER.power == 3){	
	BULLETS[free_bullets[0]].isactive = 1;
	BULLETS[free_bullets[0]].x = PLAYER.x - (6<<6);
	BULLETS[free_bullets[0]].y = PLAYER.y;
	
	BULLETS[free_bullets[1]].isactive = 1;
	BULLETS[free_bullets[1]].x = PLAYER.x + (6<<6);
	BULLETS[free_bullets[1]].y = PLAYER.y;
	
	BULLETS[free_bullets[2]].isactive = 1;
	BULLETS[free_bullets[2]].x = PLAYER.x;
	BULLETS[free_bullets[2]].y = PLAYER.y;
	PLAYER.last_shot = SHOOT_LAG;

    }
    
}

void draw_player(void){
    oam+=move_metasprite_ex(PLAYER.sprites[0],
		       SPACESHIP_TILE_OFFSET,0,0,
		       PLAYER.x>>6, PLAYER.y>>6);
}
