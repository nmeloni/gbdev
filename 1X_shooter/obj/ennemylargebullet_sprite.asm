;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler
; Version 4.5.1 #15267 (Linux)
;--------------------------------------------------------
	.module ennemylargebullet_sprite
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _ennemylargebullet_sprite_metasprites
	.globl _ennemylargebullet_sprite_metasprite0
	.globl _ennemylargebullet_sprite_tiles
	.globl _ennemylargebullet_sprite_palettes
	.globl b___func_ennemylargebullet_sprite
	.globl ___func_ennemylargebullet_sprite
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
;res/ennemylargebullet_sprite.c:7: BANKREF(ennemylargebullet_sprite)
;	---------------------------------
; Function __func_ennemylargebullet_sprite
; ---------------------------------
	b___func_ennemylargebullet_sprite	= 0
___func_ennemylargebullet_sprite::
	.local b___func_ennemylargebullet_sprite 
	___bank_ennemylargebullet_sprite = b___func_ennemylargebullet_sprite 
	.globl ___bank_ennemylargebullet_sprite 
	.area _CODE
_ennemylargebullet_sprite_palettes:
	.dw #0x294a
	.dw #0x7fff
	.dw #0x56b5
	.dw #0x0000
_ennemylargebullet_sprite_tiles:
	.db #0x0b	; 11
	.db #0x07	; 7
	.db #0x2c	; 44
	.db #0x1f	; 31
	.db #0x50	; 80	'P'
	.db #0x3f	; 63
	.db #0x22	; 34
	.db #0x7d	; 125
	.db #0xc5	; 197
	.db #0x7a	; 122	'z'
	.db #0x4b	; 75	'K'
	.db #0xf4	; 244
	.db #0x97	; 151
	.db #0xe8	; 232
	.db #0x8f	; 143
	.db #0xf0	; 240
	.db #0x8f	; 143
	.db #0xf0	; 240
	.db #0x97	; 151
	.db #0xe8	; 232
	.db #0x4b	; 75	'K'
	.db #0xf4	; 244
	.db #0xc5	; 197
	.db #0x7a	; 122	'z'
	.db #0x22	; 34
	.db #0x7d	; 125
	.db #0x50	; 80	'P'
	.db #0x3f	; 63
	.db #0x2c	; 44
	.db #0x1f	; 31
	.db #0x0b	; 11
	.db #0x07	; 7
	.db #0xd0	; 208
	.db #0xe0	; 224
	.db #0x34	; 52	'4'
	.db #0xf8	; 248
	.db #0x0a	; 10
	.db #0xfc	; 252
	.db #0x44	; 68	'D'
	.db #0xbe	; 190
	.db #0xa3	; 163
	.db #0x5e	; 94
	.db #0xd2	; 210
	.db #0x2f	; 47
	.db #0xe9	; 233
	.db #0x17	; 23
	.db #0xf1	; 241
	.db #0x0f	; 15
	.db #0xf1	; 241
	.db #0x0f	; 15
	.db #0xe9	; 233
	.db #0x17	; 23
	.db #0xd2	; 210
	.db #0x2f	; 47
	.db #0xa3	; 163
	.db #0x5e	; 94
	.db #0x44	; 68	'D'
	.db #0xbe	; 190
	.db #0x0a	; 10
	.db #0xfc	; 252
	.db #0x34	; 52	'4'
	.db #0xf8	; 248
	.db #0xd0	; 208
	.db #0xe0	; 224
_ennemylargebullet_sprite_metasprite0:
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
_ennemylargebullet_sprite_metasprites:
	.dw _ennemylargebullet_sprite_metasprite0
	.area _INITIALIZER
	.area _CABS (ABS)
