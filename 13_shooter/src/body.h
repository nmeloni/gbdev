#ifndef BODY_H
#define BODY_H

#include <gb/gb.h>
#include <stdint.h>

typedef struct {
    uint8_t x, y;
    int8_t dx, dy;
    int8_t fx, fy;
} body_t;

void init_body(body_t* body, uint8_t x, uint8_t y);
void update_body(body_t* body);

#endif // BODY_H
