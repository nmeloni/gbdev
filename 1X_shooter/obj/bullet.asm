;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler
; Version 4.5.1 #15267 (Linux)
;--------------------------------------------------------
	.module bullet
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _active_bullet_index
	.globl _ACTIVE_BULLETS
	.globl _BULLETS
	.globl _init_bullets
	.globl _handle_bullets
	.globl _kill_active_bullet
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _DATA
_BULLETS::
	.ds 28
_ACTIVE_BULLETS::
	.ds 4
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
___EMU_PROFILER_INIT:
	.ds 2
_active_bullet_index::
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
;src/bullet.c:8: void init_bullets(void){
;	---------------------------------
; Function init_bullets
; ---------------------------------
_init_bullets::
;src/bullet.c:9: for (uint8_t i=0; i<MAX_BULLETS; i++){
	ld	c, #0x00
00103$:
	ld	a, c
	sub	a, #0x04
	ret	NC
;src/bullet.c:10: BULLETS[i].isactive = 0;
	ld	b, #0x00
	ld	l, c
	ld	h, b
	add	hl, hl
	add	hl, bc
	add	hl, hl
	add	hl, bc
	ld	a, l
	add	a, #<(_BULLETS)
	ld	e, a
	ld	a, h
	adc	a, #>(_BULLETS)
	ld	d, a
	ld	hl, #0x0006
	add	hl, de
	ld	(hl), #0x00
;src/bullet.c:11: BULLETS[i].x = 0;
	ld	l, e
	ld	h, d
	xor	a, a
	ld	(hl+), a
	ld	(hl), a
;src/bullet.c:12: BULLETS[i].y = 0;
	ld	l, e
	ld	h, d
	inc	hl
	inc	hl
	xor	a, a
	ld	(hl+), a
	ld	(hl), a
;src/bullet.c:13: BULLETS[i].px = 0;
	ld	hl, #0x0004
	add	hl, de
	ld	(hl), #0x00
;src/bullet.c:14: BULLETS[i].py = 0;
	ld	hl, #0x0005
	add	hl, de
	ld	(hl), #0x00
;src/bullet.c:9: for (uint8_t i=0; i<MAX_BULLETS; i++){
	inc	c
;src/bullet.c:16: }
	jr	00103$
;src/bullet.c:18: void handle_bullets(void){
;	---------------------------------
; Function handle_bullets
; ---------------------------------
_handle_bullets::
	add	sp, #-16
;src/bullet.c:20: for (uint8_t j=0; j<active_bullet_index; j++){
	ld	c, #0x00
00119$:
	ld	a, c
	ld	hl, #_active_bullet_index
	sub	a, (hl)
	jp	NC, 00121$
;src/bullet.c:21: uint8_t i = ACTIVE_BULLETS[j];
	ld	hl, #_ACTIVE_BULLETS
	ld	b, #0x00
	add	hl, bc
;src/bullet.c:23: if ( BULLETS[i].y > BULLET_SPEED){
	ld	e, (hl)
	ld	d, #0x00
	ld	l, e
	ld	h, d
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	push	hl
	ld	a, l
	ldhl	sp,	#16
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#15
	ld	(hl), a
	ld	de, #_BULLETS
	ld	a, (hl-)
	ld	l, (hl)
	ld	h, a
	add	hl, de
	inc	sp
	inc	sp
	ld	e, l
	ld	d, h
	push	de
	ld	hl, #0x0002
	add	hl, de
	push	hl
	ld	a, l
	ldhl	sp,	#14
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#13
	ld	(hl-), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ld	b, a
	inc	de
	ld	a, (de)
	ld	e, b
	ld	d, a
;src/bullet.c:25: BULLETS[i].py = BULLETS[i].y>>8;
	push	de
	ldhl	sp,#2
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0005
	add	hl, de
	pop	de
	push	hl
	ld	a, l
	ldhl	sp,	#4
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#3
	ld	(hl), a
;src/bullet.c:23: if ( BULLETS[i].y > BULLET_SPEED){
	xor	a, a
	cp	a, e
	ld	a, #0x03
	sbc	a, d
	jp	NC, 00109$
;src/bullet.c:24: BULLETS[i].y -= BULLET_SPEED;
	ld	b, e
	ld	a,d
	add	a,#0xfd
	ldhl	sp,	#14
	ld	(hl), b
	inc	hl
	ld	(hl), a
	ldhl	sp,	#12
	ld	a, (hl+)
	ld	e, a
	ld	a, (hl+)
	ld	d, a
	ld	a, (hl+)
	ld	(de), a
	inc	de
	ld	a, (hl)
	ld	(de), a
;src/bullet.c:25: BULLETS[i].py = BULLETS[i].y>>8;
	ld	a, (hl)
	ldhl	sp,	#2
	ld	e, (hl)
	inc	hl
	ld	h, (hl)
	ld	l, e
	ld	(hl), a
;src/bullet.c:28: for (uint8_t l=0; l<active_ennemies_index; l++){
	ldhl	sp,	#0
	ld	a, (hl)
	ldhl	sp,	#4
	ld	(hl), a
	ldhl	sp,	#1
	ld	a, (hl)
	ldhl	sp,	#5
	ld	(hl), a
	ldhl	sp,	#2
	ld	a, (hl)
	ldhl	sp,	#6
	ld	(hl), a
	ldhl	sp,	#3
	ld	a, (hl)
	ldhl	sp,	#7
	ld	(hl), a
	ld	b, #0x00
00116$:
	ld	a, b
	ld	hl, #_active_ennemies_index
	sub	a, (hl)
	jp	NC, 00110$
;src/bullet.c:29: k = ACTIVE_ENNEMIES[l];
	ld	a, #<(_ACTIVE_ENNEMIES)
	add	a, b
	ld	l, a
	ld	a, #>(_ACTIVE_ENNEMIES)
	adc	a, #0x00
	ld	h, a
;src/bullet.c:30: if ( ((ENNEMIES[k].py) < (BULLETS[i].py)+8) &&
	ld	e, (hl)
	ld	d, #0x00
	ld	l, e
	ld	h, d
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, de
	push	hl
	ld	a, l
	ldhl	sp,	#16
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#15
	ld	(hl), a
	ld	de, #_ENNEMIES
	ld	a, (hl-)
	ld	l, (hl)
	ld	h, a
	add	hl, de
	push	hl
	ld	a, l
	ldhl	sp,	#10
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#9
	ld	(hl-), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0009
	add	hl, de
	ld	e, l
	ld	d, h
	ld	a, (de)
	ldhl	sp,	#15
	ld	(hl), a
	ldhl	sp,#6
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ldhl	sp,	#10
	ld	(hl+), a
	xor	a, a
	ld	(hl-), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0008
	add	hl, de
	push	hl
	ld	a, l
	ldhl	sp,	#14
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#13
	ld	(hl+), a
	inc	hl
	ld	a, (hl-)
	ld	(hl+), a
	ld	(hl), #0x00
	ldhl	sp,	#14
	ld	e, l
	ld	d, h
	ldhl	sp,	#12
	ld	a, (de)
	inc	de
	sub	a, (hl)
	inc	hl
	ld	a, (de)
	sbc	a, (hl)
	jp	NC, 00117$
;src/bullet.c:31: ((ENNEMIES[k].py) > (BULLETS[i].py)-8) )
	ldhl	sp,#10
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0008
	ld	a, e
	sub	a, l
	ld	e, a
	ld	a, d
	sbc	a, h
	ldhl	sp,	#13
	ld	(hl-), a
	ld	(hl), e
	ldhl	sp,	#12
	ld	e, l
	ld	d, h
	ldhl	sp,	#14
	ld	a, (de)
	inc	de
	sub	a, (hl)
	inc	hl
	ld	a, (de)
	sbc	a, (hl)
	ld	a, (de)
	ld	d, a
	bit	7, (hl)
	jr	Z, 00195$
	bit	7, d
	jr	NZ, 00196$
	cp	a, a
	jr	00196$
00195$:
	bit	7, d
	jr	Z, 00196$
	scf
00196$:
	jp	NC, 00117$
;src/bullet.c:32: if ( ((ENNEMIES[k].px) < (BULLETS[i].px)+8) &&
	ldhl	sp,#8
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0008
	add	hl, de
	ld	e, l
	ld	d, h
	ld	a, (de)
	ldhl	sp,	#15
	ld	(hl), a
	ldhl	sp,#4
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0004
	add	hl, de
	ld	e, l
	ld	d, h
	ld	a, (de)
	ldhl	sp,	#10
	ld	(hl+), a
	xor	a, a
	ld	(hl-), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0008
	add	hl, de
	push	hl
	ld	a, l
	ldhl	sp,	#14
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#13
	ld	(hl+), a
	inc	hl
	ld	a, (hl-)
	ld	(hl+), a
	ld	(hl), #0x00
	ldhl	sp,	#14
	ld	e, l
	ld	d, h
	ldhl	sp,	#12
	ld	a, (de)
	inc	de
	sub	a, (hl)
	inc	hl
	ld	a, (de)
	sbc	a, (hl)
	jr	NC, 00117$
;src/bullet.c:33: ((ENNEMIES[k].px) > (BULLETS[i].px)-8)){
	ldhl	sp,#10
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0008
	ld	a, e
	sub	a, l
	ld	e, a
	ld	a, d
	sbc	a, h
	ldhl	sp,	#13
	ld	(hl-), a
	ld	(hl), e
	ldhl	sp,	#12
	ld	e, l
	ld	d, h
	ldhl	sp,	#14
	ld	a, (de)
	inc	de
	sub	a, (hl)
	inc	hl
	ld	a, (de)
	sbc	a, (hl)
	ld	a, (de)
	ld	d, a
	bit	7, (hl)
	jr	Z, 00197$
	bit	7, d
	jr	NZ, 00198$
	cp	a, a
	jr	00198$
00197$:
	bit	7, d
	jr	Z, 00198$
	scf
00198$:
	jr	NC, 00117$
;src/bullet.c:35: ENNEMIES[k].hp -= PLAYER.power;
	ldhl	sp,#8
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x000e
	add	hl, de
	push	hl
	ld	a, l
	ldhl	sp,	#16
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#15
	ld	(hl-), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ld	hl, #(_PLAYER + 8)
	ld	l, (hl)
	sub	a, l
	ldhl	sp,	#14
	ld	e, (hl)
	inc	hl
	ld	h, (hl)
	ld	l, e
	ld	(hl), a
;src/bullet.c:36: ENNEMIES[k].ishit = 4;
	ldhl	sp,#8
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x000f
	add	hl, de
	ld	(hl), #0x04
;src/bullet.c:37: kill_active_bullet(j);
	push	bc
	ld	a, c
	call	_kill_active_bullet
	pop	bc
00117$:
;src/bullet.c:28: for (uint8_t l=0; l<active_ennemies_index; l++){
	inc	b
	jp	00116$
00109$:
;src/bullet.c:41: kill_active_bullet(j);
	push	bc
	ld	a, c
	call	_kill_active_bullet
	pop	bc
00110$:
;src/bullet.c:44: if (BULLETS[i].isactive){
	pop	de
	push	de
	ld	hl, #0x0006
	add	hl, de
	ld	e, l
	ld	d, h
	ld	a, (de)
	or	a, a
	jr	Z, 00120$
;src/bullet.c:47: BULLETS[i].px, BULLETS[i].py);
	ldhl	sp,#2
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	a, (de)
	ld	b, a
	pop	de
	push	de
	ld	hl, #0x0004
	add	hl, de
	ld	e, l
	ld	d, h
	ld	a, (de)
	ldhl	sp,	#14
	ld	(hl), a
	ld	a, (#_oam)
	ldhl	sp,	#15
	ld	(hl), a
;src/bullet.c:46: PLAYER.bullet_sprite_offset,0,oam,
	ld	a, (#(_PLAYER + 18) + 0)
	ld	(#___current_base_tile),a
;src/bullet.c:45: oam+=move_metasprite_ex(PLAYER.bullet_metasprites[0],
	ld	hl, #(_PLAYER + 16)
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	ld	a, (hl+)
	ld	l, (hl)
;/home/meloni/Lib/gbdk/include/gb/metasprites.h:160: __current_metasprite = metasprite;
	ld	e, a
	ld	d, l
	ld	hl, #___current_metasprite
	ld	a, e
	ld	(hl+), a
	ld	(hl), d
;/home/meloni/Lib/gbdk/include/gb/metasprites.h:162: __current_base_prop = base_prop;
	xor	a, a
	ld	(#___current_base_prop),a
;/home/meloni/Lib/gbdk/include/gb/metasprites.h:163: return __move_metasprite(base_sprite, (y << 8) | (uint8_t)x);
	ldhl	sp,	#14
	ld	a, (hl+)
	ld	e, a
	ld	d, b
	push	bc
	ld	a, (hl)
	call	___move_metasprite
	pop	bc
;src/bullet.c:47: BULLETS[i].px, BULLETS[i].py);
	ld	hl, #_oam
	add	a, (hl)
	ld	(hl), a
00120$:
;src/bullet.c:20: for (uint8_t j=0; j<active_bullet_index; j++){
	inc	c
	jp	00119$
00121$:
;src/bullet.c:50: }
	add	sp, #16
	ret
;src/bullet.c:53: void kill_active_bullet(uint8_t j){
;	---------------------------------
; Function kill_active_bullet
; ---------------------------------
_kill_active_bullet::
	ld	c, a
;src/bullet.c:54: BULLETS[ACTIVE_BULLETS[j]].isactive = 0;
	ld	hl, #_ACTIVE_BULLETS
	ld	b, #0x00
	add	hl, bc
	ld	e, (hl)
	ld	d, #0x00
	ld	l, e
	ld	h, d
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	ld	de, #_BULLETS
	add	hl, de
	ld	de, #0x0006
	add	hl, de
	ld	(hl), #0x00
;src/bullet.c:55: for (uint8_t i=j; i<active_bullet_index; i++){
00103$:
	ld	a, c
	ld	hl, #_active_bullet_index
	sub	a, (hl)
	jr	NC, 00101$
;src/bullet.c:56: ACTIVE_BULLETS[i] = ACTIVE_BULLETS[i+1];
	ld	hl, #_ACTIVE_BULLETS
	ld	b, #0x00
	add	hl, bc
	ld	a, c
	inc	a
	ld	b, a
	rlca
	sbc	a, a
	ld	d, a
	ld	a, b
	add	a, #<(_ACTIVE_BULLETS)
	ld	e, a
	ld	a, d
	adc	a, #>(_ACTIVE_BULLETS)
	ld	d, a
	ld	a, (de)
	ld	(hl), a
;src/bullet.c:55: for (uint8_t i=j; i<active_bullet_index; i++){
	inc	c
	jr	00103$
00101$:
;src/bullet.c:58: active_bullet_index--;
	ld	hl, #_active_bullet_index
	dec	(hl)
;src/bullet.c:59: }
	ret
	.area _CODE
	.area _INITIALIZER
__xinit____EMU_PROFILER_INIT:
	.dw _EMU_profiler_message
__xinit__active_bullet_index:
	.db #0x00	; 0
	.area _CABS (ABS)
