#include "bullet.h"

uint8_t bullet_bounding_box[] = {2,1,4,4};
bullet_t BULLETS[MAX_BULLETS];

void init_bullets(void){
    for (uint8_t i=0; i<MAX_BULLETS; i++){
	BULLETS[i].isactive = 0;
	BULLETS[i].x = 0;
	BULLETS[i].y = 0;
    }
}

void handle_bullets(void){
    for (uint8_t i=0; i<MAX_BULLETS; i++){
	if (BULLETS[i].isactive){
	    if ( BULLETS[i].y > BULLET_SPEED)
		BULLETS[i].y -= BULLET_SPEED;
	    else {
		BULLETS[i].y = 0;
		BULLETS[i].isactive = 0;
	    }
	}
    }
}

void draw_bullets(void){
    for (uint8_t i=0; i<MAX_BULLETS; i++){
	if (BULLETS[i].isactive){
	    oam+=move_metasprite_ex(bullet_sprite_metasprites[0],
				    BULLET_TILE_OFFSET,0,oam,
				    BULLETS[i].x>>6, BULLETS[i].y>>6);
	}
    }
}
