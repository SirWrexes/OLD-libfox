##
## EPITECH PROJECT, 2019
## libfox_memory
## File description:
## lib Makefile
##

SHELL		=	/bin/sh
CC			?=	gcc

############
NAME		=	libfox_memory.a
TESTS		=	tests_memory
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
PSRC		+=	$(PDIR)/fox_allocbytes.c
PSRC		+=	$(PDIR)/fox_calloc.c
PSRC		+=	$(PDIR)/fox_memcpy.c
PSRC		+=	$(PDIR)/fox_memset.c
PSRC		+=	$(PDIR)/fox_realloc.c
PSRC		+=	$(PDIR)/cleanup/fox_autoclose.c
PSRC		+=	$(PDIR)/cleanup/fox_autofree.c
 #
TSRC		+=	$(TDIR)/test_fox_allocbytes.c
TSRC		+=	$(TDIR)/test_fox_calloc.c
TSRC		+=	$(TDIR)/test_fox_memcpy.c
TSRC		+=	$(TDIR)/test_fox_memset.c
TSRC		+=	$(TDIR)/test_fox_realloc.c
TSRC		+=	$(TDIR)/test_fox_autofree.c
TSRC		+=	$(TDIR)/test_fox_autoclose.c
############

OBJ			=	$(SRC:.c=.o)

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
	@if [ -e $(NAME) ];				\
	then							\
		echo "Updating fox_memory";	\
		ar ru $(NAME) $(OBJ);		\
	else							\
		echo "Creating fox_memory";	\
		ar rc $(NAME) $(OBJ);		\
	fi

$(TESTS):
	$(CC) -o $(TESTS) $(TFLAGS) $(TLIB) $(PSRC) $(TSRC)
	-@./$(TESTS)
	@echo																			| cat
	@echo "\tfox_cleanup tests produce double free exceptions.\n"					| cat
	@echo "\t\tIt's part of the testing process. They're intended to happen.\n"		| cat
	@echo																			| cat
	@echo "\tfox_allocbytes produces undefined results.\n"							| cat
	@echo "\t\tIts tests fail and you shouldn't use the function at all for now.\n"	| cat
	@echo																			| cat
	@rm -f **test_*.gc*
	@gcovr -s

clean:
	@echo "fox_memory: Deleting object files"
	@rm -f $(OBJ)
	@echo "fox_memory: Deleting temp files"
	@rm -f *~ **.gc*
	@echo "fox_memory: Deleting test binaries"
	@rm -f a.out

fclean: clean
	@echo "fox_memory: Deleting $(NAME)"
	@rm -f $(NAME)
	@if [ -e $(TESTS) ];						\
    then										\
    	echo "fox_memory: Deleting $(TESTS)";	\
    	rm -f $(TESTS);							\
    fi

re:	fclean all

.PHONY:all clean fclean re