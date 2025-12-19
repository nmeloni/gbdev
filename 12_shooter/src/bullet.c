#include "bullet.h"

const uint8_t bullet_bounding_box[] = {2,1,4,4};
bullet_t BULLETS[MAX_BULLETS][3];

void init_bullets(void){
    for (uint8_t i=0; i<MAX_BULLETS; i++){
	for (uint8_t j=0; j<3; j++){
	    BULLETS[i][j].isactive = 0;
	    BULLETS[i][j].x = 0;
	    BULLETS[i][j].y = 0;
	}
    }
}

void handle_bullets(void){
    for (uint8_t i=0; i<MAX_BULLETS; i++){
	for (uint8_t j=0; j<PLAYER.power; j++){
	    if (!BULLETS[i][j].isactive) continue;
	//EMU_printf("Bullet at %d,%d\n", BULLETS[i][j].x>>8, BULLETS[i][j].y>>8);
	    if ( BULLETS[i][j].y > BULLET_SPEED){
		BULLETS[i][j].y -= BULLET_SPEED;
	    } else {
		BULLETS[i][j].y = 0;
		BULLETS[i][j].isactive = 0;
	    }
	    if (BULLETS[i][j].isactive){
		oam+=move_metasprite_ex(bullet_sprite_metasprites[0],
					BULLET_TILE_OFFSET,0,oam,
					BULLETS[i][j].x>>8, BULLETS[i][j].y>>8);
	    }
	}
    }
}

