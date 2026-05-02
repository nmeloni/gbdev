#
# Makefile — 12_bullet_hell
# Module de test de performance : bullets, collisions, mesure CPU
#

LCC = $(GBDKDIR)bin/lcc

PROJECTNAME = bullet_hell

SRCDIR  = src
OBJDIR  = obj
RESDIR  = res

INC = -Isrc -Ires -Wf--max-allocs-per-node50000 -Wf--opt-code-speed

LCCFLAGS += $(INC)

BINS      = $(PROJECTNAME).gb
CSOURCES  = $(wildcard $(SRCDIR)/*.c)
RESOURCES = $(wildcard $(RESDIR)/*.c)
OBJS      = $(CSOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o) \
            $(RESOURCES:$(RESDIR)/%.c=$(OBJDIR)/res_%.o)

all: prepare $(BINS)

resources:
	@echo "Generating resources..."
	@$(MAKE) -C $(RESDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo "  CC $<"
	$(LCC) $(LCCFLAGS) -c -o $@ $<

$(OBJDIR)/res_%.o: $(RESDIR)/%.c
	@echo "  CC $<"
	$(LCC) $(LCCFLAGS) -c -o $@ $<

$(BINS): $(OBJS)
	$(LCC) $(LCCFLAGS) -o $(BINS) $(OBJS)

prepare:
	@mkdir -p $(OBJDIR)

clean:
	rm -f *.gb *.ihx *.cdb *.adb *.noi *.map
	rm -rf $(OBJDIR)
