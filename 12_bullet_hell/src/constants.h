#ifndef CONSTANTS_H
#define CONSTANTS_H

// ─── Ecran ────────────────────────────────────────────────────────────────────
#define SCREEN_WIDTH          160u
#define SCREEN_HEIGHT         144u
#define SPRITE_DRAW_OFFSET_X  4u
#define SPRITE_DRAW_OFFSET_Y  8u

// Zone de jeu (offset matériel OAM : +8 x, +16 y)
#define GAMESCREEN_X_ORIGIN   8u
#define GAMESCREEN_Y_ORIGIN   16u
#define GAMESCREEN_WIDTH      144u
#define GAMESCREEN_HEIGHT     128u
#define GAMESCREEN_X_END      (GAMESCREEN_X_ORIGIN + GAMESCREEN_WIDTH)
#define GAMESCREEN_Y_END      (GAMESCREEN_Y_ORIGIN + GAMESCREEN_HEIGHT)

// ─── Joueur ───────────────────────────────────────────────────────────────────
#define PLAYER_SPEED          14
#define BOOST_SPEED           24
#define PLAYER_BOOST_DURATION 48u

#define PLAYER_MIN_X  16u
#define PLAYER_MAX_X  152u
#define PLAYER_MIN_Y  24u
#define PLAYER_MAX_Y  136u

#define PLAYER_START_X  84u
#define PLAYER_START_Y  120u

// ─── Bullets ──────────────────────────────────────────────────────────────────
#define MAX_BULLETS           32u   // 40 OAM - 2 pour le joueur (2 hw sprites 8x16)
#define BULLET_HITBOX_W       2u
#define BULLET_HITBOX_H       2u

// Nombre de frames entre chaque spawn d'un nouveau bullet
#define BULLET_SPAWN_INTERVAL 4u

// ─── Offsets tiles VRAM sprites ───────────────────────────────────────────────
// player_sprite : 12 tiles (3 frames × 4 tiles)  → slots 0-11
// bullet_sprite :  6 tiles (3 frames × 2 tiles)  → slots 12-17
#define PLAYER_TILE_OFFSET    0u
#define BULLET_TILE_OFFSET    12u

// ─── Physique (virgule fixe 4 bits) ───────────────────────────────────────────
#define FRAC_SHIFT            4
#define FRAC_MASK             0x0F
#define MAN_DIST_THRESHOLD    10

#endif // CONSTANTS_H
