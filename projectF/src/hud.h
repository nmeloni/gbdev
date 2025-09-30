#ifndef HUD_H
#define HUD_H

#include <gb/gb.h>
#include <gbdk/font.h>

#define FONT_OFFSET 37
#define WINDOW_OFFSET 10

#define TILE_0 0x1
#define TILE_A 0xB

#define SCORE_X 7
#define SCORE_Y 1

typedef struct {
    uint16_t score;
    uint8_t score_string[7]; // 4 digits + 00 + null terminator
    uint8_t lives;
    uint8_t level;
    font_t font;
} hud_t;

void init_hud(void);
void update_hud(void);
void draw_hud(void);
void set_score(uint16_t score);
void set_lives(uint8_t lives);
void set_health(uint8_t health);

extern hud_t HUD;

#endif
