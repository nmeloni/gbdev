#ifndef BULLET_PATTERN_H
#define BULLET_PATTERN_H

#include <stdint.h>

#include "game_types.h"

void init_bullet_pattern_manager(BulletPatternManager * bpm, BulletPatternType type);
void update_bullet_pattern_manager(BulletPatternManager * bpm, uint8_t x, uint8_t y);

#endif
