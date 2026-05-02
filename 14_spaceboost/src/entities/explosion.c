#include <stdint.h>

#include "game.h"
#include "constants.h"
#include "explosion.h"
#include "explosion_sprite.h"
#include "utils.h"

Explosion EXPLOSION_QUEUE[MAX_EXPLOSIONS];
uint8_t queue_rear, queue_front;

static inline void draw_explosion(Explosion *ex);

void init_explosions(void) {
    uint8_t i;
    Explosion *ex = &EXPLOSION_QUEUE[0];

    queue_rear = 0;
    queue_front = 0;

    for (i = 0; i < MAX_EXPLOSIONS; i++, ex++) {
	ex->x = 0;
	ex->y = 0;
	ex->frame_timer = 0;
    }
}

void add_explosion(uint8_t x, uint8_t y) {
    Explosion *ex = &EXPLOSION_QUEUE[queue_front];
    ex->x = x;
    ex->y = y;
    ex->frame_timer = EXPLOSION_DURATION;
    queue_front = (queue_front + 1) % MAX_EXPLOSIONS;
}


void update_explosions(void) {
    Explosion *ex = &EXPLOSION_QUEUE[queue_rear];
    for(uint8_t i = queue_rear; i != queue_front; i = (i + 1) % MAX_EXPLOSIONS) {
	ex->frame_timer--;
	if (ex->frame_timer == 0) {
	    queue_rear = (queue_rear + 1) % MAX_EXPLOSIONS;
	}

	if ( (frame_counter^i) % 2) continue;

	uint8_t frame = ex->frame_timer >> EXPLOSION_ANIM_SPEED_LOG2;
	oam += move_metasprite_ex(explosion_sprite_metasprites[3-frame],
				  EXPLOSION_TILE_OFFSET, 0, oam,
				  ex->x, ex->y);
    }
}
