#ifndef BODY_H
#define BODY_H

#include <gb/gb.h>
#include <stdint.h>
#include <gbdk/emu_debug.h>

typedef struct {
    uint8_t x, y;
    int8_t dx, dy;
    int8_t fx, fy;
} body_t;

inline void init_body(body_t* body, uint8_t x, uint8_t y);
inline void update_body_position(body_t* body);

inline uint8_t clamp(uint8_t value, uint8_t min, uint8_t max);

#endif // BODY_H
