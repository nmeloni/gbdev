;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler
; Version 4.5.1 #15267 (Linux)
;--------------------------------------------------------
	.module powerup_sprite
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _powerup_sprite_metasprites
	.globl _powerup_sprite_metasprite2
	.globl _powerup_sprite_metasprite1
	.globl _powerup_sprite_metasprite0
	.globl _powerup_sprite_tiles
	.globl _powerup_sprite_palettes
	.globl b___func_powerup_sprite
	.globl ___func_powerup_sprite
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
;res/powerup_sprite.c:7: BANKREF(powerup_sprite)
;	---------------------------------
; Function __func_powerup_sprite
; ---------------------------------
	b___func_powerup_sprite	= 0
___func_powerup_sprite::
	.local b___func_powerup_sprite 
	___bank_powerup_sprite = b___func_powerup_sprite 
	.globl ___bank_powerup_sprite 
	.area _CODE
_powerup_sprite_palettes:
	.dw #0x294a
	.dw #0x7fff
	.dw #0x56b5
	.dw #0x0000
_powerup_sprite_tiles:
	.db #0x3f	; 63
	.db #0x3f	; 63
	.db #0x3f	; 63
	.db #0x20	; 32
	.db #0xff	; 255
	.db #0xc0	; 192
	.db #0xff	; 255
	.db #0x8f	; 143
	.db #0xf0	; 240
	.db #0x9f	; 159
	.db #0xe1	; 225
	.db #0x99	; 153
	.db #0xe1	; 225
	.db #0x91	; 145
	.db #0xe2	; 226
	.db #0x92	; 146
	.db #0xe3	; 227
	.db #0x93	; 147
	.db #0xe6	; 230
	.db #0x97	; 151
	.db #0xe6	; 230
	.db #0x96	; 150
	.db #0xe6	; 230
	.db #0x96	; 150
	.db #0xf0	; 240
	.db #0x8f	; 143
	.db #0xff	; 255
	.db #0xc0	; 192
	.db #0x3f	; 63
	.db #0x20	; 32
	.db #0x3f	; 63
	.db #0x3f	; 63
	.db #0xfc	; 252
	.db #0xfc	; 252
	.db #0xfc	; 252
	.db #0x04	; 4
	.db #0xff	; 255
	.db #0x03	; 3
	.db #0xff	; 255
	.db #0xf1	; 241
	.db #0x0f	; 15
	.db #0xf9	; 249
	.db #0xe7	; 231
	.db #0xf9	; 249
	.db #0x17	; 23
	.db #0x79	; 121	'y'
	.db #0x17	; 23
	.db #0x39	; 57	'9'
	.db #0xe7	; 231
	.db #0xe9	; 233
	.db #0x07	; 7
	.db #0xc9	; 201
	.db #0x07	; 7
	.db #0x09	; 9
	.db #0x07	; 7
	.db #0x09	; 9
	.db #0x0f	; 15
	.db #0xf1	; 241
	.db #0xff	; 255
	.db #0x03	; 3
	.db #0xfc	; 252
	.db #0x04	; 4
	.db #0xfc	; 252
	.db #0xfc	; 252
	.db #0x3f	; 63
	.db #0x3f	; 63
	.db #0x3f	; 63
	.db #0x20	; 32
	.db #0xff	; 255
	.db #0xc0	; 192
	.db #0xff	; 255
	.db #0x8f	; 143
	.db #0xf0	; 240
	.db #0x9f	; 159
	.db #0xe0	; 224
	.db #0x98	; 152
	.db #0xe1	; 225
	.db #0x91	; 145
	.db #0xe2	; 226
	.db #0x93	; 147
	.db #0xe1	; 225
	.db #0x91	; 145
	.db #0xe0	; 224
	.db #0x91	; 145
	.db #0xe7	; 231
	.db #0x97	; 151
	.db #0xe0	; 224
	.db #0x96	; 150
	.db #0xf0	; 240
	.db #0x8f	; 143
	.db #0xff	; 255
	.db #0xc0	; 192
	.db #0x3f	; 63
	.db #0x20	; 32
	.db #0x3f	; 63
	.db #0x3f	; 63
	.db #0xfc	; 252
	.db #0xfc	; 252
	.db #0xfc	; 252
	.db #0x04	; 4
	.db #0xff	; 255
	.db #0x03	; 3
	.db #0xff	; 255
	.db #0xf1	; 241
	.db #0x0f	; 15
	.db #0xf9	; 249
	.db #0xe7	; 231
	.db #0xf9	; 249
	.db #0x07	; 7
	.db #0xc9	; 201
	.db #0x07	; 7
	.db #0x09	; 9
	.db #0x87	; 135
	.db #0x89	; 137
	.db #0x47	; 71	'G'
	.db #0xc9	; 201
	.db #0x87	; 135
	.db #0xc9	; 201
	.db #0x07	; 7
	.db #0x09	; 9
	.db #0x0f	; 15
	.db #0xf1	; 241
	.db #0xff	; 255
	.db #0x03	; 3
	.db #0xfc	; 252
	.db #0x04	; 4
	.db #0xfc	; 252
	.db #0xfc	; 252
	.db #0x3f	; 63
	.db #0x3f	; 63
	.db #0x3f	; 63
	.db #0x20	; 32
	.db #0xff	; 255
	.db #0xc0	; 192
	.db #0xff	; 255
	.db #0x8f	; 143
	.db #0xf0	; 240
	.db #0x9f	; 159
	.db #0xe0	; 224
	.db #0x98	; 152
	.db #0xe5	; 229
	.db #0x95	; 149
	.db #0xed	; 237
	.db #0x9d	; 157
	.db #0xe5	; 229
	.db #0x9d	; 157
	.db #0xe4	; 228
	.db #0x95	; 149
	.db #0xe0	; 224
	.db #0x90	; 144
	.db #0xe0	; 224
	.db #0x90	; 144
	.db #0xf0	; 240
	.db #0x8f	; 143
	.db #0xff	; 255
	.db #0xc0	; 192
	.db #0x3f	; 63
	.db #0x20	; 32
	.db #0x3f	; 63
	.db #0x3f	; 63
	.db #0xfc	; 252
	.db #0xfc	; 252
	.db #0xfc	; 252
	.db #0x04	; 4
	.db #0xff	; 255
	.db #0x03	; 3
	.db #0xff	; 255
	.db #0xf1	; 241
	.db #0x0f	; 15
	.db #0xf9	; 249
	.db #0x07	; 7
	.db #0x19	; 25
	.db #0x77	; 119	'w'
	.db #0x79	; 121	'y'
	.db #0x57	; 87	'W'
	.db #0x79	; 121	'y'
	.db #0x77	; 119	'w'
	.db #0x79	; 121	'y'
	.db #0xc7	; 199
	.db #0xc9	; 201
	.db #0x47	; 71	'G'
	.db #0xc9	; 201
	.db #0x07	; 7
	.db #0x09	; 9
	.db #0x0f	; 15
	.db #0xf1	; 241
	.db #0xff	; 255
	.db #0x03	; 3
	.db #0xfc	; 252
	.db #0x04	; 4
	.db #0xfc	; 252
	.db #0xfc	; 252
_powerup_sprite_metasprite0:
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
_powerup_sprite_metasprite1:
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
_powerup_sprite_metasprite2:
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
_powerup_sprite_metasprites:
	.dw _powerup_sprite_metasprite0
	.dw _powerup_sprite_metasprite1
	.dw _powerup_sprite_metasprite2
	.area _INITIALIZER
	.area _CABS (ABS)
