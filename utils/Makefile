##
## <COMPANY>, <YEAR>
## <PROJECT>
## File description:
## Main Makefile
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
.DEFAULT_GOAL := all
##############################

#
# Colours
##########################################
CRESET      :=	\033[0m

# \033[38;2;<R>;<G>;<B>m
CRED        :=	\033[38;2;255;0;0m
CGREEN      :=	\033[38;2;0;255;0m
CBLUE       :=	\033[38;2;0;0;255m
CLIGHTBLUE  :=	\033[38;2;88;255;250m
##########################################

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
# Custom compilation settings
##############################
DEFINE      +=
#------------------------------
INCLUDES    +=	-iquote $(PINC)
INCLUDES    +=	-iquote $(TINC)
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
TLDLIBS     +=	-l criterion
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
FOXMODULES  :=	$(foreach mod,$(USEDMODULES),-l $(LFOXPREFIX)$(mod))
#
INCLUDES    +=	-iquote $(FOXINC)
LDFLAGS     +=	-L $(FOXDIR)
##############################

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

################################################################################
################################################################################
##                                                                            ##
##                              RECEIPES                                      ##
##                                                                            ##
################################################################################
################################################################################

.PHONY: all
all: $(LFOX) $(PROJECT)

%.o: CFLAGS += -MT $@ -MMD
%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<
	@echo -e "[$(PROJECT)] $(CGREEN)Compile OK ✓$(CRESET) $@"

.PHONY: $(LFOX)
$(LFOX):
	@echo    "[$(LFOX)]: Making modules {$(USEDMODULES)}"                       | cat
	@$(MAKE) $(FOXDIR) $(USEDMODULES)

$(PROJECT): LDLIBS := $(LDLIBS) $(FOXMODULES)
$(PROJECT): $(OBJ)
$(PROJECT): $(MAIN:.c=.o)
	@echo  "[$(PROJECT)] Linking with follwing options (ordered):"             | cat
	@echo  "[$(PROJECT)] CC      = $(CC)                                       | cat
	@echo  "[$(PROJECT)] OBJECTS = $^"                                         | cat
	@echo  "[$(PROJECT)] CFLAGS  = $(CFLAGS)"                                  | cat
	@echo  "[$(PROJECT)] LDFLAGS = $(LDFLAGS)"                                 | cat
	@echo  "[$(PROJECT)] LDLIBS  = $(LDLIBS)"                                  | cat
	@$(CC) -o $(PROJECT) $^ $(CFLAGS) $(LDFLAGS) $(LDLIBS)
	@echo  "[$(PROJECT) | linking] OK"                                          | cat

$(PROJECT)_gdb: SRC    += $(MAIN)
$(PROJECT)_gdb: CFLAGS += -g
$(PROJECT)_gdb:
	@echo  "[$(PROJECT)] Linking with follwing options (ordered):"             | cat
	@echo  "[$(PROJECT)] CC      = $(CC)                                       | cat
	@echo  "[$(PROJECT)] SOURCES = $(SRC)"                                     | cat
	@echo  "[$(PROJECT)] CFLAGS  = $(CFLAGS)"                                  | cat
	@echo  "[$(PROJECT)] LDFLAGS = $(LDFLAGS)"                                 | cat
	@echo  "[$(PROJECT)] LDLIBS  = $(LDLIBS)"                                  | cat
	$(CC)  -o $(PROJECT) $(SRC) $(CFLAGS) $(LDFLAGS) $(LDLIBS)
	@echo  "[$(PROJECT) | linking] OK"                                          | cat

$(PROJECT)_valgrind: CFLAGS += -g3
$(PROJECT)_valgrind: $(OBJ)
$(PROJECT)_valgrind: $(MAIN:.c=.o)
	@echo  "[$(PROJECT)] Linking with follwing options (ordered):"             | cat
	@echo  "[$(PROJECT)] CC      = $(CC)                                       | cat
	@echo  "[$(PROJECT)] OBJECTS = $^"                                         | cat
	@echo  "[$(PROJECT)] CFLAGS  = $(CFLAGS)"                                  | cat
	@echo  "[$(PROJECT)] LDFLAGS = $(LDFLAGS)"                                 | cat
	@echo  "[$(PROJECT)] LDLIBS  = $(LDLIBS)"                                  | cat
	$(CC)  -o $(PROJECT) $^ $(CFLAGS) $(LDFLAGS) $(LDLIBS)
	@echo  "[$(PROJECT) | linking] OK"                                          | cat

$(TESTBIN): DEFINE  += $(TDEFINE)
$(TESTBIN): SRC     += $(TESTS)
$(TESTBIN): CFLAGS  += $(WRAPPERS)
$(TESTBIN): LDFLAGS += $(TLDFLAGS)
$(TESTBIN): LDLIBS  += $(TLDLIBS)  $(FOXMODULES)
$(TESTBIN): $(LFOX)
	@echo         "[$(PROJECT)] Testing lib$(LFOX)"                            | cat
	@$(MAKE)      $(FOXDIR) tests
	@echo         "[$(PROJECT)] Testing project"                               | cat
	@echo         "[$(PROJECT)] Linking with follwing options (ordered):"      | cat
	@echo         "[$(PROJECT)] CC      = $(CC)                                | cat
	@echo         "[$(PROJECT)] OBJECTS = $^"                                  | cat
	@echo         "[$(PROJECT)] CFLAGS  = $(CFLAGS)"                           | cat
	@echo         "[$(PROJECT)] LDFLAGS = $(LDFLAGS)"                          | cat
	@echo         "[$(PROJECT)] LDLIBS  = $(LDLIBS)"                           | cat
	@$(CC)        $(CFLAGS) -o $(TESTBIN) $(SRC) $(LDFLAGS) $(LDLIBS)
	@echo         "[$(PROJECT) | linking] OK"                                   | cat
	@./$(TESTBIN) $(TRUNFLAGS)
	@echo         "[$(PROJECT)] Fetching lib$(LFOX) coverage files"            | cat
	@-$(CP)       $(PDIR) $(FOX_COVRG) 2>/dev/null
	@echo         "[$(PROJECT)] Moving test sources coverage files"            | cat
	@$(MV)        $(TDIR) test_*.gc*
	@echo         "[$(PROJECT)] Complete coverage report"                      | cat
	@$(GCOV)      --exclude-directories tests 2>/dev/null

.PHONY: clean
clean:
	@echo    "[$(PROJECT)] Removing coverage files"                            | cat
	@-$(RM)  *.gc* tests/*.gc*
	@echo    "[$(PROJECT)] Removing object files"                              | cat
	@-$(RM)  $(OBJ) $(MAIN:.c=.o)
	@echo    "[$(PROJECT)] Cleaning slave targets"                             | cat
	@$(foreach mod,$(USEDMODULES), $(MAKE) $(FOXDIR) clean-$(mod);)

.PHONY: fclean
fclean:
	@echo     "[$(PROJECT)] Removing dependency files"                         | cat
	@-$(RM)   $(DEP) $(MAIN:.c=.d)
	@echo     "[$(PROJECT)] Removing coverage files"                           | cat
	@-$(RM)   *.gc* tests/*.gc*
	@echo     "[$(PROJECT)] Removing object files"                             | cat
	@-$(RM)   $(OBJ)
	@echo     "[$(PROJECT)] Removing binary"                                   | cat
	@-$(RM)   $(PROJECT)
	@echo     "[$(PROJECT)] Removing test binary"                              | cat
	@-$(RM)   $(TESTBIN)
	@echo     "[$(PROJECT)] Cleaning slave targets"                            | cat
	@$(MAKE)  $(FOXDIR) fclean

.PHONY: re
re:	fclean all
