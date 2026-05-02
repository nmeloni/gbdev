#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>



inline uint8_t abs_diff(uint8_t x1, uint8_t x2);
inline uint8_t manathan_distance(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);

// Collision AABB : retourne 1 si les deux rectangles se chevauchent
inline uint8_t check_collision_box(const uint8_t x1, const uint8_t y1,
				   const uint8_t w1, const uint8_t h1,
                                   const uint8_t x2, const uint8_t y2,
				   const uint8_t w2, const uint8_t h2);

inline uint8_t clamp(uint8_t value, uint8_t min, uint8_t max);
inline uint8_t is_inside_bounds(uint8_t value, uint8_t min, uint8_t max);
inline uint8_t is_outside_bounds(uint8_t value, uint8_t min, uint8_t max);

// Direction approximée de (x1,y1) vers (x2,y2) parmi 16 angles
// 0=droite, 4=haut, 8=gauche, 12=bas
inline uint8_t aimed_direction(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);

extern const int8_t directions_dx[16];
extern const int8_t directions_dy[16];

#endif // UTILS_H
