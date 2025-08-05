GBDK_DIR = ${GBDKDIR}
PNG2ASSET = $(GBDK_DIR)/bin/png2asset

LCC = $(GBDK_DIR)/bin/lcc
RES = res
PNG = $(RES)/png
SRC = score.c $(RES)/gb_numbers.c
INC = -Ires

BIN = score.gb

all: $(BIN)

$(BIN) : $(SRC)
	$(LCC) -o $@ $^ $(INC)

$(RES)/%.c: $(PNG)/%.png
	$(PNG2ASSET) $^ -c $@ -sw 8 -sh 8 -spr8x8

clean:
	rm -f $(BIN) *~ $(RES)/*.c
