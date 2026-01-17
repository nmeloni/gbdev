;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler
; Version 4.5.1 #15267 (Linux)
;--------------------------------------------------------
	.module ennemy
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _active_ennemies_index
	.globl _ennemy_metasprites
	.globl _ACTIVE_ENNEMIES
	.globl _ENNEMIES
	.globl _ennemy_pattern
	.globl _ennemy_bbox
	.globl _ennemy_tile_offset
	.globl _init_enemies
	.globl _add_ennemy
	.globl _handle_ennemies
	.globl _kill_active_ennemy
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _DATA
_ENNEMIES::
	.ds 136
_ACTIVE_ENNEMIES::
	.ds 8
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
___EMU_PROFILER_INIT:
	.ds 2
_ennemy_metasprites::
	.ds 6
_active_ennemies_index::
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
;src/ennemy.c:46: void init_enemies(void){
;	---------------------------------
; Function init_enemies
; ---------------------------------
_init_enemies::
;src/ennemy.c:47: for (uint8_t i=0; i<MAX_ENNEMY; i++){
	ld	c, #0x00
00103$:
	ld	a, c
	sub	a, #0x08
	ret	NC
;src/ennemy.c:48: ENNEMIES[i].isactive = 0;
	ld	b, #0x00
	ld	l, c
	ld	h, b
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, bc
	ld	a, l
	add	a, #<(_ENNEMIES)
	ld	e, a
	ld	a, h
	adc	a, #>(_ENNEMIES)
	ld	d, a
	ld	hl, #0x0010
	add	hl, de
	ld	(hl), #0x00
;src/ennemy.c:49: ENNEMIES[i].x = 0;
	ld	l, e
	ld	h, d
	xor	a, a
	ld	(hl+), a
	ld	(hl), a
;src/ennemy.c:50: ENNEMIES[i].y = 0;
	ld	l, e
	ld	h, d
	inc	hl
	inc	hl
	xor	a, a
	ld	(hl+), a
	ld	(hl), a
;src/ennemy.c:51: ENNEMIES[i].dx = 0;
	ld	hl, #0x0004
	add	hl, de
	xor	a, a
	ld	(hl+), a
	ld	(hl), a
;src/ennemy.c:52: ENNEMIES[i].dy = 0;
	ld	hl, #0x0006
	add	hl, de
	xor	a, a
	ld	(hl+), a
	ld	(hl), a
;src/ennemy.c:53: ENNEMIES[i].framecount = 0;
	ld	hl, #0x000a
	add	hl, de
	ld	(hl), #0x00
;src/ennemy.c:54: ENNEMIES[i].activepattern = 0;
	ld	hl, #0x000b
	add	hl, de
	ld	(hl), #0x00
;src/ennemy.c:55: ENNEMIES[i].type = ENNEMY_1;
	ld	hl, #0x000c
	add	hl, de
	ld	(hl), #0x00
;src/ennemy.c:56: ENNEMIES[i].ishit = 0;
	ld	hl, #0x000f
	add	hl, de
	ld	(hl), #0x00
;src/ennemy.c:58: ACTIVE_ENNEMIES[i]=255;
	ld	hl, #_ACTIVE_ENNEMIES
	ld	b, #0x00
	add	hl, bc
	ld	(hl), #0xff
;src/ennemy.c:47: for (uint8_t i=0; i<MAX_ENNEMY; i++){
	inc	c
;src/ennemy.c:60: }
	jr	00103$
_ennemy_tile_offset:
	.db #0x40	; 64
	.db #0x44	; 68	'D'
	.db #0x48	; 72	'H'
_ennemy_bbox:
	.db #0xf6	; -10
	.db #0x0a	;  10
	.db #0xf6	; -10
	.db #0x0a	;  10
	.db #0xf6	; -10
	.db #0x0a	;  10
	.db #0xf6	; -10
	.db #0x0a	;  10
	.db #0xf6	; -10
	.db #0x0a	;  10
	.db #0xf6	; -10
	.db #0x0a	;  10
_ennemy_pattern:
	.db #0xfc	; -4
	.db #0x01	;  1
	.db #0x14	;  20
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0xfd	; -3
	.db #0x01	;  1
	.db #0x14	;  20
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0xff	; -1
	.db #0x01	;  1
	.db #0x14	;  20
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x01	;  1
	.db #0x14	;  20
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x01	;  1
	.db #0x01	;  1
	.db #0x14	;  20
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x03	;  3
	.db #0x01	;  1
	.db #0x14	;  20
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x04	;  4
	.db #0x01	;  1
	.db #0x09	;  9
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x04	;  4
	.db #0x01	;  1
	.db #0x01	;  1
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x04	;  4
	.db #0x01	;  1
	.db #0x01	;  1
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x04	;  4
	.db #0x01	;  1
	.db #0x01	;  1
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x04	;  4
	.db #0x01	;  1
	.db #0x08	;  8
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x03	;  3
	.db #0x01	;  1
	.db #0x14	;  20
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x01	;  1
	.db #0x01	;  1
	.db #0x14	;  20
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x01	;  1
	.db #0x14	;  20
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0xff	; -1
	.db #0x01	;  1
	.db #0x14	;  20
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0xfd	; -3
	.db #0x01	;  1
	.db #0x14	;  20
	.db #0x00	;  0
	.db #0x00	;  0
;src/ennemy.c:62: void add_ennemy(uint8_t x, uint8_t y, uint8_t type, uint8_t pattern, uint16_t speed, int8_t hp){
;	---------------------------------
; Function add_ennemy
; ---------------------------------
_add_ennemy::
	add	sp, #-7
	ldhl	sp,	#6
	ld	(hl-), a
	ld	(hl), e
;src/ennemy.c:64: for (i=0; i<MAX_ENNEMY; i++) {
	ldhl	sp,	#2
	xor	a, a
	ld	(hl+), a
	inc	hl
	ld	(hl), #0x00
00104$:
;src/ennemy.c:65: if (!ENNEMIES[i].isactive){
	ldhl	sp,	#4
	ld	c, (hl)
	ld	b, #0x00
	ld	l, c
	ld	h, b
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, bc
	ld	bc, #_ENNEMIES
	add	hl, bc
	ld	c, l
	ld	b, h
	ld	hl, #0x0010
	add	hl, bc
	ld	a, (hl)
	or	a, a
	jp	NZ, 00105$
;src/ennemy.c:66: ENNEMIES[i].isactive = 1;
	ld	(hl), #0x01
;src/ennemy.c:67: ENNEMIES[i].x = x<<8;
	inc	sp
	inc	sp
	push	bc
	ldhl	sp,	#6
	ld	e, (hl)
	xor	a, a
	ldhl	sp,	#3
	ld	(hl+), a
	ld	(hl), e
	pop	de
	push	de
	xor	a, a
	ld	(de), a
	inc	de
;src/ennemy.c:68: ENNEMIES[i].y = y<<8;
	ld	a, (hl+)
	ld	(de), a
	ld	e, c
	ld	d, b
	inc	de
	inc	de
	ld	a, (hl-)
	dec	hl
	ld	(hl+), a
	xor	a, a
	ld	(hl-), a
	ld	a, (hl+)
	ld	(hl-), a
	xor	a, a
	ld	(hl+), a
	ld	(de), a
	inc	de
	ld	a, (hl)
	ld	(de), a
;src/ennemy.c:69: ENNEMIES[i].dx = speed;
	ld	hl, #0x0004
	add	hl, bc
	ld	e, l
	ld	d, h
	ldhl	sp,	#11
	ld	a, (hl+)
	ld	(de), a
	inc	de
	ld	a, (hl)
	ld	(de), a
;src/ennemy.c:70: ENNEMIES[i].dy = speed;
	ld	hl, #0x0006
	add	hl, bc
	ld	e, l
	ld	d, h
	ldhl	sp,	#11
	ld	a, (hl+)
	ld	(de), a
	inc	de
	ld	a, (hl)
	ld	(de), a
;src/ennemy.c:71: ENNEMIES[i].px = x;
	ld	hl, #0x0008
	add	hl, bc
	ld	e, l
	ld	d, h
	ldhl	sp,	#6
	ld	a, (hl)
	ld	(de), a
;src/ennemy.c:72: ENNEMIES[i].py = y;
	ld	hl, #0x0009
	add	hl, bc
	ld	e, l
	ld	d, h
	ldhl	sp,	#5
	ld	a, (hl)
	ld	(de), a
;src/ennemy.c:73: ENNEMIES[i].hp = hp;
	ld	hl, #0x000e
	add	hl, bc
	ld	e, l
	ld	d, h
	ldhl	sp,	#13
	ld	a, (hl)
	ld	(de), a
;src/ennemy.c:74: ENNEMIES[i].pattern = pattern;
	ld	hl, #0x000d
	add	hl, bc
	ld	e, l
	ld	d, h
	ldhl	sp,	#10
	ld	a, (hl)
	ld	(de), a
;src/ennemy.c:75: ENNEMIES[i].activepattern = 0;
	ld	hl, #0x000b
	add	hl, bc
	ld	(hl), #0x00
;src/ennemy.c:76: ENNEMIES[i].type = type;
	ld	hl, #0x000c
	add	hl, bc
	ld	e, l
	ld	d, h
	ldhl	sp,	#9
	ld	a, (hl)
	ld	(de), a
;src/ennemy.c:77: ENNEMIES[i].framecount = ennemy_pattern[pattern][0][2];
	ld	hl, #0x000a
	add	hl, bc
	ld	c, l
	ld	b, h
	ldhl	sp,	#10
	ld	e, (hl)
	ld	d, #0x00
	ld	l, e
	ld	h, d
	add	hl, hl
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
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
	ld	hl,#_ennemy_pattern + 1
	add	hl,de
	inc	hl
	ld	e, l
	ld	d, h
	ld	a, (de)
	ld	(bc), a
;src/ennemy.c:79: ACTIVE_ENNEMIES[active_ennemies_index++] = i;
	ld	a, (_active_ennemies_index)
	ld	c, a
	ld	hl, #_active_ennemies_index
	inc	(hl)
	ld	a, c
	add	a, #<(_ACTIVE_ENNEMIES)
	ld	c, a
	ld	a, #0x00
	adc	a, #>(_ACTIVE_ENNEMIES)
	ld	b, a
	ldhl	sp,	#2
	ld	a, (hl)
	ld	(bc), a
;src/ennemy.c:81: return;	    
	jr	00106$
00105$:
;src/ennemy.c:64: for (i=0; i<MAX_ENNEMY; i++) {
	ldhl	sp,	#4
	inc	(hl)
	ld	a, (hl-)
	dec	hl
	ld	(hl+), a
	inc	hl
	ld	a, (hl)
	sub	a, #0x08
	jp	C, 00104$
00106$:
;src/ennemy.c:84: }
	add	sp, #7
	pop	hl
	add	sp, #5
	jp	(hl)
;src/ennemy.c:86: void handle_ennemies(void){
;	---------------------------------
; Function handle_ennemies
; ---------------------------------
_handle_ennemies::
;src/ennemy.c:87: for (uint8_t j=0; j < active_ennemies_index; j++){
	ld	c, #0x00
00106$:
	ld	a, c
	ld	hl, #_active_ennemies_index
	sub	a, (hl)
	ret	NC
;src/ennemy.c:88: uint8_t i = ACTIVE_ENNEMIES[j];
	ld	hl, #_ACTIVE_ENNEMIES
	ld	b, #0x00
	add	hl, bc
;src/ennemy.c:89: if (ENNEMIES[i].hp <= 0){
	ld	e, (hl)
	ld	d, #0x00
	ld	l, e
	ld	h, d
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, de
	ld	de, #_ENNEMIES
	add	hl, de
	ld	de, #0x000e
	add	hl, de
	ld	b, (hl)
	ld	e, b
	xor	a, a
	ld	d, a
	sub	a, b
	bit	7, e
	jr	Z, 00131$
	bit	7, d
	jr	NZ, 00132$
	cp	a, a
	jr	00132$
00131$:
	bit	7, d
	jr	Z, 00132$
	scf
00132$:
	jr	C, 00103$
;src/ennemy.c:90: kill_active_ennemy(j);
	push	bc
	ld	a, c
	call	_kill_active_ennemy
	pop	bc
;src/ennemy.c:91: continue;
00103$:
;src/ennemy.c:87: for (uint8_t j=0; j < active_ennemies_index; j++){
	inc	c
;src/ennemy.c:163: }
	jr	00106$
;src/ennemy.c:165: void kill_active_ennemy(uint8_t j){
;	---------------------------------
; Function kill_active_ennemy
; ---------------------------------
_kill_active_ennemy::
	ld	c, a
;src/ennemy.c:166: ENNEMIES[ACTIVE_ENNEMIES[j]].isactive = 0;
	ld	hl, #_ACTIVE_ENNEMIES
	ld	b, #0x00
	add	hl, bc
	ld	c, (hl)
	ld	b, #0x00
	ld	l, c
	ld	h, b
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, bc
	ld	de, #_ENNEMIES
	add	hl, de
	ld	bc, #0x0010
	add	hl, bc
	ld	(hl), #0x00
;src/ennemy.c:173: }
	ret
	.area _CODE
	.area _INITIALIZER
__xinit____EMU_PROFILER_INIT:
	.dw _EMU_profiler_message
__xinit__ennemy_metasprites:
	.dw _ennemy_1_sprite_metasprites
	.dw _ennemy_2_sprite_metasprites
	.dw _ennemy_3_sprite_metasprites
__xinit__active_ennemies_index:
	.db #0x00	; 0
	.area _CABS (ABS)
