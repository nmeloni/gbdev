#ifndef PLAYER_H
#define PLAYER_H

#include <stdint.h>

#include "game_types.h"

extern Player *PLAYER;

void init_player(void);
void update_player(void);
void reset_player(uint8_t x, uint8_t y);
void powerup_player(PowerUpType type);
void add_to_score(uint8_t points);
void kill_player(void);
void hit_player(void);

#endif // PLAYER_H
