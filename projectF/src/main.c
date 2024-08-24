#include <gb/gb.h>

#include "global.h"
#include "player.h"

void main(void){

  
  init_player(20,120);
  
  SHOW_SPRITES;
  DISPLAY_ON;
  
  while (1){
    UPDATE_KEYS();
    update_player();
    draw_player();
    wait_vbl_done();
  }
}
