#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <gbdk/emu_debug.h>

// ─── Ecran ────────────────────────────────────────────────────────────────────
#define SCREEN_WIDTH          160u
#define SCREEN_HEIGHT         144u

// ─── Background ───────────────────────────────────────────────────────────────
#define BACKGROUND_SCROLL_SPEED_Y (-3)

// ─── HUD ──────────────────────────────────────────────────────────────────────
#define HUD_COL_LIVES    2u
#define HUD_COL_SCORE   12u

// Zone de jeu (sprites OAM : décalage matériel de 8,16)
#define GAMESCREEN_X_ORIGIN   8u
#define GAMESCREEN_Y_ORIGIN   16u
#define GAMESCREEN_WIDTH      144u
#define GAMESCREEN_HEIGHT     128u
#define GAMESCREEN_X_END      (GAMESCREEN_X_ORIGIN + GAMESCREEN_WIDTH)
#define GAMESCREEN_Y_END      (GAMESCREEN_Y_ORIGIN + GAMESCREEN_HEIGHT)

// ─── Pools d'entités ──────────────────────────────────────────────────────────
#define MAX_ENEMIES           8u
#define MAX_SHOTS             4u
#define MAX_BULLETS           16u
#define MAX_EXPLOSIONS        8u

// ─── Joueur ───────────────────────────────────────────────────────────────────
#define PLAYER_LIVES            3u
#define PLAYER_SPEED            14
#define BOOST_SPEED             24
#define PLAYER_MAX_POWER_LVL    2u
#define PLAYER_MAX_LIVES        9u
#define PLAYER_INVINCIBILITY  191u
#define PLAYER_SHOT_COOLDOWN   12u
#define PLAYER_BOOST_DURATION  48u
#define PLAYER_BBOX_W           1u
#define PLAYER_BBOX_H           1u
// Limites basées sur l'analyse des offsets metasprite (METASPR_ITEM(dy,dx,dtile,props))
// Entry 0 : dx=-8 → OAM_x = body.x-8 → screen cols body.x-16 à body.x-9  (gauche)
// Entry 1 : dx=+8 → OAM_x = body.x+8 → screen cols body.x   à body.x+7   (droite)
// Bord gauche : body.x-16 = 0  → body.x = 16
// Bord droit  : body.x+7  = 159 → body.x = 152
// Bord haut/bas inchangés (validés par test)
#define PLAYER_MIN_X          8u
#define PLAYER_MAX_X          168u
#define PLAYER_MIN_Y          24u
#define PLAYER_MAX_Y          144u

#define PLAYER_START_X        84u
#define PLAYER_START_Y        112u

#define PLAYER_ANIMATION_FRAME_TOP   0
#define PLAYER_ANIMATION_FRAME_LEFT  1
#define PLAYER_ANIMATION_FRAME_RIGHT 2

// ─── Tirs joueur ──────────────────────────────────────────────────────────────
#define SHOT_SPEED              48
#define SHOT_ONSCREEN_X_OFFSET (-4)
#define SHOT_ONSCREEN_Y_OFFSET (-8)

#define SHOT_LVL1_WIDTH        1u
#define SHOT_LVL1_HEIGHT       2u
#define SHOT_LVL2_WIDTH        3u
#define SHOT_LVL2_HEIGHT       2u
#define SHOT_LVL3_WIDTH        6u
#define SHOT_LVL3_HEIGHT       3u

#define SHOT_POWER_LVL_1       1u
#define SHOT_POWER_LVL_2       2u
#define SHOT_POWER_LVL_3       4u

#define SHOT_BOUND_FRAME_SKIP  8u

// ───  Power Up─────────────────────────────────────────────────────────────────
#define POWERUP_BOUND_FRAME_SKIP     16u
#define POWERUP_VS_PLAYER_FRAME_SKIP  2u
#define POWERUP_VS_PLAYER_MAN_DIST   16u
#define POWERUP_BBOX_W                8u
#define POWERUP_BBOX_H                8u

// ─── Physique (virgule fixe 4 bits) ───────────────────────────────────────────
#define FRAC_SHIFT            4
#define FRAC_MASK             0x0F

// ───  Bullet ──────────────────────────────────────────────────────────────────
#define BULLET_SPRITE_X_OFFSET  (-4)
#define BULLET_SPRITE_Y_OFFSET  (-8)

#define BULLET_BOUND_FRAME_SKIP      16u
#define BULLET_VS_PLAYER_FRAME_SKIP   2u
#define BULLET_MIN_X                  4u
#define BULLET_MIN_Y                  8u
#define BULLET_MAX_X                168u
#define BULLET_MAX_Y                144u
#define BULLET_VS_PLAYER_MAN_DIST     8u

#define DIRECTIONS_NUMBER            16u
// ─── Enemy ────────────────────────────────────────────────────────────────────
// Marges de détection hors-écran (permet de sortir légèrement)
#define ENEMY_MIN_X     4u
#define ENEMY_MIN_Y     8u
#define ENEMY_MAX_X     168u
#define ENEMY_MAX_Y     144u

#define ENEMY_IS_HIT_DURATION    24u
#define ENEMY_ANIM_DURATION       8u
#define ENEMY_ANIM_DURATION_LOG2  3u

#define ENEMY_BOUND_HP_FRAME_SKIP    8u
#define ENEMY_VS_SHOT_FRAME_SKIP     4u
#define ENEMY_VS_SHOT_MAN_DIST      16u
#define ENEMY_VS_PLAYER_FRAME_SKIP   2u
#define ENEMY_VS_PLAYER_MAN_DIST    16u

// ─── Offsets de tiles dans la VRAM sprite ────────────────────────────────────
// Chaque entrée = index de départ dans la table sprite hardware (0-127 en 8x16)
// Layout séquentiel calculé depuis les TILE_COUNT de chaque sprite :
//   player(12) shield(4) shot(6) explosion(16) bullet(6)
//   powerup(12) enemy_1(8) enemy_2(8) enemy_3(8) boss(24) → total 104
#define PLAYER_TILE_OFFSET           0u
#define SHIELD_TILE_OFFSET          12u
#define SHOT_TILE_OFFSET            16u
#define EXPLOSION_TILE_OFFSET       22u
#define BULLET_SMALL_TILE_OFFSET    38u
#define BULLET_LARGE_TILE_OFFSET    40u
#define BULLET_LASER_TILE_OFFSET    42u

#define POWERUP_TILE_OFFSET         44u
#define POWERUP_SHOT_TILE_OFFSET       (POWERUP_TILE_OFFSET)
#define POWERUP_SHIELD_TILE_OFFSET     (POWERUP_TILE_OFFSET + 4u)
#define POWERUP_EXTRA_LIFE_TILE_OFFSET (POWERUP_TILE_OFFSET + 8u)

#define ENEMY_TILE_OFFSET   80u
#define ENEMY_1_TILE_OFFSET (ENEMY_TILE_OFFSET)
#define ENEMY_2_TILE_OFFSET (ENEMY_TILE_OFFSET + 8u)
#define ENEMY_3_TILE_OFFSET (ENEMY_TILE_OFFSET + 16u)
#define ENEMY_4_TILE_OFFSET (ENEMY_TILE_OFFSET + 24u)
#define ENEMY_5_TILE_OFFSET (ENEMY_TILE_OFFSET + 32u)
#define ENEMY_6_TILE_OFFSET (ENEMY_TILE_OFFSET + 40u)
#define ENEMY_7_TILE_OFFSET (ENEMY_TILE_OFFSET + 48u)
#define BOSS_TILE_OFFSET    80u

#define HUD_BLANK_TILE 0xC0u
#define HUD_SHIP_TILE  0xC1u
#define FONT_TILE      0xC2u

// ─── Durées et timings ────────────────────────────────────────────────────────
#define EXPLOSION_DURATION         32u
#define EXPLOSION_ANIM_SPEED_LOG2   3u
#define EXPLOSION_FRAMES            4u
#define HIT_FLASH_DURATION          6u

// ─── Score ────────────────────────────────────────────────────────────────────
#define SCORE_ENEMY_1         10u
#define SCORE_ENEMY_2         20u
#define SCORE_ENEMY_3         30u
#define SCORE_BOSS            200u


#endif // CONSTANTS_H
