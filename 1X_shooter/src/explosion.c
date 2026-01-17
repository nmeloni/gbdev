#include "explosion.h"


explosion_t EXPLOSIONS[MAX_EXPLOSIONS];
uint8_t queue_start=0, queue_end=0;

void init_explosions(void){
    for (uint8_t i=0; i<MAX_EXPLOSIONS; i++){
	EXPLOSIONS[i].px = 0;
	EXPLOSIONS[i].py = 0;
	EXPLOSIONS[i].framecount = 0;
    }
}
void add_exploision(uint8_t x, uint8_t y){
    EXPLOSIONS[queue_end].px = x;
    EXPLOSIONS[queue_end].py = y;
    EXPLOSIONS[queue_end].framecount = NB_EXPLOSION_FRAME;
    queue_end = (queue_end+1)%MAX_EXPLOSIONS;
}

void handle_explosions(void){
    uint8_t i=queue_start;
    while (i != queue_end){
	if (EXPLOSIONS[i].framecount){
	    EXPLOSIONS[i].framecount--;
	    oam+=move_metasprite_ex(explosion_sprite_metasprites[(EXPLOSIONS[i].framecount & 24)>>3],
				    EXPLOSION_TILE_OFFSET,0,oam,
				    EXPLOSIONS[i].px, EXPLOSIONS[i].py);
	} else {
	    queue_start = i;
	}
	i = (i+1)%MAX_EXPLOSIONS;
    }
}
