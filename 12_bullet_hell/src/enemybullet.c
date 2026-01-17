#include "enemybullet.h"


// 0 = droite, sens anti-horaire
const int8_t dir16_vx_slow[4][5] = {
    {+16, +15, +11, +6, 0},
    {+16, +15, +11, +6, 0},
    {-16, -15, -11, -6, 0},
    {-16, -15, -11, -6, 0}   
};

const int8_t dir16_vy_slow[4][5] = {
    {0, -6, -11, -15, -16},
    {0, +6, +11, +15, +16},
    {0, -6, -11, -15, -16},
    {0, +6, +11, +15, +16}
};

const int8_t dir16_vx_normal[4][5] = {
    {+32, +30, +22, +12, 0},
    {+32, +30, +22, +12, 0},
    {-32, -30, -22, -12, 0},
    {-32, -30, -22, -12, 0}   
};

const int8_t dir16_vy_normal[4][5] = {
    {0, -12, -22, -30, -32},
    {0, +12, +22, +30, +32},
    {0, -12, -22, -30, -32},
    {0, +12, +22, +30, +32}
};

const int8_t (* dir16_vx[])[5] = {
	dir16_vx_slow,
	dir16_vx_normal
};

const int8_t (* dir16_vy[])[5] = {
	dir16_vy_slow,
	dir16_vy_normal
};


enemybullet_t ENEMYBULLET_POOL[MAX_ENEMYBULLETS];
uint8_t ACTIVE_ENEMYBULLET_POOL[MAX_ENEMYBULLETS];
uint8_t quadrant, angle;
uint8_t active_enemybullet_index = 0;

void init_enemy_bullets(void){
    for (uint8_t i=0; i<MAX_ENEMYBULLETS; i++){
	ENEMYBULLET_POOL[i].isactive = 0;
	ENEMYBULLET_POOL[i].x = 0;
	ENEMYBULLET_POOL[i].y = 0;
	ENEMYBULLET_POOL[i].dx = 0;
	ENEMYBULLET_POOL[i].dy = 0;
	ENEMYBULLET_POOL[i].fx = 0;
	ENEMYBULLET_POOL[i].fy = 0;
	ENEMYBULLET_POOL[i].px = 0;
	ENEMYBULLET_POOL[i].py = 0;
	ACTIVE_ENEMYBULLET_POOL[i] = 255;
    }
}

void add_enemy_bullet(uint8_t x, uint8_t y, int8_t dx, int8_t dy){
    for (uint8_t i=0; i<MAX_ENEMYBULLETS; i++){
	if (!ENEMYBULLET_POOL[i].isactive){
	    ENEMYBULLET_POOL[i].isactive = 1;
	    ENEMYBULLET_POOL[i].x = x;
	    ENEMYBULLET_POOL[i].y = y;
	    ENEMYBULLET_POOL[i].dx = dx;
	    ENEMYBULLET_POOL[i].dy = dy;
	    ENEMYBULLET_POOL[i].fx = 0;
	    ENEMYBULLET_POOL[i].fy = 0;
	    ENEMYBULLET_POOL[i].px = x-ENEMYBULLET_X_OFFSET;
	    ENEMYBULLET_POOL[i].py = y-ENEMYBULLET_Y_OFFSET;
	    ACTIVE_ENEMYBULLET_POOL[active_enemybullet_index++] = i;
	    break;
	}
    }
}

void aim_at_player(uint8_t x, uint8_t y){
    uint8_t adx,ady;
    //On décide de la direction du tir
    if (PLAYER.px < x){
	adx = x - (PLAYER.px);
	quadrant = 2;
    } else {
	adx = (PLAYER.px) - x;
	quadrant = 0;
    }
    if (PLAYER.py > y){
	ady = (PLAYER.py) - y;
	quadrant |= 1;
    } else {
	ady = y - (PLAYER.py);
    }

    //On choisit l'angle le plus proche
    uint8_t temp;
    if (adx >= ady){
	temp = adx-ady;
	if ( temp>>2 > ady){
	    angle = 0; //Horizontal
	} else if (temp>>1 > ady>>1){
	    angle = 1; //Petit angle
	} else {
	    angle = 2; //Moyen angle
	}
    } else {
	temp = ady-adx;
	if ( temp>>2 > adx){
	    angle = 4; //Vertical
	} else if (temp>>1 > adx>>1){
	    angle = 3; //Grand angle
	} else {
	    angle = 2; //Moyen angle
	}
    }
}

void handle_enemy_bullets(void){
    for (uint8_t j=0; j<active_enemybullet_index; j++){

	uint8_t i = ACTIVE_ENEMYBULLET_POOL[j];

	if ( (level_framecounter + j)%2 ) continue;
	//On ne gère que la moitié des bullets par frame pour alléger le CPU
	
	ENEMYBULLET_POOL[i].fx += ENEMYBULLET_POOL[i].dx;
	if (ENEMYBULLET_POOL[i].fx >= 16){
	    ENEMYBULLET_POOL[i].x += ENEMYBULLET_POOL[i].fx >> 4;
	    ENEMYBULLET_POOL[i].px = ENEMYBULLET_POOL[i].x - ENEMYBULLET_X_OFFSET;
	    ENEMYBULLET_POOL[i].fx &= 0x0F;
	} else if (ENEMYBULLET_POOL[i].fx <= -16){
	    ENEMYBULLET_POOL[i].x -= (-ENEMYBULLET_POOL[i].fx) >> 4;
	    ENEMYBULLET_POOL[i].px = ENEMYBULLET_POOL[i].x - ENEMYBULLET_X_OFFSET;
	    ENEMYBULLET_POOL[i].fx &= 0x0F;
	}
	ENEMYBULLET_POOL[i].fy += ENEMYBULLET_POOL[i].dy;
	if (ENEMYBULLET_POOL[i].fy >= 16){
	    ENEMYBULLET_POOL[i].y += ENEMYBULLET_POOL[i].fy >> 4;
	    ENEMYBULLET_POOL[i].py = ENEMYBULLET_POOL[i].y - ENEMYBULLET_Y_OFFSET;
	    ENEMYBULLET_POOL[i].fy &= 0x0F;
	} else if (ENEMYBULLET_POOL[i].fy <= -16){
	    ENEMYBULLET_POOL[i].y -= (-ENEMYBULLET_POOL[i].fy) >> 4;
	    ENEMYBULLET_POOL[i].py = ENEMYBULLET_POOL[i].y - ENEMYBULLET_Y_OFFSET;
	    ENEMYBULLET_POOL[i].fy &= 0x0F;
	}
	
	//collision avec le joueur
	if ( (PLAYER.px+1) > ENEMYBULLET_POOL[i].x &&
	     (PLAYER.px-1) < ENEMYBULLET_POOL[i].x)
	    if ( (PLAYER.py+1) > ENEMYBULLET_POOL[i].y &&
		 (PLAYER.py-1) < ENEMYBULLET_POOL[i].y){
		//Le joueur est touché
		kill_active_enemybullet(j);
		EMU_printf("Bullet/Player hit!\n");
	    }
	
		

	
	//On vérifie si la bullet est hors écran	
	if(ENEMYBULLET_POOL[i].x < GAMESCREEN_X_ORIGIN ||
	   ENEMYBULLET_POOL[i].x > GAMESCREEN_X_END ||
	   ENEMYBULLET_POOL[i].y < GAMESCREEN_Y_ORIGIN ||
	   ENEMYBULLET_POOL[i].y > GAMESCREEN_Y_END ){
	    kill_active_enemybullet(j);
	}

	
	
    skip_enemybullet_update:
	//On l'affiche
	if (ENEMYBULLET_POOL[i].isactive){
	    set_sprite_tile(oam, ENEMYBULLET_TILE_OFFSET);
	    move_sprite(oam++,
			ENEMYBULLET_POOL[i].px,
			ENEMYBULLET_POOL[i].py);
	}
	
    }
}

inline void kill_active_enemybullet(uint8_t j){
    uint8_t i = ACTIVE_ENEMYBULLET_POOL[j];
    ENEMYBULLET_POOL[i].isactive = 0;
    //On compacte le tableau des actifs
    ACTIVE_ENEMYBULLET_POOL[j] = ACTIVE_ENEMYBULLET_POOL[--active_enemybullet_index];

}
