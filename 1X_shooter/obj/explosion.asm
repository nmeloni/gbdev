;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler
; Version 4.5.1 #15267 (Linux)
;--------------------------------------------------------
	.module explosion
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _queue_end
	.globl _queue_start
	.globl _EXPLOSIONS
	.globl _init_explosions
	.globl _add_exploision
	.globl _handle_explosions
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _DATA
_EXPLOSIONS::
	.ds 24
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
___EMU_PROFILER_INIT:
	.ds 2
_queue_start::
	.ds 1
_queue_end::
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
;src/explosion.c:7: void init_explosions(void){
;	---------------------------------
; Function init_explosions
; ---------------------------------
_init_explosions::
;src/explosion.c:8: for (uint8_t i=0; i<MAX_EXPLOSIONS; i++){
	ld	c, #0x00
00103$:
	ld	a, c
	sub	a, #0x08
	ret	NC
;src/explosion.c:9: EXPLOSIONS[i].px = 0;
	ld	b, #0x00
	ld	l, c
	ld	h, b
	add	hl, hl
	add	hl, bc
	ld	de, #_EXPLOSIONS
	add	hl, de
	ld	(hl), #0x00
;src/explosion.c:10: EXPLOSIONS[i].py = 0;
	ld	e, l
	ld	d, h
;src/explosion.c:11: EXPLOSIONS[i].framecount = 0;
	inc	hl
	inc	hl
	inc	de
	xor	a, a
	ld	(de), a
	ld	(hl), #0x00
;src/explosion.c:8: for (uint8_t i=0; i<MAX_EXPLOSIONS; i++){
	inc	c
;src/explosion.c:13: }
	jr	00103$
;src/explosion.c:14: void add_exploision(uint8_t x, uint8_t y){
;	---------------------------------
; Function add_exploision
; ---------------------------------
_add_exploision::
	dec	sp
	dec	sp
	ldhl	sp,	#1
	ld	(hl-), a
	ld	(hl), e
;src/explosion.c:15: EXPLOSIONS[queue_end].px = x;
	ld	hl, #_queue_end
	ld	c, (hl)
	ld	b, #0x00
	ld	l, c
	ld	h, b
	add	hl, hl
	add	hl, bc
	ld	bc, #_EXPLOSIONS
	add	hl, bc
	ld	c, l
	ld	b, h
	ldhl	sp,	#1
	ld	a, (hl)
	ld	(bc), a
;src/explosion.c:16: EXPLOSIONS[queue_end].py = y;
	ld	hl, #_queue_end
	ld	c, (hl)
	ld	b, #0x00
	ld	l, c
	ld	h, b
	add	hl, hl
	add	hl, bc
	ld	bc, #_EXPLOSIONS
	add	hl, bc
	inc	hl
	ld	c, l
	ld	b, h
	ldhl	sp,	#0
	ld	a, (hl)
	ld	(bc), a
;src/explosion.c:17: EXPLOSIONS[queue_end].framecount = NB_EXPLOSION_FRAME;
	ld	hl, #_queue_end
	ld	c, (hl)
	ld	b, #0x00
	ld	l, c
	ld	h, b
	add	hl, hl
	add	hl, bc
	ld	bc, #_EXPLOSIONS
	add	hl, bc
	inc	hl
	inc	hl
	ld	(hl), #0x20
;src/explosion.c:18: queue_end = (queue_end+1)%MAX_EXPLOSIONS;
	ld	a, (_queue_end)
	ld	d, #0x00
	ld	e, a
	inc	de
	ld	bc, #0x0008
	call	__modsint
	ld	hl, #_queue_end
	ld	(hl), c
;src/explosion.c:19: }
	inc	sp
	inc	sp
	ret
;src/explosion.c:21: void handle_explosions(void){
;	---------------------------------
; Function handle_explosions
; ---------------------------------
_handle_explosions::
	add	sp, #-3
;src/explosion.c:22: uint8_t i=queue_start;
	ld	a, (_queue_start)
	ld	c, a
;src/explosion.c:23: while (i != queue_end){
00104$:
	ld	a, (#_queue_end)
	sub	a, c
	jr	Z, 00108$
;src/explosion.c:24: if (EXPLOSIONS[i].framecount){
	ld	b, #0x00
	ld	l, c
	ld	h, b
	add	hl, hl
	add	hl, bc
	ld	de, #_EXPLOSIONS
	add	hl, de
	ld	e, l
	ld	d, h
	inc	de
	inc	de
	ld	a, (de)
	or	a, a
	jr	Z, 00102$
;src/explosion.c:25: EXPLOSIONS[i].framecount--;
	dec	a
	ld	b, a
	ld	(de), a
;src/explosion.c:28: EXPLOSIONS[i].px, EXPLOSIONS[i].py);
	ld	e, l
	ld	d, h
	inc	de
	ld	a, (de)
	push	hl
	ldhl	sp,	#2
	ld	(hl), a
	pop	hl
	ld	a, (hl)
	ldhl	sp,	#1
	ld	(hl), a
	ld	a, (#_oam)
	ldhl	sp,	#2
	ld	(hl), a
;src/explosion.c:26: oam+=move_metasprite_ex(explosion_sprite_metasprites[(EXPLOSIONS[i].framecount & 24)>>3],
	ld	a, b
	and	a, #0x18
	ld	l, a
	ld	h, #0x00
	sra	h
	rr	l
	sra	h
	rr	l
	sra	h
	rr	l
	add	hl, hl
	ld	de, #_explosion_sprite_metasprites
	add	hl, de
	ld	a, (hl+)
	ld	b, (hl)
;/home/meloni/Lib/gbdk/include/gb/metasprites.h:160: __current_metasprite = metasprite;
	ld	hl, #___current_metasprite
	ld	(hl+), a
	ld	(hl), b
;/home/meloni/Lib/gbdk/include/gb/metasprites.h:161: __current_base_tile = base_tile;
	ld	hl, #___current_base_tile
	ld	(hl), #0x70
;/home/meloni/Lib/gbdk/include/gb/metasprites.h:162: __current_base_prop = base_prop;
	xor	a, a
	ld	(#___current_base_prop),a
;/home/meloni/Lib/gbdk/include/gb/metasprites.h:163: return __move_metasprite(base_sprite, (y << 8) | (uint8_t)x);
	ldhl	sp,	#0
	ld	a, (hl+)
	ld	d, a
	ld	a, (hl+)
	ld	b, a
	ld	e, b
	push	bc
	ld	a, (hl)
	call	___move_metasprite
	pop	bc
;src/explosion.c:28: EXPLOSIONS[i].px, EXPLOSIONS[i].py);
	ld	hl, #_oam
	add	a, (hl)
	ld	(hl), a
	jr	00103$
00102$:
;src/explosion.c:30: queue_start = i;
	ld	hl, #_queue_start
	ld	(hl), c
00103$:
;src/explosion.c:32: i = (i+1)%MAX_EXPLOSIONS;
	ld	d, #0x00
	ld	e, c
	inc	de
	ld	bc, #0x0008
	call	__modsint
	jr	00104$
00108$:
;src/explosion.c:34: }
	add	sp, #3
	ret
	.area _CODE
	.area _INITIALIZER
__xinit____EMU_PROFILER_INIT:
	.dw _EMU_profiler_message
__xinit__queue_start:
	.db #0x00	; 0
__xinit__queue_end:
	.db #0x00	; 0
	.area _CABS (ABS)
