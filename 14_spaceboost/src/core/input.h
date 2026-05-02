#ifndef INPUT_H
#define INPUT_H

#include <gb/gb.h>
#include <stdint.h>

extern uint8_t current_joypad;
extern uint8_t previous_joypad;

#define UPDATE_KEYS()    previous_joypad = current_joypad; current_joypad = joypad()
#define KEY_PRESSED(K)   (current_joypad & (K))
#define KEY_DEBOUNCE(K)  ((current_joypad & (K)) && (previous_joypad & (K)))
#define KEY_TICKED(K)    ((current_joypad & (K)) && !(previous_joypad & (K)))
#define KEY_RELEASED(K)  ((previous_joypad & (K)) && !(current_joypad & (K)))

#endif // INPUT_H
