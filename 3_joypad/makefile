GBDK_DIR = ${GBDKDIR}

LCC = $(GBDK_DIR)/bin/lcc
RES = res
SRC = joypad.c res/buttons.c
INC = -Ires

BIN = joypad.gb

all: $(BIN)

$(BIN) : $(SRC)
	$(LCC) -o $@ $^ $(INC)

clean:
	rm -f $(BIN) *~
