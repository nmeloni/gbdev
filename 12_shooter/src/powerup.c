#include "powerup.h"

uint8_t powerup_bounding_box[] = {0,0,8,8};
int16_t powerup_pattern[][3] = {
    {-4<<4, 1<<4, 10},
    {-3<<4, 1<<4, 10},
    {-1<<4, 1<<4, 10},
    { 0,    1<<4, 10},
    { 1<<4, 1<<4, 10},
    { 3<<4, 1<<4, 10},
    { 4<<4, 1<<4, 10},
    { 3<<4, 1<<4, 10},
    { 1<<4, 1<<4, 10},
    { 0,    1<<4, 10},
    {-1<<4, 1<<4, 10},
    {-3<<4, 1<<4, 10}
};
powerup_t POWERUPS[MAX_POWERUPS];

void init_powerups(void){
    for (uint8_t i=0; i< MAX_POWERUPS; i++){
	POWERUPS[i].x = 0;
	POWERUPS[i].y = 0;
	POWERUPS[i].isactive = 0;
	POWERUPS[i].activepattern = 0;
	POWERUPS[i].framecount = 0;
    }
}

void handle_powerups(void){
    for (uint8_t i=0; i<MAX_POWERUPS; i++){
	if (POWERUPS[i].isactive){
	    if (POWERUPS[i].framecount == 0){
		POWERUPS[i].framecount = powerup_pattern[POWERUPS[i].activepattern][2];
		POWERUPS[i].activepattern+=1;
		if (POWERUPS[i].activepattern >= POWERUP_PATTERN_COUNT){
		    POWERUPS[i].activepattern = 0;
		}
	    }
	    POWERUPS[i].framecount--;
	    POWERUPS[i].x += powerup_pattern[POWERUPS[i].activepattern][0];
	    POWERUPS[i].y += powerup_pattern[POWERUPS[i].activepattern][1];
	    if (POWERUPS[i].y > 160<<6) POWERUPS[i].isactive = 0;
	}
    }
}

void add_powerup(uint8_t x, uint8_t y){
    for (uint8_t i=0; i<MAX_POWERUPS; i++) {
	if (!POWERUPS[i].isactive){
	    POWERUPS[i].isactive = 1;
	    POWERUPS[i].x = x<<6;
	    POWERUPS[i].y = y<<6;
	    POWERUPS[i].activepattern = 0;
	    POWERUPS[i].framecount = powerup_pattern[0][2];
	    break;
	}
    }
}


void draw_powerups(void){
    for (uint8_t i=0; i<MAX_POWERUPS; i++){
	if (POWERUPS[i].isactive){
	    oam+=move_metasprite_ex(powerup_sprite_metasprites[0],
				    POWERUP_TILE_OFFSET,0,oam,
				    POWERUPS[i].x>>6, POWERUPS[i].y>>6);
	}
    }
}
