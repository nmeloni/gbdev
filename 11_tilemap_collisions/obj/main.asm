;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler
; Version 4.5.1 #15267 (Linux)
;--------------------------------------------------------
	.module main
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _main
	.globl _set_bkg_tiles
	.globl _set_bkg_data
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
;src/main.c:5: void main(void) {
;	---------------------------------
; Function main
; ---------------------------------
_main::
;src/main.c:7: BGP_REG = DMG_PALETTE(dungeon_tileset_palettes[3], dungeon_tileset_palettes[1], dungeon_tileset_palettes[2], dungeon_tileset_palettes[0]);
	ld	a, (#_dungeon_tileset_palettes + 0)
	and	a, #0x03
	rrca
	rrca
	and	a, #0xc0
	ld	c, a
	ld	a, (#(_dungeon_tileset_palettes + 4) + 0)
	swap a
	and	a, #0x30
	or	a, c
	ld	c, a
	ld	a, (#(_dungeon_tileset_palettes + 2) + 0)
	and	a, #0x03
	add	a, a
	add	a, a
	or	a, c
	ld	c, a
	ld	a, (#(_dungeon_tileset_palettes + 6) + 0)
	and	a, #0x03
	or	a, c
	ldh	(_BGP_REG + 0), a
;src/main.c:9: DISPLAY_ON;
	ldh	a, (_LCDC_REG + 0)
	or	a, #0x80
	ldh	(_LCDC_REG + 0), a
;src/main.c:10: SHOW_BKG;
	ldh	a, (_LCDC_REG + 0)
	or	a, #0x01
	ldh	(_LCDC_REG + 0), a
;src/main.c:12: SPRITES_8x8;
	ldh	a, (_LCDC_REG + 0)
	and	a, #0xfb
	ldh	(_LCDC_REG + 0), a
;src/main.c:13: set_bkg_data(0, dungeon_tileset_TILE_COUNT, dungeon_tileset_tiles);
	ld	de, #_dungeon_tileset_tiles
	push	de
	ld	hl, #0x1d00
	push	hl
	call	_set_bkg_data
	add	sp, #4
;src/main.c:14: set_bkg_tiles(0, 0, 20, 18, dungeon_map_map);
	ld	de, #_dungeon_map_map
	push	de
	ld	hl, #0x1214
	push	hl
	xor	a, a
	rrca
	push	af
	call	_set_bkg_tiles
	add	sp, #6
;src/main.c:16: }
	ret
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
