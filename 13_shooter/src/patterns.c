#include "patterns.h"

extern const uint8_t move_pattern_lengths[] = {
    1,16
};
const int8_t (* const move_patterns[])[3] = {
    move_pattern_straight,
    move_pattern_zigzag
};

const uint8_t shoot_pattern_lengths[] = {
    1 
};
const int8_t (* const  shoot_patterns[])[4] = {
    shoot_pattern_aimed
};

// Shoot patterns {frame_delay, shoot_type, dx, dy}

// Pattern 0: Mouvement en ligne droite descendante
const int8_t move_pattern_straight[][3] = {
    {10, 0, 4}    
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
const int8_t shoot_pattern_aimed[1][4] = {
    {60, BULLET_TYPE_SMALL, 0, 32},
};
