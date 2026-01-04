#ifndef GLOBAL_H
#define GLOBAL_H

#define UPDATE_KEYS()   previous_joypad = current_joypad; current_joypad = joypad()
#define KEY_PRESSED(K)  (current_joypad & (K))
#define KEY_RELEASED(K)    (!(current_joypad & (K)) && (previous_joypad & (K)))

#include <gb/gb.h>
#include <stdint.h>
#include <gbdk/platform.h>
#include <gbdk/metasprites.h>
#include <gbdk/emu_debug.h>

#include "bullet.h"
#include "powerup.h"
#include "ennemy.h"
#include "player.h"

#define GAMESCREEN_X_ORIGIN  (8)
#define GAMESCREEN_Y_ORIGIN  (16)
#define GAMESCREEN_WIDTH     (160)
#define GAMESCREEN_HEIGTH    (128)
#define GAMESCREEN_X_END     (GAMESCREEN_X_ORIGIN+GAMESCREEN_WIDTH)
#define GAMESCREEN_Y_END     (GAMESCREEN_Y_ORIGIN+GAMESCREEN_HEIGTH)

extern uint8_t current_joypad, previous_joypad;
extern uint16_t level_framecounter;
extern uint8_t oam;

#endif
