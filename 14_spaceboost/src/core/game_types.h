#ifndef TYPES_H
#define TYPES_H

#include <stdint.h>
#include <gbdk/metasprites.h>

// ─── Corps physique (virgule fixe 4 bits) ─────────────────────────────────────
typedef struct {
    uint8_t x, y;
    int8_t  dx, dy;
    int8_t  fx, fy;
} Body;

// ─── Structure Joueur ───────────────────────────────────────────────────────
typedef struct {
    Body  body;
    uint8_t active;
    uint8_t lives;
    uint8_t shield;
    uint8_t invincibility_timer;
    uint8_t shoot_cooldown;
    uint8_t shoot_power;
    uint8_t boost;
    const metasprite_t * const * metasprites;
} Player;

// ─── Structure Tir joueur ────────────────────────────────────────────────────
typedef struct{
    Body body;
    uint8_t active;
} Shot;

#endif // TYPES_H
