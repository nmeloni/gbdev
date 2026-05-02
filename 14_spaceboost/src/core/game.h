#ifndef GAME_H
#define GAME_H

#include <gb/gb.h>
#include <stdint.h>

#include "constants.h"
#include "game_types.h"
#include "input.h"

// ─── États du jeu ─────────────────────────────────────────────────────────────
typedef enum {
    GAME_STATE_INIT,
    GAME_STATE_LOGO,
    GAME_STATE_TITLE_SCREEN,
    GAME_STATE_PLAY,
    GAME_STATE_PAUSE,
    GAME_STATE_GAME_OVER
} game_state_t;

extern game_state_t game_state;

// Compteur de frames global (incrémenté à chaque frame de gameplay)
extern uint16_t frame_counter;

// Index OAM courant — réinitialisé à 0 chaque frame, passé aux fonctions de dessin
extern uint8_t oam;

void game_init(void);
void game_change_state(game_state_t new_state);
void game_update(void);

#endif // GAME_H
