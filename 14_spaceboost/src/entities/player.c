#include "utils.h"
#include "player.h"
#include "hud.h"
#include "game.h"
#include "input.h"
#include "body.h"
#include "shot.h"
#include "explosion.h"
#include "player_sprite.h"
#include "shield_sprite.h"

static void update_player_input(void);
static void check_player_bounds(void);
static void draw_player(void);

static const uint16_t boost_speed_table[24] = {
    1,  1,  1,  1,
    2,  2,  2,  2,
    3,  3,  4,  4,
    4,  5,  12, 12,
    16, 16, 32, 64,
    80, 80, 72, 48
};

static const uint16_t boost_speed_table_normalized[24] = {
    1,  1,  0,  1,
    2,  1,  2,  1,
    2,  2,  2,  3,
    3,  4,  8,  9,
    11, 11, 22, 45,
    56, 57, 51, 34
};

Player player;
Player * PLAYER = &player;

void init_player(void) {
    PLAYER->lives       = PLAYER_LIVES;
    PLAYER->score       = 0;
    PLAYER->active      = 0;  // activé par EVENT_ACTIVATE_PLAYER après l'intro
    PLAYER->metasprites = player_sprite_metasprites;
    reset_player(PLAYER_START_X, PLAYER_START_Y);
}

void reset_player(uint8_t x, uint8_t y) {
    init_body(&PLAYER->body, x, y);
    PLAYER->shot_cooldown      = 0;
    PLAYER->shot_power         = 0;
    PLAYER->invincibility_timer = 0;
    PLAYER->boost               = 0;
    PLAYER->shield              = 0;
}

void kill_player(void) {
    add_explosion(PLAYER->body.x, PLAYER->body.y);
    PLAYER->lives--;
    reset_player(PLAYER_START_X, PLAYER_START_Y);
    PLAYER->invincibility_timer = PLAYER_INVINCIBILITY;
    hud_set_lives();
}

void hit_player(void) {
    kill_player();
}

void add_to_score(uint8_t points){
    PLAYER->score += points;
}

void update_player(void) {
    if (PLAYER->lives == 0) {
        PLAYER->active = 0;
        game_change_state(GAME_STATE_GAME_OVER);
        return;
    }
    if (PLAYER->active) {
        update_player_input();
        update_body_position(&PLAYER->body);
        check_player_bounds();
    }
    draw_player();  // toujours dessiné : visible pendant l'intro
		    // (level_intro gère le mouvement)
}

void powerup_player(PowerUpType type){
    switch (type) {
    case POWERUP_TYPE_SHOT:
        if (PLAYER->shot_power < PLAYER_MAX_POWER_LVL){
            PLAYER->shot_power++;
            powerup_shot(PLAYER->shot_power);
        }
	break;
    case POWERUP_TYPE_SHIELD:
	PLAYER->shield = 1;
	break;
    case POWERUP_TYPE_LIFE:
	if (PLAYER->lives < PLAYER_MAX_LIVES) PLAYER->lives++;
	break;
    }
}

static void update_player_input(void) {
    if (PLAYER->invincibility_timer) {
        PLAYER->invincibility_timer--;
    }

    uint8_t speed = PLAYER_SPEED;

    if (PLAYER->boost) {
        PLAYER->boost--;
        if (PLAYER->body.dx && PLAYER->body.dy) {
            speed = boost_speed_table_normalized[(PLAYER->boost & 62) >> 1];
        } else {
            speed = boost_speed_table[(PLAYER->boost & 62) >> 1];
        }
        if (PLAYER->body.dx > 0) {
            PLAYER->body.dx = speed;
        } else if (PLAYER->body.dx < 0) {
            PLAYER->body.dx = -speed;
        }
        if (PLAYER->body.dy > 0) {
            PLAYER->body.dy = speed;
        } else if (PLAYER->body.dy < 0) {
            PLAYER->body.dy = -speed;
        }
    } else {
        PLAYER->body.dx = 0;
        PLAYER->body.dy = 0;

        if (KEY_RELEASED(J_A)) {
            PLAYER->boost = PLAYER_BOOST_DURATION;
            speed = BOOST_SPEED;
        }

        if (KEY_PRESSED(J_LEFT))  PLAYER->body.dx = -speed;
        if (KEY_PRESSED(J_RIGHT)) PLAYER->body.dx =  speed;
        if (KEY_PRESSED(J_UP))    PLAYER->body.dy = -speed;
        if (KEY_PRESSED(J_DOWN))  PLAYER->body.dy =  speed;
    }

    if (PLAYER->shot_cooldown) {
        PLAYER->shot_cooldown--;
    } else if (KEY_PRESSED(J_B)) {
        fire_shot(PLAYER->body.x, PLAYER->body.y - 8, 0, -SHOT_SPEED);
        PLAYER->shot_cooldown = PLAYER_SHOT_COOLDOWN;
    }
}

static void check_player_bounds(void) {
    PLAYER->body.x = clamp(PLAYER->body.x , PLAYER_MIN_X, PLAYER_MAX_X);
    PLAYER->body.y = clamp(PLAYER->body.y , PLAYER_MIN_Y, PLAYER_MAX_Y);
}

static void draw_player(void) {
    if (PLAYER->invincibility_timer & 8) return;

    uint8_t frame = PLAYER_ANIMATION_FRAME_TOP;
    if (PLAYER->boost) {
        if (PLAYER->body.dx < 0) {
            frame = PLAYER_ANIMATION_FRAME_LEFT;
        } else if (PLAYER->body.dx > 0) {
            frame = PLAYER_ANIMATION_FRAME_RIGHT;
        }
    }
    oam += move_metasprite_ex(PLAYER->metasprites[frame],
                              PLAYER_TILE_OFFSET, 0, oam,
                              PLAYER->body.x, PLAYER->body.y);
    if (PLAYER->shield && (frame_counter & 1)) {
        oam += move_metasprite_ex(shield_sprite_metasprites[0],
                                  SHIELD_TILE_OFFSET, 0, oam,
                                  PLAYER->body.x, PLAYER->body.y);
    }
}
