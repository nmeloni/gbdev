#ifndef SHOT_H
#define SHOT_H

#include <gb/gb.h>
#include <stdint.h>
#include <gbdk/metasprites.h>

#include "body.h"
#include "game.h"
#include "player.h"
#include "shot_sprite.h"

#define SHOT_TILE_OFFSET        12
#define SHOT_ONSCREEN_OFFSET   (-4)
#define MAX_SHOTS                5
#define SHOT_SPEED              32

typedef struct {
    uint8_t active;
    body_t body;
} shot_t;

extern shot_t SHOTS_POOL[MAX_SHOTS];
extern uint8_t ACTIVE_SHOTS[MAX_SHOTS];
extern uint8_t active_shot_index;
extern const uint8_t shot_bbox[3][2];
extern const uint8_t shot_power_table[3];

void init_shots(void);
void fire_shot(uint8_t x, uint8_t y, int8_t dx, int8_t dy);
void update_shots(void);

inline void kill_active_shot(uint8_t j);

#endif // SHOT_H
	       
