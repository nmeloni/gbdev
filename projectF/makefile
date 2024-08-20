GBDK_DIR = ${GBDKDIR}
PNG2ASSET = $(GBDK_DIR)/bin/png2asset

LCC = $(GBDK_DIR)/bin/lcc

RESDIR = res
SRCDIR = src
INCDIR = include

SRC = $(wildcard $(SRCDIR)/*)

BIN = projectF.gb

all: $(BIN)

$(BIN): $(SRC)
	$(LCC) -o $@ $^ 

clean:
	rm -f $(BIN) *~
