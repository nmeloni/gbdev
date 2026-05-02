#ifndef POWERUP_H
#define POWERUP_H

#include <stdint.h>

#include "game_types.h"
#include "constants.h"

extern PowerUp *POWERUP;

void init_powerup(void);
void spawn_powerup(uint8_t type, uint8_t x, uint8_t y);
void update_powerup(void);

#endif // POWERUP_H
