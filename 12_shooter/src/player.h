#ifndef PLAYER_H
#define PLAYER_H

#include <gb/gb.h>
#include <stdint.h>

#include <gbdk/platform.h>
#include <gbdk/metasprites.h>
#include <gbdk/emu_debug.h>

#include "spaceship_sprite.h"

#include "bullet.h"
#include "powerup.h"
#include "ennemy.h"

#define UPDATE_KEYS()   previous_joypad = current_joypad; current_joypad = joypad()
#define KEY_PRESSED(K)  (current_joypad & (K))
#define KEY_RELEASED(K)    (!(current_joypad & (K)) && (previous_joypad & (K)))

#define SPACESHIP_TILE_OFFSET   (1)
#define NORMAL_SPEED            (3<<4)
#define BOOST_SPEED             (10<<5)
#define BOOST_LAG               (24)
#define BOOST_DURATION          (4)

#define MAX_SHOTS               (3)
#define SHOOT_LAG               (8)

#define RESET_PLAYER() {    PLAYER.x = 72<<6; \
    PLAYER.y = 100<<6;			      \
    PLAYER.dx = NORMAL_SPEED;			      \
    PLAYER.dy = NORMAL_SPEED;			      \
    PLAYER.power = 1;			      \
    PLAYER.last_shot = 0;			      \
    PLAYER.last_boost = 0;			      \
    PLAYER.boost = 0;			      \
    }

typedef struct {
    uint16_t x,y,dx,dy;
    uint8_t power;
    uint8_t lives;
    uint8_t last_shot;
    uint8_t last_boost;
    uint8_t boost;
    uint8_t const * bbx;
    metasprite_t * const * sprites;
} player_t;



extern uint8_t current_joypad, previous_joypad;
extern player_t PLAYER;

extern uint8_t oam;

void init_player(void);
void handle_player(void);
uint8_t player_collision(uint16_t x, uint16_t y, uint8_t *bbox);
void handle_collisions(void);
void shoot(void);
void draw_player(void);



#endif
