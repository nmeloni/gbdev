#include "level.h"

inline void level_intro(void);
inline void end_level(void);

uint8_t level_event_framecounter = 0;
uint8_t level_event_index = 0;

const uint8_t  (*LEVEL_EVENTS)[5];
const uint8_t  (*ENEMY_SPAWN_LIST)[6];

void load_level(uint8_t level_id){
    switch(level_id){
    case 1:
	LEVEL_EVENTS = level_1_events;
	ENEMY_SPAWN_LIST = level_1_enemies;
	load_level_1_gfx();
	break;
    default:
	break;
    }
    level_event_index = 0;
    level_event_framecounter = LEVEL_EVENTS[level_event_index][0];
}

void update_level(void){
    if (BOSS.active) return;
    uint8_t event_type = LEVEL_EVENTS[level_event_index][1];
    if (event_type == EVENT_LEVEL_INTRO) {
	level_intro();
	return;
    }
    if (event_type == EVENT_END_LEVEL) {
	end_level();
	return;
    }
    
    if (level_event_framecounter == 0){
	EMU_printf("Executing level event type %d at index %d\n", event_type, level_event_index);
	// Exécution de l'événement
	switch(event_type){
	    // Spawn enemy
	case EVENT_SPAWN_ENEMY:
	{
	    uint8_t spawn_index = LEVEL_EVENTS[level_event_index][2];
	    uint8_t enemy_type = ENEMY_SPAWN_LIST[spawn_index][0];
	    uint8_t enemy_hp = ENEMY_SPAWN_LIST[spawn_index][1];
	    uint8_t enemy_weapon = ENEMY_SPAWN_LIST[spawn_index][2];
	    uint8_t move_pattern = ENEMY_SPAWN_LIST[spawn_index][3];
	    uint8_t shoot_pattern = ENEMY_SPAWN_LIST[spawn_index][4];
	    uint8_t shoot_pattern_speed = ENEMY_SPAWN_LIST[spawn_index][5];
		
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
	case EVENT_INIT_LEVEL:
	    EMU_printf("Level intro\n");
	    PLAYER.body.x = LEVEL_EVENTS[level_event_index][3];
	    PLAYER.body.y = LEVEL_EVENTS[level_event_index][4];
	    PLAYER.body.dx = 0;
	    PLAYER.body.dy = -4;
	    break;
	// Fin du niveau
	case EVENT_ACTIVATE_PLAYER:
	    PLAYER.active = 1;
	    break;
	default:
	    break;

	}
	// Passage à l'événement suivant
	level_event_index++;
	level_event_framecounter = LEVEL_EVENTS[level_event_index][0];
    } else {
	// Compte à rebours avant le prochain événement
	
	level_event_framecounter--;
    }
}
			    

void level_intro(void){
    if (PLAYER.body.y > PLAYER_START_Y){
	update_body_position(&PLAYER.body);
    } else {
	level_event_index++;
	level_event_framecounter = LEVEL_EVENTS[level_event_index][0];
    }
}

void end_level(void){
	game_change_state(GAME_STATE_TITLE_SCREEN);
}
