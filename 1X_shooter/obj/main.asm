;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler
; Version 4.5.1 #15267 (Linux)
;--------------------------------------------------------
	.module main
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _main
	.globl _init_enemy_bullets
	.globl _draw_player
	.globl _handle_player
	.globl _init_player
	.globl _hide_sprites_range
	.globl _fill_win_rect
	.globl _set_sprite_data
	.globl _set_bkg_data
	.globl _vsync
	.globl _joypad
	.globl _level_framecounter
	.globl _oam
	.globl _white_tile
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _DATA
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
___EMU_PROFILER_INIT:
	.ds 2
_oam::
	.ds 1
_level_framecounter::
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
;src/main.c:23: void main(void){
;	---------------------------------
; Function main
; ---------------------------------
_main::
	add	sp, #-44
;src/main.c:26: set_sprite_data(SPACESHIP_TILE_OFFSET, spaceship_sprite_TILE_COUNT, spaceship_sprite_tiles);
	ld	de, #_spaceship_sprite_tiles
	push	de
	ld	hl, #0x400
	push	hl
	call	_set_sprite_data
	add	sp, #4
;src/main.c:27: set_sprite_data(ENEMYBULLET_TILE_OFFSET, enemybullet_sprite_TILE_COUNT, enemybullet_sprite_tiles);
	ld	de, #_enemybullet_sprite_tiles
	push	de
	ld	hl, #0x230
	push	hl
	call	_set_sprite_data
	add	sp, #4
;src/main.c:48: set_bkg_data(0X80, early_gameboyfont_TILE_COUNT, early_gameboyfont_tiles);
	ld	de, #_early_gameboyfont_tiles
	push	de
	ld	hl, #0x2980
	push	hl
	call	_set_bkg_data
	add	sp, #4
;src/main.c:50: fill_win_rect( 0,0,20,4,0x80);
	ld	hl, #0x8004
	push	hl
	ld	a, #0x14
	push	af
	inc	sp
	xor	a, a
	rrca
	push	af
	call	_fill_win_rect
	add	sp, #5
;/home/meloni/Lib/gbdk/include/gb/gb.h:1739: WX_REG=x, WY_REG=y;
	ld	a, #0x08
	ldh	(_WX_REG + 0), a
	ld	a, #0x88
	ldh	(_WY_REG + 0), a
;src/main.c:70: BGP_REG = DMG_PALETTE(DMG_WHITE, DMG_LITE_GRAY, DMG_DARK_GRAY, DMG_BLACK);
	ld	a, #0xe4
	ldh	(_BGP_REG + 0), a
;src/main.c:71: OBP0_REG = DMG_PALETTE(DMG_DARK_GRAY,DMG_WHITE, DMG_LITE_GRAY,  DMG_BLACK); 
	ld	a, #0xd2
	ldh	(_OBP0_REG + 0), a
;src/main.c:72: OBP1_REG = DMG_PALETTE(DMG_WHITE, DMG_LITE_GRAY, DMG_LITE_GRAY, DMG_LITE_GRAY); 
	ld	a, #0x54
	ldh	(_OBP1_REG + 0), a
;src/main.c:76: const uint8_t starting_points[20][2]= {
	ldhl	sp,	#0
	ld	a, #0x08
	ld	(hl+), a
	ld	a, #0x10
	ld	(hl+), a
	ld	a, #0x08
	ld	(hl+), a
	ld	a, #0x20
	ld	(hl+), a
	ld	a, #0x08
	ld	(hl+), a
	ld	a, #0x40
	ld	(hl+), a
	ld	a, #0x08
	ld	(hl+), a
	ld	a, #0x90
	ld	(hl+), a
	ld	a, #0x08
	ld	(hl+), a
	ld	a, #0x90
	ld	(hl+), a
	ld	a, #0x20
	ld	(hl+), a
	ld	a, #0x10
	ld	(hl+), a
	ld	a, #0x40
	ld	(hl+), a
	ld	a, #0x10
	ld	(hl+), a
	ld	a, #0x60
	ld	(hl+), a
	ld	a, #0x10
	ld	(hl+), a
	ld	a, #0x80
	ld	(hl+), a
	ld	a, #0x10
	ld	(hl+), a
	ld	a, #0x90
	ld	(hl+), a
	ld	a, #0x10
	ld	(hl+), a
	ld	a, #0xa8
	ld	(hl+), a
	ld	a, #0x20
	ld	(hl+), a
	ld	a, #0xa8
	ld	(hl+), a
	ld	a, #0x40
	ld	(hl+), a
	ld	a, #0xa8
	ld	(hl+), a
	ld	a, #0x80
	ld	(hl+), a
	ld	a, #0x20
	ld	(hl+), a
	ld	a, #0x90
	ld	(hl+), a
	ld	a, #0x60
	ld	(hl+), a
	ld	a, #0x90
	ld	(hl+), a
	ld	a, #0x80
	ld	(hl+), a
	ld	a, #0x90
	ld	(hl+), a
	ld	a, #0x50
	ld	(hl+), a
	ld	a, #0x80
	ld	(hl+), a
	ld	a, #0x50
	ld	(hl+), a
	ld	a, #0x90
	ld	(hl+), a
	ld	a, #0xd4
	ld	(hl+), a
	ld	a, #0x90
	ld	(hl+), a
	ld	a, #0x50
	ld	(hl+), a
	ld	(hl), #0x90
;src/main.c:85: for (uint8_t i=0; i<20; i++){
	ld	e, #0x00
00111$:
	ld	a, e
	sub	a, #0x14
	jr	NC, 00101$
;/home/meloni/Lib/gbdk/include/gb/gb.h:1887: shadow_OAM[nb].tile=tile;
	ld	c, e
	ld	b, #0x00
	ldhl	sp,	#40
	ld	a, c
	ld	(hl+), a
	ld	(hl), b
	ld	a, #0x02
00165$:
	ldhl	sp,	#40
	sla	(hl)
	inc	hl
	rl	(hl)
	dec	a
	jr	NZ, 00165$
	push	de
	ld	de, #_shadow_OAM
	ld	a, (hl-)
	ld	l, (hl)
	ld	h, a
	add	hl, de
	pop	de
	ld	d, l
	inc	hl
	inc	hl
	ld	(hl), #0x30
;src/main.c:87: move_sprite(i, starting_points[i][0], starting_points[i][1]);
	sla	c
	rl	b
	ld	hl, #0
	add	hl, sp
	add	hl, bc
	ld	c,l
	ld	b,h
	inc	hl
	ld	a, (hl)
	ldhl	sp,	#42
	ld	(hl), a
	ld	a, (bc)
	ldhl	sp,	#43
	ld	(hl), a
;/home/meloni/Lib/gbdk/include/gb/gb.h:1973: OAM_item_t * itm = &shadow_OAM[nb];
	ld	bc, #_shadow_OAM+0
	ldhl	sp,	#40
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	add	hl, bc
	ld	c, l
	ld	b, h
;/home/meloni/Lib/gbdk/include/gb/gb.h:1974: itm->y=y, itm->x=x;
	ldhl	sp,	#42
	ld	a, (hl+)
	ld	(bc), a
	inc	bc
	ld	a, (hl)
	ld	(bc), a
;src/main.c:85: for (uint8_t i=0; i<20; i++){
	inc	e
	jr	00111$
00101$:
;src/main.c:89: SPRITES_8x16;
	ldh	a, (_LCDC_REG + 0)
	or	a, #0x04
	ldh	(_LCDC_REG + 0), a
;src/main.c:90: SHOW_SPRITES;
	ldh	a, (_LCDC_REG + 0)
	or	a, #0x02
	ldh	(_LCDC_REG + 0), a
;src/main.c:91: SHOW_BKG;
	ldh	a, (_LCDC_REG + 0)
	or	a, #0x01
	ldh	(_LCDC_REG + 0), a
;src/main.c:92: SHOW_WIN;
	ldh	a, (_LCDC_REG + 0)
	or	a, #0x20
	ldh	(_LCDC_REG + 0), a
;src/main.c:93: DISPLAY_ON;
	ldh	a, (_LCDC_REG + 0)
	or	a, #0x80
	ldh	(_LCDC_REG + 0), a
;src/main.c:95: init_player();
	call	_init_player
;src/main.c:97: init_enemy_bullets();
	call	_init_enemy_bullets
;src/main.c:98: while(1) {
00104$:
;src/main.c:100: vsync();
	call	_vsync
;src/main.c:102: oam = 20;
	ld	hl, #_oam
	ld	(hl), #0x14
;src/main.c:103: level_framecounter++;
	ld	hl, #_level_framecounter
	inc	(hl)
	jr	NZ, 00167$
	inc	hl
	inc	(hl)
00167$:
;src/main.c:105: UPDATE_KEYS();
	ld	a, (#_current_joypad)
	ld	(#_previous_joypad),a
	call	_joypad
	ld	(#_current_joypad),a
;src/main.c:137: handle_player();
	call	_handle_player
;src/main.c:138: for (uint8_t i=0; i<20; i++){
	ld	c, #0x00
00114$:
	ld	a, c
	sub	a, #0x14
	jr	NC, 00102$
;/home/meloni/Lib/gbdk/include/gb/gb.h:1989: OAM_item_t * itm = &shadow_OAM[nb];
	ld	de, #_shadow_OAM+0
	ld	l, c
	xor	a, a
	ld	h, a
	add	hl, hl
	add	hl, hl
	add	hl, de
;/home/meloni/Lib/gbdk/include/gb/gb.h:1990: itm->y+=y, itm->x+=x;
	ld	e, l
	ld	d, h
	inc	hl
	ld	a, (de)
	inc	a
	ld	(de), a
	inc	(hl)
	ld	a, (hl)
;src/main.c:138: for (uint8_t i=0; i<20; i++){
	inc	c
	jr	00114$
00102$:
;src/main.c:150: draw_player();
	call	_draw_player
;src/main.c:154: hide_sprites_range(oam,MAX_HARDWARE_SPRITES);
	ld	e, #0x28
	ld	a, (_oam)
	call	_hide_sprites_range
	jr	00104$
;src/main.c:157: }
	add	sp, #44
	ret
_white_tile:
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.area _CODE
	.area _INITIALIZER
__xinit____EMU_PROFILER_INIT:
	.dw _EMU_profiler_message
__xinit__oam:
	.db #0x00	; 0
__xinit__level_framecounter:
	.dw #0x0000
	.area _CABS (ABS)
