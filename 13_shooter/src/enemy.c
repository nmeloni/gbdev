#include "enemy.h"

enemy_t ENEMY_POOL[MAX_ENEMIES];
uint8_t ACTIVE_ENEMY_POOL[MAX_ENEMIES];
uint8_t active_enemy_index = 0;

inline void  handle_move_pattern(uint8_t i);
inline void  handle_shoot_pattern(uint8_t i);
inline void  check_enemy_bounds(uint8_t i);
inline void  check_collision_with_player(uint8_t i);
inline void  draw_enemy(uint8_t i);
inline void  kill_active_enemy(uint8_t j);
inline void  check_enemy_hitshots(uint8_t i);

const uint8_t enemy_bbox[][2] = {
    {7 , 7},   // ENEMY_TYPE_1
    {7 , 7},   // ENEMY_TYPE_2
    {7 , 7}    // ENEMY_TYPE_3
};

const uint8_t enemy_tile_offsets[] = {
    ENEMY_1_TILE_OFFSET,
    ENENY_2_TILE_OFFSET,
    ENEMY_3_TILE_OFFSET
};

const const metasprite_t* const * enemy_metasprites[] = {
    enemy_1_sprite_metasprites,
    enemy_2_sprite_metasprites,
    enemy_3_sprite_metasprites
};

void init_enemies(void) {
    for (uint8_t i = 0; i < MAX_ENEMIES; i++) {
	ENEMY_POOL[i].active = 0;
    }
    active_enemy_index = 0;
}

void add_enemy(uint8_t x, uint8_t y, uint8_t type, uint8_t weapon, uint8_t hp, uint8_t move_pattern, uint8_t shoot_pattern){
    for (uint8_t i=0; i<MAX_ENEMIES; i++){
	if (!ENEMY_POOL[i].active){
	    ENEMY_POOL[i].active = 1;
	    ENEMY_POOL[i].body.x = x;
	    ENEMY_POOL[i].body.y = y;
	    ENEMY_POOL[i].body.dx = 0;
	    ENEMY_POOL[i].body.dy = 0;
	    ENEMY_POOL[i].body.fx = 0;
	    ENEMY_POOL[i].body.fy = 0; 
	    ENEMY_POOL[i].type = type;
	    ENEMY_POOL[i].weapon = weapon;
	    ENEMY_POOL[i].move_pattern = move_pattern;
	    ENEMY_POOL[i].shoot_pattern = shoot_pattern;
	    ENEMY_POOL[i].move_activepattern = 0;
	    ENEMY_POOL[i].shoot_activepattern = 0;
	    ENEMY_POOL[i].move_framecounter = move_patterns[move_pattern][0][0];
	    ENEMY_POOL[i].shoot_framecounter = shoot_patterns[shoot_pattern][0][0];
	    ENEMY_POOL[i].frame_timer = 0;
	    ENEMY_POOL[i].hp = hp;
	    ENEMY_POOL[i].ishit = 0;
	    ACTIVE_ENEMY_POOL[active_enemy_index++] = i;
	    break;
	}
    }
}

void update_enemies(void) {
    for (uint8_t j=0; j<active_enemy_index; j++){

	uint8_t i = ACTIVE_ENEMY_POOL[j];
	//gestion du pattern de mouvement
	handle_move_pattern(i);

	//gestion du pattern de tir
	handle_shoot_pattern(i);	    
	
	//Mouvement de l'ennemi
	update_body_position(&ENEMY_POOL[i].body);

	// Verification des collisions et des limites toutes les deux frames
	// pour alléger le CPU
	if ( (frame_counter - j) % 4 == 0){ 
	    //Vérification des limites de l'écran
	    check_enemy_bounds(i);
	
	    //collision avec les tirs du joueur
	    check_enemy_hitshots(i);
	
	    //collision avec le joueur
	    check_collision_with_player(i);
	}
	//Gestion de l'état d'ennemi touché
	if (ENEMY_POOL[i].active == 0){
	    kill_active_enemy(j);
	    continue; //Passer à l'ennemi suivant
	}

	//Dessin de l'ennemi
	draw_enemy(i);
    }
}

inline void  handle_move_pattern(uint8_t i){
    //gestion du pattern de mouvement
    uint8_t step;
    uint8_t current_move_pattern = ENEMY_POOL[i].move_pattern;
    uint8_t pattern_length = move_pattern_lengths[current_move_pattern];
    if (ENEMY_POOL[i].move_framecounter == 0){
	//On passe au step suivant
	ENEMY_POOL[i].move_activepattern++;
	if (ENEMY_POOL[i].move_activepattern >= pattern_length){
	    ENEMY_POOL[i].move_activepattern = 0;
	}
	//On applique le step
	step = ENEMY_POOL[i].move_activepattern;
	ENEMY_POOL[i].move_framecounter = move_patterns[current_move_pattern][step][0];
	ENEMY_POOL[i].body.dx = move_patterns[current_move_pattern][step][1];
	ENEMY_POOL[i].body.dy = move_patterns[current_move_pattern][step][2];
    }
    ENEMY_POOL[i].move_framecounter--;
}

inline void  handle_shoot_pattern(uint8_t i){
    uint8_t current_shoot_pattern = ENEMY_POOL[i].shoot_pattern;
    uint8_t shoot_pattern_length = shoot_pattern_lengths[current_shoot_pattern];
    if (ENEMY_POOL[i].shoot_framecounter == 0){
	uint8_t step = ENEMY_POOL[i].shoot_activepattern;
	    
	//Type de tir
	uint8_t flag = shoot_patterns[current_shoot_pattern][step][1];
	if (flag){
	    //Paramètres du tir
	    int8_t bullet_dx,bullet_dy;
	    if (flag & AIMED_SHOT){
		EMU_printf("Aimed shot\n");
		uint8_t direction = aimed_direction(ENEMY_POOL[i].body.x, ENEMY_POOL[i].body.y, PLAYER.body.x, PLAYER.body.y);
		bullet_dx = directions_dx[direction]<<(flag & SHOT_SPEED_MASK);
		bullet_dy = directions_dy[direction]<<(flag & SHOT_SPEED_MASK);
	    } else {
		bullet_dx = shoot_patterns[current_shoot_pattern][step][2];
		bullet_dy = shoot_patterns[current_shoot_pattern][step][3];
	    }
	    //On ajoute la bullet
	    fire_bullet(ENEMY_POOL[i].weapon, ENEMY_POOL[i].body.x, ENEMY_POOL[i].body.y, bullet_dx, bullet_dy);
	    
	}
	//On passe au step suivant
	ENEMY_POOL[i].shoot_activepattern++;
	if (ENEMY_POOL[i].shoot_activepattern >= shoot_pattern_length){
	    ENEMY_POOL[i].shoot_activepattern = 0;
	}
	//On applique le step
	step = ENEMY_POOL[i].shoot_activepattern;
	ENEMY_POOL[i].shoot_framecounter = shoot_patterns[current_shoot_pattern][step][0];
	    
    }
    ENEMY_POOL[i].shoot_framecounter--;
}

inline void  check_enemy_hitshots(uint8_t i){
    //Vérification des collisions avec les tirs du joueur
    uint8_t type = ENEMY_POOL[i].type;
    for (uint8_t j=0; j<active_shot_index; j++){
	uint8_t k = ACTIVE_SHOTS[j];

	
	if (check_collision_box(ENEMY_POOL[i].body.x, ENEMY_POOL[i].body.y,
				enemy_bbox[type][0],
				enemy_bbox[type][1],
				SHOTS_POOL[k].body.x, SHOTS_POOL[k].body.y,
				shot_bbox[PLAYER.shoot_power][0], shot_bbox[PLAYER.shoot_power][1]) ){
	    // Collision détectée avec un tir du joueur
	    ENEMY_POOL[i].hp-= shot_power_table[PLAYER.shoot_power];
	    ENEMY_POOL[i].ishit = HIT_FLASH_DURATION;
	    if (ENEMY_POOL[i].hp <= 0){
		add_explosion(ENEMY_POOL[i].body.x, ENEMY_POOL[i].body.y);
		ENEMY_POOL[i].active = 0;
	    }
	    // Supprimer le tir du joueur
	    kill_active_shot(j);
	}
    }
}

inline void  check_collision_with_player(uint8_t i){
    uint8_t type = ENEMY_POOL[i].type;
    if (check_collision_box(ENEMY_POOL[i].body.x, ENEMY_POOL[i].body.y
			    ,enemy_bbox[type][0], enemy_bbox[type][1],
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


inline void  check_enemy_bounds(uint8_t i){
    // Désactiver l'ennemi s'il sort de l'écran
    ENEMY_POOL[i].active = is_inside_bounds(ENEMY_POOL[i].body.x,
					 GAMESCREEN_X_ORIGIN,
					 GAMESCREEN_X_END) &
			    is_inside_bounds(ENEMY_POOL[i].body.y,
					     GAMESCREEN_Y_ORIGIN,
					     GAMESCREEN_Y_END);
    
}

inline void  draw_enemy(uint8_t i){
    uint8_t type = ENEMY_POOL[i].type;
    uint8_t oam_prop = OAMF_PAL0;
    uint8_t frame = (ENEMY_POOL[i].frame_timer & SPRITE_FRAME_DURATION) >> SPRITE_FRAME_DURATION_LOG2; 
    ENEMY_POOL[i].frame_timer++;
    if (ENEMY_POOL[i].ishit){
	ENEMY_POOL[i].ishit--;
	oam_prop = OAMF_PAL1;
    }
    // Mise à jour du sprite de l'ennemi
    oam+= move_metasprite_ex(enemy_metasprites[type][frame],
			     enemy_tile_offsets[type],oam_prop ,oam,
			     ENEMY_POOL[i].body.x,
			     ENEMY_POOL[i].body.y);
}

inline void  kill_active_enemy(uint8_t j){
    ENEMY_POOL[ACTIVE_ENEMY_POOL[j]].active = 0;
    // Supprimer l'ennemi inactif de la liste des ennemis actifs
    ACTIVE_ENEMY_POOL[j] = ACTIVE_ENEMY_POOL[--active_enemy_index];
}
