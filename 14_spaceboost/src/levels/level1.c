#include <stdint.h>

#include "game_types.h"
#include "constants.h"


const LevelEvent level_1_events[]={
    {.level_event_type = LEVEL_EVENT_INIT,              .enemy_type = ENEMY_NONE, .enemy_data_type = ENEMY_DATA_NONE,  .x = PLAYER_START_X,  .y = 180, .duration = 0},
    {.level_event_type = LEVEL_EVENT_INTRO,             .enemy_type = ENEMY_NONE, .enemy_data_type = ENEMY_DATA_NONE,  .x = 0,  .y = 0, .duration = 240},
    {.level_event_type = LEVEL_EVENT_START,             .enemy_type = ENEMY_NONE, .enemy_data_type = ENEMY_DATA_NONE,  .x = 0,  .y = 0, .duration = 0},


    {.level_event_type = LEVEL_EVENT_SPAWN_ENEMY, .enemy_type = ENEMY_DRONE, .enemy_data_type = ENEMY_DATA_DRONE_1, .x = 20, .y = 8, .duration = 240},
    {.level_event_type = LEVEL_EVENT_SPAWN_ENEMY, .enemy_type = ENEMY_DRONE, .enemy_data_type = ENEMY_DATA_DRONE_1, .x = 40, .y = 8, .duration = 20},
    {.level_event_type = LEVEL_EVENT_SPAWN_ENEMY, .enemy_type = ENEMY_DRONE, .enemy_data_type = ENEMY_DATA_DRONE_1, .x = 60, .y = 8, .duration = 20},
    {.level_event_type = LEVEL_EVENT_SPAWN_ENEMY, .enemy_type = ENEMY_DRONE, .enemy_data_type = ENEMY_DATA_DRONE_1, .x = 80, .y = 8, .duration = 20},
    {.level_event_type = LEVEL_EVENT_SPAWN_ENEMY, .enemy_type = ENEMY_DRONE, .enemy_data_type = ENEMY_DATA_DRONE_1, .x = 100, .y = 8, .duration = 20},
    {.level_event_type = LEVEL_EVENT_SPAWN_ENEMY, .enemy_type = ENEMY_DRONE, .enemy_data_type = ENEMY_DATA_DRONE_1, .x = 120, .y = 8, .duration = 20},
     {.level_event_type = LEVEL_EVENT_SPAWN_ENEMY, .enemy_type = ENEMY_DRONE, .enemy_data_type = ENEMY_DATA_DRONE_1, .x = 140, .y = 8, .duration = 20},
    {.level_event_type = LEVEL_EVENT_SPAWN_ENEMY, .enemy_type = ENEMY_DRONE, .enemy_data_type = ENEMY_DATA_DRONE_1, .x = 160, .y = 8, .duration = 20},
    //{.level_event_type = LEVEL_EVENT_SPAWN_ENEMY, .enemy_type = ENEMY_SCOUT, .enemy_data_type = ENEMY_DATA_DRONE_1, .x = 80, .y = 8, .duration = 240},
    //{.level_event_type = LEVEL_EVENT_SPAWN_ENEMY, .enemy_type = ENEMY_MINION, .enemy_data_type = ENEMY_DATA_DRONE_1, .x = 80, .y = 8, .duration = 240},
    //{.level_event_type = LEVEL_EVENT_SPAWN_ENEMY, .enemy_type = ENEMY_SPHERE, .enemy_data_type = ENEMY_DATA_DRONE_1, .x = 80, .y = 8, .duration = 240},
    //{.level_event_type = LEVEL_EVENT_SPAWN_ENEMY, .enemy_type = ENEMY_PROBE, .enemy_data_type = ENEMY_DATA_DRONE_1, .x = 80, .y = 8, .duration = 240},

    {.level_event_type = LEVEL_EVENT_NONE,              .enemy_type = ENEMY_NONE, .enemy_data_type = ENEMY_DATA_NONE, .x = 0, .y = 0, .duration = 240},
    {.level_event_type = LEVEL_EVENT_NONE,              .enemy_type = ENEMY_NONE, .enemy_data_type = ENEMY_DATA_NONE, .x = 0, .y = 0, .duration = 240},
    {.level_event_type = LEVEL_EVENT_NONE,              .enemy_type = ENEMY_NONE, .enemy_data_type = ENEMY_DATA_NONE, .x = 0, .y = 0, .duration = 240},
    {.level_event_type = LEVEL_EVENT_NONE,              .enemy_type = ENEMY_NONE, .enemy_data_type = ENEMY_DATA_NONE, .x = 0, .y = 0, .duration = 240},


    {.level_event_type = LEVEL_EVENT_END,               .enemy_type = ENEMY_NONE, .enemy_data_type = ENEMY_DATA_NONE,  .x = 0,  .y = 0, .duration = 0},
    {.level_event_type = LEVEL_EVENT_NONE,              .enemy_type = ENEMY_NONE, .enemy_data_type = ENEMY_DATA_NONE, .x = 0, .y = 0, .duration = 120},
    {.level_event_type = LEVEL_EVENT_OUTRO,             .enemy_type = ENEMY_NONE, .enemy_data_type = ENEMY_DATA_NONE,  .x = 0,  .y = 0, .duration = 240},
    {.level_event_type = LEVEL_EVENT_LOAD_TITLE_SCREEN, .enemy_type = ENEMY_NONE, .enemy_data_type = ENEMY_DATA_NONE,  .x = 0,  .y = 0, .duration = 0},
    {.level_event_type = LEVEL_EVENT_NONE,              .enemy_type = ENEMY_NONE, .enemy_data_type = ENEMY_DATA_NONE, .x = 0, .y = 0, .duration = 0}
};
