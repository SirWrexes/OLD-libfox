##
## <COMPANY> <YEAR>
## <PROJECT>
## File description:
## <DESCRIPTION>
##



################################################################################
################################################################################
##                                                                            ##
##                               SETTINGS                                     ##
##                                                                            ##
################################################################################
################################################################################

#
# Fundamentals
##############################
PROJECT     =	
TESTBIN     =	tests_run
SHELL       =	/bin/bash
MAKE        =	make --silent -C
RM          =	rm -f
CP          =	cp -t
MV          =	mv -t
GCOV        =	gcovr
CC          =	gcc
#CC          =	clang
.DEFAULT_GOAL := $(PROJECT)
##############################

#
# Project architecture
##############################
PDIR        =	.
TDIR        =	$(PDIR)/tests
#------------------------------
TSRC        =	$(TDIR)/source
PSRC        =	$(PDIR)/source
#------------------------------
TINC        =	$(TDIR)/include
PINC        =	$(PDIR)/include
#------------------------------
BINDIR      =	$(PDIR)
#------------------------------
VPATH       =	$(PSRC):$(TSRC)
##############################

#
# Libfox Module automation
##############################
# Uncomment lines corresponding
# to modules used in the project

#USEDMODULES +=	$(LFOX_GRAPH)
#USEDMODULES +=	$(LFOX_IO)
#USEDMODULES +=	$(LFOX_MEMORY)
#USEDMODULES +=	$(LFOX_STRING)

# I wasted way to much sleep time
# making this. Please buy me a coffee.
##############################


#
# Don't touch that
##############################
LFOX        =	fox
LFOXPREFIX  =	$(LFOX)_
FOXDIR      =	$(PDIR)/lib$(LFOX)
FOXSRC      =	$(FOXDIR)/source
FOXINC      =	$(FOXDIR)/include
#
LFOX_GRAPH  =	graph
LFOX_IO     =	io
LFOX_MEMORY =	memory
LFOX_STRING =	string
#
FOX_COVRG   +=	$(FOXSRC)/*.gc*
#
FOXMODULES  =	$(foreach mod,$(USEDMODULES),-l$(LFOXPREFIX)$(mod))
#
INCLUDES    =	-iquote$(FOXINC)
LDFLAGS     =	-L$(FOXDIR)
LDLIBS      =	$(FOXMODULES)
##############################

#
# Colours/Format
##########################################
CRESET      :=	\033[0m

# Colours
# \033[38;2;<R>;<G>;<B>m
CRED        :=	\033[38;2;255;0;0m
CGREEN      :=	\033[38;2;0;255;0m
CLIGHTGREEN :=	\033[38;2;190;255;200m
CBLUE       :=	\033[38;2;0;0;255m
CLIGHTBLUE  :=	\033[38;2;88;255;250m
CYELLOW     :=	\033[38;2;255;247;3m

# Format
CBOLD       :=	\033[1m
CUNDERLN    :=	\033[4m
##########################################

#
# Progress counter
##########################################
ifndef ECHO
T           :=	$(shell make -nrRf $(firstword $(MAKEFILE_LIST)) $(MAKECMDGOALS) \
                  ECHO="P-COUNT" | grep -c "P-COUNT")
N           :=	x
C           :=	0
ECHO         = echo -e "$(CGREEN)[$(PROJECT) | `expr $C '*' 100 / $T`%]$(CRESET)"$(eval N = x $N)$(eval C = $(words $N))
endif
##########################################

#
# Custom compilation settings
##############################
DEFINE      +=
#------------------------------
INCLUDES    +=	-iquote$(PINC)
INCLUDES    +=	-iquote$(TINC)
#------------------------------
CFLAGS      +=	$(DEFINE)
CFLAGS      +=	$(INCLUDES)
#------------------------------
GCCFLAGS    +=	-Wall -Wextra
GCCFLAGS    +=	-Werror
CLANGFLAGS  +=	-Weverything
ifeq ($(CC), clang)
    CFLAGS += $(CLANGFLAGS)
else
    CFLAGS += $(GCCFLAGS)
endif
#------------------------------
LDFLAGS     +=
LDLIBS      +=
##############################

#
# Test configuration
##############################
TDEFINE     +=	-D _TESTS_RUN_
TLDLIBS     +=	-lcriterion
TLDFLAGS    +=	--coverage
#------------------------------
#WR_MALLOC   =	-Wl,--wrap=malloc
WRAPPERS    +=	$(WR_MALLOC)
#------------------------------
TRUNFLAGS   +=	-S
TRUNFLAGS   +=	--timeout 5
TRUNFLAGS   +=	--always-succeed
#------------------------------
GCOVFLAGS   +=	--exclude-directories $(subst ./,,$(TDIR))
GCOVFLAGS   +=	--exclude-directories $(subst ./,,$(FOXDIR))
##############################



################################################################################
################################################################################
##                                                                            ##
##                               RECEIPES                                     ##
##                                                                            ##
################################################################################
################################################################################

%.o: CFLAGS += -MT $@ -MMD
%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<
	@$(ECHO) "$(CLIGHTGREEN)Compile OK ✓$(CRESET) $(subst $(PSRC)/,,$@)"
	@$(eval RELINK = 1)
	@sleep 0.1

ifdef USEDMODULES
.PHONY: $(LFOX)
$(LFOX):
	@if ( ! $(MAKE) $(FOXDIR) $(USEDMODULES) -q );              \
	then                                                        \
	    $(ECHO) "Making Lib$(LFOX) modules {$(USEDMODULES)}";   \
	    $(MAKE) $(FOXDIR) $(USEDMODULES);                       \
	else                                                        \
	    echo -e "$(CGREEN)[$(PROJECT)]$(CRESET) Lib$(LFOX) modules are up to date."; \
	fi

.PHONY: $(LFOX)-tests
$(LFOX)-tests:
	@if ( ! $(MAKE) $(FOXDIR) tests ); \
	then                               \
	    $(ECHO) "Making unit tests";   \
	    $(MAKE) $(FOXDIR) tests;       \
	fi

.PHONY: $(LFOX)-clean
$(LFOX)-clean:
	@$(ECHO) "Cleaning slave targets"
	@if [ -e $(FOXDIR)/unit_tests ];                                           \
	then                                                                       \
	    $(MAKE) $(FOXDIR) fclean;                                              \
	else                                                                       \
	    $(foreach mod,$(USEDMODULES), $(MAKE) $(FOXDIR) $(FOXCLEAN)-$(mod);)   \
	fi

else
.PHONY: $(LFOX)
$(LFOX):
	@echo -n ""

.PHONY: $(LFOX)-clean
$(LFOX)-tests:
	@$(MAKE) $(FOXDIR) fclean 

endif

.PHONY: build
build: $(FILES) $(BIN)
	@
	@if ( ! $(MAKE) . $(FILES) -q ); \
	then                             \
	    $(MAKE) . $(FILES);          \
	    echo  -e  "$(CGREEN)[$(PROJECT)]$(CRESET) $(CBOLD)Linking with follwing options (ordered):$(CRESET)";                                 \
	    echo  -e  "$(CGREEN)[$(PROJECT)]$(CRESET) $(CUNDERLN)CC$(CRESET)      = $(CC)";                                                       \
	    echo  -ne "$(CGREEN)[$(PROJECT)]$(CRESET) $(CUNDERLN)FILES$(CRESET)   = \n$(foreach i,$(sort $(subst $(PSRC)/,,$(FILES))),\t$(i)\n)"; \
	    echo  -ne "$(CGREEN)[$(PROJECT)]$(CRESET) $(CUNDERLN)CFLAGS$(CRESET)  = \n$(foreach i,$(CFLAGS),\t$(i)\n)";                           \
	    echo  -ne "$(CGREEN)[$(PROJECT)]$(CRESET) $(CUNDERLN)LDFLAGS$(CRESET) = \n$(foreach i,$(LDFLAGS),\t$(i)\n)";                          \
	    echo  -ne "$(CGREEN)[$(PROJECT)]$(CRESET) $(CUNDERLN)LDLIBS$(CRESET)  = \n$(foreach i,$(LDLIBS),\t$(i)\n)";                           \
	    $(CC) -o  $(BIN) $(FILES) $(CFLAGS) $(LDFLAGS) $(LDLIBS);                                                                             \
	    echo  -e  "$(CGREEN)[$(PROJECT)] $(CLIGHTGREEN)$(CBOLD)Linking OK$(CRESET)";                                                          \
	fi

.PHONY: clean
clean: FOXCLEAN = clean
clean: $(LFOX)-clean
	@$(ECHO) "Removing coverage files"
	@-$(RM)  *.gc* tests/*.gc*
	@$(ECHO) "Removing object files"
	@-$(RM)  $(OBJ) $(MAIN:.c=.o)
	@$(ECHO)  "Removing dependency files"
	@-$(RM)   $(DEP)

.PHONY: fclean
fclean: FOXCLEAN = fclean
fclean: $(LFOX)-clean
	@$(ECHO)  "Removing coverage files"
	@-$(RM)   *.gc* tests/*.gc*
	@$(ECHO)  "Removing object files"
	@-$(RM)   $(OBJ) $(MAIN:.c=.o)
	@$(ECHO)  "Removing binary"
	@-$(RM)   $(BINDIR)/$(PROJECT) $(BINDIR)/$(PROJECT)_gdb $(BINDIR)/$(PROJECT)_vgd
	@$(ECHO)  "Removing test binary"
	@-$(RM)   $(BINDIR)/$(TESTBIN)

.PHONY: re
re:	fclean all



################################################################################
################################################################################
##                                                                            ##
##                               TARGETS                                      ##
##                                                                            ##
################################################################################
################################################################################

.PHONY: all
all: $(PROJECT)

ifneq "$(BINDIR)" "."

.PHONY: $(PROJECT)
.PHONY: $(PROJECT)_gdb
.PHONY: $(PROJECT)_vgd
.PHONY: $(TESTBIN)

endif

$(BINDIR)/$(PROJECT): $(PROJECT)
$(PROJECT): BIN   = $(BINDIR)/$(PROJECT)
$(PROJECT): FILES = $(MAIN:.c=.o) $(OBJ)
$(PROJECT): CFLAGS += -O
$(PROJECT): $(LFOX) build

$(BINDIR)/$(PROJECT)_gdb: $(POJECT)_gdb
$(PROJECT)_gdb: BIN     = $(BINDIR)/$(PROJECT)_gdb
$(PROJECT)_gdb: CFLAGS += -g
$(PROJECT)_gdb: FILES   = $(MAIN) $(SRC)
$(PROJECT)_gdb: $(LFOX) build

$(BINDIR)/$(PROJECT)_vgd: $(PROJECT)_vgd
$(PROJECT)_vgd: BIN     = $(BINDIR)/$(PROJECT)_vgd
$(PROJECT)_vgd: CFLAGS += -g3
$(PROJECT)_vgd: FILES   = $(MAIN:.c=.o) $(OBJ)
$(PROJECT)_vgd: $(LFOX) build

$(BINDIR)/$(TESTBIN): $(TESTBIN)
$(TESTBIN): BIN      = $(BINDIR)/$(TESTBIN)
$(TESTBIN): DEFINE  += $(TDEFINE)
$(TESTBIN): CFLAGS  += $(WRAPPERS)
$(TESTBIN): LDFLAGS += $(TLDFLAGS)
$(TESTBIN): LDLIBS  += $(TLDLIBS)
$(TESTBIN): FILES   += $(SRC) $(TESTS)
$(TESTBIN): $(LFOX)-tests
$(TESTBIN): $(LFOX) build
	@./$(BIN) $(TRUNFLAGS) -q
	@echo     "[$(PROJECT)] Complete coverage report"  | cat
	@$(GCOV)  --exclude-directories tests 2>/dev/null
	@echo     "[$(PROJECT)] Unit tests summary"        | cat
	@./$(BIN) $(TRUNFLAGS)



################################################################################
################################################################################
##                                                                            ##
##                               SOURCES                                      ##
##                                                                            ##
################################################################################
################################################################################

#
# Project
##############################
MAIN        :=	$(PSRC)/
#------------------------------
SRC         +=	
##############################

#
# Test
##############################
TESTS       +=
##############################

#
# Dependency automation & .o's
##############################
OBJ         :=	$(SRC:.c=.o)
DEP         :=	$(OBJ:.o=.d) $(MAIN:.c=.d)
-include $(DEP)
.PRECIOUS := $(DEP)
##############################
