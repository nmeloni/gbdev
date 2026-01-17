#ifndef ENNEMY_H
#define ENNEMY_H

#include <gb/gb.h>
#include <stdint.h>

#include <gbdk/platform.h>
#include <gbdk/metasprites.h>
#include <gbdk/emu_debug.h>

#include "global.h"

#include "ennemy_1_sprite.h"
#include "ennemy_2_sprite.h"
#include "ennemy_3_sprite.h"
#include "enemybullet_sprite.h"
#include "ennemylaser_sprite.h"

#define ENNEMY_1_TILE_OFFSET      (64)
#define ENNEMY_2_TILE_OFFSET      (68)
#define ENNEMY_3_TILE_OFFSET      (72)

#define ENNEMY_1_SPEED            (1<<6)

#define ENNEMY_PATTERN_SIZE       (16)

#define ENNEMY_AIM                (1<<7)
#define ENNEMY_SHOOT_QUADRANT     (3)
#define ENNEMY_SHOOT_ANGLE        (7<<2)

#define ENNEMY_SHOOT_RIGHT        (0)
#define ENNEMY_SHOOT_UP           (4<<2)
#define ENNEMY_SHOOT_LEFT         (2)
#define ENNEMY_SHOOT_DOWN         (1+(4<<2))

#define ENNEMY_SHOOT_UP_RIGHT     (2<<2)
#define ENNEMY_SHOOT_DOWN_RIGHT   (1+(2<<2))
#define ENNEMY_SHOOT_UP_LEFT      (2+(2<<2))
#define ENNEMY_SHOOT_DOWN_LEFT    (3+(2<<2))

#define ENNEMY_SHOOT_UP_RIGHT_RIGHT   (1<<2)
#define ENNEMY_SHOOT_UP_RIGHT_UP      (3<<2)
#define ENNEMY_SHOOT_DOWN_RIGHT_RIGHT (1+(1<<2))
#define ENNEMY_SHOOT_DOWN_RIGHT_DOWN  (1+(3<<2))
#define ENNEMY_SHOOT_UP_LEFT_LEFT   (2+(1<<2))
#define ENNEMY_SHOOT_UP_LEFT_UP      (2+(3<<2))
#define ENNEMY_SHOOT_DOWN_LEFT_LEFT (3+(1<<2))
#define ENNEMY_SHOOT_DOWN_LEFT_DOWN  (3+(3<<2))



#define ENNEMY_SHOOT              (1<<7)

#define MAX_ENNEMY                (8)

enum {ENNEMY_1,ENNEMY_2, ENNEMY_3};

typedef struct {
    uint16_t x,y;
    uint16_t dx,dy;
    uint8_t px,py;
    uint8_t framecount;
    uint8_t activepattern;
    uint8_t type;
    uint8_t pattern;
    int8_t hp;
    uint8_t ishit;
    uint8_t isactive;
} ennemy_t;

void init_enemies(void);
void handle_ennemies(void);
void add_ennemy(uint8_t x, uint8_t y, uint8_t type, uint8_t pattern, uint16_t speed, int8_t hp);
void kill_active_ennemy(uint8_t j);

//extern const int8_t ennemy_1_bounding_box[];
extern ennemy_t ENNEMIES[MAX_ENNEMY];
extern uint8_t  ACTIVE_ENNEMIES[MAX_ENNEMY];
extern uint8_t  active_ennemies_index;
extern uint8_t oam;


#endif
