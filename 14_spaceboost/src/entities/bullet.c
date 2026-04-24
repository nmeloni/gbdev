#include <stdint.h>

#include "game.h"
#include "utils.h"
#include "body.h"
#include "bullet.h"
#include "player.h"

Bullet   BULLETS_POOL[MAX_BULLETS];
uint8_t  ACTIVE_BULLETS[MAX_BULLETS];
uint8_t  active_bullet_count = 0;

const uint8_t bullet_bbox[3][2] = {
    [BULLET_TYPE_SMALL] = {2,2},
    [BULLET_TYPE_LARGE] = {5,5},
    [BULLET_TYPE_LASER] = {4,10}
};
//modifier a chaque frame pour ne tester les collisions des bullets
//d'indice pair ou impair
static uint8_t bullet_collision_bit;

//QUelques variable globale pour economiser des caluls
static const uint8_t * bbbox;
static uint8_t bullet_bbox_w, bullet_bbox_h;

static inline void kill_bullet(Bullet *b, uint8_t j);
static inline void desactivate_bullet(Bullet *b);
static inline void handle_bullet_bound(Bullet *b);
static inline void handle_bullet_vs_player(Bullet *b);
static inline void draw_bullet(Bullet *b);

void init_bullets(void)  {
    bullet_collision_bit = 0;
    Bullet  *b = &BULLETS_POOL[0];
    for (uint8_t i = 0; i < MAX_BULLETS; i++, b++) {
        b->active = 0;
    }
}

void fire_bullet(uint8_t type, uint8_t x, uint8_t y, int8_t dx, int8_t dy) {
    if (active_bullet_count >= MAX_BULLETS) return;
    Bullet  *b = &BULLETS_POOL[0];
    for (uint8_t i = 0; i < MAX_BULLETS; i++,b++) {
        if (b->active) continue;

	b->type = type;
	b->body.x = x;
        b->body.y = y;
	b->body.dx = dx;
        b->body.dy = dy;
        b->body.fx = 0;
        b->body.fy = 0;
	b->active = 1;

	ACTIVE_BULLETS[active_bullet_count++] = i;
	return;
    }
}

void update_bullets(void) {
    // Boucle uniquement sur les bullets actifs (pas MAX_BULLETS)
    uint8_t j = 0;
    uint8_t *ab = &ACTIVE_BULLETS[0];
    bullet_collision_bit ^= 1;
    
    while (j < active_bullet_count) {
        uint8_t i = *ab; //ACTIVE_BULLETS[j];

	Bullet *b = &BULLETS_POOL[i];
	
	bbbox = bullet_bbox[b->type];
	bullet_bbox_w = bbbox[0];
	bullet_bbox_h = bbbox[1];
        // Nettoyage d'un bullet tué par check_collision la frame précédente
        if (!b->active) {
            kill_bullet(b,j);
            continue; // ne pas incrémenter j : le slot contient maintenant le dernier élément
        }
	update_body_position(&b->body);

	//On gère la sortie de l'écran avec frame skip
	if (frame_counter % BULLET_BOUND_FRAME_SKIP == 0){
	    handle_bullet_bound(b);
	}

	//On gère la collision avec le joueur index skip et teste
	//d'invicibilité du joueur
	if ( (bullet_collision_bit) && (PLAYER->invincibility_timer == 0) ){
	    handle_bullet_vs_player(b);
	}

	//On affiche une frame sur 2
	if (bullet_collision_bit) draw_bullet(b);

	j++;
	ab++;
    }
}

static inline void kill_bullet(Bullet *b, uint8_t j){
    b->active = 0;
    ACTIVE_BULLETS[j] = ACTIVE_BULLETS[--active_bullet_count];
}

static inline void desactivate_bullet(Bullet *b){
    b->active = 0;
}

static inline void handle_bullet_bound(Bullet *b){
    if (is_outside_bounds(b->body.x, BULLET_MIN_X, BULLET_MAX_X) ||
	is_outside_bounds(b->body.y, BULLET_MIN_Y, BULLET_MAX_Y)){
	desactivate_bullet(b);
    }
}

static inline void handle_bullet_vs_player(Bullet *b){
    if (manathan_distance(b->body.x, b->body.y, PLAYER->body.x, PLAYER->body.y)
	<= BULLET_VS_PLAYER_MAN_DIST ){
	//On test la collision avec le joueur
	if (check_collision_box(PLAYER->body.x, PLAYER->body.y,
				PLAYER_BBOX_W, PLAYER_BBOX_H,
				b->body.x, b->body.y,
				bullet_bbox_w, bullet_bbox_h)){
	    hit_player();
	}
    }
}

static inline void draw_bullet(Bullet *b){
    switch (b->type) {
    case BULLET_TYPE_SMALL:
	set_sprite_tile(oam, BULLET_SMALL_TILE_OFFSET);
	break;
    case BULLET_TYPE_LARGE:
	set_sprite_tile(oam, BULLET_LARGE_TILE_OFFSET);
	break;
    case BULLET_TYPE_LASER:
	set_sprite_tile(oam, BULLET_LASER_TILE_OFFSET);
	break;
    default:
	set_sprite_tile(oam, BULLET_SMALL_TILE_OFFSET);
	break;
    }
    move_sprite(oam,
		b->body.x + BULLET_SPRITE_X_OFFSET,
		b->body.y + BULLET_SPRITE_Y_OFFSET);
    oam++;
}
 

