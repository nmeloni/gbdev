#include <gb/gb.h>
#include "dungeon_tileset.h"
#include "dungeon_map.h"

void main(void) {

    BGP_REG = DMG_PALETTE(dungeon_tileset_palettes[3], dungeon_tileset_palettes[1], dungeon_tileset_palettes[2], dungeon_tileset_palettes[0]);
        
    DISPLAY_ON;
    SHOW_BKG;

    SPRITES_8x8;
    set_bkg_data(0, dungeon_tileset_TILE_COUNT, dungeon_tileset_tiles);
    set_bkg_tiles(0, 0, 20, 18, dungeon_map_map);
    
}
