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
	POWERUP.px = POWERUP.x >> 8;
	POWERUP.py = POWERUP.y >> 8;
	if (POWERUP.py > 168){
	    POWERUP.isactive = 0;
	    return;
	}
	
	if ( ((PLAYER.py) < (POWERUP.py)+4) &&
	     ((PLAYER.py) > (POWERUP.py)-4) )
	    if ( ((PLAYER.px) < (POWERUP.px)+4) &&
		 ((PLAYER.px) > (POWERUP.px)-4)){
		//Collision avec le joueur
		POWERUP.isactive = 0;
		//Application de l'effet
		switch (POWERUP.flag){
		    case POWERUP_FLAG_POWER_UP:
			if (PLAYER.power < 4){
			    PLAYER.power += 1;
			    if (PLAYER.power == 2){
				PLAYER.bullet_metasprites = bullet_lvl2_sprite_metasprites;
				PLAYER.bullet_sprite_offset = BULLET_LVL2_TILE_OFFSET;
			    }
			    else {
				PLAYER.bullet_metasprites = bullet_lvl3_sprite_metasprites;
				PLAYER.bullet_sprite_offset = BULLET_LVL3_TILE_OFFSET;
			    } 
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
				POWERUP.px, POWERUP.py);
    }
    
}


void add_powerup(uint8_t x, uint8_t y, uint8_t flag){
    if (!POWERUP.isactive){
	POWERUP.isactive = 1;
	POWERUP.x = x<<8;
	POWERUP.y = y<<8;
	POWERUP.px = x;
	POWERUP.py = y;
	POWERUP.flag = flag;
	POWERUP.activepattern = 0;
	POWERUP.framecount = powerup_pattern[0][2];
    }
}
