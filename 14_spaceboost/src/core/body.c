#include "body.h"

inline void init_body(Body* body, uint8_t x, uint8_t y) {
    body->x = x;
    body->y = y;
    body->dx = 0;
    body->dy = 0;
    body->fx = 0;
    body->fy = 0;
}

inline void update_body_position(Body* body) {
    body->fx += body->dx;
    body->fy += body->dy;

    body->x += body->fx >> FRAC_SHIFT;
    body->y += body->fy >> FRAC_SHIFT;

    body->fx &= FRAC_MASK;
    body->fy &= FRAC_MASK;
}

