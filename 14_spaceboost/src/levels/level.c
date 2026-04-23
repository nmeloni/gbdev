#include "level.h"
#include "game.h"
#include "player.h"
#include "body.h"

static void level_intro(void);
static void end_level(void);

static uint8_t level_event_framecounter = 0;
static uint8_t level_event_index = 0;

const uint8_t (*LEVEL_EVENTS)[5]    = 0;
const uint8_t (*ENEMY_SPAWN_LIST)[6] = 0;

void load_level(uint8_t level_id) {
    switch (level_id) {
        case 1:
            LEVEL_EVENTS     = level_1_events;
            ENEMY_SPAWN_LIST = level_1_enemies;
            break;
        default:
            break;
    }
    level_event_index = 0;
    level_event_framecounter = LEVEL_EVENTS[level_event_index][0];
}

void update_level(void) {
    if (BOSS.active) return;

    uint8_t event_type = LEVEL_EVENTS[level_event_index][1];

    if (event_type == EVENT_LEVEL_INTRO) { level_intro(); return; }
    if (event_type == EVENT_END_LEVEL)   { end_level();   return; }

    if (level_event_framecounter == 0) {
        switch (event_type) {
            case EVENT_SPAWN_ENEMY: {
                uint8_t spawn_index       = LEVEL_EVENTS[level_event_index][2];
                uint8_t x                 = LEVEL_EVENTS[level_event_index][3];
                uint8_t y                 = LEVEL_EVENTS[level_event_index][4];
                uint8_t enemy_type        = ENEMY_SPAWN_LIST[spawn_index][0];
                uint8_t enemy_hp          = ENEMY_SPAWN_LIST[spawn_index][1];
                uint8_t enemy_weapon      = ENEMY_SPAWN_LIST[spawn_index][2];
                uint8_t move_pattern      = ENEMY_SPAWN_LIST[spawn_index][3];
                uint8_t shoot_pattern     = ENEMY_SPAWN_LIST[spawn_index][4];
                uint8_t shoot_speed       = ENEMY_SPAWN_LIST[spawn_index][5];
                add_enemy(x, y, enemy_type, enemy_weapon, enemy_hp,
                          move_pattern, shoot_pattern, shoot_speed);
                break;
            }
            case EVENT_SPAWN_POWERUP_SHOT: {
                uint8_t x = LEVEL_EVENTS[level_event_index][3];
                uint8_t y = LEVEL_EVENTS[level_event_index][4];
                spawn_powerup(POWERUP_TYPE_SHOT, x, y);
                break;
            }
            case EVENT_SPAWN_BOSS: {
                uint8_t boss_id = LEVEL_EVENTS[level_event_index][2];
                uint8_t x       = LEVEL_EVENTS[level_event_index][3];
                uint8_t y       = LEVEL_EVENTS[level_event_index][4];
                spawn_boss(boss_id, x, y);
                break;
            }
            case EVENT_INIT_LEVEL:
                PLAYER->body.x  = LEVEL_EVENTS[level_event_index][3];
                PLAYER->body.y  = LEVEL_EVENTS[level_event_index][4];
                PLAYER->body.dx = 0;
                PLAYER->body.dy = -4;
                break;
            case EVENT_ACTIVATE_PLAYER:
                PLAYER->active = 1;
                break;
            default:
                break;
        }
        level_event_index++;
        level_event_framecounter = LEVEL_EVENTS[level_event_index][0];
    } else {
        level_event_framecounter--;
    }
}

static void level_intro(void) {
    if (PLAYER->body.y > PLAYER_START_Y) {
        update_body_position(&PLAYER->body);
    } else {
        level_event_index++;
        level_event_framecounter = LEVEL_EVENTS[level_event_index][0];
    }
}

static void end_level(void) {
    game_change_state(GAME_STATE_TITLE_SCREEN);
}
