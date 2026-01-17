;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler
; Version 4.5.1 #15267 (Linux)
;--------------------------------------------------------
	.module ennemy_2_sprite
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _ennemy_2_sprite_metasprites
	.globl _ennemy_2_sprite_metasprite0
	.globl _ennemy_2_sprite_tiles
	.globl _ennemy_2_sprite_palettes
	.globl b___func_ennemy_2_sprite
	.globl ___func_ennemy_2_sprite
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
;res/ennemy_2_sprite.c:7: BANKREF(ennemy_2_sprite)
;	---------------------------------
; Function __func_ennemy_2_sprite
; ---------------------------------
	b___func_ennemy_2_sprite	= 0
___func_ennemy_2_sprite::
	.local b___func_ennemy_2_sprite 
	___bank_ennemy_2_sprite = b___func_ennemy_2_sprite 
	.globl ___bank_ennemy_2_sprite 
	.area _CODE
_ennemy_2_sprite_palettes:
	.dw #0x294a
	.dw #0x7fff
	.dw #0x56b5
	.dw #0x0000
_ennemy_2_sprite_tiles:
	.db #0x0f	; 15
	.db #0x0f	; 15
	.db #0x1a	; 26
	.db #0x15	; 21
	.db #0x35	; 53	'5'
	.db #0x2a	; 42
	.db #0x6b	; 107	'k'
	.db #0x55	; 85	'U'
	.db #0x97	; 151
	.db #0xe9	; 233
	.db #0xa9	; 169
	.db #0xd6	; 214
	.db #0x90	; 144
	.db #0xef	; 239
	.db #0xa8	; 168
	.db #0xd7	; 215
	.db #0xf0	; 240
	.db #0xef	; 239
	.db #0xaa	; 170
	.db #0xf5	; 245
	.db #0xd5	; 213
	.db #0xfa	; 250
	.db #0xaf	; 175
	.db #0xff	; 255
	.db #0x50	; 80	'P'
	.db #0x7f	; 127
	.db #0x20	; 32
	.db #0x3f	; 63
	.db #0x10	; 16
	.db #0x1f	; 31
	.db #0x0f	; 15
	.db #0x0f	; 15
	.db #0xf0	; 240
	.db #0xf0	; 240
	.db #0x38	; 56	'8'
	.db #0xc8	; 200
	.db #0x9c	; 156
	.db #0x64	; 100	'd'
	.db #0xce	; 206
	.db #0xb2	; 178
	.db #0xe7	; 231
	.db #0x99	; 153
	.db #0xab	; 171
	.db #0x55	; 85	'U'
	.db #0x2b	; 43
	.db #0xd5	; 213
	.db #0x1b	; 27
	.db #0xe5	; 229
	.db #0x1b	; 27
	.db #0xe5	; 229
	.db #0xab	; 171
	.db #0x55	; 85	'U'
	.db #0x57	; 87	'W'
	.db #0xa9	; 169
	.db #0xef	; 239
	.db #0xf1	; 241
	.db #0x0e	; 14
	.db #0xf2	; 242
	.db #0x0c	; 12
	.db #0xf4	; 244
	.db #0x08	; 8
	.db #0xf8	; 248
	.db #0xf0	; 240
	.db #0xf0	; 240
_ennemy_2_sprite_metasprite0:
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
_ennemy_2_sprite_metasprites:
	.dw _ennemy_2_sprite_metasprite0
	.area _INITIALIZER
	.area _CABS (ABS)
