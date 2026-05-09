#ifndef BOSS_H
#define BOSS_H

#include <gb/gb.h>
#include <stdint.h>
#include <gbdk/metasprites.h>

#include "game_types.h"
#include "constants.h"

#define BOSS_START_X  80u
#define BOSS_START_Y  48u

#define BOSS_MIN_X  16u
#define BOSS_MAX_X  160u
#define BOSS_MIN_Y  16u
#define BOSS_MAX_Y  144u

extern Boss *BOSS;

void init_boss(void);
void spawn_boss(BossId boss_id);
void update_boss(void);

#endif // BOSS_H
