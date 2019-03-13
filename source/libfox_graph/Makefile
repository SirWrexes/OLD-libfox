##
## EPITECH PROJECT, 2019
## libfox_graph
## File description:
## Slave Makefile
##

SHELL		=	/bin/sh
CC			?=	gcc

############
NAME		=	graph
TARGET		=	libfox_$(NAME).a
TESTS		=	tests_$(NAME)
######
PINC		+=	./include
PDIR		+=	./src
 #
TINC		+=	./tests/include
TDIR		+=	./tests/src
######
VPATH		=	$(PDIR):$(PINC):$(TDIR):$(TINC)
############

############
PSRC		+=	$(PDIR)/aitem/aitem_create.c
PSRC		+=	$(PDIR)/aitem/aitem_destroy.c
PSRC		+=	$(PDIR)/alist/alist_create.c
PSRC		+=	$(PDIR)/alist/alist_destroy.c
PSRC		+=	$(PDIR)/graph/graph_create.c
PSRC		+=	$(PDIR)/graph/graph_destroy.c
PSRC		+=	$(DIR_IO)/src/fox_puts.c
PSRC		+=	$(DIR_STRING)/src/fox_strdup.c
PSRC		+=	$(DIR_STRING)/src/fox_strlen.c
 #
TSRC		+=	$(TDIR)/test_aitem.c
TSRC		+=	$(TDIR)/test_alist.c
TSRC		+=	$(TDIR)/test_graph.c
TSRC		+=	$(DIR_IO)/$(TDIR)/test_fox_puts.c
TSRC		+=	$(DIR_STRING)/$(TDIR)/test_fox_strdup.c
TSRC		+=	$(DIR_STRING)/$(TDIR)/test_fox_strlen.c
############

############
OBJ			=	$(PSRC:%.c=%.o)
DEP			=	$(OBJ:.o=.d)
.PRECIOUS	=	$(DEP)
-include $(DEP)
############

############
include ../.includes
CFLAGS		+=	$(INCLUDES)
CFLAGS		+=	-Wall -Wextra
CFLAGS		+=	-Werror
 #
TFLAGS		+=	$(CFLAGS)
TFLAGS		+=	-iquote $(TINC)
TFLAGS		+=  --coverage -lcriterion
TFLAGS		+=	-D LIBFOX_UT
 #
TRFLAGS		+=	--always-succeed --timeout 5
############

.DEFAULT_GOAL := $(TARGET)
$(TARGET): $(OBJ)
	@if [ -e $@ ];			\
	then					\
		echo "Updating $@";	\
		ar ru $@ $<;		\
	else					\
		echo "Creating $@";	\
		ar rc $@ $<;		\
	fi

%.o: CFLAGS += -MT $@ -MMD
%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<
	@echo "[$(NAME) | $(CC)] OK → $@"

$(TESTS):
	@$(CC) -o $(TESTS) $(TFLAGS) $(PSRC) $(TSRC)
	@echo							| cat
	@echo							| cat
	@echo "[$(NAME)]: unit tests"	| cat
	@./$(TESTS) $(TRFLAGS)
	@rm -f **test_*.gc*
	@gcovr -sb

clean:
	@echo "[$(NAME)]: Deleting object files"
	@rm -f $(OBJ)
	@echo "[$(NAME)]: Deleting temp files"
	@rm -f *~ **.gc*
	@echo "[$(NAME)]: Deleting dummy binaries (a.out)"
	@rm -f a.out

fclean: clean
	@echo "[$(NAME)]: Deleting dependency files"
	@rm -f $(DEP)
	@echo "[$(NAME)]: Deleting $(TARGET)"
	@rm -f $(TARGET)
	@if [ -e $(TESTS) ];						\
	then										\
		echo "[$(NAME)]: Deleting $(TESTS)";	\
		rm -f $(TESTS);							\
	fi

re:	fclean $(TARGET)

.PHONY:all clean fclean re $(TESTS)