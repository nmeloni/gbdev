#include "ennemy.h"


const metasprite_t * const * ennemy_metasprites[] = {
    ennemy_1_sprite_metasprites,
    ennemy_2_sprite_metasprites,
    ennemy_3_sprite_metasprites
};
const uint8_t ennemy_tile_offset[] = {
    ENNEMY_1_TILE_OFFSET,
    ENNEMY_2_TILE_OFFSET,
    ENNEMY_3_TILE_OFFSET
};
const int8_t ennemy_bbox[][4]= {
    {-10,10,-10,10},
    {-10,10,-10,10},
    {-10,10,-10,10}
};
//const int8_t ennemy_1_bounding_box[]={2,2,12,12};
const int8_t ennemy_pattern[][ENNEMY_PATTERN_SIZE][5] ={
    {
	//PATTERN 0
	{ 2, 0, 20, 0, 0},
	{ 0, 1, 1, ENNEMY_SHOOT|ENNEMYBULLET_TYPE_LASER, ENNEMY_SHOOT_DOWN},
	{ 0, 2, 9, 0, 0},
	{ 0, 1, 9, 0, 0},
	{-2, 0, 20, 0, 0},
	{-2, 0, 19, 0, 0},
	{-2, 0, 1, ENNEMY_SHOOT|ENNEMYBULLET_TYPE_LASER, ENNEMY_SHOOT_DOWN},
	{-2, 0, 20, 0, 0},
	{-2, 0, 20, 0, 0},
	{ 0, 1, 1, ENNEMY_SHOOT|ENNEMYBULLET_TYPE_LASER, ENNEMY_SHOOT_DOWN},
	{ 0, 2, 9, 0, 0},
	{ 0, 1, 9, 0, 0},
	{ 2, 0, 20, 0, 0},
	{ 2, 0, 19, 0, 0},
	{ 2, 0,  1, ENNEMY_SHOOT|ENNEMYBULLET_TYPE_LASER, ENNEMY_SHOOT_DOWN},
	{ 2, 0, 20, 0, 0}
    },
    {
	//PATTERN 1
	{ 0, 1, 1, ENNEMY_SHOOT|ENNEMYBULLET_TYPE_NORMAL, ENNEMY_SHOOT_DOWN},
	{ 0, 1, 7, 0, 0 },
	{ 0, 1, 1, ENNEMY_SHOOT|ENNEMYBULLET_TYPE_NORMAL, ENNEMY_SHOOT_DOWN_LEFT},
	{ 0, 1, 7, 0, 0 },
	{ 0, 1, 1, ENNEMY_SHOOT|ENNEMYBULLET_TYPE_NORMAL, ENNEMY_SHOOT_LEFT},
	{ 0, 1, 7, 0, 0 },
	{ 0, 1, 1, ENNEMY_SHOOT|ENNEMYBULLET_TYPE_NORMAL, ENNEMY_SHOOT_UP_LEFT},
	{ 0, 1, 7, 0, 0 },
	{ 0, 1, 1, ENNEMY_SHOOT|ENNEMYBULLET_TYPE_NORMAL, ENNEMY_SHOOT_UP_LEFT_UP},
	{ 0, 1, 7, 0, 0 },
	{ 0, 1, 1, ENNEMY_SHOOT|ENNEMYBULLET_TYPE_NORMAL, ENNEMY_SHOOT_UP_LEFT_LEFT},
	{ 0, 1, 7, 0, 0 },
	{ 0, 1, 1, ENNEMY_SHOOT|ENNEMYBULLET_TYPE_NORMAL, ENNEMY_SHOOT_DOWN_LEFT_LEFT},
	{ 0, 1, 7, 0, 0 },
	{ 0, 1, 1, ENNEMY_SHOOT|ENNEMYBULLET_TYPE_NORMAL, ENNEMY_SHOOT_DOWN_LEFT_DOWN},
	{ 0, 1, 7, 0, 0 },
    },
    {
	//PATTERN 2
	{ 0, 1, 1, ENNEMY_SHOOT|ENNEMYBULLET_TYPE_NORMAL, ENNEMY_SHOOT_DOWN},
	{ 0, 1, 7, 0, 0 },
	{ 0, 1, 1, ENNEMY_SHOOT|ENNEMYBULLET_TYPE_NORMAL, ENNEMY_SHOOT_DOWN_RIGHT},
	{ 0, 1, 7, 0, 0 },
	{ 0, 1, 1, ENNEMY_SHOOT|ENNEMYBULLET_TYPE_NORMAL, ENNEMY_SHOOT_RIGHT},
	{ 0, 1, 7, 0, 0 },
	{ 0, 1, 1, ENNEMY_SHOOT|ENNEMYBULLET_TYPE_NORMAL, ENNEMY_SHOOT_UP_RIGHT},
	{ 0, 1, 7, 0, 0 },
	{ 0, 1, 1, ENNEMY_SHOOT|ENNEMYBULLET_TYPE_NORMAL, ENNEMY_SHOOT_UP_RIGHT_UP},
	{ 0, 1, 7, 0, 0 },
	{ 0, 1, 1, ENNEMY_SHOOT|ENNEMYBULLET_TYPE_NORMAL, ENNEMY_SHOOT_UP_RIGHT_RIGHT},
	{ 0, 1, 7, 0, 0 },
	{ 0, 1, 1, ENNEMY_SHOOT|ENNEMYBULLET_TYPE_NORMAL, ENNEMY_SHOOT_DOWN_RIGHT_RIGHT},
	{ 0, 1, 7, 0, 0 },
	{ 0, 1, 1, ENNEMY_SHOOT|ENNEMYBULLET_TYPE_NORMAL, ENNEMY_SHOOT_DOWN_RIGHT_DOWN},
	{ 0, 1, 7, 0, 0 },
    },
    {
	//PATTERN 3
	{ 0, 1, 1, ENNEMY_SHOOT|ENNEMYBULLET_TYPE_NORMAL, ENNEMY_SHOOT_DOWN},
	{ 0, 1, 7, 0, 0 },
	{ 0, 1, 1, ENNEMY_SHOOT|ENNEMYBULLET_TYPE_NORMAL, ENNEMY_SHOOT_LEFT},
	{ 0, 1, 7, 0, 0 },
	{ 0, 1, 1, ENNEMY_SHOOT|ENNEMYBULLET_TYPE_NORMAL, ENNEMY_SHOOT_UP},
	{ 0, 1, 7, 0, 0 },
	{ 0, 1, 1, ENNEMY_SHOOT|ENNEMYBULLET_TYPE_NORMAL, ENNEMY_SHOOT_RIGHT},
	{ 0, 1, 7, 0, 0 },
	{ 0, 1, 1, ENNEMY_SHOOT|ENNEMYBULLET_TYPE_NORMAL, ENNEMY_SHOOT_DOWN_LEFT},
	{ 0, 1, 7, 0, 0 },
	{ 0, 1, 1, ENNEMY_SHOOT|ENNEMYBULLET_TYPE_NORMAL, ENNEMY_SHOOT_UP_LEFT},
	{ 0, 1, 7, 0, 0 },
	{ 0, 1, 1, ENNEMY_SHOOT|ENNEMYBULLET_TYPE_NORMAL, ENNEMY_SHOOT_UP_RIGHT},
	{ 0, 1, 7, 0, 0 },
	{ 0, 1, 1, ENNEMY_SHOOT|ENNEMYBULLET_TYPE_NORMAL, ENNEMY_SHOOT_DOWN_RIGHT},
	{ 0, 1, 7, 0, 0 }

    },
    {
	//PATTERN 4
	{-4, 1, 20, 0, 0},
	{-3, 1, 20, 0, 0},
	{-1, 1, 20, 0, 0},
	{ 0, 1, 20, 0, 0},
	{ 1, 1, 20, 0, 0},
	{ 3, 1, 20, 0, 0},
	{ 4, 1, 9, 0, 0},
	{ 4, 1, 1, 0, 0},
	{ 4, 1, 1, ENNEMY_SHOOT|ENNEMYBULLET_TYPE_NORMAL, ENNEMY_AIM},
	{ 4, 1, 1, 0, 0},
	{ 4, 1, 8, 0, 0},
	{ 3, 1, 20, 0, 0},
	{ 1, 1, 20, 0, 0},
	{ 0, 1, 20, 0, 0},
	{-1, 1, 20, 0, 0},
	{-3, 1, 20, 0, 0}
    }
    
};
ennemy_t ENNEMIES[MAX_ENNEMY];
uint8_t  ACTIVE_ENNEMIES[MAX_ENNEMY];
uint8_t  active_ennemies_index = 0;

void init_enemies(void){
    for (uint8_t i=0; i<MAX_ENNEMY; i++){
	ENNEMIES[i].isactive = 0;
	ENNEMIES[i].x = 0;
	ENNEMIES[i].y = 0;
	ENNEMIES[i].dx = 0;
	ENNEMIES[i].dy = 0;
	ENNEMIES[i].framecount = 0;
	ENNEMIES[i].activepattern = 0;
	ENNEMIES[i].type = ENNEMY_1;
	ENNEMIES[i].ishit = 0;

	ACTIVE_ENNEMIES[i]=255;
    }
}

void add_ennemy(uint8_t x, uint8_t y, uint8_t type, uint8_t pattern, uint16_t speed, int8_t hp){
    uint8_t i;
    for (i=0; i<MAX_ENNEMY; i++) {
	if (!ENNEMIES[i].isactive){
	    ENNEMIES[i].isactive = 1;
	    ENNEMIES[i].x = x<<8;
	    ENNEMIES[i].y = y<<8;
	    ENNEMIES[i].dx = speed;
	    ENNEMIES[i].dy = speed;
	    ENNEMIES[i].px = x;
	    ENNEMIES[i].py = y;
	    ENNEMIES[i].hp = hp;
	    ENNEMIES[i].pattern = pattern;
	    ENNEMIES[i].activepattern = 0;
	    ENNEMIES[i].type = type;
	    ENNEMIES[i].framecount = ennemy_pattern[pattern][0][2];

	    ACTIVE_ENNEMIES[active_ennemies_index++] = i;
	    
	    return;	    
	}
    }
}

void handle_ennemies(void){
    for (uint8_t j=0; j < active_ennemies_index; j++){
	uint8_t i = ACTIVE_ENNEMIES[j];
	if (ENNEMIES[i].hp <= 0){
	    kill_active_ennemy(j);
	    continue;
	}

	uint8_t type = ENNEMIES[i].type;
	uint8_t pattern = ENNEMIES[i].pattern;
	uint8_t activepattern = ENNEMIES[i].activepattern;
	// Gestion du pattern
	if (ENNEMIES[i].framecount == 0){
	    ENNEMIES[i].activepattern= (activepattern+1)%ENNEMY_PATTERN_SIZE;
	    activepattern = ENNEMIES[i].activepattern;
	    ENNEMIES[i].framecount = ennemy_pattern[pattern][activepattern][2];
	}
	
	ENNEMIES[i].framecount--;
	ENNEMIES[i].x += ennemy_pattern[pattern][activepattern][0]*ENNEMIES[i].dx;
	ENNEMIES[i].y += ennemy_pattern[pattern][activepattern][1]*ENNEMIES[i].dy;
	ENNEMIES[i].px = ENNEMIES[i].x >> 8;
	ENNEMIES[i].py = ENNEMIES[i].y >> 8;

	if (ennemy_pattern[pattern][activepattern][3]&ENNEMY_SHOOT){
	    
	    if (ennemy_pattern[pattern][activepattern][4] & ENNEMY_AIM){
		aim_at_player(ENNEMIES[i].px,ENNEMIES[i].py);
	    } else {
		quadrant = ennemy_pattern[pattern][activepattern][4] & ENNEMY_SHOOT_QUADRANT;
		angle = (ennemy_pattern[pattern][activepattern][4] & ENNEMY_SHOOT_ANGLE)>>2;
	    }
	    add_ennemy_bullet(ENNEMIES[i].px,
			      ENNEMIES[i].py,
			      dir16_vx[quadrant][angle],
			      dir16_vy[quadrant][angle],
			      ennemy_pattern[pattern][activepattern][3]&(15));
	}

	    
	//Collision avec le joueur
	if (((PLAYER.py) < (ENNEMIES[i].py)+8) &&
	    ((PLAYER.py) > (ENNEMIES[i].py)-8) )
	    if ( ((PLAYER.px) < (ENNEMIES[i].px)+8) &&
		 ((PLAYER.px) > (ENNEMIES[i].px)-8)){
		//Collision detected
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

	//Gestion des tirs ennemis
	//TODO
	    
	//Hors écran ?
	if (ENNEMIES[i].py > 168) kill_active_ennemy(j);
	// Dessine l'ennemi
	if (ENNEMIES[i].isactive){
	    uint8_t palette = 0;
	    if (ENNEMIES[i].ishit){
		ENNEMIES[i].ishit--;
		palette = 16;
	    }
	    oam+=move_metasprite_ex(ennemy_metasprites[type][0],
				    ennemy_tile_offset[type],palette,oam,
				    ENNEMIES[i].px, ENNEMIES[i].py);
	}
    }
}

void kill_active_ennemy(uint8_t j){
    ENNEMIES[ACTIVE_ENNEMIES[j]].isactive = 0;
    if (ENNEMIES[ACTIVE_ENNEMIES[j]].hp<=0) add_exploision(ENNEMIES[ACTIVE_ENNEMIES[j]].px,ENNEMIES[ACTIVE_ENNEMIES[j]].py );
    for (uint8_t i=j; i<active_ennemies_index; i++){
	ACTIVE_ENNEMIES[i] = ACTIVE_ENNEMIES[i+1];
    }
    active_ennemies_index--;
}
