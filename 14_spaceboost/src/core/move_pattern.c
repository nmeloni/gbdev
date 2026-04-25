#include "move_pattern.h"
#include "constants.h"
#include "game_types.h"
#include <stdint.h>

static const uint8_t pattern_length[] = {
    [STATIC_PATTERN_TYPE_MOVE_DOWN]=1,1,1,1,1,1,1,1,
    [STATIC_PATTERN_TYPE_MOVE_LEFT_BKG]=1,1,
    [STATIC_PATTERN_TYPE_MOVE_LATERAL]=16,16,
    [STATIC_PATTERN_TYPE_NONE]=1
};

static const StaticPattern move_down[1] = {
    { .dx = 0, .dy = 4, .duration = 120 }
};

static const StaticPattern move_down_fast[1] = {
    { .dx = 0, .dy = 8, .duration = 120 }
};

static const StaticPattern move_up[1] = {
    { .dx = 0, .dy = -4, .duration = 120 }
};

static const StaticPattern move_up_fast[1] = {
    { .dx = 0, .dy = -8, .duration = 120 }
};

static const StaticPattern move_left[1] = {
    { .dx = -4, .dy = 0, .duration = 120 }
};

static const StaticPattern move_left_fast[1] = {
    { .dx = -8, .dy = 0, .duration = 120 }
};

static const StaticPattern move_right[1] = {
    { .dx = 4, .dy = 0, .duration = 120 }
};

static const StaticPattern move_right_fast[1] = {
    { .dx = 8, .dy = 0, .duration = 120 }
};

static const StaticPattern move_left_background[1] = {
   { .dx = -8, .dy = -BACKGROUND_SCROLL_SPEED_Y, .duration = 120 }
};

static const StaticPattern move_right_background[1] = {
   { .dx = 8, .dy = -BACKGROUND_SCROLL_SPEED_Y, .duration = 120 }
};   
    
static const StaticPattern move_lateral[16] = {
    {.dx =   16, .dy =  0, .duration = 5},
    {.dx =  12, .dy =  0, .duration = 10},
    {.dx =   8, .dy =  0, .duration = 10},
    {.dx =   4, .dy =  0, .duration = 10},
    {.dx =    0, .dy =  0, .duration = 5},
    {.dx =  -4, .dy =  0, .duration = 10},
    {.dx =  -8, .dy =  0, .duration = 10},
    {.dx = -12, .dy =  0, .duration = 10},
    {.dx =  -16, .dy =  0, .duration = 5},
    {.dx = -12, .dy =  0, .duration = 10},
    {.dx =  -8, .dy =  0, .duration = 10},
    {.dx =  -4, .dy =  0, .duration = 10},
    {.dx =    0, .dy =  0, .duration = 5},
    {.dx =   4, .dy =  0, .duration = 10},
    {.dx =   8, .dy =  0, .duration = 10},
    {.dx =  12, .dy =  0, .duration = 10}
};

static const StaticPattern move_zigzag[16] = {
    {.dx =   32, .dy =   4, .duration = 5},
    {.dx =  24, .dy =   4, .duration = 10},
    {.dx =  16, .dy =   4, .duration = 10},
    {.dx =   8, .dy =   4, .duration = 10},
    {.dx =    0, .dy =   4, .duration = 5},
    {.dx =  -8, .dy =   4, .duration = 10},
    {.dx = -16, .dy =   4, .duration = 10},
    {.dx = -24, .dy =   4, .duration = 10},
    {.dx =  -32, .dy =   4, .duration = 5},
    {.dx = -24, .dy =   4, .duration = 10},
    {.dx = -16, .dy =   4, .duration = 10},
    {.dx =  -8, .dy =   4, .duration = 10},
    {.dx =    0, .dy =   4, .duration = 5},
    {.dx =   8, .dy =   4, .duration = 10},
    {.dx =  16, .dy =   4, .duration = 10},
    {.dx =  24, .dy =   4, .duration = 10}
};
    
static const StaticPattern move_none[1] = {
    { .dx = 0, .dy = 0, .duration = 0 }
};

static const StaticPattern *  move_patterns[] = {
    move_down,
    move_down_fast,
    move_up,
    move_up_fast,
    move_left,
    move_left_fast,
    move_right,
    move_right_fast,
    move_left_background,
    move_right_background,
    move_lateral,
    move_zigzag,
    move_none
};

void init_static_move_pattern_manager(StaticPatternManager *smp,
			      StaticPatternType intro_pattern_type,
			      StaticPatternType loop_pattern_type,
			      uint8_t initial_pattern){
    smp->active_type_index = 0;
    smp->active_type = intro_pattern_type;
    smp->type[0] = intro_pattern_type;
    smp->type[1] = loop_pattern_type;
    smp->pattern_length = pattern_length[intro_pattern_type];
    smp->active_pattern = initial_pattern;
    smp->timer = move_patterns[intro_pattern_type][initial_pattern].duration;
    smp->dx = move_patterns[intro_pattern_type][initial_pattern].dx;
    smp->dy = move_patterns[intro_pattern_type][initial_pattern].dy;
}

void update_static_move_pattern_manager(StaticPatternManager *smp){
    if (smp->timer == 0){
	//Le pattern courant se termine on passe au suivant
	smp->active_pattern++;
	//S'il y a depassement et qu'on est sur le deuxième type de
	//pattern on on boucle, sinon on change de type de pattern
	if (smp->active_pattern >= smp->pattern_length){
	    if (smp->active_type_index == 1){
		smp->active_pattern = 0;
	    } else {
		smp->active_type_index = 1;
		smp->active_type = smp->type[1];
		smp->pattern_length = pattern_length[smp->active_type];
		smp->active_pattern = 0;
	    }
	}
	//on remet le timer a jour
	const StaticPattern *temp = &move_patterns[smp->active_type][smp->active_pattern];
	smp->timer = temp->duration;
	smp->dx    = temp->dx;
	smp->dy    = temp->dy;
    }
    smp->timer--;
}



