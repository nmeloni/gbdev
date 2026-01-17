;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler
; Version 4.5.1 #15267 (Linux)
;--------------------------------------------------------
	.module powerup
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _init_powerups
	.globl _POWERUP
	.globl _powerup_pattern
	.globl _handle_powerup
	.globl _add_powerup
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _DATA
_POWERUP::
	.ds 11
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
;src/powerup.c:19: void init_powerups(void){
;	---------------------------------
; Function init_powerups
; ---------------------------------
_init_powerups::
;src/powerup.c:20: POWERUP.x = 0;
	ld	hl, #_POWERUP
	xor	a, a
	ld	(hl+), a
;src/powerup.c:21: POWERUP.y = 0;
	ld	(hl+), a
	xor	a, a
	ld	(hl+), a
	ld	(hl), a
;src/powerup.c:22: POWERUP.type = 0;
	ld	hl, #_POWERUP + 6
	ld	(hl), #0x00
;src/powerup.c:23: POWERUP.isactive = 0;
	ld	hl, #_POWERUP + 7
	ld	(hl), #0x00
;src/powerup.c:24: POWERUP.activepattern = 0;
	ld	hl, #_POWERUP + 8
	ld	(hl), #0x00
;src/powerup.c:25: POWERUP.framecount = 0;
	ld	hl, #(_POWERUP + 9)
	xor	a, a
	ld	(hl+), a
	ld	(hl), a
;src/powerup.c:26: }
	ret
_powerup_pattern:
	.dw #0xff00
	.dw #0x0040
	.dw #0x000a
	.dw #0xff40
	.dw #0x0040
	.dw #0x000a
	.dw #0xffc0
	.dw #0x0040
	.dw #0x000a
	.dw #0x0000
	.dw #0x0040
	.dw #0x000a
	.dw #0x0040
	.dw #0x0040
	.dw #0x000a
	.dw #0x00c0
	.dw #0x0040
	.dw #0x000a
	.dw #0x0100
	.dw #0x0040
	.dw #0x000a
	.dw #0x00c0
	.dw #0x0040
	.dw #0x000a
	.dw #0x0040
	.dw #0x0040
	.dw #0x000a
	.dw #0x0000
	.dw #0x0040
	.dw #0x000a
	.dw #0xffc0
	.dw #0x0040
	.dw #0x000a
	.dw #0xff40
	.dw #0x0040
	.dw #0x000a
;src/powerup.c:29: void handle_powerup(void){
;	---------------------------------
; Function handle_powerup
; ---------------------------------
_handle_powerup::
	add	sp, #-4
;src/powerup.c:30: if (POWERUP.isactive && (level_framecounter % 2 == 0)){
;src/powerup.c:41: POWERUP.px = POWERUP.x >> 8;
;src/powerup.c:42: POWERUP.py = POWERUP.y >> 8;
;src/powerup.c:55: switch (POWERUP.type){
;src/powerup.c:30: if (POWERUP.isactive && (level_framecounter % 2 == 0)){
	ld	a, (#(_POWERUP + 7) + 0)
	or	a, a
	jp	Z, 00123$
	ld	a, (_level_framecounter)
	rrca
	jp	C, 00123$
;src/powerup.c:31: if (POWERUP.framecount == 0){
	ld	hl, #(_POWERUP + 9)
	ld	a, (hl+)
;src/powerup.c:32: POWERUP.framecount = powerup_pattern[POWERUP.activepattern][2];
;src/powerup.c:31: if (POWERUP.framecount == 0){
	or	a, (hl)
	jr	NZ, 00104$
;src/powerup.c:32: POWERUP.framecount = powerup_pattern[POWERUP.activepattern][2];
	ld	hl, #(_POWERUP + 8)
	ld	c, (hl)
	ld	b, #0x00
	ld	l, c
	ld	h, b
	add	hl, hl
	add	hl, bc
	add	hl, hl
	ld	de, #_powerup_pattern
	add	hl, de
	ld	bc, #0x0004
	add	hl, bc
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	hl, #(_POWERUP + 9)
	ld	a, c
	ld	(hl+), a
;src/powerup.c:33: POWERUP.activepattern+=1;
	ld	a, b
	ld	(hl-), a
	dec	hl
	ld	a, (#(_POWERUP + 8) + 0)
	inc	a
	ld	(hl), a
;src/powerup.c:34: if (POWERUP.activepattern >= POWERUP_PATTERN_COUNT){
	ld	a, (#(_POWERUP + 8) + 0)
	sub	a, #0x0c
	jr	C, 00104$
;src/powerup.c:35: POWERUP.activepattern = 0;
	ld	(hl), #0x00
00104$:
;src/powerup.c:38: POWERUP.framecount--;
	ld	hl, #(_POWERUP + 9)
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	dec	bc
	ld	hl, #(_POWERUP + 9)
	ld	a, c
	ld	(hl+), a
	ld	(hl), b
;src/powerup.c:39: POWERUP.x += powerup_pattern[POWERUP.activepattern][0];
	ld	hl, #_POWERUP
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	a, (#(_POWERUP + 8) + 0)
	ld	e, a
	ld	d, #0x00
	ld	l, e
	ld	h, d
	add	hl, hl
	add	hl, de
	add	hl, hl
	ld	de, #_powerup_pattern
	add	hl, de
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	add	hl, bc
	ld	c, l
	ld	b, h
	ld	hl, #_POWERUP
	ld	a, c
	ld	(hl+), a
	ld	(hl), b
;src/powerup.c:40: POWERUP.y += powerup_pattern[POWERUP.activepattern][1];
	ld	hl, #(_POWERUP + 2)
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	a, (#(_POWERUP + 8) + 0)
	ld	e, a
	ld	d, #0x00
	ld	l, e
	ld	h, d
	add	hl, hl
	add	hl, de
	add	hl, hl
	ld	de, #_powerup_pattern
	add	hl, de
	inc	hl
	inc	hl
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	add	hl, bc
	ld	c, l
	ld	b, h
	ld	hl, #(_POWERUP + 2)
	ld	a, c
	ld	(hl+), a
	ld	(hl), b
;src/powerup.c:41: POWERUP.px = POWERUP.x >> 8;
	ld	hl, #_POWERUP
	ld	a, (hl+)
	ld	a, (hl)
	ld	(#(_POWERUP + 4)),a
;src/powerup.c:42: POWERUP.py = POWERUP.y >> 8;
	ld	hl, #(_POWERUP + 2)
	ld	a, (hl+)
	ld	a, (hl)
	ld	hl, #(_POWERUP + 5)
	ld	(hl), a
;src/powerup.c:43: if (POWERUP.py > 168){
	cp	a, #0xa9
	jr	C, 00106$
;src/powerup.c:44: POWERUP.isactive = 0;
	inc	hl
	inc	hl
	ld	(hl), #0x00
;src/powerup.c:45: return;
	jp	00128$
00106$:
;src/powerup.c:48: if ( ((PLAYER.py) < (POWERUP.py)+8) &&
	ld	a, (#(_PLAYER + 7) + 0)
	ldhl	sp,	#3
	ld	(hl), a
	ld	hl, #(_POWERUP + 5)
	ld	c, (hl)
	ld	b, #0x00
	ld	hl, #0x0008
	add	hl, bc
	inc	sp
	inc	sp
	push	hl
	ldhl	sp,	#3
	ld	a, (hl-)
	ld	(hl+), a
	ld	(hl), #0x00
	ldhl	sp,	#2
	ld	e, l
	ld	d, h
	ldhl	sp,	#0
	ld	a, (de)
	inc	de
	sub	a, (hl)
	inc	hl
	ld	a, (de)
	sbc	a, (hl)
	jp	NC, 00123$
;src/powerup.c:49: ((PLAYER.py) > (POWERUP.py)-7) )
	ld	de, #0x0007
	ld	a, c
	sub	a, e
	ld	e, a
	ld	a, b
	sbc	a, d
	ldhl	sp,	#1
	ld	(hl-), a
	ld	(hl), e
	ldhl	sp,	#0
	ld	e, l
	ld	d, h
	ldhl	sp,	#2
	ld	a, (de)
	inc	de
	sub	a, (hl)
	inc	hl
	ld	a, (de)
	sbc	a, (hl)
	ld	a, (de)
	ld	d, a
	ld	e, (hl)
	bit	7, e
	jr	Z, 00237$
	bit	7, d
	jr	NZ, 00238$
	cp	a, a
	jr	00238$
00237$:
	bit	7, d
	jr	Z, 00238$
	scf
00238$:
	jp	NC, 00123$
;src/powerup.c:50: if ( ((PLAYER.px) < (POWERUP.px)+8) &&
	ld	a, (#(_PLAYER + 6) + 0)
	ldhl	sp,	#3
	ld	(hl), a
	ld	hl, #(_POWERUP + 4)
	ld	c, (hl)
	ld	b, #0x00
	ld	hl, #0x0008
	add	hl, bc
	inc	sp
	inc	sp
	push	hl
	ldhl	sp,	#3
	ld	a, (hl-)
	ld	(hl+), a
	ld	(hl), #0x00
	ldhl	sp,	#2
	ld	e, l
	ld	d, h
	ldhl	sp,	#0
	ld	a, (de)
	inc	de
	sub	a, (hl)
	inc	hl
	ld	a, (de)
	sbc	a, (hl)
	jr	NC, 00123$
;src/powerup.c:51: ((PLAYER.px) > (POWERUP.px)-7)){
	ld	a, c
	add	a, #0xf9
	ld	c, a
	ld	a, b
	adc	a, #0xff
	ld	b, a
	ldhl	sp,	#2
	ld	a, c
	sub	a, (hl)
	inc	hl
	ld	a, b
	sbc	a, (hl)
	ld	a, b
	ld	d, a
	ld	e, (hl)
	bit	7, e
	jr	Z, 00239$
	bit	7, d
	jr	NZ, 00240$
	cp	a, a
	jr	00240$
00239$:
	bit	7, d
	jr	Z, 00240$
	scf
00240$:
	jr	NC, 00123$
;src/powerup.c:53: POWERUP.isactive = 0;
	ld	hl, #(_POWERUP + 7)
	ld	(hl), #0x00
;src/powerup.c:55: switch (POWERUP.type){
	ld	a, (#(_POWERUP + 6) + 0)
	or	a, a
	jr	Z, 00107$
	cp	a, #0x01
	jr	Z, 00114$
	sub	a, #0x02
	jr	Z, 00113$
	jr	00123$
;src/powerup.c:56: case POWERUP_TYPE_POWER_UP:
00107$:
;src/powerup.c:57: if (PLAYER.power < 4){
	ld	hl, #_PLAYER + 8
	ld	a, (hl)
	cp	a, #0x04
	jr	NC, 00123$
;src/powerup.c:58: PLAYER.power += 1;
	inc	a
	ld	(hl), a
;src/powerup.c:59: if (PLAYER.power == 2){
	ld	e, (hl)
;src/powerup.c:60: PLAYER.bullet_metasprites = bullet_lvl2_sprite_metasprites;
;src/powerup.c:61: PLAYER.bullet_sprite_offset = BULLET_LVL2_TILE_OFFSET;
	ld	bc, #_PLAYER + 18
;src/powerup.c:59: if (PLAYER.power == 2){
	ld	a, e
	sub	a, #0x02
	jr	NZ, 00109$
;src/powerup.c:60: PLAYER.bullet_metasprites = bullet_lvl2_sprite_metasprites;
	ld	hl, #(_PLAYER + 16)
	ld	(hl), #<(_bullet_lvl2_sprite_metasprites)
	inc	hl
	ld	(hl), #>(_bullet_lvl2_sprite_metasprites)
;src/powerup.c:61: PLAYER.bullet_sprite_offset = BULLET_LVL2_TILE_OFFSET;
	ld	a, #0x06
	ld	(bc), a
	jr	00123$
00109$:
;src/powerup.c:64: PLAYER.bullet_metasprites = bullet_lvl3_sprite_metasprites;
	ld	hl, #(_PLAYER + 16)
	ld	(hl), #<(_bullet_lvl3_sprite_metasprites)
	inc	hl
	ld	(hl), #>(_bullet_lvl3_sprite_metasprites)
;src/powerup.c:65: PLAYER.bullet_sprite_offset = BULLET_LVL3_TILE_OFFSET;
	ld	a, #0x0a
	ld	(bc), a
;src/powerup.c:68: break;
	jr	00123$
;src/powerup.c:69: case POWERUP_TYPE_EXTRA_LIFE:
00113$:
;src/powerup.c:70: PLAYER.lives += 1;
	ld	hl, #_PLAYER + 9
	inc	(hl)
;src/powerup.c:71: break;
	jr	00123$
;src/powerup.c:72: case POWERUP_TYPE_SHIELD:
00114$:
;src/powerup.c:73: PLAYER.flags |= PLAYER_FLAG_SHIELD;
	ld	hl, #_PLAYER + 14
	set	0, (hl)
;src/powerup.c:75: }
00123$:
;src/powerup.c:78: if (POWERUP.isactive){
	ld	a, (#(_POWERUP + 7) + 0)
	or	a, a
	jr	Z, 00128$
;src/powerup.c:81: POWERUP.px, POWERUP.py);
	ld	a, (#(_POWERUP + 5) + 0)
	ldhl	sp,	#2
	ld	(hl), a
	ld	hl, #(_POWERUP + 4)
	ld	c, (hl)
	ld	a, (#_oam)
	ldhl	sp,	#3
	ld	(hl), a
;src/powerup.c:79: oam+=move_metasprite_ex(powerup_sprite_metasprites[POWERUP.type],
	ld	hl, #(_POWERUP + 6)
	ld	l, (hl)
	xor	a, a
	ld	h, a
	add	hl, hl
	ld	de, #_powerup_sprite_metasprites
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
	ld	(hl), #0x20
;/home/meloni/Lib/gbdk/include/gb/metasprites.h:162: __current_base_prop = base_prop;
	xor	a, a
	ld	(#___current_base_prop),a
;/home/meloni/Lib/gbdk/include/gb/metasprites.h:163: return __move_metasprite(base_sprite, (y << 8) | (uint8_t)x);
	ldhl	sp,	#2
	ld	a, (hl+)
	ld	d, a
	ld	e, c
	ld	a, (hl)
	call	___move_metasprite
;src/powerup.c:81: POWERUP.px, POWERUP.py);
	ld	hl, #_oam
	add	a, (hl)
	ld	(hl), a
00128$:
;src/powerup.c:84: }
	add	sp, #4
	ret
;src/powerup.c:87: void add_powerup(uint8_t x, uint8_t y, uint8_t type){
;	---------------------------------
; Function add_powerup
; ---------------------------------
_add_powerup::
	ld	d, a
;src/powerup.c:88: if (!POWERUP.isactive){
	ld	hl, #_POWERUP + 7
	ld	a, (hl)
	or	a, a
	jr	NZ, 00103$
;src/powerup.c:89: POWERUP.isactive = 1;
	ld	(hl), #0x01
;src/powerup.c:90: POWERUP.x = x<<8;
	ld	bc, #_POWERUP
	ld	h, d
	xor	a, a
	ld	(bc), a
	inc	bc
	ld	a, h
	ld	(bc), a
;src/powerup.c:91: POWERUP.y = y<<8;
	ld	bc, #_POWERUP + 2
	ld	h, e
	xor	a, a
	ld	(bc), a
	inc	bc
	ld	a, h
	ld	(bc), a
;src/powerup.c:92: POWERUP.px = x;
	ld	hl, #_POWERUP + 4
	ld	(hl), d
;src/powerup.c:93: POWERUP.py = y;
	ld	hl, #_POWERUP + 5
	ld	(hl), e
;src/powerup.c:94: POWERUP.type = type;
	ld	de, #(_POWERUP + 6)
	ldhl	sp,	#2
	ld	a, (hl)
	ld	(de), a
;src/powerup.c:95: POWERUP.activepattern = 0;
	ld	hl, #_POWERUP + 8
	ld	(hl), #0x00
;src/powerup.c:96: POWERUP.framecount = powerup_pattern[0][2];
	ld	hl, #(_powerup_pattern + 4)
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	ld	hl, #(_POWERUP + 9)
	ld	(hl), c
	inc	hl
	ld	(hl), b
00103$:
;src/powerup.c:98: }
	pop	hl
	inc	sp
	jp	(hl)
	.area _CODE
	.area _INITIALIZER
__xinit____EMU_PROFILER_INIT:
	.dw _EMU_profiler_message
	.area _CABS (ABS)
