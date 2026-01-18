#ifndef UTILS_H
#define UTILS_H

#include <gb/gb.h>
#include <stdint.h>
#include <gbdk/emu_debug.h>

// Vérifie la collision entre deux entités rectangulaires
inline uint8_t check_collision_box(uint8_t x1, uint8_t y1, uint8_t w1, uint8_t h1,
				uint8_t x2, uint8_t y2, uint8_t w2, uint8_t h2);

// Calcule un approximation de la direction entre deux points (x1, y1)
// vers (x2, y2) parmi 16 directions 0 = droite, 4 = haut, 8 = gauche,
// 12 = bas
inline uint8_t aimed_direction(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);

#endif // UTILS_H
