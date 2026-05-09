#include "game.h"
#include "body.h"
#include "player.h"
#include "enemy.h"
#include "boss.h"
#include "enemy_data.h"

#include "level.h"
#include "level1.h"

LevelEventManager lem;
PowerUpType powerup_event = POWERUP_TYPE_NONE;

extern LevelEventManager * LEM = &lem;

static inline void handle_init_event(void);
static inline void handle_intro_event(void);
static inline void handle_start_event(void);
static inline void handle_end_event(void);
static inline void handle_outro_event(void);
static inline void handle_load_event(void);
static inline void handle_spawn_enemy_event(void);

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
        case LEVEL_EVENT_OUTRO:
            handle_outro_event();
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
    case LEVEL_EVENT_END:
        handle_end_event();
        break;
    case LEVEL_EVENT_START:
        handle_start_event();
        break;
    case LEVEL_EVENT_SPAWN_ENEMY:
        handle_spawn_enemy_event();
        break;
    case LEVEL_EVENT_BOSS_BEHOLDER:
        spawn_boss(BOSS_BEHOLDER);
        break;
    case LEVEL_EVENT_BOSS_DREADNOUGHT:
        spawn_boss(BOSS_DREADNOUGHT);
        break;
    case LEVEL_EVENT_POWERUP_SHOT:
        powerup_event = POWERUP_TYPE_SHOT;
        break;
    case LEVEL_EVENT_POWERUP_SHIELD:
        powerup_event = POWERUP_TYPE_SHIELD;
        break;
    case LEVEL_EVENT_POWERUP_LIFE:
        powerup_event = POWERUP_TYPE_LIFE;
        break;
    case LEVEL_EVENT_LOAD_TITLE_SCREEN:
        handle_load_event();
        break;
    default:
        break;
    }
    LEM->current_event_index++;
    LEM->current_event_type = LEM->le[LEM->current_event_index].level_event_type;
    LEM->timer = LEM->le[LEM->current_event_index].duration;
    EMU_printf("Event Number %d timer %d\n",     LEM->current_event_index, LEM->timer);
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
    EMU_printf("\desactivate player\n");
    PLAYER->active = 0;
    PLAYER->body.dy = 0;
    PLAYER->body.dx = 0;
}

static inline void handle_outro_event(void){
    if (PLAYER->body.y > 8){
        if (PLAYER->body.dy > -120){
            PLAYER->body.dy -= 2;
        }
        update_body_position(&PLAYER->body);
        return;
    }
}

static inline void handle_load_event(void){
    switch (LEM->current_event_type) {
    case LEVEL_EVENT_LOAD_TITLE_SCREEN:
        game_change_state(GAME_STATE_TITLE_SCREEN);
        break;
    default:
        game_change_state(GAME_STATE_TITLE_SCREEN);
        break;
    }
}

static inline void handle_spawn_enemy_event(void){
    const LevelEvent *le = &LEM->le[LEM->current_event_index];

    uint8_t type = le->enemy_type;
    uint8_t data_type = le->enemy_data_type;
    uint8_t speed = enemy_speed[data_type];
    uint8_t hp = enemy_hp[data_type];
    add_enemy(le->x, le->y, type, data_type, hp, speed, powerup_event);
    powerup_event = POWERUP_TYPE_NONE;
}
