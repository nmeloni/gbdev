#include <stdint.h>

#include "game.h"
#include "constants.h"
#include "game_types.h"
#include "gfx.h"
#include "hud.h"
#include "background.h"
#include "logo.h"
#include "titlescreen.h"
#include "audio.h"
#include "player.h"
#include "shot.h"
#include "enemy.h"
#include "bullet.h"
#include "boss.h"
#include "powerup.h"
#include "explosion.h"
#include "level.h"


// ─── État global ──────────────────────────────────────────────────────────────
game_state_t game_state    = GAME_STATE_INIT;
game_state_t previous_state = GAME_STATE_INIT;

uint16_t frame_counter = 0;
uint8_t  oam           = 0;

// ─── Prototypes internes ──────────────────────────────────────────────────────
static void init_gameplay(void);
static void update_gameplay(void);
static void update_pause(void);
static void init_game_over(void);
static void update_game_over(void);

// ─── API publique ─────────────────────────────────────────────────────────────

void game_init(void) {
    oam           = 0;
    frame_counter = 0;
    hide_sprites_range(0, MAX_HARDWARE_SPRITES);
    game_change_state(GAME_STATE_PLAY);
}

void game_change_state(game_state_t new_state) {
    previous_state = game_state;
    game_state     = new_state;

    switch (game_state) {
        case GAME_STATE_INIT:
            game_init();
            break;
        case GAME_STATE_LOGO:
            init_logo();
            break;
        case GAME_STATE_TITLE_SCREEN:
            init_title_screen();
            break;
        case GAME_STATE_PLAY:
            if (previous_state == GAME_STATE_PAUSE) {
                // Reprise depuis pause : rien à réinitialiser
            } else {
                init_gameplay();
            }
            break;
        case GAME_STATE_PAUSE:
            // Rien à initialiser : l'état de jeu est conservé
            break;
        case GAME_STATE_GAME_OVER:
            init_game_over();
            break;
        default:
            break;
    }
}

void game_update(void) {
    UPDATE_KEYS();

    switch (game_state) {
        case GAME_STATE_INIT:
            game_init();
            break;
        case GAME_STATE_LOGO:
            show_logo();
            break;
        case GAME_STATE_TITLE_SCREEN:
            show_title_screen();
            break;
        case GAME_STATE_PLAY:
            update_gameplay();
            break;
        case GAME_STATE_PAUSE:
            update_pause();
            break;
        case GAME_STATE_GAME_OVER:
            update_game_over();
            break;
        default:
            break;
    }
}

// ─── Implémentations internes ─────────────────────────────────────────────────

static void init_gameplay(void) {
    frame_counter = 0;
    gfx_init();
    init_player();
    init_hud();

    init_shots();
    init_enemies();
    init_bullets();
    init_powerup();
    init_explosions();
    //init_boss();
    init_background();
    //init_audio();
    init_level(LEVEL_1);

}

static void update_gameplay(void) {
    // Sur la première frame, neutralise les KEY_RELEASED hérités du title screen
    // (évite un boost involontaire si A était tenu pendant le menu)
    if (frame_counter == 0) previous_joypad = current_joypad;
    frame_counter++;
    oam = 0;

    update_shots();
    update_player();

    update_bullets();
    update_enemies();

    //if (BOSS.active) update_boss();
    update_powerup();
    update_explosions();

    scroll_background();
    update_level();

    hide_sprites_range(oam, MAX_HARDWARE_SPRITES);

    // Entrée en pause
    if (KEY_TICKED(J_START)) {
        game_change_state(GAME_STATE_PAUSE);
    }
}

static void update_pause(void) {
    // On continue d'afficher la scène mais sans la mettre à jour
    if (KEY_TICKED(J_START)) {
        game_change_state(GAME_STATE_PLAY);
    }
}

static void init_game_over(void) {
    frame_counter = 180;
}

static void update_game_over(void) {
    if (frame_counter > 0) {
        oam = 0;
        update_shots();
        //update_enemies();
        //if (BOSS.active) update_boss();
        //update_bullets();
        //update_powerup();
        //update_explosions();
        scroll_background();
        hide_sprites_range(oam, MAX_HARDWARE_SPRITES);
        frame_counter--;
    } else {
        game_change_state(GAME_STATE_TITLE_SCREEN);
    }
}
