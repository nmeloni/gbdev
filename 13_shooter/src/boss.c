#include "boss.h"

void handle_boss_pattern(void);
void handle_boss_move_pattern(void);
void handle_boss_shoot_pattern(void);
void check_collision_boss_with_player(void);
void check_boss_hitshots(void);
void draw_boss(void);
void check_boss_bounds(void);
inline void special_pattern_aimed(void);

boss_t BOSS;

const int8_t explosion_coordiantes[][2] = {
    {4, 0},
    {12, -6},
    {-9, 9},
    {4, -12},
    {-10, -5},
    {8, 10},
    {-5, 12},
    {0, 0}
};

const int8_t boss_jiggle_pattern[][2] = {
    {-2, 2},
    {2, 0},
    {0, 2},
    {-2, 0},
    {0, -2},
    {2, 2},
    {-2, -2},
    {2, -2}
};


const uint8_t boss_bbox[][2] = {
    {16, 16}  // Taille du boss (largeur, hauteur)
};

const uint8_t boss_weapon_table[][5] = {
    {BULLET_TYPE_NONE, BULLET_TYPE_LARGE, BULLET_TYPE_NONE, BULLET_TYPE_LARGE,BULLET_TYPE_NONE} // Armes du mini-boss 1
};
    
const uint8_t mini_boss_1_move_patterns[][4] = {
    {BOSS_PATTERN_TIME_TRIGGER, 240u, MOVE_PATTERN_DOWN, SHOOT_PATTERN_NONE},
    {BOSS_PATTERN_HEALTH_TRIGGER, 100u, MOVE_PATTERN_LATERAL, SHOOT_PATTERN_AIMED},
    {BOSS_PATTERN_TIME_TRIGGER, 120u, MOVE_PATTERN_SPECIAL_CENTER, SHOOT_PATTERN_NONE},
    {BOSS_PATTERN_HEALTH_TRIGGER, 50u, MOVE_PATTERN_SPECIAL_AIMED, SHOOT_PATTERN_NONE},
    {BOSS_PATTERN_TIME_TRIGGER, 240u, MOVE_PATTERN_SPECIAL_CENTER, SHOOT_PATTERN_NONE},
    {BOSS_PATTERN_HEALTH_TRIGGER, 0u, MOVE_PATTERN_SPECIAL_AIMED, SHOOT_PATTERN_CIRCULAR},
    {BOSS_PATTERN_DESTROY, 240u,0,0}
    
};


void init_boss(void) {
    BOSS.active = 0;
    BOSS.move_patterns = NULL;
    BOSS.nb_move_patterns = 0;
    BOSS.current_move_pattern = 0;
}

void spawn_boss(uint8_t boss_id, uint8_t x, uint8_t y) {
    BOSS.active = 1;
    BOSS.flag = BOSS_FLAG_ENTERING;
    init_body(&BOSS.body, x, y);
    switch (boss_id) {
    case MINI_BOSS_1:
	BOSS.hp = 120;
	BOSS.move_patterns = mini_boss_1_move_patterns;
	BOSS.weapons = boss_weapon_table[0];
	BOSS.shoot_pattern_speed = 1; // Vitesse de tir moyenne
	
	BOSS.current_pattern = 0;
	BOSS.current_pattern_trigger = mini_boss_1_move_patterns[0][0];
	BOSS.pattern_framecounter = mini_boss_1_move_patterns[0][1];
	BOSS.current_move_pattern = mini_boss_1_move_patterns[0][2];
	BOSS.current_shoot_pattern = mini_boss_1_move_patterns[0][3];

	BOSS.move_activepattern = 0;
	BOSS.move_framecounter = move_patterns[BOSS.current_move_pattern][0][0];
    	BOSS.body.dx = move_patterns[BOSS.current_move_pattern][0][1];
	BOSS.body.dy = move_patterns[BOSS.current_move_pattern][0][2];

	
	BOSS.shoot_activepattern = 0;
	BOSS.shoot_framecounter = shoot_patterns[BOSS.current_shoot_pattern][0][0];
	
	BOSS.metasprites = mini_boss_1_sprite_metasprites;
	// Initialiser les patterns de mouvement et d'attaque spécifiques au boss
	break;
	// Ajouter d'autres cas pour différents boss si nécessaire

    default:
	BOSS.active = 0; // Boss inconnu, ne pas l'activer
	break;
    }

	
}

void update_boss(void) {
    if (BOSS.active) {
	// Logique de mise à jour du boss (mouvement, attaques, etc.)
	handle_boss_pattern();
	update_body_position(&BOSS.body);
	check_collision_boss_with_player();
	check_boss_hitshots();
	draw_boss();
    }
}

inline void handle_boss_pattern(void) {
    // Implémenter la logique de pattern de mouvement et d'attaque du boss
    switch (BOSS.current_pattern_trigger) {
    case BOSS_PATTERN_TIME_TRIGGER:
	if (BOSS.pattern_framecounter > 0) {
	    BOSS.pattern_framecounter--;
	} else {
	    // Passer au pattern suivant
	    BOSS.current_pattern++;
	    BOSS.current_pattern_trigger = BOSS.move_patterns[BOSS.current_pattern][0];
	    BOSS.pattern_framecounter = BOSS.move_patterns[BOSS.current_pattern][1];
	    BOSS.current_move_pattern = BOSS.move_patterns[BOSS.current_pattern][2];
	    BOSS.current_shoot_pattern = BOSS.move_patterns[BOSS.current_pattern][3];

	    BOSS.move_activepattern = 0;
	    BOSS.move_framecounter = move_patterns[BOSS.current_move_pattern][0][0];
	    BOSS.body.dx = move_patterns[BOSS.current_move_pattern][0][1];
	    BOSS.body.dy = move_patterns[BOSS.current_move_pattern][0][2];

	
	    BOSS.shoot_activepattern = 0;
	    BOSS.shoot_framecounter = shoot_patterns[BOSS.current_shoot_pattern][0][0];
	}	    
	break;
    case BOSS_PATTERN_HEALTH_TRIGGER:
	if (BOSS.hp <= BOSS.move_patterns[BOSS.current_pattern][1]) {
	    // Passer au pattern suivant
	    BOSS.current_pattern++;
	    BOSS.current_pattern_trigger = BOSS.move_patterns[BOSS.current_pattern][0];
	    BOSS.pattern_framecounter = BOSS.move_patterns[BOSS.current_pattern][1];
	    BOSS.current_move_pattern = BOSS.move_patterns[BOSS.current_pattern][2];
	    BOSS.current_shoot_pattern = BOSS.move_patterns[BOSS.current_pattern][3];

	    BOSS.move_activepattern = 0;
	    BOSS.move_framecounter = move_patterns[BOSS.current_move_pattern][0][0];
	    BOSS.body.dx = move_patterns[BOSS.current_move_pattern][0][1];
	    BOSS.body.dy = move_patterns[BOSS.current_move_pattern][0][2];

	
	    BOSS.shoot_activepattern = 0;
	    BOSS.shoot_framecounter = shoot_patterns[BOSS.current_shoot_pattern][0][0];
	}
	break;
	// Ajouter d'autres types de triggers si nécessaire
    
    case BOSS_PATTERN_DESTROY:
	BOSS.body.dx = 0;
	BOSS.body.dy = 0;
	if (BOSS.pattern_framecounter > 0) {
	    if (BOSS.pattern_framecounter % 8 == 0) {
		uint8_t explosion_num = (BOSS.pattern_framecounter >> 3) & 0x07;
		add_explosion(BOSS.body.x + explosion_coordiantes[explosion_num][0],
			      BOSS.body.y + explosion_coordiantes[explosion_num][1]);
	    }
	    BOSS.pattern_framecounter--;
	} else {
	    BOSS.active = 0; // Boss détruit
	}
	break;
    default:
	break;
    }
	    
    // Gestion du pattern de mouvement
    handle_boss_move_pattern();
    // Gestion du pattern de tir
    handle_boss_shoot_pattern();    
	
}

inline void  handle_boss_move_pattern(void){
    //gestion du pattern de mouvement
    uint8_t step;
    uint8_t current_move_pattern = BOSS.current_move_pattern;
    uint8_t pattern_length = move_pattern_lengths[current_move_pattern];

    switch (current_move_pattern) {
    case MOVE_PATTERN_SPECIAL_CENTER:
	// Mouvement spécial : se centrer à l'écran
	uint8_t target_x = BOSS_GAMESCREEN_X_START;
	uint8_t target_y = BOSS_GAMESCREEN_Y_START;
	if (BOSS.body.x < target_x) {
	    BOSS.body.dx = 8;
	} else if (BOSS.body.x > target_x) {
	    BOSS.body.dx = -8;
	} else {
	    BOSS.body.dx = 0;
	}
	if (BOSS.body.y < target_y) {
	    BOSS.body.dy = 8;
	} else if (BOSS.body.y > target_y) {
	    BOSS.body.dy = -8;
	} else {
	    BOSS.body.dy = 0;
	}
	break;
    case MOVE_PATTERN_SPECIAL_AIMED:
	// Mouvement spécial : se déplacer vers le joueur
	special_pattern_aimed();
	check_boss_bounds();
	break;
    default:
	break;
    }
    if (BOSS.move_framecounter == 0){
	//On passe au step suivant
	BOSS.move_activepattern++;
	if (BOSS.move_activepattern >= pattern_length){
	    BOSS.move_activepattern = 0;
	    BOSS.move_framecounter = move_patterns[current_move_pattern][0][0];
	}
	//On applique le step
	step = BOSS.move_activepattern;
	BOSS.move_framecounter = move_patterns[current_move_pattern][step][0];
	BOSS.body.dx = move_patterns[current_move_pattern][step][1];
	BOSS.body.dy = move_patterns[current_move_pattern][step][2];
    } else {
	BOSS.move_framecounter--;
    }
}

inline void handle_boss_shoot_pattern(void){
    // Implémenter la logique de tir du boss selon son pattern de tir
    uint8_t current_shoot_pattern = BOSS.current_shoot_pattern;
    if (current_shoot_pattern == SHOOT_PATTERN_NONE){
	return;
    }
    uint8_t shoot_pattern_length = shoot_pattern_lengths[current_shoot_pattern];
    uint8_t shoot_pattern_speed = BOSS.shoot_pattern_speed;
    if (BOSS.shoot_framecounter == 0){
	uint8_t step = BOSS.shoot_activepattern;
	//Type de tir
	uint8_t flag = shoot_patterns[current_shoot_pattern][step][1];
	int8_t bullet_dx,bullet_dy;
	if (flag & AIMED_SHOT){
	    uint8_t direction = aimed_direction(BOSS.body.x, BOSS.body.y, PLAYER
						.body.x, PLAYER.body.y);
	    bullet_dx = directions_dx[direction]<<(shoot_pattern_speed);
	    bullet_dy = directions_dy[direction]<<(shoot_pattern_speed);
	} else {
	    bullet_dx = shoot_patterns[current_shoot_pattern][step][2]<<(shoot_pattern_speed);
	    bullet_dy = shoot_patterns[current_shoot_pattern][step][3]<<(shoot_pattern_speed);
	}
	//On ajoute la bullet
	fire_bullet(BOSS.weapons[BOSS.current_pattern], BOSS.body.x, BOSS.body.y, bullet_dx, bullet_dy);
	//On passe au step suivant
	BOSS.shoot_activepattern++;
	if (BOSS.shoot_activepattern >= shoot_pattern_length){
	    BOSS.shoot_activepattern = 0;
	}
	//On applique le step
	step = BOSS.shoot_activepattern;
	BOSS.shoot_framecounter = shoot_patterns[current_shoot_pattern][step][0];
    }
    BOSS.shoot_framecounter--;
}


inline void check_collision_boss_with_player(void) {
    // Implémenter la logique de collision entre le boss et le joueur
    if (check_collision_box(BOSS.body.x, BOSS.body.y,
			    boss_bbox[0][0], boss_bbox[0][1],
			    PLAYER.body.x, PLAYER.body.y, 0, 0) ) {
	// Collision détectée avec le joueur
	if (PLAYER.shield) {
	    PLAYER.shield = 0;
	    PLAYER.invincibility_timer = PLAYER_INVINCIBILITY_FRAMES;
	}
	if (PLAYER.invincibility_timer == 0) {
	    kill_player();
	}
    }    
}

inline void check_boss_hitshots(void) {
    // Implémenter la logique de détection des tirs du joueur touchant le boss
    for (uint8_t j=0; j<active_shot_index; j++){
	uint8_t k = ACTIVE_SHOTS[j];

	
	if (check_collision_box(BOSS.body.x, BOSS.body.y,
				boss_bbox[0][0],
				boss_bbox[0][1],
				SHOTS_POOL[k].body.x, SHOTS_POOL[k].body.y,
				shot_bbox[PLAYER.shoot_power][0], shot_bbox[PLAYER.shoot_power][1]) ){
	    // Collision détectée avec un tir du joueur
	    BOSS.hp-= shot_power_table[PLAYER.shoot_power];
	    BOSS.ishit = HIT_FLASH_DURATION;
	    EMU_printf("Boss hit! HP=%d\n", BOSS.hp);
	    // Supprimer le tir du joueur
	    kill_active_shot(j);
	}
	    
    }
}

inline void draw_boss(void) {
    uint8_t oam_prop = 0;
    if (BOSS.ishit) {
	BOSS.ishit--;
	oam_prop = OAMF_PAL1;
    }
    oam+= move_metasprite_ex(BOSS.metasprites[0],
			     BOSS_TILE_OFFSET, oam_prop, oam,
			     BOSS.body.x,
			     BOSS.body.y);
    
}

inline void check_boss_bounds(void) {
    // Limitation aux bords de l'écran de jeu
    
    BOSS.body.x = clamp(BOSS.body.x, BOSS_MIN_X, BOSS_MAX_X);
    BOSS.body.y = clamp(BOSS.body.y, BOSS_MIN_Y, BOSS_MAX_Y);
    
}

inline void special_pattern_aimed(void) {
    static uint8_t initialized = 0;
    switch (BOSS.move_activepattern) {
    case SPECIAL_PATTERN_AIMED_JIGGLE:
	
	if (BOSS.move_framecounter % 4 == 0) {
	    uint8_t step = (BOSS.move_framecounter >> 2) & 0x07;
	    BOSS.body.dx = boss_jiggle_pattern[step][0];
	    BOSS.body.dy = boss_jiggle_pattern[step][1];
	}
	break;
    
    case SPECIAL_PATTERN_AIMED_MOVE:
	if (!initialized) {
	    uint8_t direction = aimed_direction(BOSS.body.x, BOSS.body.y, PLAYER
						 .body.x, PLAYER.body.y);
	    BOSS.body.dx = directions_dx[direction] << 2;
	    BOSS.body.dy = directions_dy[direction] << 2;
	    initialized = 1;
	} else {
	    return;
	}
	break;
    case SPECIAL_PATTERN_AIMED_WAIT:
    case SPECIAL_PATTERN_AIMED_STOP:
	BOSS.body.dx = 0;
	BOSS.body.dy = 0;
	initialized = 0;
	break;
    default:
	break;
    }
}
	

	
