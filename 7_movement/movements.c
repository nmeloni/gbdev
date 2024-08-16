#include <gb/gb.h>
#include "carti.h"

#define STATE_IDLE        1
#define STATE_RUN         2
#define STATE_JUMP        4
#define STATE_DIR_RIGHT   8

#define INIT_ENTITY(ENTITY,OFFSET,COUNT,TILES,METASPRITES) {	\
  ENTITY.x  = 0; \
  ENTITY.y  = 0; \
  ENTITY.dx = 0; \
  ENTITY.dy = 0; \
  ENTITY.state = STATE_IDLE; \
  ENTITY.prev_state = STATE_IDLE;	\
  ENTITY.sprites = METASPRITES;	\
  ENTITY.runframe = 0; \
  set_sprite_data(OFFSET, COUNT, TILES); \
}


#define carti_TILE_OFFSET 0
#define carti_BASE_SPRITE 0

#define MAX_SPEED       0x20
#define ACCELERATION    0x1
#define AIR_CTRL        0x1
#define DECELERATION    0x4
#define SKIDDING        0x6
#define JUMP_PUSH       0x60
#define GRAVITY         0x4
#define MAX_FALL_SPEED  0x24


typedef struct {
  //position et vitesse
  uint16_t x, y;
  int16_t  dx, dy;
  //etat (STATE_IDLE par defaut)
  uint8_t state, prev_state;
  uint8_t runframe;
  metasprite_t * const * sprites;
} entity;

uint8_t global_frame = 0;

void main(void)
{
  entity carti;
  INIT_ENTITY(carti,
	      carti_TILE_OFFSET,
	      carti_TILE_COUNT,
	      carti_tiles,
	      carti_metasprites);

  carti.x = 20<<4;
  carti.y = 120<<4;
  
  SHOW_SPRITES;
  DISPLAY_ON;

  uint8_t frame_id = 0;
  uint8_t hiwater = 0;
  uint8_t on_ground = 0;
  uint8_t previous_joypad,current_joypad = 0;

  while (1){

    // On sauvegarde les inputs de la frame précédente et on récupère les nouveaux
    previous_joypad = current_joypad;
    current_joypad = joypad();

    //On modifie la physique du personnage en fonction des inputs

    
    if (carti.state & STATE_JUMP){
      //Si le personnage est en l'air
      //On gère le air control
      if (current_joypad & J_RIGHT){
	if (carti.dx < 0) carti.dx += AIR_CTRL;
      } else if (current_joypad & J_LEFT){
	if (carti.dx > 0) carti.dx -= AIR_CTRL;
      }
      
      //On applique la gravité
      carti.dy += GRAVITY;
      if (carti.dy > MAX_FALL_SPEED) carti.dy = MAX_FALL_SPEED;
      
      
    } else {
      //Si le personnage est au sol
      if (current_joypad & J_RIGHT){
	if (carti.dx < 0) carti.dx += SKIDDING;
	else carti.dx += ACCELERATION;
	if (carti.dx > MAX_SPEED) carti.dx = MAX_SPEED;
      }
      //
      else if (current_joypad & J_LEFT){
	if (carti.dx > 0) carti.dx -= SKIDDING;
	else carti.dx -= ACCELERATION;
	if (carti.dx < -MAX_SPEED) carti.dx = -MAX_SPEED;
      }
      else {
	//Si aucune direction horizontale mais le personnage est en
	//mouvement horizontal on apllique une décelération
	if (carti.dx > DECELERATION)  carti.dx -= DECELERATION;
	else if (carti.dx < -DECELERATION) carti.dx += DECELERATION;
	else carti.dx = 0;
      }

      if (current_joypad & J_A){
	//applique une poussée vertivale
	carti.dy -= JUMP_PUSH;
      }
    }
    
    
    
    //On applique la physique au personnage
    carti.x += carti.dx;
    carti.y += carti.dy;
    //On gère les collisions
    if (carti.x > (160<<4)) carti.x = (160<<4);
    if (carti.x < (8<<4)) carti.x = (8<<4);
    if (carti.y >= (120<<4)){
      carti.y = (120<<4);
      carti.dy = 0;
      on_ground = 1;
    } else on_ground = 0;
    //On met à jour l'état de Carti
    carti.state = 0;
    if (!on_ground) {
      carti.state |= STATE_JUMP;
      if (carti.dx >= 0) carti.state |= STATE_DIR_RIGHT;
    } else {
      if (carti.dx > 0) carti.state  |= (STATE_RUN | STATE_DIR_RIGHT);
      if (carti.dx < 0) carti.state  |= STATE_RUN;
      if (carti.dx == 0) carti.state |= STATE_IDLE;
    }
    //On gère l'affichage

    
    if (carti.state == STATE_IDLE){
      carti.runframe = 0;
      move_metasprite_ex(carti.sprites[0],0,0,0,carti.x>>4,carti.y>>4);
    }
    else if (carti.state & STATE_JUMP){
      carti.runframe = 0;
      if (carti.state & STATE_DIR_RIGHT)
	move_metasprite_ex(carti.sprites[3],0,0,0,carti.x>>4,carti.y>>4);
      else
	move_metasprite_flipx(carti.sprites[3],0,0,0,carti.x>>4,carti.y>>4);
    }
    else if (carti.state & STATE_RUN) {
      if (carti.runframe & 0x8) frame_id = 1;
      else frame_id = 2;
      if (carti.state & STATE_DIR_RIGHT)
	move_metasprite_ex(carti.sprites[frame_id],0,0,0,carti.x>>4,carti.y>>4);
      else
	move_metasprite_flipx(carti.sprites[frame_id],0,0,0,carti.x>>4,carti.y>>4);
      carti.runframe++;
    }
      
    wait_vbl_done();
    global_frame++;
  }
}
