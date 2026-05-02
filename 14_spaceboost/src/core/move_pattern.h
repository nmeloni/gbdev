#ifndef MOVE_PATTERN_H
#define MOVE_PATTERN_H

#include <stdint.h>

#include "constants.h"
#include "game_types.h"


void init_static_move_pattern_manager(StaticPatternManager *smp,
			      StaticPatternType intro_pattern_type,
			      StaticPatternType loop_pattern_type,
			      uint8_t initial_pattern);
void update_static_move_pattern_manager(StaticPatternManager *smp);


#endif
