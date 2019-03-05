##
## EPITECH PROJECT, 2019
## libfox_memory
## File description:
## Slave Makefile
##

SHELL		=	/bin/sh
CC			?=	gcc

############
NAME		=	memory
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

OBJ			=	$(PSRC:.c=.o)

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
$(TARGET): $(TARGET)($(OBJ))

$(TESTS):
	@$(CC) -o $(TESTS) $(TFLAGS) $(TLIB) $(PSRC) $(TSRC)
	@echo						| cat
	@echo						| cat
	@echo "$(NAME): unit tests"	| cat
	@printf "\tfox_cleanup tests produce double free exceptions.\n"						| cat
	@printf "\t\tIt's part of the testing process. They're intended to happen.\n"		| cat
	@echo																				| cat
	@printf "\tfox_allocbytes produces undefined results.\n"							| cat
	@printf "\t\tIts tests fail and you shouldn't use the function at all for now.\n"	| cat
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

re:	fclean all

.PHONY:all clean fclean re