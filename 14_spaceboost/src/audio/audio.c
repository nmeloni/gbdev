#include "audio.h"

static void sfx_shoot(void);
static void sfx_explode(void);
static void sfx_hit(void);
static void sfx_powerup(void);

void init_audio(void) {
    NR52_REG = 0x80; // Son activé
    NR50_REG = 0x77; // Volume max L/R
    NR51_REG = 0xFF; // Tous canaux vers L/R
}

void audio_play_sfx(SfxId id) {
    switch (id) {
        case SFX_SHOOT:   sfx_shoot();   break;
        case SFX_EXPLODE: sfx_explode(); break;
        case SFX_HIT:     sfx_hit();     break;
        case SFX_POWERUP: sfx_powerup(); break;
    }
}

static void sfx_shoot(void) {
    NR10_REG = 0x1F;
    NR11_REG = 0x28;
    NR12_REG = 0xF1;
    NR13_REG = 0xEA;
    NR14_REG = 0x86;
}

static void sfx_explode(void) {
    NR41_REG = 0x10;
    NR42_REG = 0xF1;
    NR43_REG = 0x25;
    NR44_REG = 0xC0;
}

static void sfx_hit(void) {
    NR10_REG = 0x00;
    NR11_REG = 0x80;
    NR12_REG = 0xE2;
    NR13_REG = 0x20;
    NR14_REG = 0x87;
}

static void sfx_powerup(void) {
    NR10_REG = 0x1E;
    NR11_REG = 0x40;
    NR12_REG = 0xF3;
    NR13_REG = 0x30;
    NR14_REG = 0x87;
}
