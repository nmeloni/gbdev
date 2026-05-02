#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>

// Vérifie la collision AABB entre deux rectangles positionnés en (x,y) avec taille (w,h)
inline uint8_t abs_diff(uint8_t x1, uint8_t x2);
inline uint8_t manathan_distance(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);

inline uint8_t check_collision_box(uint8_t x1, uint8_t y1, uint8_t w1, uint8_t h1,
                                   uint8_t x2, uint8_t y2, uint8_t w2, uint8_t h2);

// Retourne la direction approchée (0-15) de (x1,y1) vers (x2,y2)
// 0 = droite, 4 = haut, 8 = gauche, 12 = bas
inline uint8_t aimed_direction(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);

// Tables de vitesse par direction (16 directions, ~16 subpixels/frame)
extern const int8_t directions_dx[16];
extern const int8_t directions_dy[16];

#endif // UTILS_H
