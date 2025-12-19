#include "powerup.h"

const int16_t powerup_pattern[][3] = {
    {-4<<6, 1<<6, 10},
    {-3<<6, 1<<6, 10},
    {-1<<6, 1<<6, 10},
    { 0,    1<<6, 10},
    { 1<<6, 1<<6, 10},
    { 3<<6, 1<<6, 10},
    { 4<<6, 1<<6, 10},
    { 3<<6, 1<<6, 10},
    { 1<<6, 1<<6, 10},
    { 0,    1<<6, 10},
    {-1<<6, 1<<6, 10},
    {-3<<6, 1<<6, 10}
};
powerup_t POWERUP;

void init_powerups(void){
    POWERUP.x = 0;
    POWERUP.y = 0;
    POWERUP.flag = 0;
    POWERUP.isactive = 0;
    POWERUP.activepattern = 0;
    POWERUP.framecount = 0;
}


void handle_powerup(void){
    if (POWERUP.isactive && (level_framecounter % 2 == 0)){
	if (POWERUP.framecount == 0){
	    POWERUP.framecount = powerup_pattern[POWERUP.activepattern][2];
		POWERUP.activepattern+=1;
		if (POWERUP.activepattern >= POWERUP_PATTERN_COUNT){
		    POWERUP.activepattern = 0;
		}
	}
	POWERUP.framecount--;
	POWERUP.x += powerup_pattern[POWERUP.activepattern][0];
	POWERUP.y += powerup_pattern[POWERUP.activepattern][1];
	if (POWERUP.y>>8 > 160){
	    POWERUP.isactive = 0;
	    return;
	}
	
	if ( ((PLAYER.y>>8) < (POWERUP.y>>8)+4) &&
	     ((PLAYER.y>>8) > (POWERUP.y>>8)-4) )
	    if ( ((PLAYER.x>>8) < (POWERUP.x>>8)+4) &&
		 ((PLAYER.x>>8) > (POWERUP.x>>8)-4)){
		//Collision avec le joueur
		POWERUP.isactive = 0;
		//Application de l'effet
		switch (POWERUP.flag){
		    case POWERUP_FLAG_POWER_UP:
			if (PLAYER.power < 3){
			    PLAYER.power += 1;
			}
			break;
		    case POWERUP_FLAG_EXTRA_LIFE:
			PLAYER.lives += 1;
			break;
		    case POWERUP_FLAG_SHIELD:
			PLAYER.flags |= PLAYER_FLAG_SHIELD;
			break;
		}
	    }
    }
    if (POWERUP.isactive){
	oam+=move_metasprite_ex(powerup_sprite_metasprites[0],
				POWERUP_TILE_OFFSET,0,oam,
				POWERUP.x>>8, POWERUP.y>>8);
    }
    
}


void add_powerup(uint8_t x, uint8_t y, uint8_t flag){
    if (!POWERUP.isactive){
	POWERUP.isactive = 1;
	POWERUP.x = x<<8;
	POWERUP.y = y<<8;
	POWERUP.flag = flag;
	POWERUP.activepattern = 0;
	POWERUP.framecount = powerup_pattern[0][2];
    }
}
