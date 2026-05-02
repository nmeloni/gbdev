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

// Phase du boss — enum clair au lieu de flags bitmaskés
typedef enum {
    BOSS_PHASE_ENTERING = 0,
    BOSS_PHASE_1,
    BOSS_PHASE_2,
    BOSS_PHASE_3,
    BOSS_PHASE_DEFEATED
} boss_phase_t;

typedef enum {
    MINI_BOSS_1 = 0,
    MINI_BOSS_2
} boss_id_t;

#define BOSS_PATTERN_TIME_TRIGGER   1u
#define BOSS_PATTERN_REPEAT_TRIGGER 2u
#define BOSS_PATTERN_HEALTH_TRIGGER 4u
#define BOSS_PATTERN_DESTROY        8u

typedef struct {
    Body         body;
    uint8_t      active;
    uint8_t      hittable;
    uint8_t      ishit;
    boss_phase_t phase;
    int16_t      hp;

    uint8_t current_pattern;
    uint8_t current_move_pattern;
    uint8_t current_shoot_pattern;
    uint8_t current_pattern_trigger;
    uint8_t pattern_framecounter;

    uint8_t move_framecounter;
    uint8_t move_activepattern;
    uint8_t nb_move_patterns;

    uint8_t shoot_framecounter;
    uint8_t shoot_pattern_speed;
    uint8_t shoot_activepattern;

    const uint8_t *weapons;
    const uint8_t (*move_patterns)[4];
    const metasprite_t * const * metasprites;
} boss_t;

extern boss_t BOSS;

void init_boss(void);
void spawn_boss(uint8_t boss_id, uint8_t x, uint8_t y);
void update_boss(void);

#endif // BOSS_H
