#ifndef ENNEMY_H
#define ENNEMY_H

#include <gb/gb.h>
#include <stdint.h>

#include <gbdk/platform.h>
#include <gbdk/metasprites.h>
#include <gbdk/emu_debug.h>

#include "player.h"

#include "ennemy16x16_sprite.h"
#include "ennemybullet_sprite.h"

#define ENNEMY_1_TILE_OFFSET      (7)
#define ENNEMY_1_SPEED            (1<<6)
#define ENNEMY_PATTERN_SIZE       (12)
#define MAX_ENNEMY                (8)

enum {ENNEMY_1};

typedef struct {
    uint16_t x,y;
    uint16_t dx,dy;
    uint8_t framecount;
    uint8_t activepattern;
    uint8_t type;
    uint8_t isactive;
} ennemy_t;

void init_enemies(void);
void handle_ennemies(void);
void add_ennemy(uint8_t x, uint8_t y, uint8_t type);

//extern const int8_t ennemy_1_bounding_box[];
extern ennemy_t ENNEMIES[MAX_ENNEMY];
extern uint8_t oam;


#endif
