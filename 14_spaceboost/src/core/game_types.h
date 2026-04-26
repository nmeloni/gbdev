#ifndef TYPES_H
#define TYPES_H

#include <stdint.h>
#include <gbdk/metasprites.h>

// ─── Corps physique (virgule fixe 4 bits) ──────────────────────────────────────
typedef struct {
    uint8_t x, y;
    int8_t  dx, dy;
    int8_t  fx, fy;
} Body;

// ─── Background (virgule fixe 4 bits) ────────────────────────────────────────── 
typedef struct {
    int8_t dx, fx;
    int8_t dy, fy;
} Background;
// ─── Structure Bullet ────────────────────────────────────────────────────────
typedef enum {
    BULLET_TYPE_SMALL,
    BULLET_TYPE_LARGE,
    BULLET_TYPE_LASER,
    BULLET_TYPE_NONE
} BulletType;

typedef struct {
    Body    body;
    uint8_t active;
    BulletType type;
} Bullet;

// ─── Directions ──────────────────────────────────────────────────────────────
typedef enum {
    //0,1,2,3
    DIR_E, DIR_ENE, DIR_NE, DIR_NNE,
    //4,5,6,7
    DIR_N, DIR_NNW, DIR_NW, DIR_WNW,
    // 8,9,10,11
    DIR_W, DIR_WSW, DIR_SW, DIR_SSW,
    //12,13,14,15
    DIR_S, DIR_SSE, DIR_SE, DIR_ESE
} Direction16;

// ─── Structure Pattern mouvement ───────────────────────────────────────────────
typedef enum {
    STATIC_PATTERN_TYPE_MOVE_DOWN,
    STATIC_PATTERN_TYPE_MOVE_DOWN_FAST,
    STATIC_PATTERN_TYPE_MOVE_UP,
    STATIC_PATTERN_TYPE_MOVE_UP_FAST,
    STATIC_PATTERN_TYPE_MOVE_LEFT,
    STATIC_PATTERN_TYPE_MOVE_LEFT_FAST,
    STATIC_PATTERN_TYPE_MOVE_RIGHT,
    STATIC_PATTERN_TYPE_MOVE_RIGHT_FAST,
    
    STATIC_PATTERN_TYPE_MOVE_LEFT_BKG,
    STATIC_PATTERN_TYPE_MOVE_RIGHT_BKG,
    
    STATIC_PATTERN_TYPE_MOVE_LATERAL,
    STATIC_PATTERN_TYPE_ZIGZAG,
    STATIC_PATTERN_TYPE_NONE
} StaticPatternType;

typedef struct {
    StaticPatternType type[2];
    StaticPatternType active_type;
    uint8_t active_type_index;
    uint8_t pattern_length;
    uint8_t active_pattern;
    uint8_t timer;
    int8_t dx, dy;
} StaticPatternManager;

typedef struct {
    int8_t dx, dy;
    uint8_t duration;
} StaticPattern;

// ─── Structure Pattern Tir enemie ──────────────────────────────────────────────
typedef enum  {
    BULLET_PATTERN_TYPE_SINGLE_DOWN,
    BULLET_PATTERN_TYPE_NONE
} BulletPatternType;

typedef struct {
    BulletType type; 
    Direction16 * dir; //direction de chaque tirs du pattern
    uint8_t length;    // nombre de directions
    uint8_t lag;       // laps de temps entre deux tirs
    uint8_t cool_down;  // laps de temps avant de repeter le pattern
} BulletPattern;

typedef struct {
    const BulletPattern * bp;
    uint8_t current_dir_index;
    uint8_t lag_timer;
    uint8_t cool_down_timer;
} BulletPatternManager;


// ─── Structure Joueur ──────────────────────────────────────────────────────────
typedef struct {
    Body  body;
    uint8_t active;
    uint8_t lives;
    uint8_t shield;
    uint8_t invincibility_timer;
    uint8_t shot_cooldown;
    uint8_t shot_power;
    uint8_t boost;
    const metasprite_t * const * metasprites;
} Player;

// ─── Structure Tir joueur ────────────────────────────────────────────────────
typedef struct{
    Body body;
    uint8_t active;
} Shot;

// ─── Structure Explosion ─────────────────────────────────────────────────────
typedef struct {
    uint8_t x;
    uint8_t y;
    uint8_t frame_timer;
} Explosion;

// ─── Structure Power UP ──────────────────────────────────────────────────────
typedef enum {
    POWERUP_TYPE_SHOT,
    POWERUP_TYPE_SHIELD,
    POWERUP_TYPE_LIFE,
    POWERUP_TYPE_NONE
} PowerUpType;

typedef struct {
    Body  body;
    uint8_t active;
    uint8_t type;
    StaticPatternManager spm;
} PowerUp;

// ─── Structure Enemy ─────────────────────────────────────────────────────────
typedef enum {
  ENEMY_DRONE,
  ENEMY_NONE
} EnemyType;

typedef enum {
    WEAPON_NONE
} WeaponType;

typedef struct {
    Body    body;
    uint8_t active;
    EnemyType type;
    int8_t  hp;
    uint8_t ishit;
    uint8_t frame_timer;
    uint8_t speed;
    PowerUpType powerup;
    uint8_t tile_offset;
    StaticPatternManager smp; //static Move Manager
    BulletPatternManager bpm; //bullet pattern manager
} Enemy;

// ─── Structure Level ─────────────────────────────────────────────────────────
typedef enum {
    LEVEL_1,
    LEVEL_2,
    LEVEL_3,
} LevelNumber;

typedef enum {
    LEVEL_EVENT_INIT,
    LEVEL_EVENT_INTRO,
    LEVEL_EVENT_START,
    LEVEL_EVENT_SPAWN_ENEMY,
    LEVEL_EVENT_END,
    LEVEL_EVENT_OUTRO,
    LEVEL_EVENT_NONE
} LevelEventType;

typedef struct {
    LevelEventType level_event_type;
    EnemyType enemy_type;
    uint8_t x, y;
    uint8_t duration;
} LevelEvent;

typedef struct{
    const LevelEvent * le;
    uint8_t current_event_index;
    LevelEventType current_event_type;
    uint8_t timer;
} LevelEventManager;

#endif // TYPES_H
