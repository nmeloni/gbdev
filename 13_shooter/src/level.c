#include "level.h"

const uint8_t enemy_spawn_list[][6]={
    {ENEMY_TYPE_1, ENEMY_HP_3, BULLET_TYPE_NONE, MOVE_PATTERN_DOWN, SHOOT_PATTERN_NONE, SHOT_SPEED_SLOW},
    {ENEMY_TYPE_1, ENEMY_HP_3, BULLET_TYPE_NONE, MOVE_PATTERN_DOWN_FAST, SHOOT_PATTERN_NONE, SHOT_SPEED_SLOW},
    {ENEMY_TYPE_1, ENEMY_HP_5, BULLET_TYPE_SMALL, MOVE_PATTERN_DOWN, SHOOT_PATTERN_DOWN, SHOT_SPEED_SLOW},
    {ENEMY_TYPE_2, ENEMY_HP_8, BULLET_TYPE_SMALL, MOVE_PATTERN_ZIGZAG, SHOOT_PATTERN_AIMED, SHOT_SPEED_MEDIUM},
    {ENEMY_TYPE_3, ENEMY_HP_10, BULLET_TYPE_SMALL, MOVE_PATTERN_DOWN, SHOOT_PATTERN_SEMI_CIRCULAR_RIGHT, SHOT_SPEED_MEDIUM},
    {ENEMY_TYPE_3, ENEMY_HP_10, BULLET_TYPE_SMALL, MOVE_PATTERN_DOWN, SHOOT_PATTERN_SEMI_CIRCULAR_LEFT, SHOT_SPEED_MEDIUM},
    {MINI_BOSS_1, 0,0,0,0,0} // Mini-boss, les patterns sont définis dans le niveau
    
};
uint8_t level_event_framecounter = 0;
uint8_t level_event_index = 0;

const uint8_t  (*LEVEL_EVENTS)[5];

const uint8_t level_demo_events[][5] = {
    // {frame_delay, event_type, spawn_index, x, y}
    /*
    {60, EVENT_SPAWN_POWERUP_SHOT, 0, 80, 8},
    {180, EVENT_SPAWN_ENEMY, 0, 80, 8},

    {20,  EVENT_NONE,        0, 0, 0},
    {120, EVENT_SPAWN_ENEMY, 0, 40, 8},
    {1,   EVENT_SPAWN_ENEMY, 0, 80, 8},
    {1,   EVENT_SPAWN_ENEMY, 0, 120, 8},

    {160, EVENT_NONE,        0, 0, 0},
    {150, EVENT_SPAWN_ENEMY, 1, 60, 8},
    {1,  EVENT_SPAWN_ENEMY, 1, 100, 8},
    {120, EVENT_SPAWN_ENEMY, 1, 60, 8},
    {1,  EVENT_SPAWN_ENEMY, 1, 100, 8},
    
    {240, EVENT_NONE,        0, 0, 0},
    {32, EVENT_SPAWN_ENEMY, 2, 80, 8},
    {32, EVENT_SPAWN_ENEMY, 2, 80, 8},
    {32, EVENT_SPAWN_ENEMY, 2, 80, 8},
    {32, EVENT_SPAWN_ENEMY, 2, 80, 8},
    
    {240, EVENT_NONE,        0, 0, 0},
    {1, EVENT_SPAWN_ENEMY, 0, 24, 8},
    {1, EVENT_SPAWN_ENEMY, 5, 150, 8},
    {240, EVENT_SPAWN_ENEMY, 1, 40, 8},
    {0, EVENT_SPAWN_ENEMY, 1, 80, 8},
    {0, EVENT_SPAWN_ENEMY, 1, 120, 8},*/
    {60, EVENT_NONE,        0, 0, 0},
    {60, EVENT_SPAWN_BOSS, MINI_BOSS_1, 80,0},
    {0, EVENT_END_LEVEL, 0, 0} // Marqueur de fin
};

void init_level(const uint8_t  (*level_events)[5]){
	LEVEL_EVENTS = level_events;
	level_event_framecounter = LEVEL_EVENTS[0][0];
	level_event_index = 0;	
}

void update_level(void){
    if (BOSS.active) return;
    if (level_event_framecounter == 0){
	// Exécution de l'événement
	uint8_t event_type = LEVEL_EVENTS[level_event_index][1];
	switch(event_type){
	    // Spawn enemy
	case EVENT_SPAWN_ENEMY:
	{
	    uint8_t spawn_index = LEVEL_EVENTS[level_event_index][2];
	    uint8_t enemy_type = enemy_spawn_list[spawn_index][0];
	    uint8_t enemy_hp = enemy_spawn_list[spawn_index][1];
	    uint8_t enemy_weapon = enemy_spawn_list[spawn_index][2];
	    uint8_t move_pattern = enemy_spawn_list[spawn_index][3];
	    uint8_t shoot_pattern = enemy_spawn_list[spawn_index][4];
	    uint8_t shoot_pattern_speed = enemy_spawn_list[spawn_index][5];
		
	    uint8_t x = LEVEL_EVENTS[level_event_index][3];
	    uint8_t y = LEVEL_EVENTS[level_event_index][4];
	    EMU_printf("Spawning enemy type %d at (%d,%d)\n", enemy_type, x, y);
	    add_enemy(x, y, enemy_type, enemy_weapon, enemy_hp ,
		      move_pattern, shoot_pattern, shoot_pattern_speed);
	}
	break;
	// Spawn powerup
	case EVENT_SPAWN_POWERUP_SHOT:
	{
	    uint8_t x = LEVEL_EVENTS[level_event_index][3];
	    uint8_t y = LEVEL_EVENTS[level_event_index][4];

	    EMU_printf("Spawning powerup  at (%d,%d)\n",  POWERUP_GAMESCREEN_Y_ORIGIN, y);
	    spawn_powerup(POWERUP_TYPE_SHOT,x,y);
	}
	break;
	// Spawn boss
	case EVENT_SPAWN_BOSS:
	{
	    uint8_t boss_id = LEVEL_EVENTS[level_event_index][2];
	    uint8_t x = LEVEL_EVENTS[level_event_index][3];
	    uint8_t y = LEVEL_EVENTS[level_event_index][4];
	    EMU_printf("Spawning boss id %d\n", boss_id);
	    spawn_boss(boss_id, x, y);
	}
	break;
	// Fin du niveau
	case EVENT_END_LEVEL:
	    init_level(level_demo_events);
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
			    

