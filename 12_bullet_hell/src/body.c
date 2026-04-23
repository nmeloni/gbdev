#include "body.h"

inline void init_body(body_t* body, uint8_t x, uint8_t y) {
    body->x = x;
    body->y = y;
    body->dx = 0;
    body->dy = 0;
    body->fx = 0;
    body->fy = 0;
}

inline void update_body_position(body_t* body) {
    body->fx += body->dx;
    body->fy += body->dy;

    body->x += body->fx >> FRAC_SHIFT;
    body->y += body->fy >> FRAC_SHIFT;

    body->fx &= FRAC_MASK;
    body->fy &= FRAC_MASK;
}

inline uint8_t clamp(uint8_t value, uint8_t min, uint8_t max) {
    value = value + ((min - value) * (min > value));
    value = value - ((value - max) * (max < value));
    return value;
}

inline uint8_t is_inside_bounds(uint8_t value, uint8_t min, uint8_t max) {
    return (value >= min) & (value <= max);
}

inline uint8_t is_outside_bounds(uint8_t value, uint8_t min, uint8_t max) {
    return (value < min) | (value > max);
}
