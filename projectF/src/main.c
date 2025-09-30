#include <gb/gb.h>

#include "global.h"
#include "player.h"
#include "hud.h"

void main(void){
  
    init_player(20,120);
    init_hud();

    SHOW_SPRITES;
    SHOW_WIN;
    DISPLAY_ON;
  
    while (1){
	// Game loop
      
	UPDATE_KEYS();
	update_player();
	draw_player();
	draw_hud();
	wait_vbl_done();
    }
}
