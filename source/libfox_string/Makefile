##
## EPITECH PROJECT, 2019
## libfox
## File description:
## input/output
##

SHELL		=	/bin/sh
CC			?=	gcc

############
NAME		=	libfox_string.a
TESTS		=	tests_string
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
PSRC		+=	$(PDIR)/fox_strcmp.c
PSRC		+=	$(PDIR)/fox_strdup.c
PSRC		+=	$(PDIR)/fox_strlen.c
 #
TSRC		+=	$(TDIR)/test_fox_strcmp.c
TSRC		+=	$(TDIR)/test_fox_strdup.c
TSRC		+=	$(TDIR)/test_fox_strlen.c
############

OBJ			=	$(PSRC:.c=.o)

############
CDEBUG		=	-g3
#CFLAGS		+=	$(CDEBUG)
CFLAGS		+=	-Wall -Wextra
CFLAGS		+=	-Werror
CFLAGS		+=	-iquote$(PINC)
 #
TFLAGS		+=	$(CFLAGS)
TFLAGS		+=	-iquote$(TINC)
TFLAGS		+=  --coverage -lcriterion
TFLAGS		+=	-D LIBFOX_UT
############

all: $(NAME)

$(NAME): $(OBJ)
	@if [ -e $(NAME) ];					\
	then								\
		echo "Updating fox_string";		\
		ar ru $(NAME) $(OBJ);			\
	else								\
		echo "Creating fox_string";		\
		ar rc $(NAME) $(OBJ);			\
	fi

$(TESTS):
	@$(CC) -o $(TESTS) $(TFLAGS) $(TLIB) $(PSRC) $(TSRC)
	-@./$(TESTS)
	@rm -f **test_*.gc*
	@gcovr -s

clean:
	@echo "fox_string: Deleting object files"
	@rm -f $(OBJ)
	@echo "fox_string: Deleting temp files"
	@rm -f *~ **.gc*
	@echo "fox_string: Deleting test binaries"
	@rm -f a.out

fclean: clean
	@echo "fox_string: Deleting $(NAME)"
	@rm -f $(NAME)
	@if [ -e $(TESTS) ];						\
	then										\
		echo "fox_string: Deleting $(TESTS)";	\
		rm -f $(TESTS);							\
	fi

re:	fclean all

.PHONY:all clean fclean re