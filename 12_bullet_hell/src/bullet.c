#include "bullet.h"
#include "body.h"
#include "constants.h"
#include "utils.h"

#include <gb/gb.h>
#include <stdint.h>

// Définis dans main.c
extern uint8_t  oam;
extern uint16_t frame_counter;

bullet_t BULLETS_POOL[MAX_BULLETS];
uint8_t  ACTIVE_BULLETS[MAX_BULLETS];
uint8_t  active_bullet_count = 0;

static uint8_t spawn_dir   = 0;
static uint8_t spawn_timer = 0;
static uint8_t bullet_collision_bit = 0;

// ─── Suppression O(1) : swap avec le dernier élément ─────────────────────────
// Attention : le bullet swappé sera traité à la prochaine frame (acceptable)
static inline void kill_bullet(uint8_t j) {
    BULLETS_POOL[ACTIVE_BULLETS[j]].active = 0;
    ACTIVE_BULLETS[j] = ACTIVE_BULLETS[--active_bullet_count];
}

// ─── Spawn ────────────────────────────────────────────────────────────────────
static void try_spawn_bullet(void) {
    if (active_bullet_count >= MAX_BULLETS) return;

    // Trouver un slot libre dans le pool (scan O(N) mais rare)
    bullet_t  *b = &BULLETS_POOL[0];
    for (uint8_t i = 0; i < MAX_BULLETS; i++,b++) {
        if (b->active) continue;

        uint8_t d  = spawn_dir & 0x0F;
        int8_t  dx = directions_dx[d];
        int8_t  dy = directions_dy[d];

        b->body.dx = dx;
        b->body.dy = dy;
        b->body.fx = 0;
        b->body.fy = 0;

        // Position sur le bord opposé à la direction
        // Variation via frame_counter pour éviter les superpositions
        uint8_t var = (uint8_t)(frame_counter ^ (i << 2));

        if (dx >= 6) {
            b->body.x = GAMESCREEN_X_ORIGIN;
            b->body.y = GAMESCREEN_Y_ORIGIN + (var & 0x7F) % GAMESCREEN_HEIGHT;
        } else if (dx <= -6) {
            b->body.x = GAMESCREEN_X_END;
            b->body.y = GAMESCREEN_Y_ORIGIN + (var & 0x7F) % GAMESCREEN_HEIGHT;
        } else if (dy >= 6) {
            b->body.x = GAMESCREEN_X_ORIGIN + (var & 0x7F) % GAMESCREEN_WIDTH;
            b->body.y = GAMESCREEN_Y_ORIGIN;
        } else if (dy <= -6) {
            b->body.x = GAMESCREEN_X_ORIGIN + (var & 0x7F) % GAMESCREEN_WIDTH;
            b->body.y = GAMESCREEN_Y_END;
        } else {
            b->body.x = (dx > 0) ? GAMESCREEN_X_ORIGIN : GAMESCREEN_X_END;
            b->body.y = (dy > 0) ? GAMESCREEN_Y_ORIGIN : GAMESCREEN_Y_END;
        }

        b->active = 1;
        ACTIVE_BULLETS[active_bullet_count++] = i;
        spawn_dir = (spawn_dir + 1) & 0x0F;
        return;
    }
}

// ─── Init ─────────────────────────────────────────────────────────────────────
void bullets_init(void) {
    bullet_t  *b = &BULLETS_POOL[0];
    for (uint8_t i = 0; i < MAX_BULLETS; i++, b++) {
        b->active = 0;
    }
    active_bullet_count = 0;
    spawn_dir           = 0;
    spawn_timer         = 0;
}

// ─── Update ───────────────────────────────────────────────────────────────────
void bullets_update(void) {
    spawn_timer++;
    if (spawn_timer >= BULLET_SPAWN_INTERVAL) {
        spawn_timer = 0;
        try_spawn_bullet();
    }

    // Boucle uniquement sur les bullets actifs (pas MAX_BULLETS)
    uint8_t j = 0;
    uint8_t *ab = &ACTIVE_BULLETS[0];
    
    while (j < active_bullet_count) {
        uint8_t i = *ab;//ACTIVE_BULLETS[j];

	bullet_t *b = &BULLETS_POOL[i];
        // Nettoyage d'un bullet tué par check_collision la frame précédente
        if (!b->active) {
            kill_bullet(j);
            continue; // ne pas incrémenter j : le slot contient maintenant le dernier élément
        }
	
	update_body_position(&b->body);

	// On check les bordures 1 frame sur 8
	if (frame_counter % 8 != 0) goto print_sprite;

	if (is_outside_bounds(b->body.x, GAMESCREEN_X_ORIGIN, GAMESCREEN_X_END) ||
	    is_outside_bounds(b->body.y, GAMESCREEN_Y_ORIGIN, GAMESCREEN_Y_END)) {
	    kill_bullet(j);
	    continue;
	}
    

    print_sprite:
	set_sprite_tile(oam, BULLET_TILE_OFFSET);
	// l'affichage des sprites standard n'est pas centré (-4,-8) pour les
	// SPRITE8x16
	move_sprite(oam, b->body.x-SPRITE_DRAW_OFFSET_X,
		    b->body.y-SPRITE_DRAW_OFFSET_Y);
	oam++;

	ab++;
	j++;
    }
}

// ─── API ──────────────────────────────────────────────────────────────────────

uint8_t bullets_get_active_count(void) {
    return active_bullet_count; // O(1)
}

uint8_t bullets_check_collision(uint8_t px, uint8_t py, uint8_t pw, uint8_t ph) {
    bullet_collision_bit ^= 1;
    uint8_t *ab = &ACTIVE_BULLETS[0];
    for (uint8_t j = 0; j < active_bullet_count; j++, ab++) {
	if ( j % 2 == bullet_collision_bit ) continue;
	uint8_t i = *ab;//ACTIVE_BULLETS[j];
	bullet_t *b = &BULLETS_POOL[i];
	if (manathan_distance(b->body.x, b->body.y, px,py) > MAN_DIST_THRESHOLD)
	    continue;
        if (check_collision_box(b->body.x, b->body.y,
                                BULLET_HITBOX_W, BULLET_HITBOX_H,
                                px, py, pw, ph)) {
            // Marquer inactive → nettoyé au prochain bullets_update
            b->active = 0;
            return 1;
        }
    }
    return 0;
}
