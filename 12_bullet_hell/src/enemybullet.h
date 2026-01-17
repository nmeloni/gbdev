#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H

#include "global.h"
#include "enemybullet_sprite.h"

#define ENEMYBULLET_TILE_OFFSET      (48)

#define ENEMYBULLET_X_OFFSET         (4)
#define ENEMYBULLET_Y_OFFSET         (8)

#define BULLET_TYPE_NULL             (0)
#define BULLET_TYPE_NORMAL           (1)
#define BULLET_TYPE_AIMED            (64)


#define MAX_ENEMYBULLETS             (16)

typedef struct {
    uint8_t x, y;
    int8_t dx, dy;
    int8_t fx, fy;
    uint8_t px, py;
    uint8_t isactive;
} enemybullet_t;

void init_enemy_bullets(void);
void add_enemy_bullet(uint8_t x, uint8_t y, int8_t dx, int8_t dy);
void handle_enemy_bullets(void);
void kill_active_enemybullet(uint8_t j);

void aim_at_player(uint8_t x, uint8_t y  );

extern enemybullet_t ENEMYBULLET_POOL[MAX_ENEMYBULLETS];
extern uint8_t ACTIVE_ENEMYBULLET_POOL[MAX_ENEMYBULLETS];
extern uint8_t quadrant;
extern uint8_t angle;

extern const int8_t (* dir16_vx[])[5];
extern const int8_t (* dir16_vy[])[5];


extern uint8_t oam;
extern uint16_t level_framecounter;
#endif // ENEMYBULLET_H
