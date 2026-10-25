#ifndef TYPES_H
#define TYPES_H

#include <gb/gb.h>      
#include "config.h"

/* ============================================================
/*  types.h : types partagés entre les modules
/* ============================================================ */

/* --- Machine à états du jeu --------------------------------- */
typedef enum {
  STATE_INIT,
  STATE_LOGO,
  STATE_TITLE_SCREEN,
  STATE_PLAY,
  STATE_PAUSE,
  STATE_GAME_OVER
} GameState;

/* --- Structure player --------------------------------------- */
typedef enum {

} PlayerState;

#endif
