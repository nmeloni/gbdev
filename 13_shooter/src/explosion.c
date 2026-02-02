#include "explosion.h"

explosion_t EXPLOSION_QUEUE[MAX_EXPLOSIONS];
uint8_t queue_rear, queue_front;

void init_explosions(void) {
    queue_rear = 0;
    queue_front = 0;
}

void add_explosion(uint8_t x, uint8_t y) {
    EXPLOSION_QUEUE[queue_front].x = x;
    EXPLOSION_QUEUE[queue_front].y = y;
    EXPLOSION_QUEUE[queue_front].frame_counter = EXPLOSION_FRAME_DURATION;
    queue_front = (queue_front + 1) % MAX_EXPLOSIONS;

    audio_play_sfx(SFX_EXPLODE);
}

void update_explosions(void) {
    for(uint8_t i = queue_rear; i != queue_front; i = (i + 1) % MAX_EXPLOSIONS) {
	uint8_t frame = EXPLOSION_QUEUE[i].frame_counter >> EXPLOSION_ANIM_SPEED;
	oam += move_metasprite_ex(explosion_sprite_metasprites[frame],
				  EXPLOSION_TILE_OFFSET, 0, oam,
				  EXPLOSION_QUEUE[i].x, EXPLOSION_QUEUE[i].y);
	EXPLOSION_QUEUE[i].frame_counter--;
	if (EXPLOSION_QUEUE[i].frame_counter == 0) {
	    queue_rear = (queue_rear + 1) % MAX_EXPLOSIONS;
	}
    }
}
	    
	    
