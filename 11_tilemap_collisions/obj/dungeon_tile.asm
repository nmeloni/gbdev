;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler
; Version 4.5.1 #15267 (Linux)
;--------------------------------------------------------
	.module dungeon_tile
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _dungeon_tile_tiles
	.globl _dungeon_tile_palettes
	.globl b___func_dungeon_tile
	.globl ___func_dungeon_tile
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
;res/dungeon_tile.c:7: BANKREF(dungeon_tile)
;	---------------------------------
; Function __func_dungeon_tile
; ---------------------------------
	b___func_dungeon_tile	= 0
___func_dungeon_tile::
	.local b___func_dungeon_tile 
	___bank_dungeon_tile = b___func_dungeon_tile 
	.globl ___bank_dungeon_tile 
	.area _CODE
_dungeon_tile_palettes:
	.dw #0x7fff
	.dw #0x56b5
	.dw #0x294a
	.dw #0x0000
_dungeon_tile_tiles:
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x79	; 121	'y'
	.db #0x80	; 128
	.db #0x7f	; 127
	.db #0x80	; 128
	.db #0x7f	; 127
	.db #0x80	; 128
	.db #0x3f	; 63
	.db #0xc0	; 192
	.db #0x7f	; 127
	.db #0x80	; 128
	.db #0x7f	; 127
	.db #0x80	; 128
	.db #0x37	; 55	'7'
	.db #0xc8	; 200
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x40	; 64
	.db #0x01	; 1
	.db #0xfc	; 252
	.db #0x01	; 1
	.db #0xfc	; 252
	.db #0x01	; 1
	.db #0xfc	; 252
	.db #0x01	; 1
	.db #0xfc	; 252
	.db #0x01	; 1
	.db #0xfe	; 254
	.db #0x01	; 1
	.db #0xfc	; 252
	.db #0x01	; 1
	.db #0xe6	; 230
	.db #0xc0	; 192
	.db #0xff	; 255
	.db #0x80	; 128
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0x3f	; 63
	.db #0xc0	; 192
	.db #0x80	; 128
	.db #0xff	; 255
	.db #0xc0	; 192
	.db #0xff	; 255
	.db #0x83	; 131
	.db #0x03	; 3
	.db #0xfd	; 253
	.db #0x01	; 1
	.db #0xfe	; 254
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xfc	; 252
	.db #0x03	; 3
	.db #0x01	; 1
	.db #0xff	; 255
	.db #0x03	; 3
	.db #0xff	; 255
	.db #0xef	; 239
	.db #0xc7	; 199
	.db #0xf7	; 247
	.db #0x83	; 131
	.db #0xfb	; 251
	.db #0x83	; 131
	.db #0xff	; 255
	.db #0x83	; 131
	.db #0xff	; 255
	.db #0x83	; 131
	.db #0xff	; 255
	.db #0x83	; 131
	.db #0xff	; 255
	.db #0x83	; 131
	.db #0xff	; 255
	.db #0x83	; 131
	.db #0xf7	; 247
	.db #0xe3	; 227
	.db #0xfb	; 251
	.db #0xc1	; 193
	.db #0xfd	; 253
	.db #0xc1	; 193
	.db #0xff	; 255
	.db #0xc1	; 193
	.db #0xff	; 255
	.db #0xc1	; 193
	.db #0xff	; 255
	.db #0xc1	; 193
	.db #0xff	; 255
	.db #0xc1	; 193
	.db #0xff	; 255
	.db #0xc1	; 193
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xf8	; 248
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xc7	; 199
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0x9f	; 159
	.db #0x3f	; 63
	.db #0xdf	; 223
	.db #0x3f	; 63
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0x1f	; 31
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xe3	; 227
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xf9	; 249
	.db #0xfc	; 252
	.db #0xfb	; 251
	.db #0xfc	; 252
	.db #0xff	; 255
	.db #0x5f	; 95
	.db #0xa0	; 160
	.db #0x2f	; 47
	.db #0xd0	; 208
	.db #0x0e	; 14
	.db #0xf1	; 241
	.db #0x27	; 39
	.db #0xd8	; 216
	.db #0x13	; 19
	.db #0xec	; 236
	.db #0x29	; 41
	.db #0xd6	; 214
	.db #0x54	; 84	'T'
	.db #0xab	; 171
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0xfc	; 252
	.db #0x01	; 1
	.db #0xfc	; 252
	.db #0x01	; 1
	.db #0xfe	; 254
	.db #0x01	; 1
	.db #0xfc	; 252
	.db #0x01	; 1
	.db #0xbe	; 190
	.db #0x41	; 65	'A'
	.db #0xfe	; 254
	.db #0x01	; 1
	.db #0xee	; 238
	.db #0x11	; 17
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0x10	; 16
	.db #0x10	; 16
	.db #0xff	; 255
	.db #0x10	; 16
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0x02	; 2
	.db #0x02	; 2
	.db #0xff	; 255
	.db #0x02	; 2
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0x04	; 4
	.db #0x04	; 4
	.db #0xff	; 255
	.db #0x04	; 4
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0x60	; 96
	.db #0x60	; 96
	.db #0xff	; 255
	.db #0x60	; 96
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0x83	; 131
	.db #0xff	; 255
	.db #0x83	; 131
	.db #0xff	; 255
	.db #0x83	; 131
	.db #0xff	; 255
	.db #0x83	; 131
	.db #0xff	; 255
	.db #0x83	; 131
	.db #0xbb	; 187
	.db #0xc7	; 199
	.db #0x83	; 131
	.db #0xff	; 255
	.db #0xc7	; 199
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xc1	; 193
	.db #0xff	; 255
	.db #0xc1	; 193
	.db #0xff	; 255
	.db #0xc1	; 193
	.db #0xff	; 255
	.db #0xc1	; 193
	.db #0xff	; 255
	.db #0xc1	; 193
	.db #0xdd	; 221
	.db #0xe3	; 227
	.db #0xc1	; 193
	.db #0xff	; 255
	.db #0xe3	; 227
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0x3f	; 63
	.db #0x3f	; 63
	.db #0xff	; 255
	.db #0x3f	; 63
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xf5	; 245
	.db #0x3f	; 63
	.db #0x2a	; 42
	.db #0xf5	; 245
	.db #0x3f	; 63
	.db #0xc0	; 192
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xfc	; 252
	.db #0xfc	; 252
	.db #0xff	; 255
	.db #0xfc	; 252
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0x5f	; 95
	.db #0xfc	; 252
	.db #0xac	; 172
	.db #0x57	; 87	'W'
	.db #0xfc	; 252
	.db #0x03	; 3
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x77	; 119	'w'
	.db #0x88	; 136
	.db #0x7b	; 123
	.db #0x84	; 132
	.db #0x7c	; 124
	.db #0x83	; 131
	.db #0x7f	; 127
	.db #0x80	; 128
	.db #0x7f	; 127
	.db #0x80	; 128
	.db #0x7f	; 127
	.db #0x80	; 128
	.db #0x7f	; 127
	.db #0x80	; 128
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0xf8	; 248
	.db #0x07	; 7
	.db #0xfc	; 252
	.db #0x03	; 3
	.db #0xfe	; 254
	.db #0x01	; 1
	.db #0xfe	; 254
	.db #0x01	; 1
	.db #0xfe	; 254
	.db #0x01	; 1
	.db #0xde	; 222
	.db #0x21	; 33
	.db #0xce	; 206
	.db #0x31	; 49	'1'
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x7f	; 127
	.db #0x80	; 128
	.db #0x7f	; 127
	.db #0x80	; 128
	.db #0x7f	; 127
	.db #0x80	; 128
	.db #0x7f	; 127
	.db #0x80	; 128
	.db #0x7f	; 127
	.db #0x80	; 128
	.db #0x7f	; 127
	.db #0x80	; 128
	.db #0x7f	; 127
	.db #0x80	; 128
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0xfe	; 254
	.db #0x01	; 1
	.db #0xfe	; 254
	.db #0x01	; 1
	.db #0xfe	; 254
	.db #0x01	; 1
	.db #0xfe	; 254
	.db #0x01	; 1
	.db #0xfe	; 254
	.db #0x01	; 1
	.db #0xfe	; 254
	.db #0x01	; 1
	.db #0xfe	; 254
	.db #0x01	; 1
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xc3	; 195
	.db #0xbf	; 191
	.db #0xe0	; 224
	.db #0x9f	; 159
	.db #0xf0	; 240
	.db #0x8f	; 143
	.db #0xf8	; 248
	.db #0x87	; 135
	.db #0xfc	; 252
	.db #0xc3	; 195
	.db #0xfe	; 254
	.db #0xc1	; 193
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xc3	; 195
	.db #0xff	; 255
	.db #0x05	; 5
	.db #0xff	; 255
	.db #0x09	; 9
	.db #0xff	; 255
	.db #0x11	; 17
	.db #0xff	; 255
	.db #0x21	; 33
	.db #0xff	; 255
	.db #0x43	; 67	'C'
	.db #0xff	; 255
	.db #0x83	; 131
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
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x7b	; 123
	.db #0x84	; 132
	.db #0x7d	; 125
	.db #0x82	; 130
	.db #0x7b	; 123
	.db #0x84	; 132
	.db #0x67	; 103	'g'
	.db #0x98	; 152
	.db #0x7f	; 127
	.db #0x80	; 128
	.db #0x7f	; 127
	.db #0x80	; 128
	.db #0x7f	; 127
	.db #0x80	; 128
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0xee	; 238
	.db #0x11	; 17
	.db #0xee	; 238
	.db #0x11	; 17
	.db #0xfe	; 254
	.db #0x01	; 1
	.db #0xfe	; 254
	.db #0x01	; 1
	.db #0xfe	; 254
	.db #0x01	; 1
	.db #0xfe	; 254
	.db #0x01	; 1
	.db #0xfe	; 254
	.db #0x01	; 1
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x7f	; 127
	.db #0x80	; 128
	.db #0x7f	; 127
	.db #0x80	; 128
	.db #0x7f	; 127
	.db #0x80	; 128
	.db #0x7f	; 127
	.db #0x80	; 128
	.db #0x7f	; 127
	.db #0x80	; 128
	.db #0x7f	; 127
	.db #0x80	; 128
	.db #0x7f	; 127
	.db #0x80	; 128
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0xfe	; 254
	.db #0x01	; 1
	.db #0xfe	; 254
	.db #0x01	; 1
	.db #0xfe	; 254
	.db #0x01	; 1
	.db #0xfe	; 254
	.db #0x01	; 1
	.db #0xfe	; 254
	.db #0x01	; 1
	.db #0xfe	; 254
	.db #0x01	; 1
	.db #0xfe	; 254
	.db #0x01	; 1
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0xc1	; 193
	.db #0xff	; 255
	.db #0xc2	; 194
	.db #0xff	; 255
	.db #0x84	; 132
	.db #0xff	; 255
	.db #0x88	; 136
	.db #0xff	; 255
	.db #0x90	; 144
	.db #0xff	; 255
	.db #0xa0	; 160
	.db #0xff	; 255
	.db #0xc3	; 195
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0x83	; 131
	.db #0x7f	; 127
	.db #0xc3	; 195
	.db #0x3f	; 63
	.db #0xe1	; 225
	.db #0x1f	; 31
	.db #0xf1	; 241
	.db #0x0f	; 15
	.db #0xf9	; 249
	.db #0x07	; 7
	.db #0xfd	; 253
	.db #0xc3	; 195
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.area _INITIALIZER
	.area _CABS (ABS)
