##
## <COMPANY>, <YEAR>
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
SHELL       =	/bin/sh
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
TSRC        =	$(TDIR)
PSRC        =	$(PDIR)/src
#------------------------------
TINC        =	$(TDIR)/include
PINC        =	$(PDIR)/include
#------------------------------
VPATH       =	$(PSRC):$(TSRC)
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
CBLUE       :=	\033[38;2;0;0;255m
CLIGHTBLUE  :=	\033[38;2;88;255;250m

# Format
CBOLD       :=	\033[1m
CUNDERLN    :=	\033[4m
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

#
# Module automation
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



################################################################################
################################################################################
##                                                                            ##
##                                RECIPES                                     ##
##                                                                            ##
################################################################################
################################################################################

%.o: CFLAGS += -MT $@ -MMD
%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<
	@echo -e "[$(PROJECT)] $(CGREEN)Compile OK ✓$(CRESET) $@"

.PHONY: $(LFOX)
$(LFOX):
	@if ( ! $(MAKE) $(FOXDIR) $(USEDMODULES) );                     \
	then                                                            \
	    echo    "[$(LFOX)]: Making modules {$(USEDMODULES)}" | cat; \
	    $(MAKE) $(FOXDIR) $(USEDMODULES);                           \
	fi

.PHONY: $(LFOX)-tests
$(LFOX)-tests:
	@if ( ! $(MAKE) $(FOXDIR) tests );                \
	then                                              \
	    echo    "[$(LFOX)]: Making unit tests" | cat; \
	    $(MAKE) $(FOXDIR) tests;                      \
	fi

.PHONY: $(LFOX)-clean
$(LFOX)-clean:
	@echo "[$(PROJECT)] Cleaning slave targets" | cat
	@if [ -e $(FOXDIR)/unit_tests ];                                           \
	then                                                                       \
	    $(MAKE) $(FOXDIR) fclean;                                              \
	else                                                                       \
	    $(foreach mod,$(USEDMODULES), $(MAKE) $(FOXDIR) $(FOXCLEAN)-$(mod);)   \
	fi


.PHONY: build
build:
	@echo  -e  "[$(PROJECT)] $(CBOLD)Linking with follwing options (ordered):$(CRESET)"       | cat
	@echo  -e  "[$(PROJECT)] $(CUNDERLN)CC$(CRESET)      = $(CC)"                             | cat
	@echo  -ne "[$(PROJECT)] $(CUNDERLN)FILES$(CRESET)   = \n$(foreach i,$(FILES),\t$(i)\n)"  | cat
	@echo  -ne "[$(PROJECT)] $(CUNDERLN)CFLAGS$(CRESET)  = \n$(foreach i,$(CFLAGS),\t$(i)\n)" | cat
	@echo  -ne "[$(PROJECT)] $(CUNDERLN)LDFLAGS$(CRESET) = \n$(foreach i,$(LDFLAGS),\t$(i)\n)"| cat
	@echo  -ne "[$(PROJECT)] $(CUNDERLN)LDLIBS$(CRESET)  = \n$(foreach i,$(LDLIBS),\t$(i)\n)" | cat
	@$(CC) -o  $(BIN) $(FILES) $(CFLAGS) $(LDFLAGS) $(LDLIBS)
	@echo  -e  "[$(PROJECT)] $(CGREEN)Linking OK$(CRESET)" | cat

.PHONY: clean
clean: FOXCLEAN = clean
clean: $(LFOX)-clean
	@echo    "[$(PROJECT)] Removing coverage files"       | cat
	@-$(RM)  *.gc* tests/*.gc*
	@echo    "[$(PROJECT)] Removing object files"         | cat
	@-$(RM)  $(OBJ) $(MAIN:.c=.o)
	@echo     "[$(PROJECT)] Removing dependency files"    | cat
	@-$(RM)   $(DEP)

.PHONY: fclean
fclean: FOXCLEAN = fclean
fclean: $(LFOX)-clean
	@echo     "[$(PROJECT)] Removing coverage files"      | cat
	@-$(RM)   *.gc* tests/*.gc*
	@echo     "[$(PROJECT)] Removing object files"        | cat
	@-$(RM)   $(OBJ) $(MAIN:.c=.o)
	@echo     "[$(PROJECT)] Removing binary"              | cat
	@-$(RM)   $(PROJECT) $(PROJECT)_gdb $(PROJECT)_vgd
	@echo     "[$(PROJECT)] Removing test binary"         | cat
	@-$(RM)   $(TESTBIN)

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

$(PROJECT): BIN   = $(PROJECT)
$(PROJECT): FILES = $(MAIN:.c=.o) $(OBJ)
$(PROJECT): $(LFOX)
$(PROJECT): $(MAIN:.c=.o) $(OBJ)
$(PROJECT): build

$(PROJECT)_gdb: BIN     = $(PROJECT)_gdb
$(PROJECT)_gdb: CFLAGS += -g
$(PROJECT)_gdb: FILES   = $(MAIN) $(SRC)
$(PROJECT)_gdb: $(LFOX)
$(PROJECT)_gdb: $(MAIN) $(SRC)
$(PROJECT)_gdb: build


$(PROJECT)_vgd: BIN     = $(PROJECT)_vgd
$(PROJECT)_vgd: CFLAGS += -g3
$(PROJECT)_vgd: FILES   = $(MAIN:.c=.o) $(OBJ)
$(PROJECT)_vgd: $(LFOX)
$(PROJECT)_vgd: $(MAIN:.c=.o) $(OBJ)
$(PROJECT)_vgd: build

$(TESTBIN): BIN      = $(TESTBIN)
$(TESTBIN): DEFINE  += $(TDEFINE)
$(TESTBIN): CFLAGS  += $(WRAPPERS)
$(TESTBIN): LDFLAGS += $(TLDFLAGS)
$(TESTBIN): LDLIBS  += $(TLDLIBS)
$(TESTBIN): FILES   += $(SRC) $(TESTS)
$(TESTBIN): $(SRC) $(TESTS)
$(TESTBIN): build
$(TESTBIN): $(LFOX)-tests
$(TESTBIN): $(LFOX)
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
MAIN        :=
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
