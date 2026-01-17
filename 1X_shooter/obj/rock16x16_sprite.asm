;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler
; Version 4.5.1 #15267 (Linux)
;--------------------------------------------------------
	.module rock16x16_sprite
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _rock16x16_sprite_metasprites
	.globl _rock16x16_sprite_metasprite0
	.globl _rock16x16_sprite_tiles
	.globl _rock16x16_sprite_palettes
	.globl b___func_rock16x16_sprite
	.globl ___func_rock16x16_sprite
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
;res/rock16x16_sprite.c:7: BANKREF(rock16x16_sprite)
;	---------------------------------
; Function __func_rock16x16_sprite
; ---------------------------------
	b___func_rock16x16_sprite	= 0
___func_rock16x16_sprite::
	.local b___func_rock16x16_sprite 
	___bank_rock16x16_sprite = b___func_rock16x16_sprite 
	.globl ___bank_rock16x16_sprite 
	.area _CODE
_rock16x16_sprite_palettes:
	.dw #0x7fff
	.dw #0x56b5
	.dw #0x294a
	.dw #0x0000
_rock16x16_sprite_tiles:
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x1f	; 31
	.db #0x1f	; 31
	.db #0x39	; 57	'9'
	.db #0x3f	; 63
	.db #0x52	; 82	'R'
	.db #0x7d	; 125
	.db #0x9c	; 156
	.db #0xe3	; 227
	.db #0xbc	; 188
	.db #0xc3	; 195
	.db #0xbf	; 191
	.db #0xc1	; 193
	.db #0xcf	; 207
	.db #0xb2	; 178
	.db #0xc6	; 198
	.db #0xfb	; 251
	.db #0xcc	; 204
	.db #0xbb	; 187
	.db #0x7f	; 127
	.db #0x31	; 49	'1'
	.db #0x7f	; 127
	.db #0x40	; 64
	.db #0x3f	; 63
	.db #0x20	; 32
	.db #0x1f	; 31
	.db #0x1b	; 27
	.db #0x07	; 7
	.db #0x07	; 7
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0xe8	; 232
	.db #0xf0	; 240
	.db #0x78	; 120	'x'
	.db #0xfc	; 252
	.db #0x36	; 54	'6'
	.db #0xcc	; 204
	.db #0x79	; 121	'y'
	.db #0x86	; 134
	.db #0x3e	; 62
	.db #0xc1	; 193
	.db #0xdf	; 223
	.db #0x39	; 57	'9'
	.db #0xee	; 238
	.db #0x1d	; 29
	.db #0xc7	; 199
	.db #0x3d	; 61
	.db #0x0e	; 14
	.db #0xfd	; 253
	.db #0x17	; 23
	.db #0xf9	; 249
	.db #0x6e	; 110	'n'
	.db #0xf2	; 242
	.db #0xfc	; 252
	.db #0x0c	; 12
	.db #0xf0	; 240
	.db #0xf0	; 240
	.db #0xe0	; 224
	.db #0xe0	; 224
	.db #0x00	; 0
	.db #0x00	; 0
_rock16x16_sprite_metasprite0:
	.db #0xf8	; -8
	.db #0xf8	; -8
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x02	; 2
	.db #0x00	; 0
	.db #0x80	; -128
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
_rock16x16_sprite_metasprites:
	.dw _rock16x16_sprite_metasprite0
	.area _INITIALIZER
	.area _CABS (ABS)
