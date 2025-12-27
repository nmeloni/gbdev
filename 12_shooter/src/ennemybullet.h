#ifndef ENNEMYBULLET_H
#define ENNEMYBULLET_H
#include <gb/gb.h>
#include <stdint.h>

#include <gbdk/platform.h>
#include <gbdk/metasprites.h>
#include <gbdk/emu_debug.h>

#include "ennemybullet_sprite.h"
#include "ennemylargebullet_sprite.h"
#include "ennemylaser_sprite.h"
#include "player.h"


#define ENNEMYBULLET_TILE_OFFSET      (48)
#define ENNEMYLARGEBULLET_TILE_OFFSET (50)
#define ENNEMYLASER_TILE_OFFSET       (54)
#define ENNEMYBULLET_SPEED            (4<<5)
#define MAX_ENNEMYBULLETS             (16)

#define ENNEMYBULLET_TYPE_NORMAL      (0)
#define ENNEMYBULLET_TYPE_LARGE       (1)
#define ENNEMYBULLET_TYPE_LASER       (2)

typedef struct {
    uint16_t x,y;
    int16_t dx,dy;
    uint8_t px, py;
    uint8_t isactive;
    uint8_t type;
} ennemybullet_t;

void init_ennemy_bullets(void);
void add_ennemy_bullet(uint8_t x, uint8_t y, int16_t dx, int16_t dy,uint8_t type);
void aim_at_player(uint8_t x, uint8_t y  );
void handle_ennemy_bullets(void); // Déplace les bullets actives et affiche
void kill_active_ennemybullet(uint8_t j);

extern ennemybullet_t ENNEMYBULLETS[MAX_ENNEMYBULLETS];
extern uint8_t ACTIVE_ENNEMYBULLETS[MAX_ENNEMYBULLETS];
extern uint8_t oam;
extern uint8_t quadrant;
extern uint8_t angle;
extern const int8_t dir16_vx[4][5];
extern const int8_t dir16_vy[4][5];
extern uint16_t level_framecounter;
#endif
