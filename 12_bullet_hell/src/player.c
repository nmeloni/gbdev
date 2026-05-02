#include "player.h"
#include "input.h"
#include "body.h"
#include "player_sprite.h"

// Définis dans main.c
extern uint8_t  oam;
extern uint16_t frame_counter;

player_t PLAYER;

static void update_player_input(void);
static void check_player_bounds(void);
static void draw_player(void);

void player_init(void) {
    init_body(&PLAYER.body, PLAYER_START_X, PLAYER_START_Y);
    PLAYER.active              = 1;
    PLAYER.boost               = 0;
    PLAYER.invincibility_timer = 0;
    PLAYER.metasprites         = player_sprite_metasprites;
}

void player_update(void) {
    update_player_input();
    update_body_position(&PLAYER.body);
    check_player_bounds();
    draw_player();
}

static void update_player_input(void) {
    if (PLAYER.invincibility_timer) {
        PLAYER.invincibility_timer--;
    }

    uint8_t speed = PLAYER_SPEED;

    if (PLAYER.boost) {
        PLAYER.boost--;
    } else {
        PLAYER.body.dx = 0;
        PLAYER.body.dy = 0;

        if (KEY_RELEASED(J_A)) {
            PLAYER.boost = PLAYER_BOOST_DURATION;
            speed = BOOST_SPEED;
        }

        if (KEY_PRESSED(J_LEFT))  PLAYER.body.dx = -speed;
        if (KEY_PRESSED(J_RIGHT)) PLAYER.body.dx =  speed;
        if (KEY_PRESSED(J_UP))    PLAYER.body.dy = -speed;
        if (KEY_PRESSED(J_DOWN))  PLAYER.body.dy =  speed;
    }
}

static void check_player_bounds(void) {
    // Gestion explicite du underflow uint8_t (valeur > 200 = underflow)
    if (PLAYER.body.x > 200u)              PLAYER.body.x = PLAYER_MIN_X;
    else if (PLAYER.body.x < PLAYER_MIN_X) PLAYER.body.x = PLAYER_MIN_X;
    else if (PLAYER.body.x > PLAYER_MAX_X) PLAYER.body.x = PLAYER_MAX_X;

    if (PLAYER.body.y > 200u)              PLAYER.body.y = PLAYER_MIN_Y;
    else if (PLAYER.body.y < PLAYER_MIN_Y) PLAYER.body.y = PLAYER_MIN_Y;
    else if (PLAYER.body.y > PLAYER_MAX_Y) PLAYER.body.y = PLAYER_MAX_Y;
}

static void draw_player(void) {
    // Clignotement pendant l'invincibilité
    if (PLAYER.invincibility_timer & 8) return;

    uint8_t frame = PLAYER_ANIMATION_FRAME_CENTER;
    if (PLAYER.body.dx < 0) frame = PLAYER_ANIMATION_FRAME_LEFT;
    else if (PLAYER.body.dx > 0) frame = PLAYER_ANIMATION_FRAME_RIGHT;

    oam += move_metasprite_ex(PLAYER.metasprites[frame],
                              PLAYER_TILE_OFFSET, 0, oam,
                              PLAYER.body.x, PLAYER.body.y);
}
