;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler
; Version 4.5.1 #15267 (Linux)
;--------------------------------------------------------
	.module ennemy_1_sprite
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _ennemy_1_sprite_metasprites
	.globl _ennemy_1_sprite_metasprite0
	.globl _ennemy_1_sprite_tiles
	.globl _ennemy_1_sprite_palettes
	.globl b___func_ennemy_1_sprite
	.globl ___func_ennemy_1_sprite
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
;res/ennemy_1_sprite.c:7: BANKREF(ennemy_1_sprite)
;	---------------------------------
; Function __func_ennemy_1_sprite
; ---------------------------------
	b___func_ennemy_1_sprite	= 0
___func_ennemy_1_sprite::
	.local b___func_ennemy_1_sprite 
	___bank_ennemy_1_sprite = b___func_ennemy_1_sprite 
	.globl ___bank_ennemy_1_sprite 
	.area _CODE
_ennemy_1_sprite_palettes:
	.dw #0x294a
	.dw #0x7fff
	.dw #0x56b5
	.dw #0x0000
_ennemy_1_sprite_tiles:
	.db #0x08	; 8
	.db #0x14	; 20
	.db #0x1c	; 28
	.db #0x22	; 34
	.db #0x14	; 20
	.db #0x3e	; 62
	.db #0x17	; 23
	.db #0x1f	; 31
	.db #0x18	; 24
	.db #0x1f	; 31
	.db #0x7a	; 122	'z'
	.db #0x75	; 117	'u'
	.db #0x8a	; 138
	.db #0xf5	; 245
	.db #0xca	; 202
	.db #0xb5	; 181
	.db #0x69	; 105	'i'
	.db #0x56	; 86	'V'
	.db #0x34	; 52	'4'
	.db #0x2b	; 43
	.db #0x1a	; 26
	.db #0x1d	; 29
	.db #0x15	; 21
	.db #0x1e	; 30
	.db #0x17	; 23
	.db #0x1f	; 31
	.db #0x1c	; 28
	.db #0x0c	; 12
	.db #0x0c	; 12
	.db #0x04	; 4
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x10	; 16
	.db #0x28	; 40
	.db #0x38	; 56	'8'
	.db #0x44	; 68	'D'
	.db #0x28	; 40
	.db #0x7c	; 124
	.db #0xe8	; 232
	.db #0xf8	; 248
	.db #0x18	; 24
	.db #0xf8	; 248
	.db #0x1e	; 30
	.db #0xee	; 238
	.db #0x11	; 17
	.db #0xef	; 239
	.db #0x11	; 17
	.db #0xef	; 239
	.db #0x92	; 146
	.db #0x6e	; 110	'n'
	.db #0x24	; 36
	.db #0xdc	; 220
	.db #0xb8	; 184
	.db #0x58	; 88	'X'
	.db #0x68	; 104	'h'
	.db #0xb8	; 184
	.db #0xe8	; 232
	.db #0xf8	; 248
	.db #0x38	; 56	'8'
	.db #0x30	; 48	'0'
	.db #0x30	; 48	'0'
	.db #0x20	; 32
	.db #0x00	; 0
	.db #0x00	; 0
_ennemy_1_sprite_metasprite0:
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
_ennemy_1_sprite_metasprites:
	.dw _ennemy_1_sprite_metasprite0
	.area _INITIALIZER
	.area _CABS (ABS)
