#include "patterns.h"

extern const uint8_t move_pattern_lengths[] = {
    1,16,16,16
};
const int8_t (* const move_patterns[])[3] = {
    move_pattern_straight,
    move_pattern_zigzag,
    move_pattern_lateral,
    move_pattern_square
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

// Pattern 2: déplacement latéral
const int8_t move_pattern_lateral[][3] = {
    {5, 16, 0},
    {10, 12, 0},
    {10, 8, 0},
    {10, 4, 0},
    {5, 0, 0},
    {10, -4, 0},
    {10, -8, 0},
    {10, -12, 0},
    {5, -16, 0},
    {10, -12, 0},
    {10, -8, 0},
    {10, -4, 0},
    {5, 0, 0},
    {10, 4, 0},
    {10, 8, 0},
    {10, 12, 0}
};

// Pattern 3: deplcement en carré
const int8_t move_pattern_square[16][3] = {
    {60, 0, 0},

    {10, 32, 0},
    {60, 20,0},
    {10, 8, 0},
    {60, 0, 0},
    
    {10, 0, 32},
    {60, 0, 20},
    {10, 0, 8},
    {60, 0, 0},

    {10, -32, 0},
    {60, -20, 0},
    {10, -8, 0},
    {60, 0, 0},
    
    {10, 0, -32},
    {60, 0,-20},
    {10, 0, -8}
   
};


// Pattern 0: shoot straight down
const int8_t shoot_pattern_down[1][4] = {
    {60, NORMAL_SHOT, 0, 32},
};

// Pattern 1: shoot aimed at player
const int8_t shoot_pattern_aimed[1][4] = {
    {60,  AIMED_SHOT|SHOT_SPEED_FAST, 0, 0},
};

// Pattern 2: clockwise circular shooting
const int8_t shoot_pattern_circular[16][4] = {
    {4, NORMAL_SHOT, 0, 32},
    {4, NORMAL_SHOT, 12, 30},
    {4, NORMAL_SHOT, 22, 22},
    {4, NORMAL_SHOT, 30, 12},
    {4, NORMAL_SHOT, 32, 0},
    {4, NORMAL_SHOT, 30, -12},
    {4, NORMAL_SHOT, 22, -22},
    {4, NORMAL_SHOT, 12, -30},
    {4, NORMAL_SHOT, 0, -32},
    {4, NORMAL_SHOT, -12, -30},
    {4, NORMAL_SHOT, -22, -22},
    {4, NORMAL_SHOT, -30, -12},
    {4, NORMAL_SHOT, -32, 0},
    {4, NORMAL_SHOT, -30, 12},
    {4, NORMAL_SHOT, -22, 22},
    {4, NORMAL_SHOT, -12, 30}
};    

const int8_t shoot_pattern_semi_circular_left[8][4] = {
    {4, NORMAL_SHOT, 0, 32},
    {4, NORMAL_SHOT, -22, 22},
    {4, NORMAL_SHOT, -32, 0},
    {4, NORMAL_SHOT, -22, -22},
   
    {4, NORMAL_SHOT, -12, 30},
    {4, NORMAL_SHOT, -30, -12},
    {4, NORMAL_SHOT, -12, -30},
    {4, NORMAL_SHOT, -30, 12}
};

const int8_t shoot_pattern_semi_circular_right[8][4] = {
    {8, NORMAL_SHOT, 0, 32},
    {8, NORMAL_SHOT, 22, 22},
    {8, NORMAL_SHOT, 32, 0},
    {8, NORMAL_SHOT, 22, -22},
    {8, NORMAL_SHOT, 12, 30},
    {8, NORMAL_SHOT, 30, -12},
    {8, NORMAL_SHOT, 12, -30},
    {8, NORMAL_SHOT, 30, 12}

};
