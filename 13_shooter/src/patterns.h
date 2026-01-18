#ifndef PATTERNS_H
#define PATTERNS_H

#include <gb/gb.h>
#include <stdint.h>

#include "bullet.h"

#define AIMED_SHOT              128

enum patterns_enum {
    MOVE_PATTERN_STRAIGHT = 0
};

enum shoot_patterns_enum {
    SHOOT_PATTERN_AIMED = 0
};

extern const uint8_t move_pattern_lengths[];
extern const int8_t (*move_patterns[])[3];

extern const uint8_t shoot_pattern_lengths[];
extern const int8_t (*shoot_patterns[])[4];

#endif // PATTERNS_H
