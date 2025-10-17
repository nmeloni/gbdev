#include <gb/gb.h>
#include "bkgtiles.h"
#include "bkgmap.h"

void main(void)
{
  // On charge les tuiles 
  set_bkg_data(0,20,bkgtiles);
  // On charge le background
  set_bkg_tiles(0,0,20,14,bkgmap);
  /* 
   * On commence par copier une zone du background neutre
   * ici les colonnes 4 et 5 de la map
   */
  char bkgcolumn[28];
  UINT8 i;
  for (i=0; i<14; i+=1)
    {
      bkgcolumn[2*i] = bkgmap[4+bkgmapWidth*(i)];
      bkgcolumn[2*i+1] = bkgmap[5+bkgmapWidth*(i)];
    }
  // On complète la VRAM pour que le défilement soit propre
  for (i=20; i<32; i+=2)
    set_bkg_tiles(i,0,2,14,bkgcolumn);
  
  
  SHOW_BKG;
  DISPLAY_ON;

  while(1)
    {
      scroll_bkg(1,0);
      delay(100);
    }
}
