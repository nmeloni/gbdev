#
# Makefile 15_runner
# Compile tous les .c dans src/ et res/
#

LCC = $(GBDKDIR)/bin/lcc

PROJECTNAME = runner

SRC_DIR    = src
RES_DIR    = res
ASSET_DIR  = assets
SPRITE_DIR = $(ASSET_DIR)/sprites
BUILD_DIR  = build

LCCFLAGS += -I$(RES_DIR) # -Wf--max-allocs-per-node50000 -Wf--opt-code-speed

BIN       = $(BUILD_DIR)/$(PROJECTNAME).gb
SRCS      = $(wildcard $(SRC_DIR)/*.c)
RESS      = $(wildcard $(RES_DIR)/*.c)
OBJS     := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
OBJS     += $(RESS:$(RES_DIR)/%.c=$(BUILD_DIR)/%.o)

all: prepare $(BIN)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(LCC) $(LCCFLAGS) -c -o $@ $<

$(BUILD_DIR)/%.o: $(RES_DIR)/%.c
	$(LCC) $(LCCFLAGS) -c -o $@ $<

$(BIN): $(OBJS)
	$(LCC) $(LCCFLAGS) -o $(BIN) $(OBJS)

prepare:
	@mkdir -p $(BUILD_DIR)
	@$(MAKE) -C $(ASSET_DIR)

clean:
	rm -f $(BUILD_DIR)/*.[aolsi]*
	rm -f $(BUILD_DIR)/*.o
	rm -f $(SRC_DIR)/*~
