;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler
; Version 4.5.1 #15267 (Linux)
;--------------------------------------------------------
	.module ennemy_3_sprite
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _ennemy_3_sprite_metasprites
	.globl _ennemy_3_sprite_metasprite0
	.globl _ennemy_3_sprite_tiles
	.globl _ennemy_3_sprite_palettes
	.globl b___func_ennemy_3_sprite
	.globl ___func_ennemy_3_sprite
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
;res/ennemy_3_sprite.c:7: BANKREF(ennemy_3_sprite)
;	---------------------------------
; Function __func_ennemy_3_sprite
; ---------------------------------
	b___func_ennemy_3_sprite	= 0
___func_ennemy_3_sprite::
	.local b___func_ennemy_3_sprite 
	___bank_ennemy_3_sprite = b___func_ennemy_3_sprite 
	.globl ___bank_ennemy_3_sprite 
	.area _CODE
_ennemy_3_sprite_palettes:
	.dw #0x294a
	.dw #0x7fff
	.dw #0x56b5
	.dw #0x0000
_ennemy_3_sprite_tiles:
	.db #0x07	; 7
	.db #0x07	; 7
	.db #0x1d	; 29
	.db #0x1b	; 27
	.db #0x2a	; 42
	.db #0x35	; 53	'5'
	.db #0x55	; 85	'U'
	.db #0x6a	; 106	'j'
	.db #0x6b	; 107	'k'
	.db #0x57	; 87	'W'
	.db #0xd7	; 215
	.db #0xac	; 172
	.db #0xae	; 174
	.db #0xd9	; 217
	.db #0xff	; 255
	.db #0xb9	; 185
	.db #0xfe	; 254
	.db #0xc9	; 201
	.db #0xdf	; 223
	.db #0xa8	; 168
	.db #0xff	; 255
	.db #0x84	; 132
	.db #0x57	; 87	'W'
	.db #0x6b	; 107	'k'
	.db #0x7f	; 127
	.db #0x41	; 65	'A'
	.db #0x35	; 53	'5'
	.db #0x2b	; 43
	.db #0x1e	; 30
	.db #0x19	; 25
	.db #0x07	; 7
	.db #0x07	; 7
	.db #0xe0	; 224
	.db #0xe0	; 224
	.db #0x38	; 56	'8'
	.db #0xd8	; 216
	.db #0x8c	; 140
	.db #0xf4	; 244
	.db #0xc2	; 194
	.db #0xbe	; 190
	.db #0xe6	; 230
	.db #0xda	; 218
	.db #0x31	; 49	'1'
	.db #0xef	; 239
	.db #0x1b	; 27
	.db #0xf5	; 245
	.db #0x91	; 145
	.db #0xff	; 255
	.db #0x9f	; 159
	.db #0xfd	; 253
	.db #0x97	; 151
	.db #0x7f	; 127
	.db #0xeb	; 235
	.db #0x3f	; 63
	.db #0xd6	; 214
	.db #0xfe	; 254
	.db #0xaa	; 170
	.db #0xfe	; 254
	.db #0x54	; 84	'T'
	.db #0xfc	; 252
	.db #0xb8	; 184
	.db #0xf8	; 248
	.db #0xe0	; 224
	.db #0xe0	; 224
_ennemy_3_sprite_metasprite0:
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
_ennemy_3_sprite_metasprites:
	.dw _ennemy_3_sprite_metasprite0
	.area _INITIALIZER
	.area _CABS (ABS)
