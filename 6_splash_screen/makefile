GBDK_DIR = ${GBDKDIR}
PNG2ASSET = $(GBDK_DIR)/bin/png2asset

LCC = $(GBDK_DIR)/bin/lcc
RES = res
SRC = splash_screen.c res/alphabet.c res/splashscreen.c
INC = -Ires

BIN = splash_screen.gb

all: $(BIN)

$(BIN) : $(SRC)
	$(LCC) -o $@ $^ $(INC)

res/splashscreen.c: res/splashscreen.png
	$(PNG2ASSET) $< -map -noflip

clean:
	rm -f $(BIN) *~ res/splashscreen.c
