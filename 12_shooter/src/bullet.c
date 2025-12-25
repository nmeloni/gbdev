#include "bullet.h"

bullet_t BULLETS[MAX_BULLETS];
uint8_t ACTIVE_BULLETS[MAX_BULLETS];
uint8_t active_bullet_index=0;


void init_bullets(void){
    for (uint8_t i=0; i<MAX_BULLETS; i++){
	BULLETS[i].isactive = 0;
	BULLETS[i].x = 0;
	BULLETS[i].y = 0;
	BULLETS[i].px = 0;
	BULLETS[i].py = 0;
    }
}

void handle_bullets(void){
        
    for (uint8_t j=0; j<active_bullet_index; j++){
	uint8_t i = ACTIVE_BULLETS[j];
	uint8_t k;
	if ( BULLETS[i].y > BULLET_SPEED){
	    BULLETS[i].y -= BULLET_SPEED;
	    BULLETS[i].py = BULLETS[i].y>>8;

	    //check for collision with ennemies
	    for (uint8_t l=0; l<active_ennemies_index; l++){
		k = ACTIVE_ENNEMIES[l];
		if ( ((ENNEMIES[k].py) < (BULLETS[i].py)+8) &&
		     ((ENNEMIES[k].py) > (BULLETS[i].py)-8) )
		    if ( ((ENNEMIES[k].px) < (BULLETS[i].px)+8) &&
			 ((ENNEMIES[k].px) > (BULLETS[i].px)-8)){
			//Collision with ennemy
			ENNEMIES[k].hp -= PLAYER.power;
			kill_active_bullet(j);
		    }
	    }
	} else {
	    kill_active_bullet(j);
	}

	if (BULLETS[i].isactive){
	    oam+=move_metasprite_ex(PLAYER.bullet_metasprites[0],
				    PLAYER.bullet_sprite_offset,0,oam,
				    BULLETS[i].px, BULLETS[i].py);
	}
    }
}


void kill_active_bullet(uint8_t j){
    BULLETS[ACTIVE_BULLETS[j]].isactive = 0;
    for (uint8_t i=j; i<active_bullet_index; i++){
	ACTIVE_BULLETS[i] = ACTIVE_BULLETS[i+1];
    }
    active_bullet_index--;
}


