#include <gb/gb.h>

#include "global.h"
#include "player.h"
#include "playersprites.h"

player_t PLAYER;
uint8_t hiwater=0;
uint8_t sprite_selection;

void init_player(uint8_t x, uint8_t y){
  INIT_PLAYER(x<<6, y<<6, playersprites_metasprites, PLAYER_PALETTE);
  set_sprite_data(PLAYER_TILE_OFFSET, playersprites_TILE_COUNT, playersprites_tiles);
}

void update_player(void){
  ///////////////////////////////////////////
  //Si le joueur vient juste d'appyer sur A
  ///////////////////////////////////////////
  if (KEY_TICKED(J_A)){
    //Si le personnage est accroupi rien ne se passe
    //Si le personnage est au sol  on initiale le compteur de frame du saut
    if (!(PLAYER.status & PLAYER_STATUS_CROUCHING) &&
	!(PLAYER.status & PLAYER_STATUS_IN_AIR) ){
      PLAYER.jump_frame = PLAYER_START_JUMP_FRAME;
    }
  }

  ///////////////////////////////////////////
  //Si le JOUEUR appuie sur Bas ou pas
  /////////////////////////////////////////// 
  if ( KEY_PRESSED(J_DOWN)){
    PLAYER.status |= PLAYER_STATUS_CROUCHING;
  } else {
    PLAYER.status &= ~PLAYER_STATUS_CROUCHING;
  }

  ///////////////////////////////////////////
  //Si le JOUEUR appuie sur B ou pas
  /////////////////////////////////////////// 
  if ( KEY_PRESSED(J_B)){
    PLAYER.status |= PLAYER_STATUS_HOLDING;
  } else {
    PLAYER.status &= ~PLAYER_STATUS_HOLDING;
  }

  ///////////////////////////////////////////////////////////////
  //Si le JOUEUR appuie sur droite le personnage commence à avancer
  ///////////////////////////////////////////////////////////////
  if ( KEY_PRESSED(J_RIGHT)){
    PLAYER.dx = 1;
  } else {
    PLAYER.dx = 0;
  }
  
  //////////////////////////
  //On applique la physique
  //////////////////////////
  
  //Si le personnage est en pĥase d'ascension
  if (PLAYER.jump_frame > 0){
    
    //Si le personnage est en l'air met le bouton saut est relaché lors
    //d'une des frames cles du saut on annule l'accélaration vers le
    //haut, permet de gérer 3 hauteurs de saut
    if ( ! KEY_PRESSED(J_A)) {
      if (PLAYER.jump_frame == PLAYER_SECOND_JUMP_FRAME) PLAYER.jump_frame = 0;
      if (PLAYER.jump_frame == PLAYER_THIRD_JUMP_FRAME)  PLAYER.jump_frame = 0;
    }

    //On modifie l'accelération verticale en fonction du pallier de saut
    if (PLAYER.jump_frame > PLAYER_SECOND_JUMP_FRAME) {
      PLAYER.dy -= PLAYER_JUMP_ACC_1;
    } else if (PLAYER.jump_frame > PLAYER_THIRD_JUMP_FRAME) {
      PLAYER.dy -= PLAYER_JUMP_ACC_2;
    } else {
      PLAYER.dy -= PLAYER_JUMP_ACC_3;
    }

    
  }
  //Sinon si le personnage est en l'air on applique la gravité et on
  //limite la vitesse de chute maximale
  if (PLAYER.status & PLAYER_STATUS_IN_AIR) {
    PLAYER.dy += PLAYER_GRAVITY;
    if (PLAYER.dy > PLAYER_MAX_FALL_SPEED) PLAYER.dy = PLAYER_MAX_FALL_SPEED;
  }

  PLAYER.x += PLAYER.dx;
  PLAYER.y += PLAYER.dy;

  PLAYER.status &=  ~PLAYER_STATUS_IDLE;
  //On vérifie les collisions au sol
  if (PLAYER.y >= 120<<6) {
    PLAYER.y = 120<<6;
    PLAYER.status &=  ~PLAYER_STATUS_IN_AIR;
    PLAYER.jump_frame = 0;
    PLAYER.dy = 0;
  } else {
    PLAYER.status |=   PLAYER_STATUS_IN_AIR;
  }

  if (PLAYER.dx > 0){
    PLAYER.status |=  PLAYER_STATUS_RUNNING;
  } else {
    PLAYER.status &= ~PLAYER_STATUS_RUNNING;
  }

  if (! (PLAYER.status & (PLAYER_STATUS_IN_AIR   |
			  PLAYER_STATUS_RUNNING  |
			  PLAYER_STATUS_CROUCHING|
			  PLAYER_STATUS_HOLDING))){
    PLAYER.status |=  PLAYER_STATUS_IDLE; 
  }
  //On modifie les différents compteur de frame
  if (PLAYER.jump_frame > 0) PLAYER.jump_frame--;
}

void draw_player(void){
  OBP0_REG = PLAYER.palette;
  if (PLAYER.status & PLAYER_STATUS_IDLE){
    hiwater = move_metasprite_ex(PLAYER.sprites[PLAYER_SPRITE_IDLE],
				 0, 0, 0,PLAYER.x>>6,PLAYER.y>>6);
  }
  ///////////////////////////////////////////////////////////////
  //Selection du metasprite en fonction de l'état du personnage
  ///////////////////////////////////////////////////////////////
  if (PLAYER.status & PLAYER_STATUS_CROUCHING){
    if (PLAYER.status & PLAYER_STATUS_HOLDING) sprite_selection = PLAYER_SPRITE_CROUCH_HOLD;
    else sprite_selection = PLAYER_SPRITE_CROUCH;
  }

  else if (PLAYER.status & PLAYER_STATUS_IN_AIR){
    if (PLAYER.status & PLAYER_STATUS_HOLDING) sprite_selection = PLAYER_SPRITE_HOLD_2;
    else sprite_selection = PLAYER_SPRITE_RUN_2;
  }

  else if (PLAYER.status & PLAYER_STATUS_RUNNING){
    if (PLAYER.status & PLAYER_STATUS_HOLDING) {
      if (PLAYER.run_frame & 4) sprite_selection = PLAYER_SPRITE_HOLD_2;
      else sprite_selection = PLAYER_SPRITE_HOLD_1;
    } else {
      if (PLAYER.run_frame & 4) sprite_selection = PLAYER_SPRITE_RUN_2;
      else sprite_selection = PLAYER_SPRITE_RUN_1;
    }
    
  }

  else if (PLAYER.status & (PLAYER_STATUS_HOLDING)){
    sprite_selection = PLAYER_SPRITE_HOLD_1;
  }
  else {
    sprite_selection = PLAYER_SPRITE_IDLE;
  }

  hiwater = move_metasprite_ex(PLAYER.sprites[sprite_selection],
				 0, 0, 0,PLAYER.x>>6,PLAYER.y>>6);
  hide_metasprite(PLAYER.sprites[sprite_selection],hiwater);

  PLAYER.run_frame++;
}
  

  
   
  

