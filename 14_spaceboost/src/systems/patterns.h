#ifndef PATTERNS_H
#define PATTERNS_H

#include <stdint.h>

#define NORMAL_SHOT          16
#define AIMED_SHOT           32
#define SHOT_SPEED_SLOW       0
#define SHOT_SPEED_MEDIUM     1
#define SHOT_SPEED_FAST       2
#define SHOT_SPEED_MASK       3

typedef enum {
    MOVE_PATTERN_DOWN = 0,
    MOVE_PATTERN_DOWN_FAST,
    MOVE_PATTERN_ZIGZAG,
    MOVE_PATTERN_LATERAL,
    MOVE_PATTERN_SQUARE,
    MOVE_PATTERN_SPECIAL_CENTER,
    MOVE_PATTERN_SPECIAL_AIMED
} move_pattern_id_t;

typedef enum {
    SHOOT_PATTERN_DOWN = 0,
    SHOOT_PATTERN_AIMED,
    SHOOT_PATTERN_CIRCULAR,
    SHOOT_PATTERN_SEMI_CIRCULAR_LEFT,
    SHOOT_PATTERN_SEMI_CIRCULAR_RIGHT,
    SHOOT_PATTERN_NONE = 255
} shoot_pattern_id_t;

extern const uint8_t         move_pattern_lengths[];
extern const int8_t  (* const move_patterns[])[3];

extern const uint8_t         shoot_pattern_lengths[];
extern const int8_t  (* const shoot_patterns[])[4];

#endif // PATTERNS_H
