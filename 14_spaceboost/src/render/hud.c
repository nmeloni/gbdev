#include <gb/gb.h>

#include "constants.h"
#include "player.h"
#include "hud.h"

// ============================================================================
// Indices de tiles dans la font (relatifs à TILE_FONT_BASE)
// ============================================================================
static const uint8_t DIGIT_TILE[10] = {
    14u,  // '0' — identique à 'O' dans cette font
    27u,  // '1'
    28u,  // '2'
    29u,  // '3'
    30u,  // '4'
    31u,  // '5'
    32u,  // '6'
    33u,  // '7'
    34u,  // '8'
    35u,  // '9'
};

// ============================================================================
// Layout Window row 0 (20 colonnes) :
//  col  0     : icône vaisseau
//  col  1     : blanc
//  col  2     : chiffre vies
//  col  3-6   : blanc
//  col  7-12  : S C O R E :
//  col  13    : blanc
//  col  14-17 : 4 chiffres score (score / 100)
//  col  18-19 : "00" fixes (scores toujours multiples de 100)
// ============================================================================
#define B  HUD_BLANK_TILE
#define T(r) ((uint8_t)(FONT_TILE + (r##u)))

static const uint8_t hud_static_row[20] = {
    HUD_SHIP_TILE, T(23), B,          // 0-2  (col 1 = X, col 2 = vies)
    B, B,                             // 3-4
    T(18), T(2), T(14), T(17), T(4), T(36),  // 5-10 : S C O R E :
    B,                                // 11
    B, B, B, B, B, B,                 // 12-17 (score, mis à jour)
    T(14), T(14),                     // 18-19 : "00" fixes
};

#undef B
#undef T

// ============================================================================
// Interface publique
// ============================================================================

void init_hud(void) {
    set_win_tiles(0u, 0u, 20u, 1u, hud_static_row);

    move_win(7u, 136u);
    SHOW_WIN;

    hud_set_lives();
    hud_set_score();
}

void update_hud(void) {}

void hud_set_score(void) {
    uint8_t tiles[6];
    uint8_t i;
    uint16_t s = PLAYER->score;

    for (i = 6u; i > 0u; i--) {
        tiles[i - 1u] = (uint8_t)(FONT_TILE + DIGIT_TILE[s % 10u]);
        s /= 10u;
    }
    set_win_tiles(HUD_COL_SCORE, 0u, 6u, 1u, tiles);
}

void hud_set_lives(void) {
    uint8_t tile = (uint8_t)(FONT_TILE + DIGIT_TILE[PLAYER->lives]);
    set_win_tiles(HUD_COL_LIVES, 0u, 1u, 1u, &tile);
}
