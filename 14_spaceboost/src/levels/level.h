#ifndef LEVEL_H
#define LEVEL_H

#include "constants.h"
#include "game_types.h"
#include <stdint.h>

extern LevelEventManager * LEM;

void init_level(uint8_t level_number);
void update_level(void);

#endif // LEVEL_H
