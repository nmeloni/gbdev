;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler
; Version 4.5.1 #15267 (Linux)
;--------------------------------------------------------
	.module ennemylaser_sprite
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _ennemylaser_sprite_metasprites
	.globl _ennemylaser_sprite_metasprite0
	.globl _ennemylaser_sprite_tiles
	.globl _ennemylaser_sprite_palettes
	.globl b___func_ennemylaser_sprite
	.globl ___func_ennemylaser_sprite
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
;res/ennemylaser_sprite.c:7: BANKREF(ennemylaser_sprite)
;	---------------------------------
; Function __func_ennemylaser_sprite
; ---------------------------------
	b___func_ennemylaser_sprite	= 0
___func_ennemylaser_sprite::
	.local b___func_ennemylaser_sprite 
	___bank_ennemylaser_sprite = b___func_ennemylaser_sprite 
	.globl ___bank_ennemylaser_sprite 
	.area _CODE
_ennemylaser_sprite_palettes:
	.dw #0x294a
	.dw #0x7fff
	.dw #0x56b5
	.dw #0x0000
_ennemylaser_sprite_tiles:
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x18	; 24
	.db #0x24	; 36
	.db #0x18	; 24
	.db #0x24	; 36
	.db #0x18	; 24
	.db #0x24	; 36
	.db #0x18	; 24
	.db #0x24	; 36
	.db #0x18	; 24
	.db #0x24	; 36
	.db #0x18	; 24
	.db #0x24	; 36
	.db #0x18	; 24
	.db #0x24	; 36
	.db #0x18	; 24
	.db #0x24	; 36
	.db #0x18	; 24
	.db #0x24	; 36
	.db #0x18	; 24
	.db #0x24	; 36
	.db #0x18	; 24
	.db #0x24	; 36
	.db #0x18	; 24
	.db #0x24	; 36
	.db #0x18	; 24
	.db #0x24	; 36
	.db #0x18	; 24
	.db #0x24	; 36
	.db #0x00	; 0
	.db #0x00	; 0
_ennemylaser_sprite_metasprite0:
	.db #0xf8	; -8
	.db #0xfc	; -4
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x80	; -128
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
_ennemylaser_sprite_metasprites:
	.dw _ennemylaser_sprite_metasprite0
	.area _INITIALIZER
	.area _CABS (ABS)
