GBDK_DIR = ${GBDKDIR}

LCC = $(GBDK_DIR)/bin/lcc
RES = res
SRC = hellosprite.c res/alphabet.c
INC = -Ires

BIN = hellosprite.gb

all: $(BIN)

$(BIN) : $(SRC)
	$(LCC) -o $@ $^ $(INC)

clean:
	rm -f $(BIN) *~
