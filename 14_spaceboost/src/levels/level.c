#include "game.h"
#include "body.h"
#include "player.h"
#include "enemy.h"
#include "level.h"

LevelEventManager lem;
extern LevelEventManager * LEM = &lem;

static inline void handle_init_event(void);
static inline void handle_intro_event(void);
static inline void handle_start_event(void);
static inline void handle_end_event(void);
static inline void handle_spawn_enemy_event(void);

const LevelEvent level_1_events[]={
    {.level_event_type = LEVEL_EVENT_INIT,        .enemy_type = ENEMY_NONE,  .x = PLAYER_START_X,  .y = 180, .duration = 0},
    {.level_event_type = LEVEL_EVENT_INTRO,       .enemy_type = ENEMY_NONE,  .x = 0,  .y = 0, .duration = 240},
    {.level_event_type = LEVEL_EVENT_START,       .enemy_type = ENEMY_NONE,  .x = 0,  .y = 0, .duration = 0},
    {.level_event_type = LEVEL_EVENT_SPAWN_ENEMY, .enemy_type = ENEMY_DRONE, .x = 80, .y = 8, .duration = 240},
    {.level_event_type = LEVEL_EVENT_NONE, .enemy_type = ENEMY_NONE, .x = 0, .y = 0, .duration = 240},
    {.level_event_type = LEVEL_EVENT_END,         .enemy_type = ENEMY_NONE,  .x = 0,  .y = 0, .duration = 240},
};

void init_level(uint8_t level_number){
    switch (level_number) {
    case LEVEL_1:
	LEM->le = level_1_events;
	LEM->current_event_index = 0;
	LEM->current_event_type = LEM->le[0].level_event_type;
	LEM->timer = LEM->le[0].duration;
	break;
    }
}

void update_level(void){
    //Si le timer non nul on traite les evenement continus
    if (LEM->timer){
	LEM->timer--;
	switch (LEM->current_event_type) {
	case LEVEL_EVENT_INTRO:
	    handle_intro_event();
	    return;
	case LEVEL_EVENT_END:
	    handle_end_event();
	    return;
	default:
	    return;
	}
    }
    //sinon on gére les evenement ponctuels
    switch (LEM->current_event_type) {
    case LEVEL_EVENT_INIT:
	handle_init_event();
	break;
    case LEVEL_EVENT_START:
	handle_start_event();
	break;
    case LEVEL_EVENT_SPAWN_ENEMY:
	handle_spawn_enemy_event();
	break;
    default:
	break;
    }
    LEM->current_event_index++;
    LEM->current_event_type = LEM->le[LEM->current_event_index].level_event_type;
    LEM->timer = LEM->le[LEM->current_event_index].duration;
}

static inline void handle_init_event(void){
    const LevelEvent *le = &LEM->le[LEM->current_event_index];
    reset_player(le->x, le->y);
    PLAYER->active = 0;
}

static inline void handle_intro_event(void){
    if (PLAYER->body.y > PLAYER_START_Y){
	PLAYER->body.dy = -4;
	update_body_position(&PLAYER->body);
    }
}

static inline void handle_start_event(void){
    PLAYER->active = 1;
    PLAYER->invincibility_timer = PLAYER_INVINCIBILITY;
}

static inline void handle_end_event(void){
    if (LEM->timer > 1){
	PLAYER->active = 0;
	PLAYER->body.dy = 0;
	PLAYER->body.dx = 0;
	return;
    }
    LEM->timer = 1;
    if (PLAYER->body.y > 8){
	if (PLAYER->body.dy > -120){
	    PLAYER->body.dy -= 2;
	}
	update_body_position(&PLAYER->body);
	return;
    }
    game_change_state(GAME_STATE_TITLE_SCREEN);
}

static inline void handle_spawn_enemy_event(void){
    const LevelEvent *le = &LEM->le[LEM->current_event_index];
    add_enemy(le->x, le->y, le->enemy_type, 3, 0, POWERUP_TYPE_SHOT);
}
