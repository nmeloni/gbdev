#ifndef PLAYER_H
#define PLAYER_H

#include <gb/gb.h>

#include "global.h"
#include "playersprites.h"

#define PLAYER_GRAVITY           0x12
#define PLAYER_JUMP_ACC_1        0x40
#define PLAYER_JUMP_ACC_2        0x20
#define PLAYER_JUMP_ACC_3        0x12
#define PLAYER_MAX_FALL_SPEED    0x100

#define PLAYER_START_JUMP_FRAME  16
#define PLAYER_SECOND_JUMP_FRAME 12
#define PLAYER_THIRD_JUMP_FRAME   8

#define PLAYER_STATUS_IDLE       1
#define PLAYER_STATUS_RUNNING    2
#define PLAYER_STATUS_CROUCHING  4
#define PLAYER_STATUS_IN_AIR     8
#define PLAYER_STATUS_HOLDING    16
#define PLAYER_STATUS_FACE_RIGHT 32

#define PLAYER_TILE_OFFSET       0


#define PLAYER_SPRITE_RUN_1       0
#define PLAYER_SPRITE_RUN_2       1
#define PLAYER_SPRITE_HOLD_1      2
#define PLAYER_SPRITE_HOLD_2      3
#define PLAYER_SPRITE_CROUCH      4
#define PLAYER_SPRITE_CROUCH_HOLD 5
#define PLAYER_SPRITE_HIT         6
#define PLAYER_SPRITE_IDLE        7

#define PLAYER_PALETTE DMG_PALETTE(			\
				   DMG_LITE_GRAY,	\
				   DMG_WHITE,		\
				   DMG_DARK_GRAY,	\
				   DMG_BLACK )
    
#define INIT_PLAYER(X,Y,METASPRITES,PALETTE) { \
    PLAYER.x  = X;							\
    PLAYER.y  = Y;							\
    PLAYER.dx = 0;							\
    PLAYER.dy = 0;							\
    PLAYER.status          =  PLAYER_STATUS_IDLE| PLAYER_STATUS_FACE_RIGHT; \
    PLAYER.previous_status =  PLAYER_STATUS_IDLE| PLAYER_STATUS_FACE_RIGHT; \
    PLAYER.sprites     = METASPRITES;					\
    PLAYER.palette     = PALETTE;					\
    PLAYER.run_frame   = 0;						\
    PLAYER.jump_frame  = 0;						\
    PLAYER.hit_frame   = 0;						\
    }

typedef struct {
  int16_t x, y;   //position en subpixel
  int16_t dx, dy; //vitesse en subpixel
  uint8_t  status, previous_status; //etat (IDLE, RUN, LEFT, RIGHT, JUMP, FALL, HIT)
  //Pointeur vers la table des metasprites
  metasprite_t * const * sprites;
  uint8_t palette;
  //compteur de frames pour gérer l'animation et la physique des mouvements
  uint8_t run_frame;
  uint8_t jump_frame;
  uint8_t hit_frame;
} player_t;

extern player_t PLAYER;

void init_player(uint8_t x, uint8_t y);
void update_player(void);
void draw_player(void);


#endif
