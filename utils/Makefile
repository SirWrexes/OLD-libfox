##
## <COMPANY>, <YEAR>
## <PROJECT_NAME>
## File description:
## Modular Makefile
##

#
# Fundamentals
##############################
PROJECT		=	
TESTBIN		=	tests_run
SHELL		=	/bin/sh
CC			=	gcc
#CC			=	clang
##############################

#
# Project architecture
##############################
PDIR		=	.
TDIR		=	$(PDIR)/tests
 #
TSRC		=	$(TDIR)/src
PSRC		=	$(PDIR)/src
 #
TINC		=	$(TDIR)/include
PINC		=	$(PDIR)/include
 #
VPATH		=	$(PSRC):$(TSRC)
##############################

#
# Module automation
##############################
# Uncomment lines corresponding
# to modules used in the project

#USEDMODULES	+=	$(LFOX_IO)
#USEDMODULES	+=	$(LFOX_MEMORY)
#USEDMODULES	+=	$(LFOX_PRINTF)
#USEDMODULES	+=	$(LFOX_STRING)

# I wasted way to much sleep time
# making this. Please buy me a coffee.
##############################

#
# Don't touch that
##############################
LFOX		=	fox
LFOXPREFIX	=	$(LFOX)_
FOXDIR		=	$(PDIR)/lib$(LFOX)
FOXSRC		=	$(FOXDIR)/source
FOXINC		=	$(FOXDIR)/include
 #
LFOX_IO		=	io
LFOX_MEMORY	=	memory
LFOX_PRINTF	=	printf
LFOX_STRING	=	string
 #
FOX_COVRG	+=	$(FOXSRC)/lib$(LFOXPREFIX)$(LFOX_IO)/*.gc*
FOX_COVRG	+=	$(FOXSRC)/lib$(LFOXPREFIX)$(LFOX_MEMORY)/*.gc*
FOX_COVRG	+=	$(FOXSRC)/lib$(LFOXPREFIX)$(LFOX_PRINTF)/*.gc*
FOX_COVRG	+=	$(FOXSRC)/lib$(LFOXPREFIX)$(LFOX_STRING)/*.gc*
 #
FOXMODULES	:= $(foreach mod,$(USEDMODULES),-l $(LFOXPREFIX)$(mod))
 #
INCLUDES	+=	-iquote $(FOXINC)
LDFLAGS		+=	-L $(FOXDIR)
 #
##############################


#
# Custom compilation settings
##############################
DEFINE		+=
 #
INCLUDES	+=	-iquote $(PINC)
INCLUDES	+=	-iquote $(TINC)
 #
CFLAGS		+=	$(DEFINE)
CFLAGS		+=	$(INCLUDES)
 #
GCCFLAGS	+=	-Wall -Wextra
GCCFLAGS	+=	-Werror
CLANGFLAGS	+=	-Weverything
ifeq ($(CC), clang)
    $(info --- $(PROJECT): Using CLANG compiler)
    CFLAGS += $(CLANGFLAGS)
else
    $(info --- $(PROJECT): Using DEFAULT compiler : $(CC))
    CFLAGS += $(GCCFLAGS)
endif
 #
LDFLAGS		+=
LDLIBS		+=
##############################

#
# Test configuration
##############################
TDEFINE		+=	-D _TESTS_RUN_
TLDLIBS		+=	-l criterion
TLDFLAGS	+=	--coverage
 #
WR_MALLOC	=	-Wl,--wrap=malloc
WRAPPERS	+=	$(WR_MALLOC)
 #
TRUNFLAGS	+=	-S
TRUNFLAGS	+=	--timeout 5
##############################

#
# Sources
##############################
MAIN		=	$(PSRC)/
SRC			+=	$(PSRC)/
 #
TESTS		+=	$(TSRC)/
 #
OBJ			=	$(SRC:.c=.o)
##############################

.DEFAULT_GOAL := all
.PHONY: all
all: $(LFOX) $(PROJECT)

.PHONY: $(LFOX)
$(LFOX):
	@echo -n "$(LFOX): "												| cat
	@git submodule --quiet update --init
	@git submodule sync
	@echo "$(LFOX): Making modules $(USEDMODULES)"						| cat
	@make --silent -C $(FOXDIR) $(USEDMODULES)

$(PROJECT): $(OBJ)
$(PROJECT): $(MAIN:.c=.o)
$(PROJECT): LDLIBS := $(LDLIBS) $(FOXMODULES)
$(PROJECT):
	$(CC) $(CFLAGS) -o $(PROJECT) $^ $(LDFLAGS) $(LDLIBS)														\

$(PROJECT)_gdb: SRC += $(MAIN)
$(PROJECT)_gdb: CFLAGS += -g
$(PROJECT)_gdb:
	$(CC) -o $(PROJECT) $(SRC) $(CFLAGS) $(LDFLAGS) $(LDLIBS)

$(PROJECT)_valgrind: $(OBJ)
$(PROJECT)_valgrind: $(MAIN:.c=.o)
$(PROJECT)_valgrind: CFLAGS += -g3
$(PROJECT)_valgrind:
	$(CC) -o $(PROJECT) $^ $(CFLAGS) $(LDFLAGS) $(LDLIBS)

$(TESTBIN): DEFINE	+= $(TDEFINE)
$(TESTBIN): SRC		+= $(TSRC)
$(TESTBIN): CFLAGS	+= $(WRAPPERS)
$(TESTBIN): LDFLAGS	+= $(TLDFLAGS)
$(TESTBIN): LDLIBS	+= $(TLDLIBS)  $(FOXMODULES)
$(TESTBIN):
	@echo	"$(PROJECT): Testing lib$(LFOX)"							| cat
	@make	--silent -C $(FOXDIR) tests
	@echo	"$(PROJECT): Testing project"								| cat
	@$(CC)	$(CFLAGS) -o $(TESTBIN) $(SRC) $(LDFLAGS) $(LDLIBS)														\
	-@./$(TESTBIN) $(TRUNFLAGS)
	@echo	"$(PROJECT): Fetching lib$(LFOX) coverage files"			| cat
	-@cp	-t . $(FOX_COVRG)
	@echo	"$(PROJECT): Fetching project coverage files"				| cat
	-@cp	-t . $(TDIR)/*.gc*
	@echo	"$(PROJECT): Moving test sources coverage files"			| cat
	@mv		-t tests test_*.gc*
	@echo	"$(PROJECT): Complete coverage report"						| cat
	@gcovr	--exclude-directories tests 2>/dev/null

.PHONY: clean
clean:
	@echo	"$(PROJECT): Removing coverage files"						| cat
	-@rm	-f *.gc* tests/*.gc*
	@echo	"$(PROJECT): Removing object files"							| cat
	-@rm	-f $(OBJ)
	@echo	"$(PROJECT): Cleaning slave targets"						| cat
	@$(foreach mod,$(USEDMODULES), make --silent -C $(FOXDIR) $(mod)-clean;)

.PHONY: fclean
fclean:
	@echo	"$(PROJECT): Removing coverage files"						| cat
	-@rm	-f *.gc* tests/*.gc*
	@echo	"$(PROJECT): Removing object files"							| cat
	-@rm	-f $(OBJ)
	@echo	"$(PROJECT): Removing binary"								| cat
	-@rm	-f $(PROJECT)
	@echo	"$(PROJECT): Cleaning slave targets"						| cat
	@$(foreach mod,$(USEDMODULES), make --silent -C $(FOXDIR) $(mod)-fclean;)

.PHONY: re
re:	fclean all