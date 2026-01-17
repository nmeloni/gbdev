;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler
; Version 4.5.1 #15267 (Linux)
;--------------------------------------------------------
	.module rock8x8_sprite
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _rock8x8_sprite_metasprites
	.globl _rock8x8_sprite_metasprite0
	.globl _rock8x8_sprite_tiles
	.globl _rock8x8_sprite_palettes
	.globl b___func_rock8x8_sprite
	.globl ___func_rock8x8_sprite
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
;res/rock8x8_sprite.c:7: BANKREF(rock8x8_sprite)
;	---------------------------------
; Function __func_rock8x8_sprite
; ---------------------------------
	b___func_rock8x8_sprite	= 0
___func_rock8x8_sprite::
	.local b___func_rock8x8_sprite 
	___bank_rock8x8_sprite = b___func_rock8x8_sprite 
	.globl ___bank_rock8x8_sprite 
	.area _CODE
_rock8x8_sprite_palettes:
	.dw #0x7fff
	.dw #0x56b5
	.dw #0x294a
	.dw #0x0000
_rock8x8_sprite_tiles:
	.db #0x18	; 24
	.db #0x1c	; 28
	.db #0x3a	; 58
	.db #0x66	; 102	'f'
	.db #0xdc	; 220
	.db #0xa3	; 163
	.db #0xb5	; 181
	.db #0xcb	; 203
	.db #0x19	; 25
	.db #0xe7	; 231
	.db #0xa5	; 165
	.db #0xdb	; 219
	.db #0x4c	; 76	'L'
	.db #0x76	; 118	'v'
	.db #0x34	; 52	'4'
	.db #0x3c	; 60
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x80	; 128
	.db #0x40	; 64
	.db #0x34	; 52	'4'
	.db #0xa8	; 168
	.db #0xd2	; 210
	.db #0x79	; 121	'y'
	.db #0xc4	; 196
	.db #0xe6	; 230
	.db #0xcc	; 204
	.db #0xe6	; 230
	.db #0xc4	; 196
	.db #0xe6	; 230
	.db #0xcc	; 204
	.db #0xe6	; 230
_rock8x8_sprite_metasprite0:
	.db #0xf8	; -8
	.db #0xfc	; -4
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x80	; -128
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
_rock8x8_sprite_metasprites:
	.dw _rock8x8_sprite_metasprite0
	.area _INITIALIZER
	.area _CABS (ABS)
