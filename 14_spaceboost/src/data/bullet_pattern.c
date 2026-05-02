#include <stdint.h>

#include "player.h"
#include "bullet.h"
#include "utils.h"
#include "bullet_pattern.h"
#include "constants.h"
#include "game_types.h"

const Direction16 shot_down[1] = { DIR_S };
const Direction16 shot_aimed_1[1] = { DIR_AIMED_1 };

const BulletPattern bullet_patterns[] = {
    [BULLET_PATTERN_TYPE_SINGLE_DOWN] = {
    .type = BULLET_TYPE_SMALL,
    .dir = shot_down,
    .length = 1,
    .lag = 10u,
    .cool_down = 10u
    },
    [BULLET_PATTERN_TYPE_NONE] = {
    .type = BULLET_TYPE_NONE,
    .dir = NULL,
    .length = 0,
    .lag = 0,
    .cool_down = 0
    }
};

static inline void handle_aimed_bullet(BulletPatternManager *bpm, Direction16 dir, uint8_t x, uint8_t y);

void init_bullet_pattern_manager(BulletPatternManager * bpm, BulletPatternType type)
{
    bpm->bp = &bullet_patterns[type];
    bpm->current_dir_index = 0;
    bpm->lag_timer = bpm->bp->lag;
    bpm->cool_down_timer = bpm->bp->cool_down;
}

void update_bullet_pattern_manager(BulletPatternManager * bpm, uint8_t x, uint8_t y){
    if (bpm->bp->type == BULLET_TYPE_NONE) return;
    if (bpm->cool_down_timer){
	bpm->cool_down_timer--;
	return;
    }
    if (bpm->bp->lag == 0){
	for (uint8_t i = 0; i < bpm->bp->length; i++){
	    Direction16 dir = bpm->bp->dir[i];
	    if (dir >= DIR_AIMED_1){
		handle_aimed_bullet(bpm, dir, x, y);
	    } else {
		int8_t dx = directions_dx[dir];
		int8_t dy = directions_dy[dir];
		fire_bullet(bpm->bp->type, x, y, dx, dy);
	    }
	}
	bpm->cool_down_timer = bpm->bp->cool_down;
    }
    if (bpm->lag_timer--) return;

    Direction16 dir = bpm->bp->dir[bpm->current_dir_index];
    if (dir >= DIR_AIMED_1){
	handle_aimed_bullet(bpm, dir, x, y);
    } else {
	int8_t dx = directions_dx[dir];
	int8_t dy = directions_dy[dir];

	fire_bullet(bpm->bp->type, x, y, dx, dy);
    }

    bpm->current_dir_index++;
    if (bpm->current_dir_index >= bpm->bp->length){
	bpm->current_dir_index = 0;
	bpm->cool_down_timer = bpm->bp->cool_down;
    }
    bpm->lag_timer = bpm->bp->lag;
}

static inline void handle_aimed_bullet(BulletPatternManager *bpm, Direction16 dir, uint8_t x, uint8_t y){
    Direction16 aimed_dir = aimed_direction(x, y, PLAYER->body.x, PLAYER->body.y);

    int8_t dx = directions_dx[aimed_dir];
    int8_t dy = directions_dy[aimed_dir];
    fire_bullet(bpm->bp->type, x, y, dx, dy);
    if (dir >= DIR_AIMED_3){
	dx = directions_dx[(aimed_dir+1) % DIRECTIONS_NUMBER];
	dy = directions_dy[(aimed_dir+1) % DIRECTIONS_NUMBER];
	fire_bullet(bpm->bp->type, x, y, dx, dy);

	dx = directions_dx[(aimed_dir-1) % DIRECTIONS_NUMBER];
	dy = directions_dy[(aimed_dir-1) % DIRECTIONS_NUMBER];
	fire_bullet(bpm->bp->type, x, y, dx, dy);
    }
    if (dir >= DIR_AIMED_5){
	dx = directions_dx[(aimed_dir+2) % DIRECTIONS_NUMBER];
	dy = directions_dy[(aimed_dir+2) % DIRECTIONS_NUMBER];
	fire_bullet(bpm->bp->type, x, y, dx, dy);

	dx = directions_dx[(aimed_dir-2) % DIRECTIONS_NUMBER];
	dy = directions_dy[(aimed_dir-2) % DIRECTIONS_NUMBER];
	fire_bullet(bpm->bp->type, x, y, dx, dy);
    }

}
