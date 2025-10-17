#include <gb/gb.h>
#include <stdio.h>


void main(void)
{
  
  NR52_REG = 0x80; //permet d'allumer le son
  NR50_REG = 0x77; //met le son des deux haut-parleurs au maximum
  NR51_REG = 0xFF; //l'ensemble des 4 canaux sont utilisés sur les deux haut-parleurs
  uint8_t current_joypad = 0, previous_joypad;
  uint8_t sound_A_cnt=0, sound_B_cnt=0;
  while (1){

    previous_joypad = current_joypad;
    current_joypad = joypad();

    //On met à jour les variables de son
    if ( (current_joypad & J_A) && !(previous_joypad & J_A)){
      if (sound_A_cnt == 0){
	sound_A_cnt = 2;
      }
    }
    if  ( (current_joypad & J_B) && !(previous_joypad & J_B)){
      if (sound_B_cnt == 0){
	sound_B_cnt = 4;
      }
    }
    //En fonction des boutons et de la frame on joue les sons correspondant
    if (sound_A_cnt > 0){
    //Bruitage de saut
      NR10_REG = 0x27;
      NR11_REG = 0x40;
      NR12_REG = 0x37;
      NR13_REG = 0xFB;
      NR14_REG = 0x85;
    }
    if (sound_B_cnt == 4){
      //Premier son du bruitage de piece
      NR21_REG = 0x81;
      NR22_REG = 0x47;
      NR23_REG = 0x97;
      NR24_REG = 0x87;
    } else if (sound_B_cnt == 2){
      NR21_REG = 0x81;
      NR22_REG = 0x47;
      NR23_REG = 0xB1;
      NR24_REG = 0x87;
    }

    if (sound_B_cnt > 0) sound_B_cnt--;
    if (sound_A_cnt > 0) sound_A_cnt--;
    wait_vbl_done();
  }
}
