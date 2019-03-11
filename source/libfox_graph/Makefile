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
 #
TSRC		+=
############

############
OBJ			=	$(PSRC:%.c=%.o)
DEP			=	$(OBJ:.o=.d)
-include $(DEP)
############

############
CFLAGS		+=	-Wall -Wextra
CFLAGS		+=	-Werror
CFLAGS		+=	-iquote$(PINC)
 #
TFLAGS		+=	$(CFLAGS)
TFLAGS		+=	-iquote$(TINC)
TFLAGS		+=  --coverage -lcriterion
TFLAGS		+=	-D LIBFOX_UT
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

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<
	@echo "[OK]: $@"

$(TESTS):
	@$(CC) -o $(TESTS) $(TFLAGS) $(TLIB) $(PSRC) $(TSRC)
	@echo						| cat
	@echo						| cat
	@echo "$(NAME): unit tests"	| cat
	-@./$(TESTS)
	@rm -f **test_*.gc*
	@gcovr -s

clean:
	@echo "$(NAME): Deleting object files"
	@rm -f $(OBJ)
	@echo "$(NAME): Deleting temp files"
	@rm -f *~ **.gc*
	@echo "$(NAME): Deleting test binaries"
	@rm -f a.out

fclean: clean
	@echo "$(NAME): Deleting $(TARGET)"
	@rm -f $(TARGET)
	@if [ -e $(TESTS) ];					\
	then									\
		echo "$(NAME): Deleting $(TESTS)";	\
		rm -f $(TESTS);						\
	fi

re:	fclean $(TARGET)

.PHONY:all clean fclean re