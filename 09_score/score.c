#include <gb/gb.h>
#include "gb_numbers.h"

#define INIT_NUMBER(NUMBER,SPRITE,X,Y) {	\
	NUMBER.sprite = SPRITE;			\
	NUMBER.x = X;				\
	NUMBER.y = Y;				\
	NUMBER.val = 0;					   \
	set_sprite_tile(NUMBER.sprite, 0);		   \
	move_sprite(NUMBER.sprite, NUMBER.x, NUMBER.y);	   \
}

struct number {
    UINT8 sprite;
    UINT8 x;
    UINT8 y;
    UINT8 val;
};

struct number score[4];
UINT8 previous = 0, current = 0;

void main(void)
{
    //On charge les sprites des nombres
    set_sprite_data(0,10,gb_numbers_tiles);
    //On initialise les nombres aux différentes possitions
    OBP0_REG = 0x88;
    OBP1_REG = 0xFF;

    
    INIT_NUMBER(score[0],0,110,72);
    INIT_NUMBER(score[1],1, 96,72);
    INIT_NUMBER(score[2],2, 80,72);
    INIT_NUMBER(score[3],3, 64,72);

    
    SHOW_SPRITES;
    DISPLAY_ON;

    uint8_t  previous_joypad, current_joypad = 0;
    UINT8 props = get_sprite_prop(score[0].sprite);
    props |= S_PALETTE;
    set_sprite_prop(score[0].sprite, props);
    
    while (1){
	// On remet le chiffre précédent inactif
	if (previous != current){
	    props = get_sprite_prop(score[previous].sprite);
	    props &= ~S_PALETTE;
	    set_sprite_prop(score[previous].sprite, props);
	    // On rend le chiffre courant actif
	    props = get_sprite_prop(score[current].sprite);
	    props |= S_PALETTE;
	    set_sprite_prop(score[current].sprite, props);
	}
	// On récupère les nouveaux input
	previous_joypad = current_joypad;
	current_joypad = joypad();
	
	previous = current;
	switch( current_joypad ){
	case J_UP:
	    // Attention le Modulo % or puissance de 2 est très cher pour la gameboy
	    // on préfèrera faire la division "a la main"
	    if (!(previous_joypad & J_UP)){
		if (score[current].val == 9){
		    score[current].val = 0;
		} else {
		    score[current].val+=1;
		}
		set_sprite_tile(score[current].sprite, score[current].val);
	    }
	    break;
	case J_DOWN:
	    if (!(previous_joypad & J_DOWN)){
		if (score[current].val == 0){
		    score[current].val = 9;
		} else {
		    score[current].val-=1;
		}
		set_sprite_tile(score[current].sprite, score[current].val);
	    }
	    break;
	case J_LEFT:
	    if (!(previous_joypad & J_LEFT)){
		if (current == 3){
		    current = 0;
		} else {
		    current += 1;
		}
	    }
	    break;
	case J_RIGHT:
	    if (!(previous_joypad & J_RIGHT)){
		if (current == 0){
		    current = 3;
		} else {
		    current -= 1;
		}
	    }
	    break;
	case J_A:
	    //On ajoute 1 point au score total
	    //On gère la retenue à la main pour éviter les opération / et %
	    score[0].val += 1;
	    if (score[0].val < 10) break;
	    score[0].val = 0;
	    score[1].val += 1;
	    if (score[1].val < 10) break;
	    score[1].val = 0;
	    score[2].val += 1;
	    if (score[2].val < 10) break;
	    score[2].val = 0;
	    score[3].val += 1;
	    if (score[3].val < 10) break;
	    score[3].val = 0;
	    break;
	default:
	    break;
	}
	for (UINT8 i=0; i<4; i++){
	    set_sprite_tile(score[i].sprite, score[i].val);
	}
	
	wait_vbl_done();
    }
}
