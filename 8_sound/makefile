GBDK_DIR = ${GBDKDIR}
PNG2ASSET = $(GBDK_DIR)/bin/png2asset

LCC = $(GBDK_DIR)/bin/lcc
RES = res
PNG = $(RES)/png
SRC = sound.c 
INC = -Ires

BIN = sound.gb

all: $(BIN)

$(BIN) : $(SRC)
	$(LCC) -o $@ $^ $(INC)

clean:
	rm -f $(BIN) *~ 
