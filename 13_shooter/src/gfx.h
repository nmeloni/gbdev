#ifndef GFX_H
#define GFX_H

#include <gb/gb.h>

#include "player.h"
#include "player_sprite.h"

#include "shot.h"
#include "shot_sprite.h"

#include "bullet.h"
#include "bullet_sprite.h"

#include "enemy.h"
#include "enemy_1_sprite.h"
#include "enemy_2_sprite.h"
#include "enemy_3_sprite.h"

#include "boss.h"
#include "mini_boss_1_sprite.h"
#include "mini_boss_2_sprite.h"

#include "explosion.h"
#include "explosion_sprite.h"

#include "powerup.h"
#include "powerup_sprite.h"

#include "background.h"
#include "space_bkg_tileset.h"
#include "space_bkg_tilemap.h"

// Fonction d'initialisation de toutes les ressources graphiques
void gfx_init(void);

#endif // GFX_H
