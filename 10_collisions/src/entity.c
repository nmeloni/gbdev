#include "entity.h"

void init_entity(Entity* entity, int16_t x, int16_t y, int8_t const * bounding_boxes, metasprite_t * const * sprites, uint8_t tile_offset) {
	entity->x = x<<6;
	entity->y = y<<6;
	entity->bounding_boxes = bounding_boxes;
	entity->sprites = sprites;
	entity->tile_offset = tile_offset;
}

uint8_t check_collision(Entity* a, Entity* b) {
    int8_t const * box_a = a->bounding_boxes;
    int8_t const * box_b = b->bounding_boxes;

    int16_t ax = (a->x >> 6) + box_a[0];
    int16_t ay = (a->y >> 6) + box_a[1];
    int16_t aw = box_a[2];
    int16_t ah = box_a[3];

    int16_t bx = (b->x >> 6) + box_b[0];
    int16_t by = (b->y >> 6) + box_b[1];
    int16_t bw = box_b[2];
    int16_t bh = box_b[3];

    if( (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by) ) {
		uint8_t collision_flags = ENTITY_NO_COLLISION;
		if (ay + ah > by && ay < by) {
			collision_flags |= ENTITY_COLLISION_DOWN;
		}
		if (ay < by + bh && ay + ah > by + bh) {
			collision_flags |= ENTITY_COLLISION_UP;
		}
		if (ax + aw > bx && ax < bx) {
			collision_flags |= ENTITY_COLLISION_RIGHT;
		}
		if (ax < bx + bw && ax + aw > bx + bw) {
			collision_flags |= ENTITY_COLLISION_LEFT;
		}
		return collision_flags;
	}
    return ENTITY_NO_COLLISION;	
}

uint8_t draw_entity(Entity* entity, uint8_t oam_index) {
    // On dessine le metasprite à la position (x, y)
    return move_metasprite_ex(entity->sprites[0],entity->tile_offset,0,oam_index, entity->x>>6, entity->y>>6);
}
