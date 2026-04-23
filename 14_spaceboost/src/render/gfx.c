#include <gb/gb.h>

#include "gfx.h"
#include "constants.h"

// Sprites
#include "player_sprite.h"
#include "shot_sprite.h"
#include "shield_sprite.h"
#include "explosion_sprite.h"
#include "bullet_sprite.h"
#include "powerup_sprite.h"
#include "enemy_drone_sprite.h"
// Background
#include "space_bkg_tileset.h"
#include "space_bkg_tilemap.h"

void gfx_init(void) {
    SPRITES_8x16;
    SHOW_SPRITES;
    SHOW_BKG;

    // Palette fond : blanc → noir
    BGP_REG  = DMG_PALETTE(DMG_WHITE, DMG_LITE_GRAY, DMG_DARK_GRAY, DMG_BLACK);
    // Palette sprites 0 (joueur, ennemis)
    OBP0_REG = DMG_PALETTE(DMG_BLACK, DMG_WHITE, DMG_LITE_GRAY, DMG_DARK_GRAY);
    // Palette sprites 1 (balles ennemies)
    OBP1_REG = DMG_PALETTE(DMG_BLACK, DMG_DARK_GRAY, DMG_DARK_GRAY, DMG_LITE_GRAY);

    // Chargement des tiles sprites en VRAM
    set_sprite_data(PLAYER_TILE_OFFSET,    player_sprite_TILE_COUNT,    player_sprite_tiles);
    set_sprite_data(SHIELD_TILE_OFFSET,    shield_sprite_TILE_COUNT,    shield_sprite_tiles);
    set_sprite_data(SHOT_TILE_OFFSET,      shot_sprite_TILE_COUNT,      shot_sprite_tiles);
    set_sprite_data(EXPLOSION_TILE_OFFSET, explosion_sprite_TILE_COUNT, explosion_sprite_tiles);
    set_sprite_data(BULLET_TILE_OFFSET,    bullet_sprite_TILE_COUNT,    bullet_sprite_tiles);
    set_sprite_data(POWERUP_TILE_OFFSET,   powerup_sprite_TILE_COUNT,   powerup_sprite_tiles);
    set_sprite_data(ENEMY_1_TILE_OFFSET,   enemy_drone_sprite_TILE_COUNT,   enemy_drone_sprite_tiles);

    // Background
    set_bkg_data(0x0, space_bkg_tileset_TILE_COUNT, space_bkg_tileset_tiles);
    set_bkg_tiles(0, 0, 20, 32, space_bkg_tilemap_map);
}
