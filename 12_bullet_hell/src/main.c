#include <gb/gb.h>
#include <stdint.h>
#include <gbdk/metasprites.h>
#include <gbdk/emu_debug.h>

#include "constants.h"
#include "input.h"
#include "player.h"
#include "bullet.h"

// Ressources générées par make resources
#include "player_sprite.h"
#include "bullet_sprite.h"

// ─── Globals partagés (extern dans player.c, bullet.c, perf.c) ────────────────
uint8_t  oam                  = 0;
uint16_t frame_counter        = 0;

// ─── Initialisation graphique ─────────────────────────────────────────────────
static void gfx_init(void) {
    SPRITES_8x16;

    // Palette fond : noir uni
    BGP_REG  = DMG_PALETTE(DMG_WHITE, DMG_LITE_GRAY, DMG_DARK_GRAY, DMG_BLACK);
    // Palette sprites 0 : joueur
    OBP0_REG = DMG_PALETTE(DMG_BLACK, DMG_WHITE, DMG_LITE_GRAY, DMG_DARK_GRAY);
    // Palette sprites 1 : bullets (couleurs inversées pour les distinguer)
    OBP1_REG = DMG_PALETTE(DMG_BLACK, DMG_DARK_GRAY, DMG_DARK_GRAY, DMG_LITE_GRAY);

    // Chargement des tiles sprites
    set_sprite_data(PLAYER_TILE_OFFSET, player_sprite_TILE_COUNT, player_sprite_tiles);
    set_sprite_data(BULLET_TILE_OFFSET, bullet_sprite_TILE_COUNT, bullet_sprite_tiles);

    hide_sprites_range(0, MAX_HARDWARE_SPRITES);
    SHOW_BKG;
    SHOW_SPRITES;
}

// ─── Point d'entrée ───────────────────────────────────────────────────────────
void main(void) {
    gfx_init();
    player_init();
    bullets_init();

    while (1) {
        vsync();

        UPDATE_KEYS();
        oam = 0;

        player_update();
        bullets_update();

        // Collision bullet → joueur : invincibilité temporaire
	
	if (bullets_check_collision(PLAYER.body.x, PLAYER.body.y, 1u, 1u)) {
	    PLAYER.invincibility_timer = 60u;
	}
        
	hide_sprites_range(oam, MAX_HARDWARE_SPRITES);
	frame_counter++;
    }
}
