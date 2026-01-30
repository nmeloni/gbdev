#ifndef AUDIO_H
#define AUDIO_H

#include <gb/gb.h>

typedef enum {
    SFX_SHOOT,
    SFX_EXPLODE,
    SFX_HIT,
    SFX_POWERUP,
} SfxId;

void audio_init(void);
void audio_play_sfx(SfxId id);

#endif // AUDIO_H
