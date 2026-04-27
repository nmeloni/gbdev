#include <stdint.h>

#include "explosion.h"
#include "move_pattern.h"
#include "bullet_pattern.h"
#include "game.h"
#include "body.h"
#include "powerup.h"
#include "utils.h"
#include "enemy.h"
#include "shot.h"
#include "player.h"

#include "enemy_drone_sprite.h"
// Stub Phase 1 — implémentation complète en Phase 3

Enemy ENEMY_POOL[MAX_ENEMIES];
uint8_t ACTIVE_ENEMY_POOL[MAX_ENEMIES];
uint8_t active_enemy_count = 0;

typedef struct  {
    StaticPatternType intro_pattern_type;
    StaticPatternType loop_pattern_type;
    uint8_t initial_pattern;
} static_manager_data;

const static_manager_data enemy_pattern_data[] = {
    [ENEMY_DATA_DRONE_1] = {STATIC_PATTERN_TYPE_NONE, STATIC_PATTERN_TYPE_MOVE_DOWN, 0}
};

const uint8_t enemy_bbox[][2] = {
    [ENEMY_DRONE] = {8,8}
};

const const metasprite_t* const * enemy_metasprites[] = {
    enemy_drone_sprite_metasprites
};

static uint8_t shot_bbox_w, shot_bbox_h;
static uint8_t enemy_bbox_w, enemy_bbow_h;

static inline void desactivate_enemy(Enemy *e);
static inline void remove_enemy(uint8_t * ae);
static inline void enemy_get_hit(Enemy *e, uint8_t damage);
static inline void destroy_enemy(Enemy *e);

static inline void handle_enemy_hp(Enemy *e);
static inline void handle_enemy_bounds(Enemy *e);
static inline void handle_enemy_vs_shot_collision(Enemy *e);
static inline void handle_enemy_vs_player(Enemy *e);
static inline void handle_enemy_move_pattern(Enemy *e);
static inline void handle_enemy_shot_pattern(Enemy *e);
static inline void draw_enemy(Enemy *e);

void init_enemies(void) {
    Enemy *e = &ENEMY_POOL[0];
    for (uint8_t i = 0; i < MAX_ENEMIES; i++,e++){
	init_body( &(e->body), 0, 0);
	e->type = ENEMY_NONE;
	e->data_type = ENEMY_DATA_NONE;
	e->hp = 0;
	e->ishit = 0;
	e->frame_timer = 0;
	e->active = 0;
	e->powerup = POWERUP_TYPE_NONE;
	e->tile_offset = ENEMY_TILE_OFFSET;
    }
}

void add_enemy(uint8_t x, uint8_t y, EnemyType type, EnemyDataType data_type, uint8_t hp, uint8_t speed, PowerUpType powerup){
    if (active_enemy_count >= MAX_ENEMIES) return;

    // Cherche un slot libre dans le pool d'ennemis
    Enemy *e = &ENEMY_POOL[0];
    for (uint8_t i = 0; i < MAX_ENEMIES; i++,e++){
	if (e->active) continue;

	//On a trouvé un slot de libre
	init_body( &(e->body), x, y);
	e->type = type;
	e->data_type = data_type;
	e->hp = hp;
	e->ishit = 0;
	e->frame_timer = 0;
	e->speed = speed;
	e->powerup = powerup;
	e->active = 1;
	init_static_move_pattern_manager(&e->smp,
					 enemy_pattern_data[data_type].intro_pattern_type,
					 enemy_pattern_data[data_type].loop_pattern_type,
					 enemy_pattern_data[data_type].initial_pattern);
	init_bullet_pattern_manager(&e->bpm, bullet_pattern_data[data_type]);
	
	ACTIVE_ENEMY_POOL[active_enemy_count++] = i;
	return;
    }
}

void update_enemies(void) {
    //On boucle uniquement sur les ennemies actifs
    uint8_t j = 0;
    uint8_t *ae = &ACTIVE_ENEMY_POOL[0];
    shot_bbox_w = shot_bbox[PLAYER->shot_power][0];
    shot_bbox_h = shot_bbox[PLAYER->shot_power][1];
    while (j < active_enemy_count) {
	uint8_t i = *ae;

	Enemy *e = &ENEMY_POOL[i];
	const uint8_t * ebbox =  enemy_bbox[e->type];
	enemy_bbox_w = ebbox[0];
	enemy_bbow_h = ebbox[1];

	if (!e->active) {
	    //si l'ennemi n'est plus actif on le supprime du pool actif
	    //et on passe à l'ennemie suivant
	    remove_enemy(ae);
	    continue;
	}

	// Gestion des hp / collision avec frame skip
	if (frame_counter % ENEMY_BOUND_HP_FRAME_SKIP == 1) {
	    //On vérifie s'il reste de hp à l'ennemie
	    handle_enemy_hp(e);
	
	    //On gère la sortie de de l'écran
	    handle_enemy_bounds(e);
	}
	
	//On gère la collision avec les tirs du joueur avec frame skip
	if (frame_counter % ENEMY_VS_SHOT_FRAME_SKIP == 2) {
	    handle_enemy_vs_shot_collision(e);
	}
	
	//On gère les collisions avec le joueur avec frame skip
	if (frame_counter % ENEMY_VS_PLAYER_FRAME_SKIP == 0) {
	    handle_enemy_vs_player(e);
	}
	
	//On gère le pattern de mouvement
	handle_enemy_move_pattern(e);

	//On gère le pattern de tir
	handle_enemy_shot_pattern(e);

	//On affiche
	draw_enemy(e);

	ae++;
	j++;
    }
}


static inline void desactivate_enemy(Enemy *e){
    e->active = 0;
}
static inline void remove_enemy(uint8_t * ae){
    *ae = ACTIVE_ENEMY_POOL[--active_enemy_count];
}

static inline void enemy_get_hit(Enemy *e, uint8_t damage){
    e->hp -= damage;
    e->ishit = ENEMY_IS_HIT_DURATION;
}

static inline void handle_enemy_hp(Enemy *e){
    if (e->hp <= 0) destroy_enemy(e);
}

static inline void destroy_enemy(Enemy *e){
    desactivate_enemy(e);
    add_explosion(e->body.x, e->body.y);
    if (e->powerup != POWERUP_TYPE_NONE){
	spawn_powerup(e->powerup, e->body.x, e->body.y);
    }
}

static inline void handle_enemy_bounds(Enemy *e){
    if ( is_outside_bounds(e->body.x, ENEMY_MIN_X, ENEMY_MAX_X) ||
	 is_outside_bounds(e->body.y, ENEMY_MIN_Y, ENEMY_MAX_Y)){
	desactivate_enemy(e);
    }
}

static inline void handle_enemy_vs_shot_collision(Enemy *e){
    uint8_t *ac = &ACTIVE_SHOTS[0];
    
    
    for (uint8_t j = 0; j < active_shot_index; j++,ac++) {
        uint8_t i = *ac;
	Shot *s = &SHOTS_POOL[i];

	// On test d'abord la distance manathan pour eliminer les
	// entité trop distantes

	if (manathan_distance(e->body.x, e->body.y, s->body.x, s->body.y) >=
	    ENEMY_VS_SHOT_MAN_DIST)
	    continue;

	if (check_collision_box(s->body.x, s->body.y, shot_bbox_w, shot_bbox_h,
				e->body.x, e->body.y, enemy_bbox_w, enemy_bbow_h)){
	    enemy_get_hit(e, shot_power_table[PLAYER->shot_power]);
	    desactivate_shot(s);
	    kill_active_shot(j);
	    return;
	}
    }
}

static inline void handle_enemy_vs_player(Enemy *e) {
    if (PLAYER->invincibility_timer) return;
    if (manathan_distance(PLAYER->body.x, PLAYER->body.y,
			  e->body.x, e->body.y) <= ENEMY_VS_PLAYER_MAN_DIST){
	//si la distance de manathan est faible on teste la collision
	if (check_collision_box(PLAYER->body.x,  PLAYER->body.y,
				PLAYER_BBOX_W, PLAYER_BBOX_H,
				e->body.x, e->body.y,
				enemy_bbox_w, enemy_bbow_h)){
	    hit_player();
	}
    }
}


static inline void handle_enemy_move_pattern(Enemy *e){
    update_static_move_pattern_manager(&e->smp);
    e->body.dx = e->smp.dx << e->speed;
    e->body.dy = e->smp.dy << e->speed;
    update_body_position(&e->body);
}

static inline void handle_enemy_shot_pattern(Enemy *e){
    update_bullet_pattern_manager(&e->bpm, e->body.x, e->body.y);
}

static inline void draw_enemy(Enemy *e){
    uint8_t oam_prop = OAMF_PAL0;
    
    uint8_t frame = (e->frame_timer & ENEMY_ANIM_DURATION) >> ENEMY_ANIM_DURATION_LOG2;

    e->frame_timer++;
    if (e->ishit){
	e->ishit--;
	oam_prop = OAMF_PAL1;
    }
    // Mise à jour du sprite de l'ennemi
    oam+= move_metasprite_ex(enemy_metasprites[e->type][frame],
			     e->tile_offset, oam_prop ,oam,
			     e->body.x,
			     e->body.y);
    
}

