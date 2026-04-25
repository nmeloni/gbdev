#include "utils.h"
#include "game.h"
#include "player.h"
#include "powerup.h"
#include "body.h"
#include "move_pattern.h"
#include "powerup_sprite.h"

// Stub Phase 1 — implémentation complète en Phase 5

static inline void handle_powerup_bounds(void);
static inline void handle_powerup_vs_player(void);
static inline void handle_powerup_move_pattern(void);
static inline void draw_powerup(void);


PowerUp powerup;
PowerUp * POWERUP = &powerup;

void init_powerup(void)  {
    POWERUP->active = 0;
}

void spawn_powerup(uint8_t type, uint8_t x, uint8_t y) {
    init_body( &POWERUP->body, x,y);
    POWERUP->type = type;
    init_static_move_pattern_manager(&POWERUP->spm,
				     STATIC_PATTERN_TYPE_MOVE_DOWN,
				     STATIC_PATTERN_TYPE_ZIGZAG, 0);
    POWERUP->active = 1;
}

void update_powerup(void) {
    if (POWERUP->active == 0) return;
    //Si le powerup est actif
    handle_powerup_move_pattern();
    //On gère les bords de l'écran avec frame skip
    if (frame_counter % POWERUP_BOUND_FRAME_SKIP == 3) handle_powerup_bounds();
    if (frame_counter % POWERUP_VS_PLAYER_FRAME_SKIP == 0) handle_powerup_vs_player();
    draw_powerup();
}

static inline void handle_powerup_bounds(void){
    POWERUP->active =
	is_inside_bounds(POWERUP->body.x, GAMESCREEN_X_ORIGIN, GAMESCREEN_X_END) &
	is_inside_bounds(POWERUP->body.y, GAMESCREEN_Y_ORIGIN, GAMESCREEN_Y_END);
}

static inline void handle_powerup_vs_player(void){
    if (manathan_distance(POWERUP->body.x, POWERUP->body.y,
			  PLAYER->body.x, PLAYER->body.y)
	<= POWERUP_VS_PLAYER_MAN_DIST ){
	//On test la collision avec le joueur
	if (check_collision_box(PLAYER->body.x, PLAYER->body.y,
				PLAYER_BBOX_W, PLAYER_BBOX_H,
				POWERUP->body.x, POWERUP->body.y,
				POWERUP_BBOX_W, POWERUP_BBOX_H)){
	    powerup_player(POWERUP->type);
	    POWERUP->active = 0;
	}
    }
}

static inline void handle_powerup_move_pattern(void){
    update_static_move_pattern_manager(&POWERUP->spm);
    POWERUP->body.dx = POWERUP->spm.dx;
    POWERUP->body.dy = POWERUP->spm.dy ;
    update_body_position(&POWERUP->body);
}


static inline void draw_powerup(void){
    uint8_t sprite, tile_offset;
    switch (POWERUP->type){
    case POWERUP_TYPE_SHOT:
	sprite = 0;
	tile_offset = POWERUP_SHOT_TILE_OFFSET;
	break;
    case POWERUP_TYPE_SHIELD:
	sprite = 1;
	tile_offset = POWERUP_SHIELD_TILE_OFFSET;
	break;
    case POWERUP_TYPE_LIFE:
	sprite = 2;
	tile_offset = POWERUP_EXTRA_LIFE_TILE_OFFSET;
	break;
    default :
	sprite = 0;
	tile_offset = POWERUP_SHOT_TILE_OFFSET;
	break;
    }

    oam += move_metasprite_ex(powerup_sprite_metasprites[sprite],
			      tile_offset, 0, oam,
			      POWERUP->body.x, POWERUP->body.y);
    
}
