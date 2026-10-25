PNG2ASSET = $(GBDKDIR)/bin/png2asset

SPRITE_DIR = sprites
RESDIR     = ../res

all: $(RESDIR)/player.c

$(RESDIR)/player.c: $(SPRITE_DIR)/player.png
	$(PNG2ASSET) $< -c $@ -sw 16 -sh 16 -spr8x16 -noflip -keep_palette_order

