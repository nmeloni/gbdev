#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <stdint.h>

typedef struct {
    int8_t dx, fx;
    int8_t dy, fy;
} background_t;

extern background_t BACKGROUND;

void init_background(void);
void scroll_background(void);

#endif // BACKGROUND_H
