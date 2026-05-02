#
# Makefile — 14_spaceboost
# Compile tous les .c dans src/ et ses sous-dossiers + res/
#

LCC = $(GBDKDIR)bin/lcc

PROJECTNAME = spaceboost

SRCDIR  = src
OBJDIR  = obj
RESDIR  = res

SRCDIRS = src \
	src/core \
	src/entities \
	src/systems \
	src/render \
	src/utils \
	src/audio \
	src/levels

INC = \
	-Ires \
	-Isrc \
	-Isrc/core \
	-Isrc/entities \
	-Isrc/systems \
	-Isrc/render \
	-Isrc/utils \
	-Isrc/audio \
	-Isrc/levels

LCCFLAGS += $(INC) # -Wf--max-allocs-per-node50000 -Wf--opt-code-speed

BINS      = $(PROJECTNAME).gb
CSOURCES  = $(foreach dir,$(SRCDIRS),$(wildcard $(dir)/*.c))
RESOURCES = $(foreach dir,$(RESDIR), $(wildcard $(dir)/*.c))
OBJS      = $(CSOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o) \
            $(RESOURCES:$(RESDIR)/%.c=$(OBJDIR)/%.o)

all: prepare $(BINS)

resources:
	@echo "Generating resources..."
	@$(MAKE) -C $(RESDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo "  CC $<"
	@mkdir -p $(dir $@)
	$(LCC) $(LCCFLAGS) -c -o $@ $<

$(OBJDIR)/%.o: $(RESDIR)/%.c
	@echo "  CC $<"
	@mkdir -p $(dir $@)
	$(LCC) $(LCCFLAGS) -c -o $@ $<

$(OBJDIR)/%.o: $(SRCDIR)/%.s
	$(LCC) $(LCCFLAGS) -c -o $@ $<

$(BINS): $(OBJS)
	$(LCC) $(LCCFLAGS) -o $(BINS) $(OBJS)

prepare:
	@mkdir -p $(OBJDIR)

clean:
	rm -f *.gb *.ihx *.cdb *.adb *.noi *.map *.s19
	rm -rf $(OBJDIR)
