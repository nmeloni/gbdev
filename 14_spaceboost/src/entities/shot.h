#ifndef SHOT_H
#define SHOT_H

#include <stdint.h>

#include "constants.h"
#include "game_types.h"


extern Shot   SHOTS_POOL[MAX_SHOTS];
extern uint8_t  ACTIVE_SHOTS[MAX_SHOTS];
extern uint8_t  active_shot_index;
extern const uint8_t shot_bbox[3][2];
extern const uint8_t shot_power_table[3];

void init_shots(void);
void fire_shot(uint8_t x, uint8_t y, int8_t dx, int8_t dy);
void update_shots(void);

inline void desactivate_shot(Shot *s);
inline void kill_active_shot(uint8_t j);

#endif // SHOT_H
