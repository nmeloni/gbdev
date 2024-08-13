#include <gb/gb.h>
#include "alphabet.h"

void main(void)
{
  /*
    On charge les sprites de 0 a 27 depuis le tableau `alphabet`
   */
  set_sprite_data(0,28,alphabet);
  
  char hello[] = "hello";
  char world[] = "world";
 
  UINT8 i;

  i= 0;
  while (hello[i] != '\0'){
    set_sprite_tile(i,hello[i]-'a'+1);
    move_sprite(i, 32+i*8, 70);
    i++;
  }

  i= 0;
  while (world[i] != '\0'){
    set_sprite_tile(i+5,world[i]-'a'+1);
    move_sprite(i+5, 32+48+i*8, 70);
    i++;
  }

  /* 
     le sprite '!' n'apparait pas car la gameboy
     ne peut afficher que 10 sprites par ligne
   */  
  set_sprite_tile(10,27);
  move_sprite(10, 32+48+i*8, 70);
  
  SHOW_SPRITES;

  /*
    Petite animation pour que les 11 sprites s'affichent
   */
  i = 10;
  scroll_sprite(i, 0 , -8 );
  while (1){
    scroll_sprite(i, 0 , 8 );
    i = (i+1) % 11;
    scroll_sprite(i, 0 , -8 );
    delay(200);
  }
}
