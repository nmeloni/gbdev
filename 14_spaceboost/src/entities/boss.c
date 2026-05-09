#include "game_types.h"
#include "game.h"
#include "utils.h"
#include "body.h"
#include "shot.h"
#include "boss.h"
#include "player.h"
#include "explosion.h"
#include "bullet_pattern.h"

#include "boss_beholder_sprite.h"

#define BOSS_PATTERN_LATERAL_LEN 16
#define BOSS_PATTERN_SHAKE_LEN   16

static const StaticPattern move_lateral[16] = {
    {.dx =   16, .dy =  0, .duration = 16},
    {.dx =  12, .dy =  0, .duration = 32},
    {.dx =   8, .dy =  0, .duration = 32},
    {.dx =   4, .dy =  0, .duration = 32},
    {.dx =    0, .dy =  0, .duration = 16},
    {.dx =  -4, .dy =  0, .duration = 32},
    {.dx =  -8, .dy =  0, .duration = 32},
    {.dx = -12, .dy =  0, .duration = 32},
    {.dx =  -16, .dy =  0, .duration = 16},
    {.dx = -12, .dy =  0, .duration = 32},
    {.dx =  -8, .dy =  0, .duration = 32},
    {.dx =  -4, .dy =  0, .duration = 32},
    {.dx =    0, .dy =  0, .duration = 16},
    {.dx =   4, .dy =  0, .duration = 32},
    {.dx =   8, .dy =  0, .duration = 32},
    {.dx =  12, .dy =  0, .duration = 32}
};

static const Direction16 shake_lut[16] = {
    11, 1, 9, 8, 12, 6, 3, 2, 7, 13, 15, 14, 5, 4, 0, 10
};

static inline void handle_boss_intro(void);
static inline void handle_boss_status(void);
static inline void handle_boss_move_pattern(void);
static inline void handle_boss_vs_shot_collision(void);
static inline void handle_boss_vs_player(void);

static inline void change_phase(void);
static inline void change_pattern(void);

static inline void hit_boss(void);
static inline void draw_boss(void);

static inline void boss_pattern_start(void);
static inline void boss_shake(void);
static inline void boss_wait(void);
static inline void boss_aim_at_player(void);
static inline void boss_charge_at_direction(void);
static inline void boss_center(void);
static inline void lateral_pattern(void);
static inline void go_to_position(uint8_t x, uint8_t y);
static inline void boss_wink(void);
static inline void boss_destroy(void);

static uint8_t static_pattern_step_counter = 0;
static Direction16 dir = 0;

const BossMovePatternType beholder_move_patterns[8][8]={
    [BOSS_PHASE_INTRO]     = {
        BOSS_PATTERN_START,
        BOSS_PATTERN_GO_TO_START_POSITION,
        BOSS_PATTERN_WINK,
        BOSS_PATTERN_CHANGE_PHASE,
        BOSS_PATTERN_END
    },
    [BOSS_PHASE_1]         = {
        BOSS_PATTERN_START,
        BOSS_PATTERN_LATERAL,
        BOSS_PATTERN_END
    },
    [BOSS_TRANSITION_1_2]  = {
        BOSS_PATTERN_START,
        BOSS_PATTERN_GO_TO_START_POSITION,
        BOSS_PATTERN_WINK,
        BOSS_PATTERN_CHANGE_PHASE,
        BOSS_PATTERN_END
    },
    [BOSS_PHASE_2]         = {
        BOSS_PATTERN_START,
        BOSS_PATTERN_SHAKE,
        BOSS_PATTERN_WAIT,
        BOSS_PATTERN_AIM_AT_PLAYER,
        BOSS_PATTERN_CHARGE_AT_DIRECTION,
        BOSS_PATTERN_CENTER,
        BOSS_PATTERN_END
    },
    [BOSS_TRANSITION_2_3]  = {
        BOSS_PATTERN_START,
        BOSS_PATTERN_GO_TO_START_POSITION,
        BOSS_PATTERN_WINK,
        BOSS_PATTERN_CHANGE_PHASE,
        BOSS_PATTERN_END
    },
    [BOSS_PHASE_3]         =  {
        BOSS_PATTERN_START,
        BOSS_PATTERN_SHAKE,
        BOSS_PATTERN_WAIT,
        BOSS_PATTERN_AIM_AT_PLAYER,
        BOSS_PATTERN_CHARGE_AT_DIRECTION,
        BOSS_PATTERN_CENTER,
        BOSS_PATTERN_END
    },
    [BOSS_PHASE_DEFEATED]  = {
        BOSS_PATTERN_START,
        BOSS_PATTERN_DESTROY,
        BOSS_PATTERN_END
    }
};

Boss boss;
Boss *BOSS = &boss;



void init_boss(void)  {
    init_body(&BOSS->body, 0, 0);
    BOSS->active = 0;
    BOSS->hittable = 0;
    BOSS->ishit = 0;
    BOSS->phase = BOSS_PHASE_INTRO;
    BOSS->frame = 0;
    BOSS->current_pattern_index = 0;
    BOSS->move_pattern_list = NULL;
    BOSS->static_pattern = NULL;
    BOSS->static_pattern_len = 0;

}

void spawn_boss(BossId boss_id) {
    switch (boss_id){
    case BOSS_BEHOLDER:
        BOSS->active = 1;
        init_body(&BOSS->body, 88, 0);
        BOSS->bbox_w = BOSS_BEHOLDER_BBOX_W;
        BOSS->bbox_h = BOSS_BEHOLDER_BBOX_H;

        BOSS->phase  = BOSS_PHASE_INTRO;
        BOSS->move_pattern_list = beholder_move_patterns;
        BOSS->current_pattern   = BOSS_PATTERN_START;

        BOSS->frame    = 0;
        BOSS->hittable = 0;
        BOSS->ishit    = 0;
        BOSS->hp       = BOSS_BEHOLDER_HP_PHASE_1;
        BOSS->timer    = BOSS_BEHOLDER_ENTER_TIMER;

        init_bullet_pattern_manager(&BOSS->bpm,
                                    BULLET_PATTERN_TYPE_NONE);
        BOSS->metasprites = boss_beholder_sprite_metasprites;

        set_sprite_data(BOSS_TILE_OFFSET,
                        boss_beholder_sprite_TILE_COUNT,
                        boss_beholder_sprite_tiles);
        break;
    default:
        break;
    }
}

void update_boss(void) {
    handle_boss_status();
    handle_boss_move_pattern();
    update_bullet_pattern_manager(&BOSS->bpm, BOSS->body.x, BOSS->body.y);
    update_body_position(&BOSS->body);
    if (BOSS->hittable){
        handle_boss_vs_shot_collision();
    }
    handle_boss_vs_player();
    draw_boss();
}


static inline void handle_boss_move_pattern(void){
    switch (BOSS->current_pattern){
    case BOSS_PATTERN_START:
        boss_pattern_start();
        break;
    case BOSS_PATTERN_GO_TO_START_POSITION:
        go_to_position(84u,60u);
        break;
    case BOSS_PATTERN_WINK:
        boss_wink();
        break;
    case BOSS_PATTERN_CHANGE_PHASE:
        change_phase();
        break;
    case BOSS_PATTERN_LATERAL:
        lateral_pattern();
        break;
    case BOSS_PATTERN_SHAKE:
        boss_shake();
        break;
    case BOSS_PATTERN_WAIT:
        boss_wait();
        break;
    case BOSS_PATTERN_AIM_AT_PLAYER:
        boss_aim_at_player();
        break;
    case BOSS_PATTERN_CHARGE_AT_DIRECTION:
        boss_charge_at_direction();
        break;
    case BOSS_PATTERN_CENTER:
        boss_center();
        break;
    case BOSS_PATTERN_DESTROY:
        boss_destroy();
        break;
    default:
        break;
    }

}
static inline void handle_boss_vs_shot_collision(void){
    uint8_t *ac = &ACTIVE_SHOTS[0];

    for (uint8_t j = 0; j < active_shot_index; j++,ac++) {
        uint8_t i = *ac;
        Shot *s = &SHOTS_POOL[i];

        // On test d'abord la distance manathan pour eliminer les
        // entité trop distantes

        if (manathan_distance(BOSS->body.x, BOSS->body.y, s->body.x, s->body.y) >=
            BOSS_VS_SHOT_MAN_DIST)
            continue;

        if (check_collision_box(s->body.x, s->body.y, shot_bbox_w, shot_bbox_h,
                                BOSS->body.x, BOSS->body.y, BOSS->bbox_w, BOSS->bbox_h)){

            hit_boss();
            desactivate_shot(s);
            kill_active_shot(j);

            return;
        }
    }
}

static inline void handle_boss_vs_player(void){
    if (PLAYER->invincibility_timer) return;
    if (check_collision_box(PLAYER->body.x,  PLAYER->body.y,
                            PLAYER_BBOX_W, PLAYER_BBOX_H,
                            BOSS->body.x, BOSS->body.y,
                            BOSS->bbox_w, BOSS->bbox_h)){
        hit_player();
    }
}

static inline void handle_boss_status(void){
    switch (BOSS->phase){
    case BOSS_PHASE_1:
    case BOSS_PHASE_2:
    case BOSS_PHASE_3:
        if (BOSS->hp < 0){
            change_phase();
        }
        break;
    default:
        break;
    }
}

static inline void hit_boss(void){
    BOSS->ishit = BOSS_HIT_TIMER;
    BOSS->hp -= shot_power;
}

static inline void draw_boss(void){
    uint8_t prop =  OAMF_PAL0;
    if (BOSS->ishit > 0u) {
        prop = OAMF_PAL1;
        BOSS->ishit--;
    }

    oam += move_metasprite_ex(
        BOSS->metasprites[BOSS->frame],
        BOSS_TILE_OFFSET, prop, oam,
        BOSS->body.x, BOSS->body.y
        );
}

static inline void change_phase(void){
    switch (BOSS->phase) {
    case BOSS_PHASE_INTRO:
        BOSS->phase = BOSS_PHASE_1;
        BOSS->current_pattern_index = 0;
        BOSS->current_pattern = BOSS->move_pattern_list[BOSS->phase][0];

        init_bullet_pattern_manager(&BOSS->bpm,
                                    BULLET_PATTERN_TYPE_SINGLE_DOWN);
        BOSS->body.dx = 0;
        BOSS->body.dy = 0;

        BOSS->frame = 0;
        BOSS->hittable = 1;

        break;
    case BOSS_PHASE_1:
        BOSS->phase = BOSS_TRANSITION_1_2;
        BOSS->current_pattern_index = 0;
        BOSS->current_pattern = BOSS->move_pattern_list[BOSS->phase][0];
        init_bullet_pattern_manager(&BOSS->bpm,
                            BULLET_PATTERN_TYPE_NONE);
        BOSS->body.dx = 0;
        BOSS->body.dy = 0;

        BOSS->hittable = 0;
        break;
    case BOSS_TRANSITION_1_2:
        BOSS->phase = BOSS_PHASE_2;
        BOSS->current_pattern_index = 0;
        BOSS->current_pattern = BOSS->move_pattern_list[BOSS->phase][0];
        init_bullet_pattern_manager(&BOSS->bpm,
                            BULLET_PATTERN_TYPE_NONE);
        BOSS->body.dx = 0;
        BOSS->body.dy = 0;

        BOSS->frame = 1;
        BOSS->hittable = 1;
        BOSS->hp = BOSS_BEHOLDER_HP_PHASE_2;
        break;
    case BOSS_PHASE_2:
        BOSS->phase = BOSS_TRANSITION_2_3;
        BOSS->current_pattern_index = 0;
        BOSS->current_pattern = BOSS->move_pattern_list[BOSS->phase][0];
        init_bullet_pattern_manager(&BOSS->bpm,
                            BULLET_PATTERN_TYPE_NONE);
        BOSS->body.dx = 0;
        BOSS->body.dy = 0;

        BOSS->hittable = 0;
        break;
    case BOSS_TRANSITION_2_3:
        BOSS->phase = BOSS_PHASE_3;
        BOSS->current_pattern_index = 0;
        BOSS->current_pattern = BOSS->move_pattern_list[BOSS->phase][0];
        init_bullet_pattern_manager(&BOSS->bpm,
                            BULLET_PATTERN_TYPE_SINGLE_DOWN);
        BOSS->body.dx = 0;
        BOSS->body.dy = 0;

        BOSS->frame = 1;
        BOSS->hittable = 1;
        BOSS->hp = BOSS_BEHOLDER_HP_PHASE_3;
        break;
    case BOSS_PHASE_3:
        BOSS->phase = BOSS_PHASE_DEFEATED;
        BOSS->current_pattern_index = 0;
        BOSS->current_pattern = BOSS->move_pattern_list[BOSS->phase][0];
        init_bullet_pattern_manager(&BOSS->bpm,
                            BULLET_PATTERN_TYPE_NONE);
        BOSS->body.dx = 0;
        BOSS->body.dy = 0;

        BOSS->hittable = 0;
    default:
        break;
    }
    EMU_printf("New Phase %d, boss pattern %d \n", BOSS->phase, BOSS->current_pattern);
}

static inline void change_pattern(void){
    BOSS->body.dx = 0;
    BOSS->body.dy = 0;

    BOSS->current_pattern_index++;
    BOSS->current_pattern = BOSS->move_pattern_list[BOSS->phase][BOSS->current_pattern_index];
    if (BOSS->current_pattern == BOSS_PATTERN_END){
            BOSS->current_pattern_index = 1;
            BOSS->current_pattern = BOSS->move_pattern_list[BOSS->phase][1];
    }

    switch (BOSS->current_pattern){
    case BOSS_PATTERN_LATERAL:
        static_pattern_step_counter = 0;
        BOSS->body.dx = move_lateral[0].dx;
        BOSS->body.dy = move_lateral[0].dy;
        BOSS->timer = move_lateral[0].duration;
        break;
    case BOSS_PATTERN_WINK:
        BOSS->timer = 160;
        break;
    case BOSS_PATTERN_SHAKE:
        BOSS->timer = 80;
        break;
    case BOSS_PATTERN_WAIT:
        BOSS->timer = 16;
        break;
    case BOSS_PATTERN_CENTER:
        BOSS->timer = 60;
        break;
    case BOSS_PATTERN_CHARGE_AT_DIRECTION:
        BOSS->body.dx = directions_dx[dir]<<2;
        BOSS->body.dy = directions_dy[dir]<<2;
        break;
    case BOSS_PATTERN_DESTROY:
        BOSS->timer = 240;
        break;
    default:
        break;
    }

    EMU_printf("Boss phase: %d, pattern: %d", BOSS->phase, BOSS->current_pattern_index);
    EMU_printf("Boss Pattern: %d", beholder_move_patterns[0][1]);
    EMU_printf("Boss Pattern: %d", BOSS->move_pattern_list[0][1]);
}

static inline void boss_pattern_start(void){
    change_pattern();
}

static inline void boss_wait(void){
    if (BOSS->timer != 0){
        BOSS->timer--;
        return;
    }
    change_pattern();
}

static inline void boss_shake(void){
    if (BOSS->timer == 0){
        change_pattern();
        return;
    }
    BOSS->timer--;
    uint8_t random_dir = shake_lut[BOSS->timer & 0xFu];
    BOSS->body.dx = directions_dx[random_dir];
    BOSS->body.dy = directions_dy[random_dir];
}

static inline void boss_aim_at_player(void){
    dir = aimed_direction(BOSS->body.x, BOSS->body.y,
                                  PLAYER->body.x,PLAYER->body.y);

    change_pattern();
}

static inline void boss_charge_at_direction(void){

    if (is_outside_bounds(BOSS->body.x,
                          GAMESCREEN_X_ORIGIN + BOSS_BEHOLDER_BBOX_W,
                          GAMESCREEN_X_END - BOSS_BEHOLDER_BBOX_W) ||
        is_outside_bounds(BOSS->body.y,
                          GAMESCREEN_Y_ORIGIN + BOSS_BEHOLDER_BBOX_H,
                          GAMESCREEN_Y_END - BOSS_BEHOLDER_BBOX_H)){
        change_pattern();
    }
}

static inline void boss_center(void){
    BOSS->body.dx = 0;
    BOSS->body.dy = 0;

    if (BOSS->timer == 0){
        change_pattern();
        return;
    }

    BOSS->timer--;
    if (BOSS->body.x > 84u) BOSS->body.dx = -4;
    if (BOSS->body.x < 84u) BOSS->body.dx = +4;
    if (BOSS->body.y > 80u) BOSS->body.dy = -4;
    if (BOSS->body.y < 80u) BOSS->body.dy = +4;
}

static inline void lateral_pattern(void){
    if (BOSS->timer != 0){
        BOSS->timer--;
        return;
    }
    static_pattern_step_counter++;
    if (static_pattern_step_counter == BOSS_PATTERN_LATERAL_LEN){
        change_pattern();
        return;
    } else {
        BOSS->body.dx = move_lateral[static_pattern_step_counter].dx;
        BOSS->body.dy = move_lateral[static_pattern_step_counter].dy;
        BOSS->timer = move_lateral[0].duration;
    }
}


static inline void go_to_position(uint8_t x, uint8_t y){
    //Pattern adaptatif, on remet a zero a chaque fois
    BOSS->body.dx = 0;
    BOSS->body.dy = 0;
    if (BOSS->body.x == x && BOSS->body.y == y){
        change_pattern();
        return;
    }

    if (BOSS->body.x > x) BOSS->body.dx = -4;
    if (BOSS->body.x < x) BOSS->body.dx = +4;
    if (BOSS->body.y > y) BOSS->body.dy = -4;
    if (BOSS->body.y < y) BOSS->body.dy = +4;
}

static inline void boss_wink(void){
    if (BOSS->timer == 0){
        change_pattern();
        return;
    }
    BOSS->timer--;
    BOSS->frame = (BOSS->timer & 0x10)>>4;
}

static inline void boss_destroy(void){
    if (BOSS->timer == 0){
        //End boss battle
        BOSS->active = 0;
        return;
    }

    if (BOSS->timer % 8 == 0){
        dir = shake_lut[ (BOSS->timer >> 3) & 0xF ];
        add_explosion(BOSS->body.x + directions_dx[dir],
                      BOSS->body.y + directions_dy[dir]);
    }

    BOSS->timer--;
}
