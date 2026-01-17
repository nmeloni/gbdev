#ifndef GAME_H
#define GAME_H

#include <gb/gb.h>
#include <stdint.h>
#include <gbdk/metasprites.h>
#include <gbdk/emu_debug.h>

#include "input.h"
#include "player.h"

#define SCREEN_WIDTH  160
#define SCREEN_HEIGHT 144

#define GAMESCREEN_X_ORIGIN  (8)
#define GAMESCREEN_Y_ORIGIN  (16)

#define GAMESCREEN_WIDTH     (160)
#define GAMESCREEN_HEIGTH    (128)

#define GAMESCREEN_X_END     (GAMESCREEN_X_ORIGIN+GAMESCREEN_WIDTH)
#define GAMESCREEN_Y_END     (GAMESCREEN_Y_ORIGIN+GAMESCREEN_HEIGTH)

// États possibles du jeu
typedef enum {
    GAME_STATE_PLAY,
    GAME_STATE_PAUSE,
    GAME_STATE_GAME_OVER
} game_state_t;

// État global du jeu
extern game_state_t game_state;

extern uint8_t oam;
extern uint16_t frame_counter;


// Initialisation du jeu
void game_init(void);

// Mise à jour du jeu (appelée une fois par frame)
void game_update(void);

#endif // GAME_H
