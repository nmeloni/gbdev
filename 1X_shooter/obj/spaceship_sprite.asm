;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler
; Version 4.5.1 #15267 (Linux)
;--------------------------------------------------------
	.module spaceship_sprite
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _spaceship_sprite_metasprites
	.globl _spaceship_sprite_metasprite0
	.globl _spaceship_sprite_tiles
	.globl _spaceship_sprite_palettes
	.globl b___func_spaceship_sprite
	.globl ___func_spaceship_sprite
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
;res/spaceship_sprite.c:7: BANKREF(spaceship_sprite)
;	---------------------------------
; Function __func_spaceship_sprite
; ---------------------------------
	b___func_spaceship_sprite	= 0
___func_spaceship_sprite::
	.local b___func_spaceship_sprite 
	___bank_spaceship_sprite = b___func_spaceship_sprite 
	.globl ___bank_spaceship_sprite 
	.area _CODE
_spaceship_sprite_palettes:
	.dw #0x294a
	.dw #0x7fff
	.dw #0x56b5
	.dw #0x0000
_spaceship_sprite_tiles:
	.db #0x01	; 1
	.db #0x01	; 1
	.db #0x02	; 2
	.db #0x03	; 3
	.db #0x05	; 5
	.db #0x07	; 7
	.db #0x05	; 5
	.db #0x06	; 6
	.db #0x05	; 5
	.db #0x06	; 6
	.db #0x02	; 2
	.db #0x03	; 3
	.db #0x02	; 2
	.db #0x03	; 3
	.db #0x26	; 38
	.db #0x25	; 37
	.db #0x3a	; 58
	.db #0x3f	; 63
	.db #0x6d	; 109	'm'
	.db #0x7f	; 127
	.db #0xd5	; 213
	.db #0xaf	; 175
	.db #0xab	; 171
	.db #0xde	; 222
	.db #0xde	; 222
	.db #0xbb	; 187
	.db #0xbf	; 191
	.db #0xfe	; 254
	.db #0x71	; 113	'q'
	.db #0x61	; 97	'a'
	.db #0x00	; 0
	.db #0x30	; 48	'0'
	.db #0x80	; 128
	.db #0x80	; 128
	.db #0x40	; 64
	.db #0xc0	; 192
	.db #0xa0	; 160
	.db #0xe0	; 224
	.db #0xa0	; 160
	.db #0x60	; 96
	.db #0xa0	; 160
	.db #0x60	; 96
	.db #0x40	; 64
	.db #0xc0	; 192
	.db #0x40	; 64
	.db #0xc0	; 192
	.db #0x64	; 100	'd'
	.db #0xa4	; 164
	.db #0x5c	; 92
	.db #0xfc	; 252
	.db #0xb6	; 182
	.db #0xfe	; 254
	.db #0xbb	; 187
	.db #0xe5	; 229
	.db #0xd5	; 213
	.db #0x7b	; 123
	.db #0x7b	; 123
	.db #0xdd	; 221
	.db #0xfd	; 253
	.db #0x7f	; 127
	.db #0x8e	; 142
	.db #0x86	; 134
	.db #0x00	; 0
	.db #0x0c	; 12
_spaceship_sprite_metasprite0:
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
_spaceship_sprite_metasprites:
	.dw _spaceship_sprite_metasprite0
	.area _INITIALIZER
	.area _CABS (ABS)
