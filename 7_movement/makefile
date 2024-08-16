GBDK_DIR = ${GBDKDIR}
PNG2ASSET = $(GBDK_DIR)/bin/png2asset

LCC = $(GBDK_DIR)/bin/lcc
RES = res
PNG = $(RES)/png
SRC = movements.c $(RES)/carti.c
INC = -Ires

BIN = movements.gb

all: $(BIN)

$(BIN) : $(SRC)
	$(LCC) -o $@ $^ $(INC)

$(RES)/carti.c: $(PNG)/carti.png
	$(PNG2ASSET) $^ -c $@ -sw 16 -sh 16 -spr8x8

clean:
	rm -f $(BIN) *~ $(RES)/carti.c
