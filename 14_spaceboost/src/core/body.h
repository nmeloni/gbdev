#ifndef BODY_H
#define BODY_H

#include "game_types.h"
#include "constants.h"

inline void init_body(Body* body, uint8_t x, uint8_t y);
inline void update_body_position(Body* body);

inline uint8_t clamp(uint8_t value, uint8_t min, uint8_t max);
inline uint8_t is_inside_bounds(uint8_t value, uint8_t min, uint8_t max);
inline uint8_t is_outside_bounds(uint8_t value, uint8_t min, uint8_t max);

#endif // BODY_H
