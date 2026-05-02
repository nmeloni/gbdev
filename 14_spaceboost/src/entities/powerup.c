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
				     STATIC_PATTERN_TYPE_NONE,
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
    // On ne teste que la sortie d'écran par le haut ou le bas
    POWERUP->active = is_inside_bounds(POWERUP->body.y,
				       GAMESCREEN_Y_ORIGIN, GAMESCREEN_Y_END);
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
    oam += move_metasprite_ex(powerup_sprite_metasprites[POWERUP->type],
			      POWERUP_TILE_OFFSET, 0, oam,
			      POWERUP->body.x, POWERUP->body.y);
    
}
