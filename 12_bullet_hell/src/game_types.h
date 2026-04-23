#ifndef TYPES_H
#define TYPES_H

#include <stdint.h>

// ─── Hitbox AABB centrée sur la position du body ──────────────────────────────
typedef struct {
    uint8_t margin_left;
    uint8_t margin_right;
    uint8_t margin_top;
    uint8_t margin_bottom;
} hitbox_t;

typedef uint8_t collision_result_t;

// ─── Corps physique (virgule fixe 4 bits) ─────────────────────────────────────
// uint8_t pour x,y : pas d'int16_t sur GB (trop lent)
typedef struct {
    uint8_t x, y;
    int8_t  dx, dy;
    int8_t  fx, fy;
} body_t;

#endif // TYPES_H
