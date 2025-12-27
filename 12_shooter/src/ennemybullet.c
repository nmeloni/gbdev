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

const metasprite_t * const * ennemybullet_metasprites[] = {
    ennemybullet_sprite_metasprites,
    ennemylargebullet_sprite_metasprites,
    ennemylaser_sprite_metasprites
};
const uint8_t ennemybullet_tile_offset[] = {
    ENNEMYBULLET_TILE_OFFSET,
    ENNEMYLARGEBULLET_TILE_OFFSET,
    ENNEMYLASER_TILE_OFFSET
};
const int8_t ennemybullet_bbox[][4]= {
    {-6,6,-6,6},
    {-10,10,-10,10},
    {-2,2,-10,20}
};

const uint8_t ennemybullet_speed[]={2,1,3};

ennemybullet_t ENNEMYBULLETS[ MAX_ENNEMYBULLETS ];
uint8_t ACTIVE_ENNEMYBULLETS[ MAX_ENNEMYBULLETS ];
uint8_t active_ennemybullet_index = 0;

void init_ennemy_bullets(void){
	for (uint8_t i=0; i<MAX_ENNEMYBULLETS; i++){
	ENNEMYBULLETS[i].isactive = 0;
	ENNEMYBULLETS[i].x = 0;
	ENNEMYBULLETS[i].y = 0;
	ENNEMYBULLETS[i].dx = 0;
	ENNEMYBULLETS[i].dy = 0;
	ENNEMYBULLETS[i].type = 0;
	ACTIVE_ENNEMYBULLETS[i] = 255;
	}
}

void add_ennemy_bullet(uint8_t x, uint8_t y, int16_t dx, int16_t dy, uint8_t type){
    for (uint8_t i=0; i<MAX_ENNEMYBULLETS; i++){
	if (!ENNEMYBULLETS[i].isactive){
	    ENNEMYBULLETS[i].isactive = 1;
	    ENNEMYBULLETS[i].x = x<<8;
	    ENNEMYBULLETS[i].y = y<<8;
	    ENNEMYBULLETS[i].dx = dx<<(ennemybullet_speed[type]);
	    ENNEMYBULLETS[i].dy = dy<<(ennemybullet_speed[type]);
	    ENNEMYBULLETS[i].px = x;
	    ENNEMYBULLETS[i].py = y;
	    ENNEMYBULLETS[i].type = type;

	    EMU_printf("Adding bullet type %d\n", ENNEMYBULLETS[i].type);
	    ACTIVE_ENNEMYBULLETS[active_ennemybullet_index++] = i;
	    break;
	}
    }
}

void aim_at_player(uint8_t x, uint8_t y){
    uint8_t adx,ady;
    //On décide de la direction du tir
    if (PLAYER.px < x){
	adx = x - (PLAYER.px);
	quadrant = 2;
    } else {
	adx = (PLAYER.px) - x;
	quadrant = 0;
    }
    if (PLAYER.py > y){
	ady = (PLAYER.py) - y;
	quadrant |= 1;
    } else {
	ady = y - (PLAYER.py);
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
    for (uint8_t j=0; j<active_ennemybullet_index; j++){
	uint8_t i = ACTIVE_ENNEMYBULLETS[j];
	
	//Déplacement
	ENNEMYBULLETS[i].x += ENNEMYBULLETS[i].dx;
	ENNEMYBULLETS[i].y += ENNEMYBULLETS[i].dy;
	ENNEMYBULLETS[i].px = ENNEMYBULLETS[i].x>>8;
	ENNEMYBULLETS[i].py = ENNEMYBULLETS[i].y>>8;
	//Hors écran ?
	if (ENNEMYBULLETS[i].px > 168 || ENNEMYBULLETS[i].py > 160 ){
	    kill_active_ennemybullet(j);
	}


	//Gestion de la moitié des bullets pour alléger le rendu
	if ( (level_framecounter - i )%2 ) continue;
	
	uint8_t type = ENNEMYBULLETS[i].type;
	if ( ((PLAYER.px) < (ENNEMYBULLETS[i].px)+ennemybullet_bbox[type][1]) &&
	     ((PLAYER.px) > (ENNEMYBULLETS[i].px)+ennemybullet_bbox[type][0]))
	    if ( ((PLAYER.py) < (ENNEMYBULLETS[i].py)+ennemybullet_bbox[type][3]) &&
		 ((PLAYER.py) > (ENNEMYBULLETS[i].py)+ennemybullet_bbox[type][2]) ){
		//Collision avec le joueur
		//EMU_printf("Player hit by ennemy bullet at %d,%d\n", ENNEMYBULLETS[i].x, ENNEMYBULLETS[i].y);
		kill_active_ennemybullet(j);
		//Gérer les dégats au joueur
		if (PLAYER.flags & PLAYER_FLAG_SHIELD){
		    PLAYER.flags &= (~PLAYER_FLAG_SHIELD);
		    PLAYER.invinsibility_timer = INVINSIBILITY_DURATION;
		} else {
		    if (!PLAYER.invinsibility_timer){
			PLAYER.lives--;
			add_exploision(PLAYER.px, PLAYER.py);
			RESET_PLAYER();
			//kill_active_ennemy(j);
		    }
		}
	    }
	if (ENNEMYBULLETS[i].isactive){
	    //Affichage
	    //EMU_printf("Draw ennemy bullet at %d,%d\n", ENNEMYBULLETS[i].x, ENNEMYBULLETS[i].y);
	    oam+=move_metasprite_ex(ennemybullet_metasprites[type][0],
				    ennemybullet_tile_offset[type],0,oam,
				    ENNEMYBULLETS[i].px, ENNEMYBULLETS[i].py);
	}
    }
}

void kill_active_ennemybullet(uint8_t j){
    ENNEMYBULLETS[ACTIVE_ENNEMYBULLETS[j]].isactive = 0;
    for (uint8_t i=j; i<active_ennemybullet_index; i++){
	ACTIVE_ENNEMYBULLETS[i] = ACTIVE_ENNEMYBULLETS[i+1];
    }
    active_ennemybullet_index--;
}

