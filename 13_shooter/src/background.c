#include "background.h"

background_t BACKGROUND;

void init_background(void) {
    // Charger les données de la carte de fond
    set_bkg_data(0x0, space_bkg_tileset_TILE_COUNT, space_bkg_tileset_tiles);
    set_bkg_tiles(0, 0, 20, 32, space_bkg_tilemap_map);
    
    BACKGROUND.dx = 0;
    BACKGROUND.fx = 0;
    BACKGROUND.dy = -4;
    BACKGROUND.fy = 0;
}



void scroll_background(void) {
    // Mise à jour des parties fractionnaires pour un mouvement plus fluide
	BACKGROUND.fx += BACKGROUND.dx;
	BACKGROUND.fy += BACKGROUND.dy;
	
	scroll_bkg(BACKGROUND.fx>>4, BACKGROUND.fy>>4);   

	BACKGROUND.fx &= 0x0F;
	BACKGROUND.fy &= 0x0F;

	// Appliquer le défilement du fond
	
    
}
