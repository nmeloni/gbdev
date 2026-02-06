#include "level1.h"

const uint8_t level_1_events[][5] = {
    {0, EVENT_INIT_LEVEL, 0,84u,180u},
    {120, EVENT_LEVEL_INTRO, 0,0,0},
    {0, EVENT_ACTIVATE_PLAYER, 0,0,0},
    
    {20, EVENT_SPAWN_ENEMY, 0, 40, 8},
    
    {240,  EVENT_NONE,        0, 0, 0},
    {240,  EVENT_NONE,        0, 0, 0},
    {240,  EVENT_NONE,        0, 0, 0},

    
    {0, EVENT_END_LEVEL, 0, 0} // Marqueur de fin
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
      {0, EVENT_SPAWN_ENEMY, 1, 120, 8},
      {240, EVENT_NONE,        0, 0, 0},
      {240, EVENT_SPAWN_BOSS, MINI_BOSS_2, 80,0},
      {0, EVENT_END_LEVEL, 0, 0}*/ // Marqueur de fin
};

const uint8_t level_1_enemies[][6] = {
    {ENEMY_TYPE_1, 10, BULLET_TYPE_NONE, MOVE_PATTERN_DOWN, SHOOT_PATTERN_NONE, SHOT_SPEED_SLOW},
    {ENEMY_TYPE_1, 10, BULLET_TYPE_LASER, MOVE_PATTERN_DOWN, SHOOT_PATTERN_DOWN, SHOT_SPEED_SLOW},
    {ENEMY_TYPE_2, 10, BULLET_TYPE_SMALL, MOVE_PATTERN_ZIGZAG, SHOOT_PATTERN_AIMED, SHOT_SPEED_MEDIUM},
    {ENEMY_TYPE_3, 10, BULLET_TYPE_SMALL, MOVE_PATTERN_DOWN, SHOOT_PATTERN_SEMI_CIRCULAR_RIGHT, SHOT_SPEED_MEDIUM},
    {ENEMY_TYPE_3, 10, BULLET_TYPE_SMALL, MOVE_PATTERN_DOWN, SHOOT_PATTERN_SEMI_CIRCULAR_LEFT, SHOT_SPEED_MEDIUM}
};


void load_level_1_gfx(void){
    set_sprite_data(ENEMY_1_TILE_OFFSET, enemy_1_sprite_TILE_COUNT, enemy_1_sprite_tiles);
    set_sprite_data(ENENY_2_TILE_OFFSET, enemy_2_sprite_TILE_COUNT, enemy_2_sprite_tiles);
    set_sprite_data(ENEMY_3_TILE_OFFSET, enemy_3_sprite_TILE_COUNT, enemy_3_sprite_tiles);
}
