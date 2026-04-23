#include <gb/gb.h>

#include "shot.h"
#include "game.h"
#include "body.h"
#include "player.h"
#include "audio.h"

static void check_shot_bounds(Shot *s);
static void draw_shot(Shot *s);

Shot  SHOTS_POOL[MAX_SHOTS];
uint8_t ACTIVE_SHOTS[MAX_SHOTS];
uint8_t active_shot_index = 0;

const uint8_t shot_bbox[3][2] = {
    {SHOT_LVL1_WIDTH, SHOT_LVL1_HEIGHT},
    {SHOT_LVL2_WIDTH, SHOT_LVL2_HEIGHT},
    {SHOT_LVL3_WIDTH, SHOT_LVL3_HEIGHT}
};

const uint8_t shot_power_table[3] = {
    SHOT_POWER_LVL_1,
    SHOT_POWER_LVL_2,
    SHOT_POWER_LVL_3
};

static const uint8_t shot_tile_offsets[3] = {
    SHOT_TILE_OFFSET,
    SHOT_TILE_OFFSET + 2,
    SHOT_TILE_OFFSET + 4
};

void init_shots(void) {
    Shot *s = &SHOTS_POOL[0];
    for (uint8_t i = 0; i < MAX_SHOTS; i++,s++) {
        s->active = 0;
    }
    active_shot_index = 0;
}

void fire_shot(uint8_t x, uint8_t y, int8_t dx, int8_t dy) {
    Shot *s = &SHOTS_POOL[0];
    for (uint8_t i = 0; i < MAX_SHOTS; i++,s++) {
        if (!s->active) {
            s->active   = 1;
            s->body.x   = x;
            s->body.y   = y;
            s->body.dx  = dx;
            s->body.dy  = dy;
            s->body.fx  = 0;
            s->body.fy  = 0;
            ACTIVE_SHOTS[active_shot_index++] = i;
            audio_play_sfx(SFX_SHOOT);
            break;
        }
    }
}

void update_shots(void) {
    uint8_t *ac = &ACTIVE_SHOTS[0];
    for (uint8_t j = 0; j < active_shot_index; j++,ac++) {
        uint8_t i = *ac;
	Shot *s = &SHOTS_POOL[i];
        update_body_position(&s->body);
        check_shot_bounds(s);
        if (s->active) {
            draw_shot(s);
        } else {
            kill_active_shot(j);
            j--;
        }
    }
}

static void check_shot_bounds(Shot *s) {
    s->active =
        is_inside_bounds(s->body.y, GAMESCREEN_Y_ORIGIN, GAMESCREEN_Y_END) &
        is_inside_bounds(s->body.x, GAMESCREEN_X_ORIGIN, GAMESCREEN_X_END);
}

static void draw_shot(Shot *s) {
    set_sprite_tile(oam, shot_tile_offsets[PLAYER->shoot_power]);
    
    move_sprite(oam++,
                s->body.x + SHOT_ONSCREEN_OFFSET,
                s->body.y + SHOT_ONSCREEN_OFFSET);
}

inline void kill_active_shot(uint8_t j) {
    ACTIVE_SHOTS[j] = ACTIVE_SHOTS[--active_shot_index];
}
