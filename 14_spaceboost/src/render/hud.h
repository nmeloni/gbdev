#ifndef HUD_H
#define HUD_H

#include <stdint.h>

// HUD via Window layer GB (bande fixe en bas, 20x2 tiles)
// Affiche : vies | score | hi-score

void init_hud(void);
void update_hud(void);          // à appeler si score/vies changé
void hud_set_score(void);
void hud_set_lives(void);

#endif
