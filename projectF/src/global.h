#ifndef GLOBAL_H
#define GLOBAL_H

#include <gb/gb.h>

#define UPDATE_KEYS()   previous_joypad = current_joypad; current_joypad = joypad()
#define KEY_PRESSED(K)  (current_joypad & (K))
#define KEY_DEBOUNCE(K) ((current_joypad & (K)) && (previous_joypad & (K)))
#define KEY_TICKED(K)   ((current_joypad & (K)) && !(previous_joypad & (K)))
#define KEY_RELEASED(K) ((previous_joypad & (K)) && !(current_joypad & (k)))

extern uint8_t current_joypad, previous_joypad;

#endif
