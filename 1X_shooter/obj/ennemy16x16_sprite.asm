;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler
; Version 4.5.1 #15267 (Linux)
;--------------------------------------------------------
	.module ennemy16x16_sprite
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _ennemy16x16_sprite_metasprites
	.globl _ennemy16x16_sprite_metasprite1
	.globl _ennemy16x16_sprite_metasprite0
	.globl _ennemy16x16_sprite_tiles
	.globl _ennemy16x16_sprite_palettes
	.globl b___func_ennemy16x16_sprite
	.globl ___func_ennemy16x16_sprite
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
;res/ennemy16x16_sprite.c:7: BANKREF(ennemy16x16_sprite)
;	---------------------------------
; Function __func_ennemy16x16_sprite
; ---------------------------------
	b___func_ennemy16x16_sprite	= 0
___func_ennemy16x16_sprite::
	.local b___func_ennemy16x16_sprite 
	___bank_ennemy16x16_sprite = b___func_ennemy16x16_sprite 
	.globl ___bank_ennemy16x16_sprite 
	.area _CODE
_ennemy16x16_sprite_palettes:
	.dw #0x7fff
	.dw #0x56b5
	.dw #0x294a
	.dw #0x0000
_ennemy16x16_sprite_tiles:
	.db #0x07	; 7
	.db #0x07	; 7
	.db #0x1c	; 28
	.db #0x1f	; 31
	.db #0x30	; 48	'0'
	.db #0x3f	; 63
	.db #0x67	; 103	'g'
	.db #0x78	; 120	'x'
	.db #0x4f	; 79	'O'
	.db #0x70	; 112	'p'
	.db #0xdf	; 223
	.db #0xe7	; 231
	.db #0xb8	; 184
	.db #0xcf	; 207
	.db #0xb4	; 180
	.db #0xd8	; 216
	.db #0xf0	; 240
	.db #0x8f	; 143
	.db #0xff	; 255
	.db #0xc0	; 192
	.db #0xf8	; 248
	.db #0xbf	; 191
	.db #0x5f	; 95
	.db #0x7f	; 127
	.db #0x67	; 103	'g'
	.db #0x5f	; 95
	.db #0x38	; 56	'8'
	.db #0x27	; 39
	.db #0x1c	; 28
	.db #0x13	; 19
	.db #0x0f	; 15
	.db #0x0f	; 15
	.db #0xe0	; 224
	.db #0xe0	; 224
	.db #0x38	; 56	'8'
	.db #0xf8	; 248
	.db #0x0c	; 12
	.db #0xfc	; 252
	.db #0x86	; 134
	.db #0x7e	; 126
	.db #0xe2	; 226
	.db #0x1e	; 30
	.db #0xf3	; 243
	.db #0xef	; 239
	.db #0x19	; 25
	.db #0xf7	; 247
	.db #0x4d	; 77	'M'
	.db #0x3b	; 59
	.db #0x09	; 9
	.db #0xf7	; 247
	.db #0xe3	; 227
	.db #0x1f	; 31
	.db #0x1d	; 29
	.db #0xff	; 255
	.db #0xfa	; 250
	.db #0xfe	; 254
	.db #0xe2	; 226
	.db #0xfe	; 254
	.db #0x0c	; 12
	.db #0xfc	; 252
	.db #0x18	; 24
	.db #0xf8	; 248
	.db #0xf0	; 240
	.db #0xf0	; 240
_ennemy16x16_sprite_metasprite0:
	.db #0xf8	; -8
	.db #0xfc	; -4
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x80	; -128
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
_ennemy16x16_sprite_metasprite1:
	.db #0xf8	; -8
	.db #0xfc	; -4
	.db #0x02	; 2
	.db #0x00	; 0
	.db #0x80	; -128
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
_ennemy16x16_sprite_metasprites:
	.dw _ennemy16x16_sprite_metasprite0
	.dw _ennemy16x16_sprite_metasprite1
	.area _INITIALIZER
	.area _CABS (ABS)
