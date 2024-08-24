GBDK_DIR  := ${GBDKDIR}
PNG2ASSET := $(GBDK_DIR)bin/png2asset

PNGDIR    := png

all: playersprites.c

playersprites.c: $(PNGDIR)/playersprites.png
	$(PNG2ASSET) $^ -c $@ -sw 16 -sh 32 -spr8x8 -keep_palette_order

clean:
	rm -f *.[hc] *~
