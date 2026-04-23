#include "utils.h"

const int8_t directions_dx[16] = {
    16, 15, 11,  6,
     0, -6,-11,-15,
   -16,-15,-11, -6,
     0,  6, 11, 15
};

const int8_t directions_dy[16] = {
     0, -6,-11,-15,
   -16,-15,-11, -6,
     0,  6, 11, 15,
    16, 15, 11,  6
};

inline uint8_t check_collision_box(uint8_t x1, uint8_t y1, uint8_t w1, uint8_t h1,
                                   uint8_t x2, uint8_t y2, uint8_t w2, uint8_t h2) {
    if ((x2 + w1 + w2 >= x1) && (x2 <= x1 + w1 + w2))
        if ((y2 + h1 + h2 >= y1) && (y2 <= y1 + h1 + h2))
            return 1;
    return 0;
}

inline uint8_t aimed_direction(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2) {
    uint8_t adx = 0, ady = 0, direction = 0;

    if (x2 < x1) { adx = x1 - x2; direction = 4; }
    else          { adx = x2 - x1; direction = 0; }

    if (y2 >= y1) { ady = y2 - y1; direction ^= 12; }
    else          { ady = y1 - y2; }

    uint8_t angle, temp;
    if (adx >= ady) {
        temp = adx - ady;
        if (temp >> 2 > ady)       angle = 0;
        else if (temp >> 1 > ady >> 1) angle = 1;
        else                       angle = 2;
    } else {
        temp = ady - adx;
        if (temp >> 2 > adx)       angle = 4;
        else if (temp >> 1 > adx >> 1) angle = 3;
        else                       angle = 2;
    }

    if (direction & 4) return (direction + 4 - angle) & 0x0F;
    else               return (direction + angle) & 0x0F;
}
