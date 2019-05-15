##
## Project name:
## LIBFOX
## File description:
## Master Makefile
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
PROJECT      =	Libfox
TESTBIN      =	unit_tests
SHELL        =	/bin/bash
MAKE         =	make --silent -C
RM           =	rm -f
CP           =	cp -t
MV           =	mv -t
GCOV         =	gcovr
CC           =	gcc
#CC          =	clang
#------------------------------
.DEFAULT_GOAL := all
##############################

#
# Project architecture
##############################
ROOT        :=	.
DIR_SRC     :=	$(ROOT)/source
DIR_TEST    :=	$(ROOT)/tests
#------------------------------
DIR_GRAPH   :=	$(DIR_SRC)/graph
DIR_IO      :=	$(DIR_SRC)/io
DIR_MATH    :=	$(DIR_SRC)/math
DIR_MEMORY  :=	$(DIR_SRC)/memory
DIR_STRING  :=	$(DIR_SRC)/string
# --
DIRS        :=	$(ROOT)
DIRS        +=	$(DIR_GRAPH)
DIRS        +=	$(DIR_IO)
DIRS        +=	$(DIR_MATH)
DIRS        +=	$(DIR_MEMORY)
DIRS        +=	$(DIR_STRING)
##############################

#
# Dependency automation
##############################
ALL_SRC     +=	$(SRC_GRAPH)
ALL_SRC     +=	$(SRC_IO)
ALL_SRC     +=	$(SRC_MATH)
ALL_SRC     +=	$(SRC_MEMORY)
ALL_SRC     +=	$(SRC_STRING)
ALL_SRC     +=	$(SRC_TESTS)
ALL_OBJ      =	$(ALL_SRC:.c=.o)
DEP          =	$(ALL_OBJ:.o=.d)
.PRECIOUS    =	$(DEP)
-include $(DEP)
#############################

#
# Compilation settings
##############################
INCLUDES    :=	$(foreach dir,$(DIRS),-iquote $(dir)/include)
#------------------------------
CFLAGS      +=	$(INCLUDES)
CFLAGS      +=	-Wall -Wextra
CFLAGS      +=	-Werror
#------------------------------
TFLAGS      +=	-D _LIBFOX_UT_
TFLAGS      +=	-iquote $(DIR_TEST)/include
TFLAGS      +=	--coverage
TFLAGS      +=	-lcriterion
TFLAGS      +=	$(WRAPPERS)
#------------------------------
WR_MALLOC   :=	-Wl,--wrap=malloc
WRAPPERS    +=	$(WR_MALLOC)
##############################

#
# Colours
##########################################
CRESET      :=	\033[0m

# \033[38;2;<R>;<G>;<B>m
CRED        :=	\033[38;2;255;0;0m
CGREEN      :=	\033[38;2;0;255;0m
CLIGHTGREEN :=  \033[38;2;190;255;200m
CBLUE       :=	\033[38;2;0;0;255m
CLIGHTBLUE  :=	\033[38;2;88;255;250m
CORANGE     :=	\033[38;2;255;167;4m

# Format
CBOLD       :=  \033[1m
CUNDERLN    :=  \033[4m 
##########################################

#
# Progress counter
##########################################
ifndef ECHO
T           :=  $(shell make --no-print-directory -nrRf $(firstword $(MAKEFILE_LIST)) $(MAKECMDGOALS) \
                  ECHO="LFOX-COUNT" | grep -c "LFOX-COUNT")
N           :=  
C           :=  0
ECHO         = echo -e "$(CORANGE)[$(PROJECT) | `expr $C '*' 100 / $T`% ($(NAME))]$(CRESET)"$(eval N = x $N)$(eval C = $(words $N))
endif
##########################################

#
# Customized implicit rules
##########################################
ifneq ("LFOX-COUNT",$(ECHO))
%.a:
	@if [ -e $@ ];                                   \
	then                                             \
	    $(ECHO) "Updating $(CLIGHTBLUE)$@$(CRESET)"; \
	    ar ru $@ $^;                                 \
	else                                             \
	    $(ECHO) "Creating $(CLIGHTBLUE)$@$(CRESET)"; \
	    ar rc $@ $^;                                 \
	fi
else
%.a:
	@$(ECHO)
endif
#------------------------------
%.o: CFLAGS += -MT $@ -MMD
%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<
	@$(ECHO) "$(CLIGHTGREEN)Compile OK ✓$(CRESET) $@"
##########################################





################################################################################
################################################################################
##                                                                            ##
##                               SOURCES                                      ##
##                                                                            ##
################################################################################
################################################################################

#
# Graph sources
##############################
SRC_GRAPH   +=	$(DIR_GRAPH)/src/aitem/aitem_create.c
SRC_GRAPH   +=	$(DIR_GRAPH)/src/aitem/aitem_destroy.c
SRC_GRAPH   +=	$(DIR_GRAPH)/src/alist/alist_create.c
SRC_GRAPH   +=	$(DIR_GRAPH)/src/alist/alist_destroy.c
SRC_GRAPH   +=	$(DIR_GRAPH)/src/graph/graph_create.c
SRC_GRAPH   +=	$(DIR_GRAPH)/src/graph/graph_destroy.c
%-graph: SRC := $(SRC_GRAPH)

#-- Dependencies
libfox_graph.a: $(DIR_IO)/src/fox_puts.o
libfox_graph.a: $(DIR_STRING)/src/fox_strdup.o
libfox_graph.a: $(DIR_STRING)/src/fox_strlen.o
##############################



#
# IO sources
##########################################
SRC_IO      +=	$(DIR_IO)/src/fox_printf.c
SRC_IO      +=	$(DIR_IO)/src/fox_putc.c
SRC_IO      +=	$(DIR_IO)/src/fox_putint.c
SRC_IO      +=	$(DIR_IO)/src/fox_putllong.c
SRC_IO      +=	$(DIR_IO)/src/fox_putnpc.c
SRC_IO      +=	$(DIR_IO)/src/fox_putnps.c
SRC_IO      +=	$(DIR_IO)/src/fox_puts.c
SRC_IO      +=	$(DIR_IO)/src/fox_putuint.c
SRC_IO      +=	$(DIR_IO)/src/fox_putuint_base.c
SRC_IO      +=	$(DIR_IO)/src/fox_putullong.c
SRC_IO      +=	$(DIR_IO)/src/fox_putullong_base.c
SRC_IO      +=	$(DIR_IO)/src/fox_printf/global_n.c
SRC_IO      +=	$(DIR_IO)/src/fox_printf/printer_picker_integer.c
SRC_IO      +=	$(DIR_IO)/src/fox_printf/printer_picker_other.c
SRC_IO      +=	$(DIR_IO)/src/fox_printf/printer_picker_unsigned.c
SRC_IO      +=	$(DIR_IO)/src/fox_printf/va_args.c
SRC_IO      +=	$(DIR_IO)/src/fox_printf/va_args_value.c
%-io: SRC := $(SRC_IO)

#-- Dependencies
libfox_io.a: $(DIR_MATH)/src/fox_nbsize.o
libfox_io.a: $(DIR_STRING)/src/fox_strlen.o
##############################



#
# Math sources
##########################################
SRC_MATH    +=	$(DIR_MATH)/src/fox_nbsize.c
SRC_MATH    +=	$(DIR_MATH)/src/fox_pow.c

#-- Dependencies
# NONE
##############################



#
# Memory sources
##########################################
SRC_MEMORY  +=	$(DIR_MEMORY)/src/fox_allocbytes.c
SRC_MEMORY  +=	$(DIR_MEMORY)/src/fox_calloc.c
SRC_MEMORY  +=	$(DIR_MEMORY)/src/fox_memcpy.c
SRC_MEMORY  +=	$(DIR_MEMORY)/src/fox_memset.c
SRC_MEMORY  +=	$(DIR_MEMORY)/src/fox_realloc.c
SRC_MEMORY  +=	$(DIR_MEMORY)/src/cleanup/fox_autoclose.c
SRC_MEMORY  +=	$(DIR_MEMORY)/src/cleanup/fox_autofree.c
%-memory: SRC := $(SRC_MEMORY)

#-- Dependencies
# NONE
##############################



#
# String sources
##########################################
SRC_STRING  +=	$(DIR_STRING)/src/fox_atoi.c
SRC_STRING  +=	$(DIR_STRING)/src/fox_isnum.c
SRC_STRING  +=	$(DIR_STRING)/src/fox_revstr.c
SRC_STRING  +=	$(DIR_STRING)/src/fox_strcmp.c
SRC_STRING  +=	$(DIR_STRING)/src/fox_strcont.c
SRC_STRING  +=	$(DIR_STRING)/src/fox_strdup.c
SRC_STRING  +=	$(DIR_STRING)/src/fox_strlen.c
SRC_STRING  +=	$(DIR_STRING)/src/fox_strspn.c
SRC_STRING  +=	$(DIR_STRING)/src/fox_strtok.c
%-string: SRC := $(SRC_STRING)

#-- Dependencies
# NONE
##############################



#
# Test sources
##########################################
#-- General
SRC_TESTS   +=	$(DIR_TEST)/test_init.c
SRC_TESTS   +=	$(DIR_TEST)/test_malloc.c
#-- Graph
SRC_TESTS   +=	$(DIR_TEST)/graph/aitem/test_aitem.c
SRC_TESTS   +=	$(DIR_TEST)/graph/alist/test_alist_additem.c
SRC_TESTS   +=	$(DIR_TEST)/graph/alist/test_alist_brokenmalloc.c
SRC_TESTS   +=	$(DIR_TEST)/graph/alist/test_alist_contains.c
SRC_TESTS   +=	$(DIR_TEST)/graph/alist/test_alist_create.c
SRC_TESTS   +=	$(DIR_TEST)/graph/alist/test_alist_destroy.c
SRC_TESTS   +=	$(DIR_TEST)/graph/alist/test_alist_fetch.c
SRC_TESTS   +=	$(DIR_TEST)/graph/alist/test_alist_flush.c
SRC_TESTS   +=	$(DIR_TEST)/graph/alist/test_alist_remove.c
SRC_TESTS   +=	$(DIR_TEST)/graph/alist/test_alist_removehead.c
SRC_TESTS   +=	$(DIR_TEST)/graph/graph/test_graph_additem1.c
SRC_TESTS   +=	$(DIR_TEST)/graph/graph/test_graph_additem2.c
SRC_TESTS   +=	$(DIR_TEST)/graph/graph/test_graph_addlist.c
SRC_TESTS   +=	$(DIR_TEST)/graph/graph/test_graph_brokenmalloc.c
SRC_TESTS   +=	$(DIR_TEST)/graph/graph/test_graph_contains.c
SRC_TESTS   +=	$(DIR_TEST)/graph/graph/test_graph_create.c
SRC_TESTS   +=	$(DIR_TEST)/graph/graph/test_graph_destroy.c
SRC_TESTS   +=	$(DIR_TEST)/graph/graph/test_graph_fetch.c
SRC_TESTS   +=	$(DIR_TEST)/graph/graph/test_graph_flush.c
SRC_TESTS   +=	$(DIR_TEST)/graph/graph/test_graph_listcontains1.c
SRC_TESTS   +=	$(DIR_TEST)/graph/graph/test_graph_listcontains2.c
SRC_TESTS   +=	$(DIR_TEST)/graph/graph/test_graph_listcontains3.c
SRC_TESTS   +=	$(DIR_TEST)/graph/graph/test_graph_remove.c
SRC_TESTS   +=	$(DIR_TEST)/graph/suites_graph.c
#-- IO
SRC_TESTS   +=	$(DIR_TEST)/io/fox_printf/test_global_n.c
SRC_TESTS   +=	$(DIR_TEST)/io/test_fox_putc.c
SRC_TESTS   +=	$(DIR_TEST)/io/test_fox_putint.c
SRC_TESTS   +=	$(DIR_TEST)/io/test_fox_puts.c
#-- Math
SRC_TESTS   +=	$(DIR_TEST)/math/test_fox_nbsize.c
#-- Memory
SRC_TESTS   +=	$(DIR_TEST)/memory/test_fox_allocbytes.c
SRC_TESTS   +=	$(DIR_TEST)/memory/test_fox_autoclose.c
SRC_TESTS   +=	$(DIR_TEST)/memory/test_fox_autofree.c
SRC_TESTS   +=	$(DIR_TEST)/memory/test_fox_calloc.c
SRC_TESTS   +=	$(DIR_TEST)/memory/test_fox_memcpy.c
SRC_TESTS   +=	$(DIR_TEST)/memory/test_fox_memset.c
SRC_TESTS   +=	$(DIR_TEST)/memory/test_fox_realloc.c
#-- String
SRC_TESTS   +=	$(DIR_TEST)/string/test_fox_atoi1.c
SRC_TESTS   +=	$(DIR_TEST)/string/test_fox_atoi2.c
SRC_TESTS   +=	$(DIR_TEST)/string/test_fox_isnum.c
SRC_TESTS   +=	$(DIR_TEST)/string/test_fox_revstr.c
SRC_TESTS   +=	$(DIR_TEST)/string/test_fox_strcmp1.c
SRC_TESTS   +=	$(DIR_TEST)/string/test_fox_strcmp2.c
SRC_TESTS   +=	$(DIR_TEST)/string/test_fox_strcont.c
SRC_TESTS   +=	$(DIR_TEST)/string/test_fox_strdup.c
SRC_TESTS   +=	$(DIR_TEST)/string/test_fox_strlen1.c
SRC_TESTS   +=	$(DIR_TEST)/string/test_fox_strlen2.c
SRC_TESTS   +=	$(DIR_TEST)/string/test_fox_strspn.c
SRC_TESTS   +=	$(DIR_TEST)/string/test_fox_strtok.c
##############################



################################################################################
################################################################################
##                                                                            ##
##                              RECEIPES                                      ##
##                                                                            ##
################################################################################
################################################################################

############################
##          ALL           ##
############################
.PHONY: all $(PROJECT)
$(PROJECT): all
all: libfox_graph.a
all: libfox_io.a
all: libfox_memory.a
all: libfox_string.a
all: tests

.PHONY: tests
tests: RUNFLAGS = --always-succeed --timeout 5
tests: COVFLAGS = -s --root $(DIR_SRC) .
tests: $(TESTBIN)
	@echo "[$(PROJECT)] Unit tests"
	@$(GCOV) $(COVFLAGS)
	@./$(TESTBIN) $(RUNFLAGS)

.PHONY: $(TESTBIN)
$(TESTBIN): CFLAGS += $(TFLAGS)
$(TESTBIN): RUNFLAGS = --always-succeed --timeout 5
$(TESTBIN):
	@$(CC) -o $@ $(CFLAGS) $(ALL_SRC)
	@./$(TESTBIN)  $(RUNFLAGS) -q

.PHONY: clean
clean: clean-graph clean-io clean-memory clean-string
	@if ls *.gc* 1 > /dev/null 2>&1;       \
	then                                   \
	    $(eval NAME = "Cleanup")           \
	    $(ECHO) "Removing coverage files"; \
	    $(RM)   **.gcda **.gcno;           \
	fi

.PHONY: fclean
fclean: fclean-graph fclean-io fclean-memory fclean-string
	@if [ -e $(TESTBIN) ];              \
	then                                \
	    $(eval NAME = "Cleanup")        \
	    $(ECHO) "Removing test binary"; \
	    $(RM)   $(TESTBIN);             \
	fi

.PHONY: re
re: fclean all
##########################################



############################
##         GRAPH          ##
############################
%-graph: NAME := Graph

.PHONY: graph lib-graph
graph: lib-graph
lib-graph:  libfox_graph.a
libfox_graph.a: $(SRC_GRAPH:.c=.o)

.PHONY: clean-graph
clean-graph:
	@$(ECHO) "Removing object files"
	@$(RM)   $(SRC:.c=.o)
	@$(ECHO) "Deleting temp files"
	@$(RM)   *~ **.gc*
	@$(ECHO) "Deleting dummy binaries (a.out)"
	@$(RM)   a.out

.PHONY: fclean-graph
fclean-graph: clean-graph
	@$(ECHO) "Deleting dependency files"
	@$(RM)   $(SRC:.c=.d)
	@$(ECHO) "Deleting lib file"
	@$(RM)   libfox_graph.a

.PHONY: re-graph
re-graph: fclean-graph lib-graph
##########################################



############################
##          IO            ##
############################
%-io: NAME := IO

.PHONY: io lib-io
io: lib-io
lib-io: libfox_io.a
libfox_io.a: $(SRC_IO:.c=.o)

.PHONY: clean-io
clean-io:
	@$(ECHO) "Removing object files"
	@$(RM)   $(SRC:.c=.o)
	@$(ECHO) "Deleting temp files"
	@$(RM)   *~ **.gc*
	@$(ECHO) "Deleting dummy binaries (a.out)"
	@$(RM)   a.out

.PHONY: fclean-io
fclean-io: clean-io
	@$(ECHO) "Deleting dependency files"
	@$(RM)   $(SRC:.c=.d)
	@$(ECHO) "Deleting lib file"
	@$(RM)   libfox_io.a

.PHONY: re-io
re-io: fclean-io io
##########################################



############################
##         MEMORY         ##
############################
%-memory: NAME := Memory

.PHONY: memory lib-memory
memory: lib-memory
lib-memory: libfox_memory.a
libfox_memory.a: $(SRC_MEMORY:.c=.o)

.PHONY: clean-memory
clean-memory:
	@$(ECHO) "Removing object files"
	@$(RM)   $(SRC:.c=.o)
	@$(ECHO) "Deleting temp files"
	@$(RM)   *~ **.gc*
	@$(ECHO) "Deleting dummy binaries (a.out)"
	@$(RM)   a.out

.PHONY: fclean-memory
fclean-memory: clean-memory
	@$(ECHO) "Deleting dependency files"
	@$(RM)   $(SRC:.c=.d)
	@$(ECHO) "Deleting lib file"
	@$(RM)   libfox_memory.a

.PHONY: re-memory
re-memory: fclean-memory memory
##########################################



############################
##         STRING         ##
############################
%-string: NAME := String

.PHONY: string lib-string
string: lib-string
lib-string: libfox_string.a
libfox_string.a: $(SRC_STRING:.c=.o)

.PHONY: clean-string
clean-string:
	@$(ECHO) "Removing object files"
	@$(RM)   $(SRC:.c=.o)
	@$(ECHO) "Deleting temp files"
	@$(RM)   *~ **.gc*
	@$(ECHO) "Deleting dummy binaries (a.out)"
	@$(RM)   a.out

.PHONY: fclean-string
fclean-string: clean-string
	@$(ECHO) "Deleting dependency files"
	@$(RM)   $(SRC:.c=.d)
	@$(ECHO) "Deleting lib file"
	@$(RM)   libfox_string.a

.PHONY: re-string
re-string: fclean-string string
##########################################
