#
# A Makefile that compiles all .c and .s files in "src" and "res" 
# subdirectories and places the output in a "obj" subdirectory
#

# If you move this project you can change the directory 
# to match your GBDK root directory (ex: GBDK_HOME = "C:/GBDK/"


LCC = $(GBDKDIR)bin/lcc
# You can set the name of the .gb ROM file here
PROJECTNAME    = shooter

SRCDIR      = src
OBJDIR      = obj
SRCDIRS      = src \
	src/core \
	src/entities \
	src/systems \
	src/render \
	src/utils \
	src/input \
	src/audio \
	src/levels

OBJDIRS      = $(subst src, obj, $(SRCDIR))
RESDIR      = res

INC =   -Ires \
        -Isrc \
        -Isrc/core \
        -Isrc/entities \
        -Isrc/systems \
        -Isrc/render \
        -Isrc/utils \
	-Isrc/input \
	-Isrc/audio \
	-Isrc/levels 



LCCFLAGS   += $(INC) 

BINS	    = $(PROJECTNAME).gb
CSOURCES    = $(foreach dir,$(SRCDIRS),$(wildcard $(dir)/*.c))
RESOURCES  = $(foreach dir,$(RESDIR), $(wildcard $(dir)/*.c))
OBJS        = $(CSOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o) \
		$(RESOURCES:$(RESDIR)/%.c=$(OBJDIR)/%.o)

all:	prepare $(BINS)


# Commande pour générer les ressources
resources:
	@echo "Generating resources..."
	@$(MAKE) -C $(RESDIR)

# Compile .c files in "src/" to .o object files
$(OBJDIR)/%.o:	$(SRCDIR)/%.c
	@echo "Compiling $< to $@"
	@mkdir -p $(dir $@)
	$(LCC) $(LCCFLAGS) -c -o $@ $<

# Compile .c files in "res/" to .o object files
$(OBJDIR)/%.o:	$(RESDIR)/%.c
	$(LCC) $(LCCFLAGS) -c -o $@ $<

# Compile .s assembly files in "src/" to .o object files
$(OBJDIR)/%.o:	$(SRCDIR)/%.s
	$(LCC) $(LCCFLAGS) -c -o $@ $<

# If needed, compile .c files in "src/" to .s assembly files
# (not required if .c is compiled directly to .o)
$(OBJDIR)/%.s:	$(SRCDIR)/%.c 
	$(LCC) $(LCCFLAGS) -S -o $@ $<

# Link the compiled object files into a .gb ROM file
$(BINS):	$(OBJS)
	$(LCC) $(LCCFLAGS) -o $(BINS) $(OBJS)

prepare:
	@mkdir -p $(OBJDIR)

clean:
	rm -f  *.gb *.ihx *.cdb *.adb *.noi *.map
	rm -rf  $(OBJDIR)/* 

