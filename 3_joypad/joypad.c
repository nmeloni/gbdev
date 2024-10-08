#include <gb/gb.h>
#include "buttons.h"

#define INIT_BUTTON(BUTTON,SPRITE,X,Y) { \
  BUTTON.sprite = SPRITE; \
  BUTTON.x = X; \
  BUTTON.y = Y; \
  BUTTON.pushed = 0; \
  set_sprite_tile(BUTTON.sprite, BUTTON.sprite*2); \
  move_sprite(BUTTON.sprite, BUTTON.x, BUTTON.y);	   \
}

struct button {
  UINT8 sprite;
  UINT8 x;
  UINT8 y;
  UINT8 pushed;
};

struct button A, B, UP, DOWN, LEFT, RIGHT, SELECT, START;

void main(void){

  //charge les sprites des buttons
  set_sprite_data(0,16,buttons);
  //On initialise les positions des différents sprites
  
  INIT_BUTTON(A,0,110,72);
  INIT_BUTTON(B,1,98,72);
  INIT_BUTTON(UP,2,48,64);
  INIT_BUTTON(DOWN,3,48,80);
  INIT_BUTTON(LEFT,4,40,72);
  INIT_BUTTON(RIGHT,5,56,72);
  INIT_BUTTON(SELECT,6,72,72);
  INIT_BUTTON(START,7,84,72);

  SHOW_SPRITES;
  
  while (1)
    {
      delay(100);
      switch( joypad() ){
      case J_A:
	A.pushed ^= 1;  //change le statut du bouton
	set_sprite_tile(A.sprite, A.sprite*2 + A.pushed);
	break; //modifie le sprite en conséquence
      case J_B:
	B.pushed ^= 1;  //change le statut du bouton
	set_sprite_tile(B.sprite, B.sprite*2 + B.pushed);
	break; //modifie le sprite en conséquence
      case J_UP:
	UP.pushed ^= 1;  //change le statut du bouton
	set_sprite_tile(UP.sprite, UP.sprite*2 + UP.pushed);
	break; //modifie le sprite en conséquence
      case J_DOWN:
	DOWN.pushed ^= 1;  //change le statut du bouton
	set_sprite_tile(DOWN.sprite, DOWN.sprite*2 + DOWN.pushed);
	break; //modifie le sprite en conséquence
      case J_LEFT:
	LEFT.pushed ^= 1;  //change le statut du bouton
	set_sprite_tile(LEFT.sprite, LEFT.sprite*2 + LEFT.pushed);
	break; //modifie le sprite en conséquence
      case J_RIGHT:
	RIGHT.pushed ^= 1;  //change le statut du bouton
	set_sprite_tile(RIGHT.sprite, RIGHT.sprite*2 + RIGHT.pushed);
	break; //modifie le sprite en conséquence
      case J_SELECT:
	SELECT.pushed ^= 1;  //change le statut du bouton
	set_sprite_tile(SELECT.sprite, SELECT.sprite*2 + SELECT.pushed);
	break; //modifie le sprite en conséquence
      case J_START:
	START.pushed ^= 1;  //change le statut du bouton
	set_sprite_tile(START.sprite, START.sprite*2 + START.pushed);
	break; //modifie le sprite en conséquence
      }
    }
}

