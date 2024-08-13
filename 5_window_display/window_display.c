#include <gb/gb.h>
#include <gbdk/font.h>

#include "bkgtiles.h"
#include "bkgmap.h"
#include "wintiles.h"
#include "winmap.h"

#define FONT_OFFSET 37
#define WINDOW_OFFSET 10

#define TILE_0 0x1
#define TILE_A 0xB

void main(void)
{
  //charge la police 'font_min' et on l'active
  font_t min_font;
  font_init();
  min_font = font_load(font_min);
  font_set(min_font);
  
  // On décale l'index de départ des tuiles du nombre de sprites de la fonte
  set_win_data(FONT_OFFSET, WINDOW_OFFSET + FONT_OFFSET ,wintiles);
  // On décale l'indiçage des tuiles dans la map en conséquénce
  set_win_based_tiles(0,0,20,4,winmap, FONT_OFFSET);
  // On déplace la fenêtre pour ne pas qu'elle masque le BKG
  move_win(7,14*8);
  // On charge le BKG 
  set_bkg_data(FONT_OFFSET+WINDOW_OFFSET,20+FONT_OFFSET+WINDOW_OFFSET,bkgtiles);
  set_bkg_based_tiles(0,0,20,14,bkgmap,FONT_OFFSET+WINDOW_OFFSET);

  SHOW_BKG;
  SHOW_WIN;
  DISPLAY_ON;

  
  char msg[] = "window display";
  uint8_t win_text[16];
    
  uint8_t i;
  for (i=0; msg[i]!='\0'; i++)
    {
      uint8_t c;
      if (msg[i]==' ') c = 0;
      else {
	c = msg[i] - 'a' + TILE_A;
      }
      win_text[i] = c;
    }

  uint8_t write = 1;
  uint8_t empty[1] = {0};;
  i = 0;  
  while(1)
    {
      if (write)
	set_win_tiles( 4+i, 1, 1, 1, win_text +i);
      else
	set_win_tiles( 4+i, 1, 1, 1, empty);
      i = i+1;
      if (i==14){
	i = 0;
	write ^= 1;
      }
      delay(100);

    }
}
