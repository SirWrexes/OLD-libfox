##
## EPITECH PROJECT, 2019
## libfox_memory
## File description:
## Slave Makefile
##

SHELL       =	/bin/sh
CC          ?=	gcc
GCOV        =	gcovr --exclude-directories tests

############
NAME        =	memory
TARGET      =	libfox_$(NAME).a
TESTS       =	tests_$(NAME)
######
PINC        +=	./include
PDIR        +=	./src
 #
TINC        +=	./tests/include
TDIR        +=	./tests/src
######
VPATH       =	$(PDIR):$(PINC):$(TDIR):$(TINC)
############

############
PSRC        +=	$(PDIR)/fox_allocbytes.c
PSRC        +=	$(PDIR)/fox_calloc.c
PSRC        +=	$(PDIR)/fox_memcpy.c
PSRC        +=	$(PDIR)/fox_memset.c
PSRC        +=	$(PDIR)/fox_realloc.c
PSRC        +=	$(PDIR)/cleanup/fox_autoclose.c
PSRC        +=	$(PDIR)/cleanup/fox_autofree.c
 #
TSRC        +=	$(TDIR)/test_fox_allocbytes.c
TSRC        +=	$(TDIR)/test_fox_calloc.c
TSRC        +=	$(TDIR)/test_fox_memcpy.c
TSRC        +=	$(TDIR)/test_fox_memset.c
TSRC        +=	$(TDIR)/test_fox_realloc.c
TSRC        +=	$(TDIR)/test_fox_autofree.c
TSRC        +=	$(TDIR)/test_fox_autoclose.c
TSRC        +=	$(TDIR)/../test_malloc.c
############

############
OBJ         =	$(PSRC:%.c=%.o)
DEP         =	$(OBJ:.o=.d)
.PRECIOUS   =	$(DEP)
-include $(DEP)
############

############
include ../.includes
CFLAGS      +=	$(INCLUDES) -iquote $(PINC)
CFLAGS      +=	-Wall -Wextra
CFLAGS      +=	-Werror
 #
TFLAGS      +=	-D LIBFOX_UT
TFLAGS      +=	-iquote $(TINC)
TFLAGS      +=	--coverage -lcriterion
TFLAGS      +=	$(WRAPPERS)
 #
WR_MALLOC   :=	-Wl,--wrap=malloc
WRAPPERS    +=	$(WR_MALLOC)
 #
TRFLAGS     +=	--always-succeed --timeout 5
############

.DEFAULT_GOAL := $(TARGET)
$(TARGET): $(OBJ)
	@if [ -e $@ ];          \
	then                    \
	    echo "Updating $@"; \
	    ar ru $@ $^;        \
	else                    \
	    echo "Creating $@"; \
	    ar rc $@ $^;        \
	fi

%.o: CFLAGS += -MT $@ -MMD
%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<
	@echo "[$(NAME) | $(CC)] OK → $@"

$(TESTS): CFLAGS += $(TFLAGS)
$(TESTS):
	$(CC)       -o  $(TESTS) $(CFLAGS) $(PSRC) $(TSRC)
	@echo                           | cat
	@echo                           | cat
	@echo "[$(NAME)]: unit tests"   | cat
	@printf "\tfox_cleanup tests produce double free exceptions.\n"                         | cat
	@printf "\t\tIt's part of the testing process. They're intended to happen.\n"           | cat
	@echo                                                                                   | cat
	@printf "\tfox_allocbytes produces undefined results.\n"                                | cat
	@printf "\t\tIts tests may fail and you shouldn't use the function at all for now.\n"   | cat
	@./$(TESTS) $(TRFLAGS)
	@rm -f **test_*.gc*
	@$(GCOV) -sb

clean:
	@echo "[$(NAME)]: Deleting object files"
	@rm -f $(OBJ)
	@echo "[$(NAME)]: Deleting temp files"
	@rm -f *~ **.gc*
	@echo "[$(NAME)]: Deleting test binaries"
	@rm -f a.out

fclean: clean
	@echo "[$(NAME)]: Deleting dependency files"
	@rm -f $(DEP)
	@echo "[$(NAME)]: Deleting $(TARGET)"
	@rm -f $(TARGET)
	@if [ -e $(TESTS) ];                        \
	then                                        \
	    echo "[$(NAME)]: Deleting $(TESTS)";    \
	    rm -f $(TESTS);                         \
	fi

re:	fclean $(TARGET)

.PHONY:all clean fclean re $(TESTS)