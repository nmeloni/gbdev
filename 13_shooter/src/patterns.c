#include "patterns.h"

extern const uint8_t move_pattern_lengths[] = {
    1,16
};
const int8_t (* const move_patterns[])[3] = {
    move_pattern_straight,
    move_pattern_zigzag
};

const uint8_t shoot_pattern_lengths[] = {
    1,1,16,8,8
};
const int8_t (* const  shoot_patterns[])[4] = {
    shoot_pattern_down,
    shoot_pattern_aimed,
    shoot_pattern_circular,
    shoot_pattern_semi_circular_left,
    shoot_pattern_semi_circular_right
};

// Shoot patterns {frame_delay, shoot_type, dx, dy}

// Pattern 0: Mouvement en ligne droite descendante
const int8_t move_pattern_straight[][3] = {
    {60, 0, 4}    
};

// Pattern 1: Descend en zigzag
const int8_t move_pattern_zigzag[16][3] = {
    {5, 16, 4},
    {10, 12, 4},
    {10, 8, 4},
    {10, 4, 4},
    {5, 0, 4},
    {10, -4, 4},
    {10, -8, 4},
    {10, -12, 4},
    {5, -16, 4},
    {10, -12, 4},
    {10, -8, 4},
    {10, -4, 4},
    {5, 0, 4},
    {10, 4, 4},
    {10, 8, 4},
    {10, 12, 4}    
};

// Pattern 0: shoot straight down
const int8_t shoot_pattern_down[1][4] = {
    {60, BULLET_TYPE_SMALL, 0, 32},
};

// Pattern 1: shoot aimed at player
const int8_t shoot_pattern_aimed[1][4] = {
	{60, BULLET_TYPE_SMALL | AIMED_SHOT, 0, 0},
};

// Pattern 2: clockwise circular shooting
const int8_t shoot_pattern_circular[16][4] = {
    {4, BULLET_TYPE_SMALL, 0, 32},
    {4, BULLET_TYPE_SMALL, 12, 30},
    {4, BULLET_TYPE_SMALL, 22, 22},
    {4, BULLET_TYPE_SMALL, 30, 12},
    {4, BULLET_TYPE_SMALL, 32, 0},
    {4, BULLET_TYPE_SMALL, 30, -12},
    {4, BULLET_TYPE_SMALL, 22, -22},
    {4, BULLET_TYPE_SMALL, 12, -30},
    {4, BULLET_TYPE_SMALL, 0, -32},
    {4, BULLET_TYPE_SMALL, -12, -30},
    {4, BULLET_TYPE_SMALL, -22, -22},
    {4, BULLET_TYPE_SMALL, -30, -12},
    {4, BULLET_TYPE_SMALL, -32, 0},
    {4, BULLET_TYPE_SMALL, -30, 12},
    {4, BULLET_TYPE_SMALL, -22, 22},
    {4, BULLET_TYPE_SMALL, -12, 30}
};    

const int8_t shoot_pattern_semi_circular_left[8][4] = {
    {4, BULLET_TYPE_LARGE, 0, 32},
    {4, BULLET_TYPE_LARGE, -22, 22},
    {4, BULLET_TYPE_LARGE, -32, 0},
    {4, BULLET_TYPE_LARGE, -22, -22},
   
    {4, BULLET_TYPE_LARGE, -12, 30},
    {4, BULLET_TYPE_LARGE, -30, -12},
    {4, BULLET_TYPE_LARGE, -12, -30},
    {4, BULLET_TYPE_LARGE, -30, 12}
};

const int8_t shoot_pattern_semi_circular_right[8][4] = {
    {4, BULLET_TYPE_LARGE, 0, 32},
    {4, BULLET_TYPE_LARGE, 22, 22},
    {4, BULLET_TYPE_LARGE, 32, 0},
    {4, BULLET_TYPE_LARGE, 22, -22},

    {4, BULLET_TYPE_LARGE, 12, 30},
    {4, BULLET_TYPE_LARGE, 30, -12},
    {4, BULLET_TYPE_LARGE, 12, -30},
    {4, BULLET_TYPE_LARGE, 30, 12}

};
