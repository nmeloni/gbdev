#ifndef ENTITY_H
#define ENTITY_H

#include <gbdk/platform.h>
#include <gbdk/metasprites.h>
#include <stdint.h>

#define ENTITY_NO_COLLISION    0
#define ENTITY_COLLISION_UP    1
#define ENTITY_COLLISION_DOWN  2
#define ENTITY_COLLISION_LEFT  4
#define ENTITY_COLLISION_RIGHT 8


typedef struct Entity {
    int16_t x;
    int16_t y;
    int8_t const * bounding_boxes;
    metasprite_t * const * sprites;
    uint8_t tile_offset;
} Entity;

void init_entity(Entity* entity, int16_t x, int16_t y, int8_t const * bounding_boxes, metasprite_t * const * sprites, uint8_t tile_offset);
uint8_t check_collision(Entity* a, Entity* b);
uint8_t draw_entity(Entity* entityn, uint8_t oam_index);
#endif // ENTITY_H
