#include "ennemybullet.h"

// 0 = droite, sens anti-horaire
const int8_t dir16_vx[4][5] = {
    {+64, +59, +45, +24, 0},
    {+64, +59, +45, +24, 0},
    {-64, -59, -45, -24, 0},
    {-64, -59, -45, -24, 0}
};
const int8_t dir16_vy[4][5] = {
    {0, -24, -45, -59, -64},
    {0, +24, +45, +59, +64},
    {0, -24, -45, -59, -64},
    {0, +24, +45, +59, +64}
};

uint8_t quadrant, angle;

ennemybullet_t ENNEMYBULLETS[ MAX_ENNEMYBULLETS ];

void init_ennemy_bullets(void){
	for (uint8_t i=0; i<MAX_ENNEMYBULLETS; i++){
	ENNEMYBULLETS[i].isactive = 0;
	ENNEMYBULLETS[i].x = 0;
	ENNEMYBULLETS[i].y = 0;
	ENNEMYBULLETS[i].dx = 0;
	ENNEMYBULLETS[i].dy = 0;
	}
}

void add_ennemy_bullet(uint8_t x, uint8_t y, int16_t dx, int16_t dy){
    for (uint8_t i=0; i<MAX_ENNEMYBULLETS; i++){
	if (!ENNEMYBULLETS[i].isactive){
	    ENNEMYBULLETS[i].isactive = 1;
	    ENNEMYBULLETS[i].x = x<<8;
	    ENNEMYBULLETS[i].y = y<<8;
	    ENNEMYBULLETS[i].dx = dx;
	    ENNEMYBULLETS[i].dy = dy;
	    break;
	}
    }
}

void aim_at_player(uint8_t x, uint8_t y){
    uint8_t adx,ady;
    //On décide de la direction du tir
    if (PLAYER.x>>8 < x){
	adx = x - (PLAYER.x>>8);
	quadrant = 2;
    } else {
	adx = (PLAYER.x>>8) - x;
	quadrant = 0;
    }
    if (PLAYER.y>>8 > y){
	ady = (PLAYER.y>>8) - y;
	quadrant |= 1;
    } else {
	ady = y - (PLAYER.y>>8);
    }

    //On choisit l'angle le plus proche
    uint8_t temp;
    if (adx >= ady){
	temp = adx-ady;
	if ( temp>>2 > ady){
	    angle = 0; //Horizontal
	} else if (temp>>1 > ady>>1){
	    angle = 1; //Petit angle
	} else {
	    angle = 2; //Moyen angle
	}
    } else {
	temp = ady-adx;
	if ( temp>>2 > adx){
	    angle = 4; //Vertical
	} else if (temp>>1 > adx>>1){
	    angle = 3; //Grand angle
	} else {
	    angle = 2; //Moyen angle
	}
    }
}

void handle_ennemy_bullets(void){
    for (uint8_t i=0; i<MAX_ENNEMYBULLETS; i++){
	if (ENNEMYBULLETS[i].isactive){
	    //Déplacement
	    ENNEMYBULLETS[i].x += ENNEMYBULLETS[i].dx;
	    ENNEMYBULLETS[i].y += ENNEMYBULLETS[i].dy;
	    //Hors écran ?
	    if (ENNEMYBULLETS[i].x>>8 > 168 || ENNEMYBULLETS[i].y>>8 > 160 ){
		ENNEMYBULLETS[i].isactive = 0;
	    }
	    if ( ((PLAYER.y>>8) < (ENNEMYBULLETS[i].y>>8)+4) &&
		 ((PLAYER.y>>8) > (ENNEMYBULLETS[i].y>>8)-4) )
		if ( ((PLAYER.x>>8) < (ENNEMYBULLETS[i].x>>8)+4) &&
		     ((PLAYER.x>>8) > (ENNEMYBULLETS[i].x>>8)-4)){
		     //Collision avec le joueur
		     //EMU_printf("Player hit by ennemy bullet at %d,%d\n", ENNEMYBULLETS[i].x, ENNEMYBULLETS[i].y);
		     ENNEMYBULLETS[i].isactive = 0;
		     //Gérer les dégats au joueur
		     if (!(PLAYER.flags & PLAYER_FLAG_INVINCIBLE)){
			 PLAYER.lives--;
			 //PLAYER.flags |= PLAYER_FLAG_INVINCIBLE;
			 EMU_printf("Player hit! Lives left: %d\n", PLAYER.x>>8);
		     }
		 }
	    
	    if (ENNEMYBULLETS[i].isactive){
		//Affichage
		//EMU_printf("Draw ennemy bullet at %d,%d\n", ENNEMYBULLETS[i].x, ENNEMYBULLETS[i].y);
		oam+=move_metasprite_ex(ennemybullet_sprite_metasprites[0],
					ENNEMYBULLET_TILE_OFFSET,0,oam,
					ENNEMYBULLETS[i].x>>8, ENNEMYBULLETS[i].y>>8);
	    
	    }
	}
    }
}
