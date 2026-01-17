#include "gfx.h"

void gfx_init(void) {

    // Définir le mode des sprites sur 8x16 pixels
    SPRITES_8x16;
    // Palletes des sprites
    OBP0_REG = DMG_PALETTE(DMG_BLACK, DMG_WHITE, DMG_LITE_GRAY, DMG_DARK_GRAY);
    // Initialisation des ressources graphiques (tiles, sprites, etc.)
    set_sprite_data(PLAYER_TILE_OFFSET, player_sprite_TILE_COUNT, player_sprite_tiles);
    set_sprite_data(SHOT_TILE_OFFSET, shot_sprite_TILE_COUNT, shot_sprite_tiles);
    
}
