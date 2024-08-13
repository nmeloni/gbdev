GBDK_DIR = ${GBDKDIR}

LCC = $(GBDK_DIR)/bin/lcc
RES = res
SRC = window_display.c $(wildcard $(RES)/*.c)
INC = -I$(RES)

BIN = window_display.gb

all: $(BIN)

$(BIN) : $(SRC)
	$(LCC) -o $@ $^ $(INC)

clean:
	rm -f $(BIN) *~
