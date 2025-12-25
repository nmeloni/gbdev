#include "ennemy.h"

//const int8_t ennemy_1_bounding_box[]={2,2,12,12};
const int8_t ennemy_pattern[][12][3] ={
    {
	//ENNEMY 1
	{-4, 1, 20},
	{-3, 1, 20},
	{-1, 1, 20},
	{ 0, 1, 20},
	{ 1, 1, 20},
	{ 3, 1, 20},
	{ 4, 1, 20},
	{ 3, 1, 20},
	{ 1, 1, 20},
	{ 0, 1, 20},
	{-1, 1, 20},
	{-3, 1, 20}
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

	ACTIVE_ENNEMIES[i]=255;
    }
}

void add_ennemy(uint8_t x, uint8_t y, uint8_t type, int8_t hp){
    uint8_t i;
    for (i=0; i<MAX_ENNEMY; i++) {
	if (!ENNEMIES[i].isactive){
	    ENNEMIES[i].isactive = 1;
	    ENNEMIES[i].x = x<<8;
	    ENNEMIES[i].y = y<<8;
	    ENNEMIES[i].dx = ENNEMY_1_SPEED;
	    ENNEMIES[i].dy = ENNEMY_1_SPEED;
	    ENNEMIES[i].px = x;
	    ENNEMIES[i].py = y;
	    ENNEMIES[i].hp = hp;
	    ENNEMIES[i].activepattern = 0;
	    ENNEMIES[i].type = type;
	    ENNEMIES[i].framecount = ennemy_pattern[type][0][2];

	    ACTIVE_ENNEMIES[active_ennemies_index++] = i;
	    EMU_printf("Ennemy added %d %d %d\n", x,y,type);
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
	// Gestion du pattern
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
	ENNEMIES[i].px = ENNEMIES[i].x >> 8;
	ENNEMIES[i].py = ENNEMIES[i].y >> 8;
	    
	//Collision avec le joueur
	if (((PLAYER.py) < (ENNEMIES[i].py)+8) &&
	    ((PLAYER.py) > (ENNEMIES[i].py)-8) )
	    if ( ((PLAYER.px) < (ENNEMIES[i].px)+8) &&
		 ((PLAYER.px) > (ENNEMIES[i].px)-8)){
		//Collision detected
		if (!(PLAYER.flags & PLAYER_FLAG_INVINCIBLE)){
		    PLAYER.lives--;
		    RESET_PLAYER();
		    kill_active_ennemy(j);
		}
	    }

	//Gestion des tirs ennemis
	//TODO
	    
	//Hors écran ?
	if (ENNEMIES[i].py > 168) kill_active_ennemy(j);

	// Dessine l'ennemi
	if (ENNEMIES[i].isactive){
	    oam+=move_metasprite_ex(ennemy16x16_sprite_metasprites[0],
				    ENNEMY_1_TILE_OFFSET,0,oam,
				    ENNEMIES[i].px, ENNEMIES[i].py);
	}
    }
}

void kill_active_ennemy(uint8_t j){
    ENNEMIES[ACTIVE_ENNEMIES[j]].isactive = 0;
    for (uint8_t i=j; i<active_ennemies_index; i++){
	ACTIVE_ENNEMIES[i] = ACTIVE_ENNEMIES[i+1];
    }
    active_ennemies_index--;
}
