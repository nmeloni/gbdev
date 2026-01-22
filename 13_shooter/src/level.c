#include "level.h"

const uint8_t enemy_spawn_list[][5]={
    {ENEMY_TYPE_1, ENEMY_HP_3, BULLET_TYPE_NONE, MOVE_PATTERN_STRAIGHT, SHOOT_PATTERN_NONE},
    {ENEMY_TYPE_2, ENEMY_HP_5, BULLET_TYPE_SMALL, MOVE_PATTERN_STRAIGHT, SHOOT_PATTERN_DOWN},
};
uint16_t level_event_framecounter = 0;
 uint8_t level_event_index = 0;

const uint8_t  (*LEVEL_EVENTS)[5];

const uint8_t level_1_events[][5] = {
    // {frame_delay, event_type, spawn_index, x, y}
    {60, EVENT_SPAWN_POWERUP_SHOT, 0, 80, 8},
    {180, EVENT_SPAWN_ENEMY, 0, 80, 8},
    {20,  EVENT_NONE,        0, 0, 0},
    {120, EVENT_SPAWN_ENEMY, 0, 40, 8},
    {1,   EVENT_SPAWN_ENEMY, 0, 80, 8},
    {1,   EVENT_SPAWN_ENEMY, 0, 120, 8},
    {120, EVENT_NONE,        0, 0, 0},
    {150, EVENT_SPAWN_ENEMY, 1, 60, 8},
    {1,  EVENT_SPAWN_ENEMY, 1, 100, 8},
    {200, EVENT_NONE,        0, 0, 0},

    {240, EVENT_NONE,        0, 0, 0},
    {0, EVENT_END_LEVEL, 0, 0} // Marqueur de fin
};

void init_level(const uint8_t  (*level_events)[5]){
	LEVEL_EVENTS = level_events;
	level_event_framecounter = LEVEL_EVENTS[0][0];
	level_event_index = 0;	
}

void update_level(void){
	if (level_event_framecounter == 0){
	    // Exécution de l'événement
	    uint8_t event_type = LEVEL_EVENTS[level_event_index][1];
	    switch(event_type){
	    case EVENT_SPAWN_ENEMY:
	    {
		uint8_t spawn_index = LEVEL_EVENTS[level_event_index][2];
		uint8_t enemy_type = enemy_spawn_list[spawn_index][0];
		uint8_t enemy_weapon = enemy_spawn_list[spawn_index][2];
		uint8_t move_pattern = enemy_spawn_list[spawn_index][3];
		uint8_t shoot_pattern = enemy_spawn_list[spawn_index][4];
		
		uint8_t x = LEVEL_EVENTS[level_event_index][3];
		uint8_t y = LEVEL_EVENTS[level_event_index][4];
		
		add_enemy(x, y, enemy_type, enemy_weapon, 3, move_pattern, shoot_pattern);
	    }
	    break;
	    case EVENT_SPAWN_POWERUP_SHOT:
	    {
		uint8_t x = LEVEL_EVENTS[level_event_index][3];
		uint8_t y = LEVEL_EVENTS[level_event_index][4];

		EMU_printf("Spawning powerup  at (%d,%d)\n",  POWERUP_GAMESCREEN_Y_ORIGIN, y);
		spawn_powerup(POWERUP_TYPE_SHOT,x,y);
	    }
	    break;		
	    case EVENT_END_LEVEL:
		init_level(level_1_events);
		return;
	    default:
		break;

			    }
	    // Passage à l'événement suivant
	    level_event_index++;
	    level_event_framecounter = LEVEL_EVENTS[level_event_index][0];
	} else {
	    level_event_framecounter--;
	}
}
			    

