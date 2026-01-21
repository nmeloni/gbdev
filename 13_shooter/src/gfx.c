#include "gfx.h"

void gfx_init(void) {

    // Définir le mode des sprites sur 8x16 pixels
    SPRITES_8x16;
    // Palletes de fond
    BGP_REG = DMG_PALETTE(DMG_WHITE, DMG_LITE_GRAY, DMG_DARK_GRAY, DMG_BLACK);
    // Palletes des sprites
    OBP0_REG = DMG_PALETTE(DMG_BLACK, DMG_WHITE, DMG_LITE_GRAY, DMG_DARK_GRAY);
    OBP1_REG = DMG_PALETTE(DMG_BLACK, DMG_DARK_GRAY, DMG_DARK_GRAY, DMG_LITE_GRAY);
    // Initialisation des ressources graphiques (tiles, sprites, etc.)
    set_sprite_data(PLAYER_TILE_OFFSET, player_sprite_TILE_COUNT, player_sprite_tiles);
    set_sprite_data(SHOT_TILE_OFFSET, shot_sprite_TILE_COUNT, shot_sprite_tiles);
    set_sprite_data(SHIELD_TILE_OFFSET, shield_sprite_TILE_COUNT, shield_sprite_tiles);
    set_sprite_data(EXPLOSION_TILE_OFFSET, explosion_sprite_TILE_COUNT, explosion_sprite_tiles);
    
    set_sprite_data(BULLET_TILE_OFFSET, bullet_sprite_TILE_COUNT, bullet_sprite_tiles);
    set_sprite_data(ENEMY_1_TILE_OFFSET, enemy_1_sprite_TILE_COUNT, enemy_1_sprite_tiles);
    set_sprite_data(ENENY_2_TILE_OFFSET, enemy_2_sprite_TILE_COUNT, enemy_2_sprite_tiles);
    set_sprite_data(ENEMY_3_TILE_OFFSET, enemy_3_sprite_TILE_COUNT, enemy_3_sprite_tiles);
    set_sprite_data(POWERUP_TILE_OFFSET, powerup_sprite_TILE_COUNT, powerup_sprite_tiles);
    set_bkg_data(0x0, space_bkg_tileset_TILE_COUNT, space_bkg_tileset_tiles);
    set_bkg_tiles(0, 0, 20, 32, space_bkg_tilemap_map);
}
