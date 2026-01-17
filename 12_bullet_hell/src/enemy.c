#include "enemy.h"


const uint8_t move_pattern_lengths[4] = {
    1, 16, 16,8 
};

// Pattern 0: Move down slowly
const int8_t move_pattern_1[1][3] = {
    {10, 0, 4}    
};
// Pattern 1: Descend en zigzag
const int8_t move_pattern_2[16][3] = {
    {5, 16, 4},
    {10, 12, 4},
    {10, 8, 4},
    {10, 4, 4},
    {5, 0, 4},
    {10, -4, 4},
    {10, -8, 4},
    {10, -12, 4},
    {5, -16, 4},
    {10, -12, 4},
    {10, -8, 4},
    {10, -4, 4},
    {5, 0, 4},
    {10, 4, 4},
    {10, 8, 4},
    {10, 12, 4}    
};

// Pattern 2: Deplacement latteral
const int8_t move_pattern_3[16][3] = {
    {5, 16, 0},
    {10, 12, 0},
    {10, 8, 0},
    {10, 4, 0},
    {5, 0, 0},
    {10, -4, 0},
    {10, -8, 0},
    {10, -12, 0},
    {5, -16, 0},
    {10, -12, 0},
    {10, -8, 0},
    {10, -4, 0},
    {5, 0, 0},
    {10, 4, 0},
    {10, 8, 0},
    {10, 12, 0}
};

// Pattern 3: centre de l'écran
const int8_t move_pattern_4[8][3] = {
    {5, 0, 8},
    {15, 0, 12},
    {20, 0, 16},
    {15, 0, 12},
    {15, 0, 8},
    {10, 0, 4},
    {127, 0, 0},
    {127, 0, 0}
};


const int8_t (* move_patterns[])[3] = {
    move_pattern_1,
    move_pattern_2,
    move_pattern_3,
    move_pattern_4
};

const uint8_t shoot_pattern_lengths[4] = {
    1,1,16,16 // Number of steps in shoot pattern 0
};

// Shoot patterns {frame_delay, shoot_type, dx, dy}

// Pattern 0: Aimed shot every 60 frames
const int8_t shoot_pattern_1[1][4] = {
    {60, BULLET_TYPE_AIMED, 0, 0},
};

// Pattern 1: Straight shot down every 60 frames
const int8_t shoot_pattern_2[1][4] = {
    {60, BULLET_TYPE_NORMAL, 0, 16},
};

//Pattern 2: tir en horloge slow
const int8_t shoot_pattern_3[16][4] = {
    {20, BULLET_TYPE_NORMAL, 16,0},
    {20, BULLET_TYPE_NORMAL, 15,6},
    {20, BULLET_TYPE_NORMAL, 11,11},
    {20, BULLET_TYPE_NORMAL, 6,15},
    {20, BULLET_TYPE_NORMAL, 0,16},
    {20, BULLET_TYPE_NORMAL, -6,15},
    {20, BULLET_TYPE_NORMAL, -11,11},
    {20, BULLET_TYPE_NORMAL, -15,6},
    {20, BULLET_TYPE_NORMAL, -16,0},
    {20, BULLET_TYPE_NORMAL, -15,-6},
    {20, BULLET_TYPE_NORMAL, -11,-11},
    {20, BULLET_TYPE_NORMAL, -6,-15},
    {20, BULLET_TYPE_NORMAL, 0,-16},
    {20, BULLET_TYPE_NORMAL, 6,-15},
    {20, BULLET_TYPE_NORMAL, 11,-11},
    {20, BULLET_TYPE_NORMAL, 15,-6}
};

//Pattern 3: tir en horloge fast
const int8_t shoot_pattern_4[16][4] = {
    {20, BULLET_TYPE_NORMAL, 32,0},
    {20, BULLET_TYPE_NORMAL, 30,12},
    {20, BULLET_TYPE_NORMAL, 22,22},
    {20, BULLET_TYPE_NORMAL, 12,30},
    {20, BULLET_TYPE_NORMAL, 0,32},
    {20, BULLET_TYPE_NORMAL, -12,30},
    {20, BULLET_TYPE_NORMAL, -22,22},
    {20, BULLET_TYPE_NORMAL, -30,12},
    {20, BULLET_TYPE_NORMAL, -32,0},
    {20, BULLET_TYPE_NORMAL, -30,-12},
    {20, BULLET_TYPE_NORMAL, -22,-22},
    {20, BULLET_TYPE_NORMAL, -12,-30},
    {20, BULLET_TYPE_NORMAL, 0,-32},
    {20, BULLET_TYPE_NORMAL, 12,-30},
    {20, BULLET_TYPE_NORMAL, 22,-22},
    {20, BULLET_TYPE_NORMAL, 30,-12}
};

const int8_t (* shoot_patterns[])[4] = {
    shoot_pattern_1,
    shoot_pattern_2,
    shoot_pattern_3,
    shoot_pattern_4
};

enemy_t ENEMY_POOL[MAX_ENEMIES];
uint8_t ACTIVE_ENEMY_POOL[MAX_ENEMIES];
uint8_t active_enemy_index = 0;

void init_enemies(void){
    for (uint8_t i=0; i<MAX_ENEMIES; i++){
	ENEMY_POOL[i].isactive = 0;
	ENEMY_POOL[i].x = 0;
	ENEMY_POOL[i].y = 0;
	ENEMY_POOL[i].dx = 0;
	ENEMY_POOL[i].dy = 0;
	ENEMY_POOL[i].fx = 0;
	ENEMY_POOL[i].fy = 0;
	ENEMY_POOL[i].px = 0;
	ENEMY_POOL[i].py = 0;
	ENEMY_POOL[i].type = 0;
	ENEMY_POOL[i].move_pattern = 0;
	ENEMY_POOL[i].shoot_pattern = 0;
	ENEMY_POOL[i].move_activepattern = 0;
	ENEMY_POOL[i].shoot_activepattern = 0;
	ENEMY_POOL[i].move_framecounter = 0;
	ENEMY_POOL[i].shoot_framecounter = 0;
	ENEMY_POOL[i].hp = 0;
	ENEMY_POOL[i].ishit = 0;
	ACTIVE_ENEMY_POOL[i] = 255;
    }
}

void add_enemy(uint8_t x, uint8_t y, uint8_t type, uint8_t move_pattern, uint8_t shoot_pattern){
    for (uint8_t i=0; i<MAX_ENEMIES; i++){
	if (!ENEMY_POOL[i].isactive){
	    ENEMY_POOL[i].isactive = 1;
	    ENEMY_POOL[i].x = x;
	    ENEMY_POOL[i].y = y;
	    ENEMY_POOL[i].dx = 0;
	    ENEMY_POOL[i].dy = 0;
	    ENEMY_POOL[i].fx = 0;
	    ENEMY_POOL[i].fy = 0;
	    ENEMY_POOL[i].px = x;
	    ENEMY_POOL[i].py = y;
	    ENEMY_POOL[i].type = type;
	    ENEMY_POOL[i].move_pattern = move_pattern;
	    ENEMY_POOL[i].shoot_pattern = shoot_pattern;
	    ENEMY_POOL[i].move_activepattern = 0;
	    ENEMY_POOL[i].shoot_activepattern = 0;
	    ENEMY_POOL[i].move_framecounter = move_patterns[move_pattern][0][0];
	    ENEMY_POOL[i].shoot_framecounter = shoot_patterns[shoot_pattern][0][0];
	    ENEMY_POOL[i].hp = 3;
	    ENEMY_POOL[i].ishit = 0;
	    ACTIVE_ENEMY_POOL[active_enemy_index++] = i;
	    break;
	}
    }
}

void handle_enemies(void){
    for (uint8_t j=0; j<active_enemy_index; j++){

	uint8_t i = ACTIVE_ENEMY_POOL[j];
	
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
	    ENEMY_POOL[i].dx = move_patterns[current_move_pattern][step][1];
	    ENEMY_POOL[i].dy = move_patterns[current_move_pattern][step][2];
	}
	ENEMY_POOL[i].move_framecounter--;

	//gestion du pattern de tir
	uint8_t current_shoot_pattern = ENEMY_POOL[i].shoot_pattern;
	uint8_t shoot_pattern_length = shoot_pattern_lengths[current_shoot_pattern];
	if (ENEMY_POOL[i].shoot_framecounter == 0){

	    step = ENEMY_POOL[i].shoot_activepattern;
	    
	    //Type de tir
	    uint8_t bullet_type = shoot_patterns[current_shoot_pattern][step][1];
	    if (bullet_type){
		//Paramètres du tir
		int8_t bullet_dx,bullet_dy;
		if (bullet_type & BULLET_TYPE_AIMED){
		    aim_at_player(ENEMY_POOL[i].x, ENEMY_POOL[i].y);
		    bullet_dx = dir16_vx[1][quadrant][angle];
		    bullet_dy = dir16_vy[1][quadrant][angle];
		    //EMU_printf("Aimed shot: dx=%d dy=%d\n", bullet_dx, bullet_dy);
		} else {
		    bullet_dx = shoot_patterns[current_shoot_pattern][step][2];
		    bullet_dy = shoot_patterns[current_shoot_pattern][step][3];
		}
		//On ajoute la bullet
		add_enemy_bullet(ENEMY_POOL[i].x, ENEMY_POOL[i].y, bullet_dx, bullet_dy);
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
	    
	
	//Mouvement de l'ennemi
	ENEMY_POOL[i].fx += ENEMY_POOL[i].dx;
	if (ENEMY_POOL[i].fx >= 16){
	    ENEMY_POOL[i].x += ENEMY_POOL[i].fx >> 4;
	    ENEMY_POOL[i].px = ENEMY_POOL[i].x;
	    ENEMY_POOL[i].fx &= 0x0F;
	} else if (ENEMY_POOL[i].fx <= -16){
	    ENEMY_POOL[i].x -= (-ENEMY_POOL[i].fx) >> 4;
	    ENEMY_POOL[i].px = ENEMY_POOL[i].x;
	    ENEMY_POOL[i].fx &= 0x0F;
	}
	ENEMY_POOL[i].fy += ENEMY_POOL[i].dy;
	if (ENEMY_POOL[i].fy >= 16){
	    ENEMY_POOL[i].y += ENEMY_POOL[i].fy >> 4;
	    ENEMY_POOL[i].py = ENEMY_POOL[i].y;
	    ENEMY_POOL[i].fy &= 0x0F;
	} else if (ENEMY_POOL[i].fy <= -16){
	    ENEMY_POOL[i].y -= (-ENEMY_POOL[i].fy) >> 4;
	    ENEMY_POOL[i].py = ENEMY_POOL[i].y;
	    ENEMY_POOL[i].fy &= 0x0F;
	}
	//collision avec le joueur
	if ( (PLAYER.px+8) > ENEMY_POOL[i].x &&
	     (PLAYER.px-8) < ENEMY_POOL[i].x)
	    if ( (PLAYER.py+8) > ENEMY_POOL[i].y &&
		 (PLAYER.py-8) < ENEMY_POOL[i].y){
		//Le joueur touche un ennemi
		kill_active_enemy(j);
		EMU_printf("Ennemy/Player hit!\n");
	    }
	//On vérifie si l'ennemie est hors écran
	if(ENEMY_POOL[i].x < GAMESCREEN_X_ORIGIN  ||
	   ENEMY_POOL[i].x > GAMESCREEN_X_END    ||
	   ENEMY_POOL[i].y < GAMESCREEN_Y_ORIGIN  ||
	   ENEMY_POOL[i].y > GAMESCREEN_Y_END ){
	    kill_active_enemy(j);
	}

	//On l'affiche
	if (ENEMY_POOL[i].isactive){
	    oam+= move_metasprite_ex(enemy_1_sprite_metasprites[0],
				     ENEMY_1_TILE_OFFSET,0,oam,
				     ENEMY_POOL[i].px, ENEMY_POOL[i].py);
	}
	    
	
    }
    
}

void kill_active_enemy(uint8_t j){
    uint8_t i = ACTIVE_ENEMY_POOL[j];
    ENEMY_POOL[i].isactive = 0;
    // On compacte le tableau des ennemis actifs
    ACTIVE_ENEMY_POOL[j] = ACTIVE_ENEMY_POOL[--active_enemy_index];
}
