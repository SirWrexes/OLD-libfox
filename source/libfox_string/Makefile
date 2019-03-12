##
## EPITECH PROJECT, 2019
## libfox_string
## File description:
## Slave Makefile
##

SHELL		=	/bin/sh
CC			?=	gcc

############
NAME		=	string
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
PSRC		+=	$(PDIR)/fox_atoi.c
PSRC		+=	$(PDIR)/fox_isnum.c
PSRC		+=	$(PDIR)/fox_revstr.c
PSRC		+=	$(PDIR)/fox_strcmp.c
PSRC		+=	$(PDIR)/fox_strdup.c
PSRC		+=	$(PDIR)/fox_strlen.c
 #
TSRC		+=	$(TDIR)/test_fox_atoi.c
TSRC		+=	$(TDIR)/test_fox_isnum.c
TSRC		+=	$(TDIR)/test_fox_revstr.c
TSRC		+=	$(TDIR)/test_fox_strcmp.c
TSRC		+=	$(TDIR)/test_fox_strdup.c
TSRC		+=	$(TDIR)/test_fox_strlen.c
############

############
OBJ			=	$(PSRC:%.c=%.o)
DEP			=	$(OBJ:.o=.d)
.PRECIOUS	=	$(DEP)
-include $(DEP)
############

############
include ../.includes
CFLAGS		+=	$(INCLUDES) -iquote $(PINC)
CFLAGS		+=	-Wall -Wextra
CFLAGS		+=	-Werror
 #
TFLAGS		+=	$(CFLAGS)
TFLAGS		+=	-iquote $(TINC)
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

%.o: CFLAGS += -MT $@ -MMD
%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<
	@echo "[$(NAME) | $(CC)] OK → $@"

$(TESTS):
	@$(CC) -o $(TESTS) $(TFLAGS) $(PSRC) $(TSRC)
	@echo							| cat
	@echo							| cat
	@echo "[$(NAME)]: unit tests"	| cat
	-@./$(TESTS)
	@rm -f **test_*.gc*
	@gcovr -s

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
	@if [ -e $(TESTS) ];						\
	then										\
		echo "[$(NAME)]: Deleting $(TESTS)";	\
		rm -f $(TESTS);							\
	fi

re:	fclean $(TARGET)

.PHONY:all clean fclean re $(TESTS)