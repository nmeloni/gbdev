#ifndef PATTERNS_H
#define PATTERNS_H

#include <gb/gb.h>
#include <stdint.h>

#include "bullet.h"

#define AIMED_SHOT              128

enum patterns_enum {
    MOVE_PATTERN_STRAIGHT = 0,
    MOVE_PATTERN_ZIGZAG = 1
};

enum shoot_patterns_enum {
    SHOOT_PATTERN_DOWN = 0,
    SHOOT_PATTERN_AIMED = 1,
    SHOOT_PATTERN_CIRCULAR = 2,
    SHOOT_PATTERN_SEMI_CIRCULAR_LEFT = 3,
    SHOOT_PATTERN_SEMI_CIRCULAR_RIGHT = 4
};

extern const uint8_t move_pattern_lengths[];
extern const int8_t ( * const move_patterns[])[3];

extern const uint8_t shoot_pattern_lengths[];
extern const int8_t (* const shoot_patterns[])[4];

#endif // PATTERNS_H
