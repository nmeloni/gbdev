GBDK_DIR = ${GBDKDIR}

LCC = $(GBDK_DIR)/bin/lcc
RES = res
SRC = sidescroller.c $(wildcard $(RES)/*.c)
INC = -I$(RES)

BIN = sidescroller.gb

all: $(BIN)

$(BIN) : $(SRC)
	$(LCC) -o $@ $^ $(INC)

clean:
	rm -f $(BIN) *~
