#ifndef PLAYER_H
#define PLAYER_H

#include "global.h"

#include "spaceship_sprite.h"
#include "shield_sprite.h"
#include "booster_sprite.h"


#define PLAYER_MIN_X            ((GAMESCREEN_X_ORIGIN+8)<<8)
#define PLAYER_MAX_X            ((GAMESCREEN_X_END-8)<<8)
#define PLAYER_MIN_Y            ((GAMESCREEN_Y_ORIGIN+8)<<8)
#define PLAYER_MAX_Y            ((GAMESCREEN_Y_END-8)<<8)

#define SPACESHIP_TILE_OFFSET   (0)
#define SHIELD_TILE_OFFSET      (14)
#define BOOSTER_TILE_OFFSET     (0x12)

#define NORMAL_SPEED            (14<<4)
#define BOOST_SPEED             (10<<7)
#define BOOST_LAG               (16)
#define BOOST_DURATION          (4)
#define INVINSIBILITY_DURATION  (120)

#define MAX_SHOTS               (3)
#define SHOOT_LAG               (8)

//Constantes de flags
#define PLAYER_FLAG_SHIELD          (1<<0)
#define PLAYER_FLAG_INVINCIBLE      (1<<1)

#define RESET_PLAYER() {    PLAYER.x = 72<<8;	      \
	PLAYER.y = 100<<8;			      \
	PLAYER.dxy = NORMAL_SPEED;		      \
	PLAYER.power = 1;			      \
	PLAYER.last_shot = 0;					      \
	PLAYER.last_boost = 0;					      \
	PLAYER.boost = 0;					      \
	PLAYER.flags = 0;					      \
	PLAYER.bullet_metasprites = bullet_lvl1_sprite_metasprites;   \
	PLAYER.bullet_sprite_offset = BULLET_LVL1_TILE_OFFSET;        \
	PLAYER.bullet_frame_counter = 0;			      \
	PLAYER.bullet_frame = 0;				      \
	PLAYER.invinsibility_timer = INVINSIBILITY_DURATION;	      \
    }

typedef struct {
    uint16_t x,y,dxy;
    uint8_t px, py;
    uint8_t power;
    uint8_t lives;
    uint8_t last_shot;
    uint8_t last_boost;
    uint8_t invinsibility_timer;
    uint8_t boost;
    uint8_t flags;
    uint8_t column;

    const metasprite_t * const * bullet_metasprites;
    uint8_t bullet_sprite_offset;
    uint8_t bullet_frame_counter;
    uint8_t bullet_frame;
} player_t;


extern player_t PLAYER;

void init_player(void);
void handle_player(void);
void shoot(void);
void draw_player(void);

#endif
