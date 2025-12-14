#include "ennemy.h"

int8_t ennemy_1_bounding_box[]={-6,-6,12,12};
int8_t ennemy_pattern[][12][3] ={
    {
	//ENNEMY 1
	{-4, 1, 30},
	{-3, 1, 30},
	{-1, 1, 30},
	{ 0,    1, 30},
	{ 1, 1, 30},
	{ 3, 1, 30},
	{ 4, 1, 30},
	{ 3, 1, 30},
	{ 1, 1, 30},
	{ 0,    1, 30},
	{-1, 1, 30},
	{-3, 1, 30}
    }
    
};
ennemy_t ENNEMIES[MAX_ENNEMY];


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
    }
}

void add_ennemy(uint8_t x, uint8_t y, uint8_t type){
    uint8_t i;
    for (i=0; i<MAX_ENNEMY; i++) {
	if (!ENNEMIES[i].isactive){
	    ENNEMIES[i].isactive = 1;
	    ENNEMIES[i].x = x<<6;
	    ENNEMIES[i].y = y<<6;
	    ENNEMIES[i].activepattern = 0;
	    ENNEMIES[i].type = type;
	    ENNEMIES[i].framecount = ennemy_pattern[type][0][2];
	    break;
	}
    }
}

void handle_ennemies(void){
    for (uint8_t i=0; i<MAX_ENNEMY; i++){
	if (ENNEMIES[i].isactive){
	    if (ENNEMIES[i].framecount == 0){
		ENNEMIES[i].framecount = ennemy_pattern[ENNEMIES[i].type][ENNEMIES[i].activepattern][2];
		ENNEMIES[i].activepattern+=1;
		if (ENNEMIES[i].activepattern >=  ENNEMY_PATTERN_SIZE ){
		    ENNEMIES[i].activepattern = 0;
		}
	    }
	    ENNEMIES[i].framecount--;
	    ENNEMIES[i].x += ennemy_pattern[ENNEMIES[i].type][ENNEMIES[i].activepattern][0]*ENNEMIES[i].dx;
	    ENNEMIES[i].y += ennemy_pattern[ENNEMIES[i].type][ENNEMIES[i].activepattern][1]*ENNEMIES[i].dy;
	    if (ENNEMIES[i].y > 160<<6) ENNEMIES[i].isactive = 0;
	}
    }
}

void draw_ennemies(void){
    for (uint8_t i=0; i<MAX_ENNEMY; i++){
	if (ENNEMIES[i].isactive){
	    oam+=move_metasprite_ex(ennemy16x16_sprite_metasprites[0],
				    ENNEMY_1_TILE_OFFSET,0,oam,
				    ENNEMIES[i].x>>6, ENNEMIES[i].y>>6);
	}
    }
}
