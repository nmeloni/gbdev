;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler
; Version 4.5.1 #15267 (Linux)
;--------------------------------------------------------
	.module explosion_sprite
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _explosion_sprite_metasprites
	.globl _explosion_sprite_metasprite3
	.globl _explosion_sprite_metasprite2
	.globl _explosion_sprite_metasprite1
	.globl _explosion_sprite_metasprite0
	.globl _explosion_sprite_tiles
	.globl _explosion_sprite_palettes
	.globl b___func_explosion_sprite
	.globl ___func_explosion_sprite
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
;res/explosion_sprite.c:7: BANKREF(explosion_sprite)
;	---------------------------------
; Function __func_explosion_sprite
; ---------------------------------
	b___func_explosion_sprite	= 0
___func_explosion_sprite::
	.local b___func_explosion_sprite 
	___bank_explosion_sprite = b___func_explosion_sprite 
	.globl ___bank_explosion_sprite 
	.area _CODE
_explosion_sprite_palettes:
	.dw #0x294a
	.dw #0x7fff
	.dw #0x56b5
	.dw #0x0000
_explosion_sprite_tiles:
	.db #0x08	; 8
	.db #0x0c	; 12
	.db #0x42	; 66	'B'
	.db #0x6c	; 108	'l'
	.db #0x2a	; 42
	.db #0x44	; 68	'D'
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x80	; 128
	.db #0xc0	; 192
	.db #0x40	; 64
	.db #0x80	; 128
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x80	; 128
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x40	; 64
	.db #0x80	; 128
	.db #0x80	; 128
	.db #0xc0	; 192
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x28	; 40
	.db #0x40	; 64
	.db #0x44	; 68	'D'
	.db #0x68	; 104	'h'
	.db #0x0a	; 10
	.db #0x0d	; 13
	.db #0x01	; 1
	.db #0x01	; 1
	.db #0x40	; 64
	.db #0x40	; 64
	.db #0x90	; 144
	.db #0x70	; 112	'p'
	.db #0xca	; 202
	.db #0x26	; 38
	.db #0x04	; 4
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x0a	; 10
	.db #0x06	; 6
	.db #0x04	; 4
	.db #0x02	; 2
	.db #0x01	; 1
	.db #0x03	; 3
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x0a	; 10
	.db #0x06	; 6
	.db #0x14	; 20
	.db #0x08	; 8
	.db #0x08	; 8
	.db #0x88	; 136
	.db #0x00	; 0
	.db #0x80	; 128
	.db #0x0d	; 13
	.db #0x0d	; 13
	.db #0x20	; 32
	.db #0x3f	; 63
	.db #0x4a	; 74	'J'
	.db #0x75	; 117	'u'
	.db #0x91	; 145
	.db #0xee	; 238
	.db #0xac	; 172
	.db #0xd3	; 211
	.db #0x97	; 151
	.db #0xe8	; 232
	.db #0x2f	; 47
	.db #0x50	; 80	'P'
	.db #0x97	; 151
	.db #0xe8	; 232
	.db #0x2f	; 47
	.db #0x50	; 80	'P'
	.db #0x97	; 151
	.db #0xe8	; 232
	.db #0xad	; 173
	.db #0xd2	; 210
	.db #0x0b	; 11
	.db #0x14	; 20
	.db #0x45	; 69	'E'
	.db #0x4a	; 74	'J'
	.db #0x12	; 18
	.db #0x1d	; 29
	.db #0x08	; 8
	.db #0x0f	; 15
	.db #0x02	; 2
	.db #0x03	; 3
	.db #0x10	; 16
	.db #0x70	; 112	'p'
	.db #0x08	; 8
	.db #0xf8	; 248
	.db #0xa4	; 164
	.db #0x5c	; 92
	.db #0xb2	; 178
	.db #0x4e	; 78	'N'
	.db #0xc2	; 194
	.db #0x3e	; 62
	.db #0xa9	; 169
	.db #0x57	; 87	'W'
	.db #0xd0	; 208
	.db #0x2e	; 46
	.db #0xa9	; 169
	.db #0x57	; 87	'W'
	.db #0xd0	; 208
	.db #0x2c	; 44
	.db #0xea	; 234
	.db #0x16	; 22
	.db #0xf2	; 242
	.db #0x0e	; 14
	.db #0xda	; 218
	.db #0x26	; 38
	.db #0xe6	; 230
	.db #0x1e	; 30
	.db #0xac	; 172
	.db #0x54	; 84	'T'
	.db #0x08	; 8
	.db #0xf8	; 248
	.db #0x60	; 96
	.db #0xe0	; 224
	.db #0x01	; 1
	.db #0x01	; 1
	.db #0x0e	; 14
	.db #0x0f	; 15
	.db #0x10	; 16
	.db #0x1f	; 31
	.db #0x20	; 32
	.db #0x3f	; 63
	.db #0x42	; 66	'B'
	.db #0x7d	; 125
	.db #0x45	; 69	'E'
	.db #0x7a	; 122	'z'
	.db #0x4b	; 75	'K'
	.db #0x74	; 116	't'
	.db #0x57	; 87	'W'
	.db #0x68	; 104	'h'
	.db #0x4b	; 75	'K'
	.db #0x74	; 116	't'
	.db #0x47	; 71	'G'
	.db #0x78	; 120	'x'
	.db #0x4a	; 74	'J'
	.db #0x75	; 117	'u'
	.db #0x25	; 37
	.db #0x3a	; 58
	.db #0x10	; 16
	.db #0x1f	; 31
	.db #0x0f	; 15
	.db #0x0f	; 15
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0xe0	; 224
	.db #0xe0	; 224
	.db #0x30	; 48	'0'
	.db #0xf0	; 240
	.db #0x10	; 16
	.db #0xf0	; 240
	.db #0x8c	; 140
	.db #0x7c	; 124
	.db #0x44	; 68	'D'
	.db #0xbc	; 188
	.db #0xa4	; 164
	.db #0x5c	; 92
	.db #0xc2	; 194
	.db #0x3e	; 62
	.db #0xa2	; 162
	.db #0x5e	; 94
	.db #0x52	; 82	'R'
	.db #0xae	; 174
	.db #0xaa	; 170
	.db #0x56	; 86	'V'
	.db #0x42	; 66	'B'
	.db #0xbe	; 190
	.db #0x04	; 4
	.db #0xe4	; 228
	.db #0x1c	; 28
	.db #0xfc	; 252
	.db #0xe0	; 224
	.db #0xe0	; 224
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x02	; 2
	.db #0x03	; 3
	.db #0x08	; 8
	.db #0x0f	; 15
	.db #0x10	; 16
	.db #0x1f	; 31
	.db #0x32	; 50	'2'
	.db #0x3d	; 61
	.db #0x23	; 35
	.db #0x3c	; 60
	.db #0x21	; 33
	.db #0x3e	; 62
	.db #0x12	; 18
	.db #0x1d	; 29
	.db #0x00	; 0
	.db #0x07	; 7
	.db #0x04	; 4
	.db #0x07	; 7
	.db #0x01	; 1
	.db #0x01	; 1
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x60	; 96
	.db #0xe0	; 224
	.db #0x10	; 16
	.db #0xf0	; 240
	.db #0xc8	; 200
	.db #0x38	; 56	'8'
	.db #0xa0	; 160
	.db #0x58	; 88	'X'
	.db #0x80	; 128
	.db #0x78	; 120	'x'
	.db #0x80	; 128
	.db #0x78	; 120	'x'
	.db #0x40	; 64
	.db #0xb8	; 184
	.db #0x28	; 40
	.db #0xd8	; 216
	.db #0x08	; 8
	.db #0xf8	; 248
	.db #0xd0	; 208
	.db #0xf0	; 240
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
_explosion_sprite_metasprite0:
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
_explosion_sprite_metasprite1:
	.db #0xf8	; -8
	.db #0xf8	; -8
	.db #0x04	; 4
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x06	; 6
	.db #0x00	; 0
	.db #0x80	; -128
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
_explosion_sprite_metasprite2:
	.db #0xf8	; -8
	.db #0xf8	; -8
	.db #0x08	; 8
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x0a	; 10
	.db #0x00	; 0
	.db #0x80	; -128
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
_explosion_sprite_metasprite3:
	.db #0xf8	; -8
	.db #0xf8	; -8
	.db #0x0c	; 12
	.db #0x00	; 0
	.db #0x00	;  0
	.db #0x08	;  8
	.db #0x0e	; 14
	.db #0x00	; 0
	.db #0x80	; -128
	.db #0x00	;  0
	.db #0x00	; 0
	.db #0x00	; 0
_explosion_sprite_metasprites:
	.dw _explosion_sprite_metasprite0
	.dw _explosion_sprite_metasprite1
	.dw _explosion_sprite_metasprite2
	.dw _explosion_sprite_metasprite3
	.area _INITIALIZER
	.area _CABS (ABS)
