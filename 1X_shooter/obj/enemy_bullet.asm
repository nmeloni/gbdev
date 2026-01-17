;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler
; Version 4.5.1 #15267 (Linux)
;--------------------------------------------------------
	.module enemy_bullet
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _active_enemybullet_index
	.globl _enemybullet_metasprites
	.globl _angle
	.globl _quadrant
	.globl _ACTIVE_ENEMYBULLET_POOL
	.globl _ENEMYBULLET_POOL
	.globl _enemybullet_bbox
	.globl _enemybullet_tile_offset
	.globl _dir16_vy
	.globl _dir16_vx
	.globl _init_enemy_bullets
	.globl _add_enemy_bullet
	.globl _aim_at_player
	.globl _handle_enemy_bullets
	.globl _kill_active_enemybullet
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _DATA
_ENEMYBULLET_POOL::
	.ds 128
_ACTIVE_ENEMYBULLET_POOL::
	.ds 16
_quadrant::
	.ds 1
_angle::
	.ds 1
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
___EMU_PROFILER_INIT:
	.ds 2
_enemybullet_metasprites::
	.ds 2
_active_enemybullet_index::
	.ds 1
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
;src/enemy_bullet.c:38: void init_enemy_bullets(void){
;	---------------------------------
; Function init_enemy_bullets
; ---------------------------------
_init_enemy_bullets::
;src/enemy_bullet.c:39: for (uint8_t i=0; i<MAX_ENEMYBULLETS; i++){
	ld	c, #0x00
00103$:
	ld	a, c
	sub	a, #0x10
	ret	NC
;src/enemy_bullet.c:40: ENEMYBULLET_POOL[i].isactive = 0;
	ld	l, c
	xor	a, a
	ld	h, a
	add	hl, hl
	add	hl, hl
	add	hl, hl
	ld	a, l
	add	a, #<(_ENEMYBULLET_POOL)
	ld	e, a
	ld	a, h
	adc	a, #>(_ENEMYBULLET_POOL)
	ld	d, a
	ld	hl, #0x0006
	add	hl, de
	ld	(hl), #0x00
;src/enemy_bullet.c:41: ENEMYBULLET_POOL[i].x = 0;
	xor	a, a
	ld	(de), a
;src/enemy_bullet.c:42: ENEMYBULLET_POOL[i].y = 0;
	ld	l, e
	ld	h, d
	inc	hl
	ld	(hl), #0x00
;src/enemy_bullet.c:43: ENEMYBULLET_POOL[i].dx = 0;
	ld	l, e
	ld	h, d
	inc	hl
	inc	hl
	ld	(hl), #0x00
;src/enemy_bullet.c:44: ENEMYBULLET_POOL[i].dy = 0;
	ld	l, e
	ld	h, d
	inc	hl
	inc	hl
	inc	hl
	ld	(hl), #0x00
;src/enemy_bullet.c:45: ENEMYBULLET_POOL[i].fx = 0;
	ld	hl, #0x0004
	add	hl, de
	ld	(hl), #0x00
;src/enemy_bullet.c:46: ENEMYBULLET_POOL[i].fy = 0;
	ld	hl, #0x0005
	add	hl, de
	ld	(hl), #0x00
;src/enemy_bullet.c:47: ENEMYBULLET_POOL[i].type = 0;
	ld	hl, #0x0007
	add	hl, de
	ld	(hl), #0x00
;src/enemy_bullet.c:48: ACTIVE_ENEMYBULLET_POOL[i] = 255;
	ld	hl, #_ACTIVE_ENEMYBULLET_POOL
	ld	b, #0x00
	add	hl, bc
	ld	(hl), #0xff
;src/enemy_bullet.c:39: for (uint8_t i=0; i<MAX_ENEMYBULLETS; i++){
	inc	c
;src/enemy_bullet.c:50: }
	jr	00103$
_dir16_vx:
	.db #0x10	;  16
	.db #0x0f	;  15
	.db #0x0b	;  11
	.db #0x06	;  6
	.db #0x00	;  0
	.db #0x10	;  16
	.db #0x0f	;  15
	.db #0x0b	;  11
	.db #0x06	;  6
	.db #0x00	;  0
	.db #0xf0	; -16
	.db #0xf1	; -15
	.db #0xf5	; -11
	.db #0xfa	; -6
	.db #0x00	;  0
	.db #0xf0	; -16
	.db #0xf1	; -15
	.db #0xf5	; -11
	.db #0xfa	; -6
	.db #0x00	;  0
_dir16_vy:
	.db #0x00	;  0
	.db #0xfa	; -6
	.db #0xf5	; -11
	.db #0xf1	; -15
	.db #0xf0	; -16
	.db #0x00	;  0
	.db #0x06	;  6
	.db #0x0b	;  11
	.db #0x0f	;  15
	.db #0x10	;  16
	.db #0x00	;  0
	.db #0xfa	; -6
	.db #0xf5	; -11
	.db #0xf1	; -15
	.db #0xf0	; -16
	.db #0x00	;  0
	.db #0x06	;  6
	.db #0x0b	;  11
	.db #0x0f	;  15
	.db #0x10	;  16
_enemybullet_tile_offset:
	.db #0x30	; 48	'0'
_enemybullet_bbox:
	.db #0xfe	; -2
	.db #0x02	;  2
	.db #0xfe	; -2
	.db #0x02	;  2
;src/enemy_bullet.c:52: void add_enemy_bullet(uint8_t x, uint8_t y, int8_t dx, int8_t dy, uint8_t type){
;	---------------------------------
; Function add_enemy_bullet
; ---------------------------------
_add_enemy_bullet::
	add	sp, #-8
	ldhl	sp,	#6
	ld	(hl-), a
	ld	(hl), e
;src/enemy_bullet.c:53: for (uint8_t i=0; i<MAX_ENEMYBULLETS; i++){
	ldhl	sp,	#2
	ld	(hl), #0x00
	ldhl	sp,	#7
	ld	(hl), #0x00
00105$:
	ldhl	sp,	#7
	ld	a, (hl)
	sub	a, #0x10
	jp	NC, 00107$
;src/enemy_bullet.c:54: if (!ENEMYBULLET_POOL[i].isactive){
	ld	a, (hl)
	ld	d, #0x00
	add	a, a
	rl	d
	add	a, a
	rl	d
	add	a, a
	rl	d
	ld	e, a
	ld	hl, #_ENEMYBULLET_POOL
	add	hl, de
	push	hl
	ld	a, l
	ldhl	sp,	#5
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#4
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
	jp	NZ, 00106$
;src/enemy_bullet.c:55: ENEMYBULLET_POOL[i].isactive = 1;
	ld	a, #0x01
	ld	(bc), a
;src/enemy_bullet.c:56: ENEMYBULLET_POOL[i].x = x;
	ldhl	sp,	#3
	ld	a, (hl+)
	ld	e, a
	ld	a, (hl+)
	inc	hl
	ld	d, a
;src/enemy_bullet.c:57: ENEMYBULLET_POOL[i].y = y;
	ld	a, (hl-)
	dec	hl
	dec	hl
	ld	(de), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	l, e
	ld	h, d
	inc	hl
	inc	sp
	inc	sp
	ld	e, l
	ld	d, h
	push	de
	ldhl	sp,	#5
;src/enemy_bullet.c:58: ENEMYBULLET_POOL[i].dx = dx;
	ld	a, (hl-)
	dec	hl
	ld	(de), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0002
	add	hl, de
	inc	sp
	inc	sp
	ld	e, l
	ld	d, h
	push	de
	ldhl	sp,	#10
	ld	a, (hl)
	ld	(de), a
;src/enemy_bullet.c:59: ENEMYBULLET_POOL[i].dy = dy;
	ldhl	sp,#3
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0003
	add	hl, de
	inc	sp
	inc	sp
	ld	e, l
	ld	d, h
	push	de
	ldhl	sp,	#11
	ld	a, (hl)
	ld	(de), a
;src/enemy_bullet.c:60: ENEMYBULLET_POOL[i].fx = 0;
	ldhl	sp,#3
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0004
	add	hl, de
	inc	sp
	inc	sp
	ld	(hl), #0x00
	push	hl
;src/enemy_bullet.c:61: ENEMYBULLET_POOL[i].fy = 0;
	ldhl	sp,#3
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0005
	add	hl, de
	inc	sp
	inc	sp
	ld	(hl), #0x00
	push	hl
;src/enemy_bullet.c:62: ENEMYBULLET_POOL[i].type = type;
	ldhl	sp,#3
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0007
	add	hl, de
	inc	sp
	inc	sp
	ld	e, l
	ld	d, h
	push	de
	ldhl	sp,	#12
	ld	a, (hl)
	ld	(de), a
;src/enemy_bullet.c:63: ACTIVE_ENEMYBULLET_POOL[active_enemybullet_index++] = i;
	ld	a, (_active_enemybullet_index)
	ld	e, a
	ld	hl, #_active_enemybullet_index
	inc	(hl)
	ld	d, #0x00
	ld	hl, #_ACTIVE_ENEMYBULLET_POOL
	add	hl, de
	push	hl
	ld	a, l
	ldhl	sp,	#5
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#4
	ld	(hl-), a
	ld	a, (hl+)
	ld	e, a
	ld	a, (hl-)
	dec	hl
	ld	d, a
	ld	a, (hl)
	ld	(de), a
;src/enemy_bullet.c:64: break;
	jr	00107$
00106$:
;src/enemy_bullet.c:53: for (uint8_t i=0; i<MAX_ENEMYBULLETS; i++){
	ldhl	sp,	#7
	inc	(hl)
	ld	a, (hl)
	ldhl	sp,	#2
	ld	(hl), a
	jp	00105$
00107$:
;src/enemy_bullet.c:67: }
	add	sp, #8
	pop	hl
	add	sp, #3
	jp	(hl)
;src/enemy_bullet.c:69: void aim_at_player(uint8_t x, uint8_t y){
;	---------------------------------
; Function aim_at_player
; ---------------------------------
_aim_at_player::
	ld	c, a
;src/enemy_bullet.c:72: if (PLAYER.px < x){
	ld	hl, #_PLAYER + 6
	ld	b, (hl)
	ld	a, b
	sub	a, c
	jr	NC, 00102$
;src/enemy_bullet.c:73: adx = x - (PLAYER.px);
	ld	a, c
	sub	a, b
	ld	c, a
;src/enemy_bullet.c:74: quadrant = 2;
	ld	hl, #_quadrant
	ld	(hl), #0x02
	jr	00103$
00102$:
;src/enemy_bullet.c:76: adx = (PLAYER.px) - x;
	ld	a, b
	sub	a, c
	ld	c, a
;src/enemy_bullet.c:77: quadrant = 0;
	xor	a, a
	ld	(#_quadrant),a
00103$:
;src/enemy_bullet.c:79: if (PLAYER.py > y){
	ld	hl, #_PLAYER + 7
	ld	b, (hl)
	ld	a, e
	sub	a, b
	jr	NC, 00105$
;src/enemy_bullet.c:80: ady = (PLAYER.py) - y;
	ld	a, b
	sub	a, e
	ld	b, a
;src/enemy_bullet.c:81: quadrant |= 1;
	ld	hl, #_quadrant
	ld	a, (hl)
	or	a, #0x01
	ld	(hl), a
	jr	00106$
00105$:
;src/enemy_bullet.c:83: ady = y - (PLAYER.py);
	ld	a, e
	sub	a, b
	ld	b, a
00106$:
;src/enemy_bullet.c:88: if (adx >= ady){
;src/enemy_bullet.c:89: temp = adx-ady;
	ld	a,c
	cp	a,b
	jr	C, 00120$
	sub	a, b
	ld	c, a
;src/enemy_bullet.c:90: if ( temp>>2 > ady){
	ld	e, c
	srl	e
	srl	e
	ld	a, b
	sub	a, e
	jr	NC, 00111$
;src/enemy_bullet.c:91: angle = 0; //Horizontal
	xor	a, a
	ld	(#_angle),a
	ret
00111$:
;src/enemy_bullet.c:92: } else if (temp>>1 > ady>>1){
	srl	c
	srl	b
	ld	a, b
	sub	a, c
	jr	NC, 00108$
;src/enemy_bullet.c:93: angle = 1; //Petit angle
	ld	hl, #_angle
	ld	(hl), #0x01
	ret
00108$:
;src/enemy_bullet.c:95: angle = 2; //Moyen angle
	ld	hl, #_angle
	ld	(hl), #0x02
	ret
00120$:
;src/enemy_bullet.c:98: temp = ady-adx;
	ld	a, b
	sub	a, c
	ld	b, a
;src/enemy_bullet.c:99: if ( temp>>2 > adx){
	ld	e, b
	srl	e
	srl	e
	ld	a, c
	sub	a, e
	jr	NC, 00117$
;src/enemy_bullet.c:100: angle = 4; //Vertical
	ld	hl, #_angle
	ld	(hl), #0x04
	ret
00117$:
;src/enemy_bullet.c:101: } else if (temp>>1 > adx>>1){
	srl	b
	srl	c
	ld	a, c
	sub	a, b
	jr	NC, 00114$
;src/enemy_bullet.c:102: angle = 3; //Grand angle
	ld	hl, #_angle
	ld	(hl), #0x03
	ret
00114$:
;src/enemy_bullet.c:104: angle = 2; //Moyen angle
	ld	hl, #_angle
	ld	(hl), #0x02
;src/enemy_bullet.c:107: }
	ret
;src/enemy_bullet.c:109: void handle_enemy_bullets(void){
;	---------------------------------
; Function handle_enemy_bullets
; ---------------------------------
_handle_enemy_bullets::
	add	sp, #-7
;src/enemy_bullet.c:110: for (uint8_t j=0; j<active_enemybullet_index; j++){
	ldhl	sp,	#6
	ld	(hl), #0x00
00111$:
	ldhl	sp,	#6
	ld	a, (hl)
	ld	hl, #_active_enemybullet_index
	sub	a, (hl)
	jp	NC, 00113$
;src/enemy_bullet.c:111: uint8_t i = ACTIVE_ENEMYBULLET_POOL[j];
	ld	de, #_ACTIVE_ENEMYBULLET_POOL
	ldhl	sp,	#6
	ld	l, (hl)
	ld	h, #0x00
	add	hl, de
	ld	c, l
	ld	b, h
	ld	a, (bc)
;src/enemy_bullet.c:113: ENEMYBULLET_POOL[i].x += ENEMYBULLET_POOL[i].dx;
	ld	l, a
	ld	h, #0x00
	add	hl, hl
	add	hl, hl
	add	hl, hl
	ld	bc, #_ENEMYBULLET_POOL
	add	hl, bc
	push	hl
	ld	a, l
	ldhl	sp,	#4
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#3
	ld	(hl-), a
	ld	a, (hl-)
	dec	hl
	ld	(hl), a
	ldhl	sp,	#3
	ld	a, (hl-)
	dec	hl
	ld	(hl+), a
	pop	de
	push	de
	ld	a, (de)
	ld	e, (hl)
	inc	hl
	ld	h, (hl)
	ld	l, e
	inc	hl
	inc	hl
	ld	c, (hl)
	add	a, c
	pop	hl
	push	hl
	ld	(hl), a
;src/enemy_bullet.c:115: ENEMYBULLET_POOL[i].y += ENEMYBULLET_POOL[i].dy;
	ldhl	sp,#2
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	l, e
	ld	h, d
	inc	hl
	push	hl
	ld	a, l
	ldhl	sp,	#6
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#5
	ld	(hl-), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ld	c, a
	ldhl	sp,	#2
	ld	a, (hl+)
	ld	e, a
	ld	a, (hl+)
	ld	d, a
	inc	de
	inc	de
	inc	de
	ld	a, (de)
	add	a, c
	ld	e, (hl)
	inc	hl
	ld	h, (hl)
	ld	l, e
	ld	(hl), a
;src/enemy_bullet.c:113: ENEMYBULLET_POOL[i].x += ENEMYBULLET_POOL[i].dx;
	pop	de
	push	de
	ld	a, (de)
;src/enemy_bullet.c:117: if(ENEMYBULLET_POOL[i].x < GAMESCREEN_X_ORIGIN ||
	cp	a, #0x08
	jr	C, 00101$
;src/enemy_bullet.c:118: ENEMYBULLET_POOL[i].x > GAMESCREEN_X_END ||
	cp	a, #0xa9
	jr	NC, 00101$
;src/enemy_bullet.c:115: ENEMYBULLET_POOL[i].y += ENEMYBULLET_POOL[i].dy;
	ldhl	sp,#4
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
;src/enemy_bullet.c:119: ENEMYBULLET_POOL[i].y < GAMESCREEN_Y_ORIGIN ||
	cp	a, #0x10
	jr	C, 00101$
;src/enemy_bullet.c:120: ENEMYBULLET_POOL[i].y > GAMESCREEN_Y_END ){
	cp	a, #0x91
	jr	C, 00102$
00101$:
;src/enemy_bullet.c:121: kill_active_enemybullet(j);
	ldhl	sp,	#6
	ld	a, (hl)
	call	_kill_active_enemybullet
00102$:
;src/enemy_bullet.c:124: if (ENEMYBULLET_POOL[i].isactive){
	ldhl	sp,#2
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0006
	add	hl, de
	ld	c, l
	ld	b, h
	ld	a, (bc)
	or	a, a
	jr	Z, 00112$
;src/enemy_bullet.c:130: ENEMYBULLET_POOL[i].x, ENEMYBULLET_POOL[i].y);
	ldhl	sp,#4
	ld	a, (hl+)
	ld	e, a
	ld	a, (hl-)
	ld	d, a
	ld	a, (de)
	ld	c, a
	pop	de
	push	de
	ld	a, (de)
	ld	(hl), a
	ld	a, (#_oam)
	ldhl	sp,	#5
;src/enemy_bullet.c:128: enemybullet_tile_offset[ENEMYBULLET_POOL[i].type],
	ld	(hl-), a
	dec	hl
	dec	hl
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0007
	add	hl, de
	ld	e, l
	ld	d, h
	ld	a, (de)
	ld	e, a
	ld	hl, #_enemybullet_tile_offset
	ld	d, #0x00
	add	hl, de
	ld	a, (hl)
	ld	(#___current_base_tile),a
;src/enemy_bullet.c:127: enemybullet_metasprites[ENEMYBULLET_POOL[i].type][0],
	xor	a, a
	ld	l, e
	ld	h, a
	add	hl, hl
	ld	de, #_enemybullet_metasprites
	add	hl, de
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	ld	a,	(hl+)
	ld	h, (hl)
;/home/meloni/Lib/gbdk/include/gb/metasprites.h:160: __current_metasprite = metasprite;
	ld	e, a
	ld	d, h
	ld	hl, #___current_metasprite
	ld	a, e
	ld	(hl+), a
	ld	(hl), d
;/home/meloni/Lib/gbdk/include/gb/metasprites.h:162: __current_base_prop = base_prop;
	xor	a, a
	ld	(#___current_base_prop),a
;/home/meloni/Lib/gbdk/include/gb/metasprites.h:163: return __move_metasprite(base_sprite, (y << 8) | (uint8_t)x);
	ld	b, c
	ldhl	sp,	#4
	ld	a, (hl+)
	ld	e, a
	ld	d, b
	ld	a, (hl)
	call	___move_metasprite
;src/enemy_bullet.c:130: ENEMYBULLET_POOL[i].x, ENEMYBULLET_POOL[i].y);
	ld	hl, #_oam
	add	a, (hl)
	ld	(hl), a
00112$:
;src/enemy_bullet.c:110: for (uint8_t j=0; j<active_enemybullet_index; j++){
	ldhl	sp,	#6
	inc	(hl)
	jp	00111$
00113$:
;src/enemy_bullet.c:134: }
	add	sp, #7
	ret
;src/enemy_bullet.c:137: void kill_active_enemybullet(uint8_t j){
;	---------------------------------
; Function kill_active_enemybullet
; ---------------------------------
_kill_active_enemybullet::
	add	sp, #-3
	ld	c, a
;src/enemy_bullet.c:138: uint8_t i = ACTIVE_ENEMYBULLET_POOL[j];
	ld	hl, #_ACTIVE_ENEMYBULLET_POOL
	ld	b, #0x00
	add	hl, bc
;src/enemy_bullet.c:139: ENEMYBULLET_POOL[i].isactive = 0;
	ld	l, (hl)
	ld	de, #_ENEMYBULLET_POOL+0
	ld	h, #0x00
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, de
	ld	de, #0x0006
	add	hl, de
	ld	(hl), #0x00
;src/enemy_bullet.c:141: for (uint8_t k=j; k<active_enemybullet_index-1; k++){
	ldhl	sp,	#2
	ld	(hl), c
00103$:
	ld	a, (_active_enemybullet_index)
	ld	c, a
	ld	b, #0x00
	dec	bc
	ldhl	sp,	#2
	ld	a, (hl-)
	dec	hl
	ld	(hl+), a
	xor	a, a
	ld	(hl-), a
	ld	a, (hl+)
	sub	a, c
	ld	a, (hl)
	sbc	a, b
	ld	d, (hl)
	ld	a, b
	bit	7,a
	jr	Z, 00122$
	bit	7, d
	jr	NZ, 00123$
	cp	a, a
	jr	00123$
00122$:
	bit	7, d
	jr	Z, 00123$
	scf
00123$:
	jr	NC, 00101$
;src/enemy_bullet.c:142: ACTIVE_ENEMYBULLET_POOL[k] = ACTIVE_ENEMYBULLET_POOL[k+1];
	ld	de, #_ACTIVE_ENEMYBULLET_POOL
	ldhl	sp,	#2
	ld	l, (hl)
	ld	h, #0x00
	add	hl, de
	ld	c, l
	ld	b, h
	ldhl	sp,	#2
	ld	a, (hl)
	inc	a
	ld	e, a
	rlca
	sbc	a, a
	ld	d, a
	ld	hl, #_ACTIVE_ENEMYBULLET_POOL
	add	hl, de
	ld	a, (hl)
	ld	(bc), a
;src/enemy_bullet.c:141: for (uint8_t k=j; k<active_enemybullet_index-1; k++){
	ldhl	sp,	#2
	inc	(hl)
	jr	00103$
00101$:
;src/enemy_bullet.c:144: active_enemybullet_index--;
	ld	hl, #_active_enemybullet_index
	dec	(hl)
;src/enemy_bullet.c:145: }
	add	sp, #3
	ret
	.area _CODE
	.area _INITIALIZER
__xinit____EMU_PROFILER_INIT:
	.dw _EMU_profiler_message
__xinit__enemybullet_metasprites:
	.dw _enemybullet_sprite_metasprites
__xinit__active_enemybullet_index:
	.db #0x00	; 0
	.area _CABS (ABS)
