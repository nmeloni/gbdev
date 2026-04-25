#include <stdint.h>

#include "bullet.h"
#include "utils.h"
#include "bullet_pattern.h"
#include "constants.h"
#include "game_types.h"

const Direction16 shot_down[1] = { DIR_S };

const BulletPattern bullet_patterns[] = {
    [BULLET_PATTERN_TYPE_SINGLE_DOWN] = {
    .type = BULLET_TYPE_SMALL,
    .dir = shot_down,
    .length = 1,
    .lag = 0,
    .cool_down = 60
    } 
};

const BulletPatternType bullet_pattern_data[] = {
    [ENEMY_DRONE] = BULLET_PATTERN_TYPE_SINGLE_DOWN
};

void init_bullet_pattern_manager(BulletPatternManager * bpm, BulletPatternType type)
{
    bpm->bp = &bullet_patterns[type];
    bpm->current_dir_index = 0;
    bpm->lag_timer = bpm->bp->lag;
    bpm->cool_down_timer = bpm->bp->cool_down;
}

void update_bullet_pattern_manager(BulletPatternManager * bpm, uint8_t x, uint8_t y){
    if (bpm->cool_down_timer--) return;
    if (bpm->bp->lag == 0){
	for (uint8_t i = 0; i < bpm->bp->length; i++){
	    Direction16 dir = bpm->bp->dir[i];
	    int8_t dx = directions_dx[dir];
	    int8_t dy = directions_dy[dir];
	    fire_bullet(bpm->bp->type, x, y, dx, dy);
	}
	bpm->cool_down_timer = bpm->bp->cool_down;
    }
    if (bpm->lag_timer--) return;
    Direction16 dir = bpm->bp->dir[bpm->current_dir_index];
    int8_t dx = directions_dx[dir];
    int8_t dy = directions_dy[dir];
    fire_bullet(bpm->bp->type, x, y, dx, dy);
    bpm->current_dir_index++;
    if (bpm->current_dir_index >= bpm->bp->length){
	bpm->current_dir_index = 0;
	bpm->cool_down_timer = bpm->bp->cool_down;
    }
    bpm->lag_timer = bpm->bp->lag;
}
