GBDK_DIR = ${GBDKDIR}

LCC = $(GBDK_DIR)bin/lcc
SRC = helloworld.c

BIN = helloworld.gb

all: $(BIN)

$(BIN) : $(SRC)
	$(LCC) -o $@ $<

clean:
	rm -f $(BIN) *~
