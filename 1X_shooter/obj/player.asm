;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler
; Version 4.5.1 #15267 (Linux)
;--------------------------------------------------------
	.module player
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _PLAYER
	.globl _previous_joypad
	.globl _current_joypad
	.globl _init_player
	.globl _handle_player
	.globl _shoot
	.globl _draw_player
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _DATA
_current_joypad::
	.ds 1
_previous_joypad::
	.ds 1
_PLAYER::
	.ds 21
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
___EMU_PROFILER_INIT:
	.ds 2
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area _DABS (ABS)
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area _HOME
	.area _GSINIT
	.area _GSFINAL
	.area _GSINIT
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area _HOME
	.area _HOME
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area _CODE
;src/player.c:9: void init_player(void){
;	---------------------------------
; Function init_player
; ---------------------------------
_init_player::
;src/player.c:10: RESET_PLAYER();
	ld	hl, #_PLAYER
	ld	(hl), #0x00
	inc	hl
	ld	(hl), #0x48
	inc	hl
	ld	(hl), #0x00
	inc	hl
	ld	(hl), #0x64
	inc	hl
	ld	(hl), #0xe0
	inc	hl
	ld	(hl), #0x00
	ld	hl, #_PLAYER + 8
	ld	(hl), #0x01
	ld	hl, #_PLAYER + 10
	ld	(hl), #0x00
	ld	hl, #_PLAYER + 11
	ld	(hl), #0x00
	ld	hl, #_PLAYER + 13
	ld	(hl), #0x00
	ld	hl, #_PLAYER + 14
	ld	(hl), #0x00
	ld	hl, #(_PLAYER + 16)
	ld	a, #<(_bullet_lvl1_sprite_metasprites)
	ld	(hl+), a
	ld	a, #>(_bullet_lvl1_sprite_metasprites)
	ld	(hl+), a
	ld	(hl), #0x04
	ld	hl, #_PLAYER + 19
	ld	(hl), #0x00
	ld	hl, #_PLAYER + 20
	ld	(hl), #0x00
	ld	hl, #_PLAYER + 12
	ld	(hl), #0x78
;src/player.c:11: PLAYER.lives = 3;
	ld	hl, #_PLAYER + 9
	ld	(hl), #0x03
;src/player.c:12: }
	ret
;src/player.c:14: void handle_player(void){
;	---------------------------------
; Function handle_player
; ---------------------------------
_handle_player::
	dec	sp
	dec	sp
;src/player.c:15: if (PLAYER.boost){ 
	ld	bc, #_PLAYER + 13
	ld	a, (bc)
;src/player.c:16: PLAYER.dxy = BOOST_SPEED;
;src/player.c:15: if (PLAYER.boost){ 
	or	a, a
	jr	Z, 00102$
;src/player.c:16: PLAYER.dxy = BOOST_SPEED;
	ld	hl, #(_PLAYER + 4)
	xor	a, a
	ld	(hl+), a
	ld	(hl), #0x05
;src/player.c:17: PLAYER.boost --;
	ld	a, (bc)
	dec	a
	ld	(bc), a
	jr	00103$
00102$:
;src/player.c:19: PLAYER.dxy = NORMAL_SPEED;
	ld	hl, #(_PLAYER + 4)
	ld	a, #0xe0
	ld	(hl+), a
	ld	(hl), #0x00
00103$:
;src/player.c:21: if (PLAYER.invinsibility_timer) PLAYER.invinsibility_timer--;
	ld	hl, #_PLAYER + 12
	ld	a, (hl)
	or	a, a
	jr	Z, 00105$
	dec	a
	ld	(hl), a
00105$:
;src/player.c:23: if (KEY_PRESSED(J_A)){
	ld	a, (_current_joypad)
	ld	e, a
;src/player.c:24: if (!PLAYER.last_boost){
	ld	hl, #_PLAYER + 11
;src/player.c:23: if (KEY_PRESSED(J_A)){
	bit	4, e
	jr	Z, 00109$
;src/player.c:24: if (!PLAYER.last_boost){
	ld	a, (hl)
	or	a, a
	jr	NZ, 00109$
;src/player.c:25: PLAYER.boost = BOOST_DURATION;
	ld	a, #0x04
	ld	(bc), a
;src/player.c:26: PLAYER.last_boost = BOOST_LAG;
	ld	(hl), #0x10
00109$:
;src/player.c:29: if (PLAYER.last_boost) PLAYER.last_boost--;
	ld	a, (hl)
	or	a, a
	jr	Z, 00111$
	dec	a
	ld	(hl), a
00111$:
;src/player.c:31: if (KEY_PRESSED(J_LEFT)){
	ld	a, (_current_joypad)
;src/player.c:32: if (PLAYER.x > PLAYER.dxy + PLAYER_MIN_X) PLAYER.x -= PLAYER.dxy;
;src/player.c:31: if (KEY_PRESSED(J_LEFT)){
	bit	1, a
	jr	Z, 00116$
;src/player.c:32: if (PLAYER.x > PLAYER.dxy + PLAYER_MIN_X) PLAYER.x -= PLAYER.dxy;
	ld	hl, #_PLAYER
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	de, #(_PLAYER + 4)
	ld	a, (de)
	ldhl	sp,	#0
	ld	(hl+), a
	inc	de
	ld	a, (de)
	ld	(hl), a
	pop	de
	push	de
	ld	hl, #0x1000
	add	hl, de
	ld	e, c
	ld	d, b
	ld	a, l
	sub	a, e
	ld	a, h
	sbc	a, d
	jr	NC, 00113$
	pop	de
	push	de
	ld	a, c
	sub	a, e
	ld	e, a
	ld	a, b
	sbc	a, d
	ld	b, a
	ld	a, e
	ld	hl, #_PLAYER
	ld	(hl+), a
	ld	(hl), b
	jr	00116$
00113$:
;src/player.c:33: else PLAYER.x = PLAYER_MIN_X;
	ld	hl, #_PLAYER
	xor	a, a
	ld	(hl+), a
	ld	(hl), #0x10
00116$:
;src/player.c:35: if (KEY_PRESSED(J_RIGHT)){
	ld	a, (_current_joypad)
	rrca
	jr	NC, 00121$
;src/player.c:36: if (PLAYER.x < (PLAYER_MAX_X) - PLAYER.dxy ) PLAYER.x += PLAYER.dxy;
	ld	hl, #_PLAYER
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	hl, #(_PLAYER + 4)
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	xor	a, a
	sub	a, l
	ld	e, a
	ld	a, #0xa0
	sbc	a, h
	ld	d, a
	ld	a, c
	sub	a, e
	ld	a, b
	sbc	a, d
	jr	NC, 00118$
	add	hl, bc
	ld	c, l
	ld	b, h
	ld	hl, #_PLAYER
	ld	a, c
	ld	(hl+), a
	ld	(hl), b
	jr	00121$
00118$:
;src/player.c:37: else PLAYER.x = ((uint16_t)PLAYER_MAX_X);
	ld	hl, #_PLAYER
	ld	(hl), #0x00
	inc	hl
	ld	(hl), #0xa0
00121$:
;src/player.c:39: if (KEY_PRESSED(J_UP)){
	ld	a, (_current_joypad)
;src/player.c:40: if (PLAYER.y > PLAYER.dxy+ (PLAYER_MIN_Y)) PLAYER.y -= PLAYER.dxy;
;src/player.c:39: if (KEY_PRESSED(J_UP)){
	bit	2,a
	jr	Z, 00126$
;src/player.c:40: if (PLAYER.y > PLAYER.dxy+ (PLAYER_MIN_Y)) PLAYER.y -= PLAYER.dxy;
	ld	hl, #(_PLAYER + 2)
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	de, #(_PLAYER + 4)
	ld	a, (de)
	ldhl	sp,	#0
	ld	(hl+), a
	inc	de
	ld	a, (de)
	ld	(hl), a
	pop	de
	push	de
	ld	hl, #0x1800
	add	hl, de
	ld	e, c
	ld	d, b
	ld	a, l
	sub	a, e
	ld	a, h
	sbc	a, d
	jr	NC, 00123$
	pop	de
	push	de
	ld	a, c
	sub	a, e
	ld	e, a
	ld	a, b
	sbc	a, d
	ld	b, a
	ld	a, e
	ld	hl, #(_PLAYER + 2)
	ld	(hl+), a
	ld	(hl), b
	jr	00126$
00123$:
;src/player.c:41: else PLAYER.y = PLAYER_MIN_Y;
	ld	hl, #(_PLAYER + 2)
	xor	a, a
	ld	(hl+), a
	ld	(hl), #0x18
00126$:
;src/player.c:43: if (KEY_PRESSED(J_DOWN)){
	ld	a, (_current_joypad)
	bit	3, a
	jr	Z, 00131$
;src/player.c:44: if (PLAYER.y < (PLAYER_MAX_Y) - PLAYER.dxy ) PLAYER.y += PLAYER.dxy;
	ld	hl, #(_PLAYER + 2)
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	hl, #(_PLAYER + 4)
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	xor	a, a
	sub	a, l
	ld	e, a
	ld	a, #0x88
	sbc	a, h
	ld	d, a
	ld	a, c
	sub	a, e
	ld	a, b
	sbc	a, d
	jr	NC, 00128$
	add	hl, bc
	ld	c, l
	ld	b, h
	ld	hl, #(_PLAYER + 2)
	ld	a, c
	ld	(hl+), a
	ld	(hl), b
	jr	00131$
00128$:
;src/player.c:45: else PLAYER.y = ((uint16_t)PLAYER_MAX_Y);
	ld	hl, #(_PLAYER + 2)
	xor	a, a
	ld	(hl+), a
	ld	(hl), #0x88
00131$:
;src/player.c:47: if (KEY_PRESSED(J_B)){
	ld	a, (_current_joypad)
	bit	5, a
	jr	Z, 00136$
;src/player.c:48: if (PLAYER.last_shot) PLAYER.last_shot--;
	ld	hl, #_PLAYER + 10
	ld	a, (hl)
	or	a, a
	jr	Z, 00133$
	dec	a
	ld	(hl), a
	jr	00136$
00133$:
;src/player.c:49: else shoot();
	call	_shoot
00136$:
;src/player.c:51: PLAYER.px = PLAYER.x >> 8;
	ld	hl, #_PLAYER
	ld	a, (hl+)
	ld	a, (hl)
	ld	(#(_PLAYER + 6)),a
;src/player.c:52: PLAYER.py = PLAYER.y >> 8;
	ld	hl, #(_PLAYER + 2)
	ld	a, (hl+)
	ld	b, (hl)
	ld	hl, #(_PLAYER + 7)
	ld	(hl), b
;src/player.c:53: PLAYER.column = (PLAYER.px + 8) >> 4;
	ld	hl, #(_PLAYER + 6)
	ld	c, (hl)
	ld	b, #0x00
	ld	hl, #0x0008
	add	hl, bc
	sra	h
	rr	l
	sra	h
	rr	l
	sra	h
	rr	l
	sra	h
	rr	l
	ld	a, l
	ld	(#(_PLAYER + 15)),a
;src/player.c:55: }
	inc	sp
	inc	sp
	ret
;src/player.c:58: void shoot(void){
;	---------------------------------
; Function shoot
; ---------------------------------
_shoot::
	add	sp, #-4
;src/player.c:59: if (PLAYER.last_shot){
	ld	a, (#(_PLAYER + 10) + 0)
	ldhl	sp,#3
;src/player.c:60: PLAYER.last_shot--;
	ld	(hl),a
	or	a,a
	jr	Z, 00102$
	dec	a
	ld	(#(_PLAYER + 10)),a
;src/player.c:61: return;
	jp	00109$
00102$:
;src/player.c:64: for (uint8_t i=0; i<MAX_BULLETS; i++){
	ldhl	sp,	#0
	ld	(hl), #0x00
	ldhl	sp,	#3
	ld	(hl), #0x00
00107$:
	ldhl	sp,	#3
	ld	a, (hl)
	sub	a, #0x04
	jp	NC, 00109$
;src/player.c:65: if (!BULLETS[i].isactive){
	ld	c, (hl)
	ld	b, #0x00
	ld	l, c
	ld	h, b
	add	hl, hl
	add	hl, bc
	add	hl, hl
	add	hl, bc
	ld	bc, #_BULLETS
	add	hl, bc
	push	hl
	ld	a, l
	ldhl	sp,	#3
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#2
	ld	(hl-), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0006
	add	hl, de
	ld	c, l
	ld	b, h
	ld	a, (bc)
	or	a, a
	jr	NZ, 00108$
;src/player.c:66: PLAYER.last_shot = SHOOT_LAG;
	ld	hl, #(_PLAYER + 10)
	ld	(hl), #0x08
;src/player.c:67: BULLETS[i].isactive = 1;
	ld	a, #0x01
	ld	(bc), a
;src/player.c:68: BULLETS[i].x = PLAYER.x;
	ldhl	sp,	#1
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	hl, #_PLAYER
	ld	a,	(hl+)
	ld	h, (hl)
	ld	(bc), a
	inc	bc
	ld	a, h
	ld	(bc), a
;src/player.c:69: BULLETS[i].y = PLAYER.y;
	ldhl	sp,	#1
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	inc	bc
	inc	bc
	ld	hl, #_PLAYER + 2
	ld	a,	(hl+)
	ld	h, (hl)
	ld	(bc), a
	inc	bc
	ld	a, h
	ld	(bc), a
;src/player.c:70: BULLETS[i].px = PLAYER.px;
	ldhl	sp,#1
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0004
	add	hl, de
	ld	c, l
	ld	b, h
	ld	a, (#(_PLAYER + 6) + 0)
	ld	(bc), a
;src/player.c:71: BULLETS[i].py = PLAYER.py;
	ldhl	sp,#1
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0005
	add	hl, de
	ld	c, l
	ld	b, h
	ld	a, (#(_PLAYER + 7) + 0)
	ld	(bc), a
;src/player.c:73: ACTIVE_BULLETS[active_bullet_index++] = i;
	ld	a, (_active_bullet_index)
	ld	c, a
	ld	hl, #_active_bullet_index
	inc	(hl)
	ld	hl, #_ACTIVE_BULLETS
	ld	b, #0x00
	add	hl, bc
	push	hl
	ldhl	sp,	#2
	ld	a, (hl)
	pop	hl
	ld	(hl), a
;src/player.c:74: return;
	jr	00109$
00108$:
;src/player.c:64: for (uint8_t i=0; i<MAX_BULLETS; i++){
	ldhl	sp,	#3
	inc	(hl)
	ld	a, (hl)
	ldhl	sp,	#0
	ld	(hl), a
	jp	00107$
00109$:
;src/player.c:77: }
	add	sp, #4
	ret
;src/player.c:79: void draw_player(void){
;	---------------------------------
; Function draw_player
; ---------------------------------
_draw_player::
	dec	sp
	dec	sp
;src/player.c:80: if (PLAYER.invinsibility_timer&8) return;
	ld	a, (#(_PLAYER + 12) + 0)
	bit	3, a
	jp	NZ, 00111$
;src/player.c:83: PLAYER.px, PLAYER.py);
	ld	hl, #(_PLAYER + 7)
	ld	b, (hl)
	ld	hl, #(_PLAYER + 6)
	ld	c, (hl)
	ld	a, (#_oam)
	ldhl	sp,	#1
	ld	(hl), a
;src/player.c:81: oam+=move_metasprite_ex(spaceship_sprite_metasprites[0],
	ld	hl, #_spaceship_sprite_metasprites
	ld	a,	(hl+)
	ld	h, (hl)
;/home/meloni/Lib/gbdk/include/gb/metasprites.h:160: __current_metasprite = metasprite;
	ld	e, a
	ld	d, h
	ld	hl, #___current_metasprite
	ld	a, e
	ld	(hl+), a
	ld	(hl), d
;/home/meloni/Lib/gbdk/include/gb/metasprites.h:161: __current_base_tile = base_tile;
;/home/meloni/Lib/gbdk/include/gb/metasprites.h:162: __current_base_prop = base_prop;
	xor	a, a
	ld	(#___current_base_tile), a
	ld	(#___current_base_prop),a
;/home/meloni/Lib/gbdk/include/gb/metasprites.h:163: return __move_metasprite(base_sprite, (y << 8) | (uint8_t)x);
	ld	d, b
	ld	e, c
	ldhl	sp,	#1
	ld	a, (hl)
	call	___move_metasprite
;src/player.c:83: PLAYER.px, PLAYER.py);
	ld	hl, #_oam
	add	a, (hl)
	ld	(hl), a
;src/player.c:84: if ( (PLAYER.flags & PLAYER_FLAG_SHIELD) && (level_framecounter & 4) ){
	ld	a, (#(_PLAYER + 14) + 0)
	rrca
	jr	NC, 00104$
	ld	a, (_level_framecounter)
	bit	2, a
	jr	Z, 00104$
;src/player.c:87: PLAYER.px, PLAYER.py);
	ld	hl, #(_PLAYER + 7)
	ld	c, (hl)
	ld	hl, #(_PLAYER + 6)
	ld	b, (hl)
	ld	a, (#_oam)
	ldhl	sp,	#1
	ld	(hl), a
;src/player.c:85: oam+=move_metasprite_ex(shield_sprite_metasprites[0],
	ld	hl, #_shield_sprite_metasprites
	ld	a,	(hl+)
	ld	h, (hl)
;/home/meloni/Lib/gbdk/include/gb/metasprites.h:160: __current_metasprite = metasprite;
	ld	e, a
	ld	d, h
	ld	hl, #___current_metasprite
	ld	a, e
	ld	(hl+), a
	ld	(hl), d
;/home/meloni/Lib/gbdk/include/gb/metasprites.h:161: __current_base_tile = base_tile;
	ld	hl, #___current_base_tile
	ld	(hl), #0x0e
;/home/meloni/Lib/gbdk/include/gb/metasprites.h:162: __current_base_prop = base_prop;
	xor	a, a
	ld	(#___current_base_prop),a
;/home/meloni/Lib/gbdk/include/gb/metasprites.h:163: return __move_metasprite(base_sprite, (y << 8) | (uint8_t)x);
	ld	d, c
	ld	e, b
	ldhl	sp,	#1
	ld	a, (hl)
	call	___move_metasprite
;src/player.c:87: PLAYER.px, PLAYER.py);
	ld	hl, #_oam
	add	a, (hl)
	ld	(hl), a
00104$:
;src/player.c:89: if (PLAYER.last_boost){
	ld	hl, #(_PLAYER + 11)
	ld	b, (hl)
	ld	a, b
	or	a, a
	jr	Z, 00111$
;src/player.c:92: PLAYER.px, PLAYER.py+6);
	ld	a, (#(_PLAYER + 7) + 0)
	add	a, #0x06
	ldhl	sp,	#0
	ld	(hl), a
	ld	hl, #(_PLAYER + 6)
	ld	c, (hl)
	ld	a, (#_oam)
	ldhl	sp,	#1
	ld	(hl), a
;src/player.c:90: oam+=move_metasprite_ex(booster_sprite_metasprites[(PLAYER.last_boost&12)>>2],
	ld	a, b
	and	a, #0x0c
	ld	l, a
	ld	h, #0x00
	sra	h
	rr	l
	sra	h
	rr	l
	add	hl, hl
	ld	de, #_booster_sprite_metasprites
	add	hl, de
	ld	a,	(hl+)
	ld	h, (hl)
;/home/meloni/Lib/gbdk/include/gb/metasprites.h:160: __current_metasprite = metasprite;
	ld	e, a
	ld	d, h
	ld	hl, #___current_metasprite
	ld	a, e
	ld	(hl+), a
	ld	(hl), d
;/home/meloni/Lib/gbdk/include/gb/metasprites.h:161: __current_base_tile = base_tile;
	ld	hl, #___current_base_tile
	ld	(hl), #0x12
;/home/meloni/Lib/gbdk/include/gb/metasprites.h:162: __current_base_prop = base_prop;
	xor	a, a
	ld	(#___current_base_prop),a
;/home/meloni/Lib/gbdk/include/gb/metasprites.h:163: return __move_metasprite(base_sprite, (y << 8) | (uint8_t)x);
	ldhl	sp,	#0
	ld	a, (hl+)
	ld	d, a
	ld	e, c
	ld	a, (hl)
	call	___move_metasprite
;src/player.c:92: PLAYER.px, PLAYER.py+6);
	ld	hl, #_oam
	add	a, (hl)
	ld	(hl), a
00111$:
;src/player.c:95: }
	inc	sp
	inc	sp
	ret
	.area _CODE
	.area _INITIALIZER
__xinit____EMU_PROFILER_INIT:
	.dw _EMU_profiler_message
	.area _CABS (ABS)
