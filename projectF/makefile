GBDK_DIR  := ${GBDKDIR}

LCC := $(GBDK_DIR)bin/lcc

RESDIR := res
PNGDIR := $(RESDIR)/png
SRCDIR := src
OBJDIR := obj

CSOURCES := $(wildcard $(SRCDIR)/*.c)
CASSETS  := $(wildcard $(RESDIR)/*.c)
COBJS    := $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(CSOURCES))
ASSETOBJS:= $(patsubst $(RESDIR)/%.c, $(OBJDIR)/%.o, $(CASSETS))
OBJS = $(COBJS) $(ASSETOBJS)

BIN := projectF.gb

all: build_all


$(OBJDIR)/%.o:	$(SRCDIR)/%.c
	$(LCC) $(LCCFLAGS) -c -o $@ $< -I$(RESDIR)

$(OBJDIR)/%.o:	$(RESDIR)/%.c
	$(LCC) $(LCCFLAGS) -c -o $@ $<

$(BIN): $(OBJS) 
	$(LCC) -o $@ $^ 

build_all:
	$(MAKE) -C $(RESDIR)
	$(MAKE) build

build:
	$(MAKE) $(BIN)

clean:
	rm -f $(BIN) *~ */*~ $(OBJDIR)/*.*

cleanasset:
	$(MAKE) -C $(RESDIR) clean
	rm -f $(ASSETOBJS)
