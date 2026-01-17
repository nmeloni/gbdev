;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler
; Version 4.5.1 #15267 (Linux)
;--------------------------------------------------------
	.module bullet_lvl1_sprite
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _bullet_lvl1_sprite_metasprites
	.globl _bullet_lvl1_sprite_metasprite0
	.globl _bullet_lvl1_sprite_tiles
	.globl _bullet_lvl1_sprite_palettes
	.globl b___func_bullet_lvl1_sprite
	.globl ___func_bullet_lvl1_sprite
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
;res/bullet_lvl1_sprite.c:7: BANKREF(bullet_lvl1_sprite)
;	---------------------------------
; Function __func_bullet_lvl1_sprite
; ---------------------------------
	b___func_bullet_lvl1_sprite	= 0
___func_bullet_lvl1_sprite::
	.local b___func_bullet_lvl1_sprite 
	___bank_bullet_lvl1_sprite = b___func_bullet_lvl1_sprite 
	.globl ___bank_bullet_lvl1_sprite 
	.area _CODE
_bullet_lvl1_sprite_palettes:
	.dw #0x294a
	.dw #0x7fff
	.dw #0x56b5
	.dw #0x0000
_bullet_lvl1_sprite_tiles:
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x10	; 16
	.db #0x10	; 16
	.db #0x28	; 40
	.db #0x38	; 56	'8'
	.db #0x10	; 16
	.db #0x28	; 40
	.db #0x10	; 16
	.db #0x28	; 40
	.db #0x10	; 16
	.db #0x28	; 40
	.db #0x00	; 0
	.db #0x10	; 16
	.db #0x10	; 16
	.db #0x10	; 16
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
_bullet_lvl1_sprite_metasprite0:
	.db #0xf8	; -8
	.db #0xfc	; -4
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x80	; -128
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
_bullet_lvl1_sprite_metasprites:
	.dw _bullet_lvl1_sprite_metasprite0
	.area _INITIALIZER
	.area _CABS (ABS)
