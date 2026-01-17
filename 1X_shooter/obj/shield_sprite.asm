;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler
; Version 4.5.1 #15267 (Linux)
;--------------------------------------------------------
	.module shield_sprite
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _shield_sprite_metasprites
	.globl _shield_sprite_metasprite0
	.globl _shield_sprite_tiles
	.globl _shield_sprite_palettes
	.globl b___func_shield_sprite
	.globl ___func_shield_sprite
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
;res/shield_sprite.c:7: BANKREF(shield_sprite)
;	---------------------------------
; Function __func_shield_sprite
; ---------------------------------
	b___func_shield_sprite	= 0
___func_shield_sprite::
	.local b___func_shield_sprite 
	___bank_shield_sprite = b___func_shield_sprite 
	.globl ___bank_shield_sprite 
	.area _CODE
_shield_sprite_palettes:
	.dw #0x7fff
	.dw #0x56b5
	.dw #0x294a
	.dw #0x0000
_shield_sprite_tiles:
	.db #0x09	; 9
	.db #0x06	; 6
	.db #0x26	; 38
	.db #0x18	; 24
	.db #0x58	; 88	'X'
	.db #0x20	; 32
	.db #0x30	; 48	'0'
	.db #0x40	; 64
	.db #0xa0	; 160
	.db #0x40	; 64
	.db #0x40	; 64
	.db #0x80	; 128
	.db #0x40	; 64
	.db #0x80	; 128
	.db #0x80	; 128
	.db #0x00	; 0
	.db #0x80	; 128
	.db #0x00	; 0
	.db #0x40	; 64
	.db #0x80	; 128
	.db #0x40	; 64
	.db #0x80	; 128
	.db #0xa0	; 160
	.db #0x40	; 64
	.db #0x30	; 48	'0'
	.db #0x40	; 64
	.db #0x58	; 88	'X'
	.db #0x20	; 32
	.db #0x26	; 38
	.db #0x18	; 24
	.db #0x09	; 9
	.db #0x06	; 6
	.db #0x90	; 144
	.db #0x60	; 96
	.db #0x64	; 100	'd'
	.db #0x18	; 24
	.db #0x1a	; 26
	.db #0x04	; 4
	.db #0x0c	; 12
	.db #0x02	; 2
	.db #0x05	; 5
	.db #0x02	; 2
	.db #0x02	; 2
	.db #0x01	; 1
	.db #0x02	; 2
	.db #0x01	; 1
	.db #0x01	; 1
	.db #0x00	; 0
	.db #0x01	; 1
	.db #0x00	; 0
	.db #0x02	; 2
	.db #0x01	; 1
	.db #0x02	; 2
	.db #0x01	; 1
	.db #0x05	; 5
	.db #0x02	; 2
	.db #0x0c	; 12
	.db #0x02	; 2
	.db #0x1a	; 26
	.db #0x04	; 4
	.db #0x24	; 36
	.db #0x18	; 24
	.db #0x90	; 144
	.db #0x60	; 96
_shield_sprite_metasprite0:
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
_shield_sprite_metasprites:
	.dw _shield_sprite_metasprite0
	.area _INITIALIZER
	.area _CABS (ABS)
