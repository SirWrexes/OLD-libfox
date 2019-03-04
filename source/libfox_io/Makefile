##
## EPITECH PROJECT, 2019
## libfox_io
## File description:
## Slave Makefile
##

SHELL		=	/bin/sh
CC			?=	gcc

############
NAME		=	io
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
PSRC		+=	$(PDIR)/fox_putc.c
PSRC		+=	$(PDIR)/fox_putint.c
PSRC		+=	$(PDIR)/fox_puts.c
PSRC		+=	$(PDIR)/libtools/foxio_nbsize.c
PSRC		+=	$(PDIR)/libtools/foxio_strlen.c
 #
TSRC		+=	$(TDIR)/test_fox_putc.c
TSRC		+=	$(TDIR)/test_fox_putint.c
TSRC		+=	$(TDIR)/test_fox_puts.c
TSRC		+=	$(TDIR)/test_foxio_nbsize.c
TSRC		+=	$(TDIR)/test_foxio_strlen.c
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

all: $(TARGET)

$(TARGET): $(OBJ)
	@if [ -e $(TARGET) ];			\
	then							\
		echo "Updating $(NAME)";	\
		ar ru $(TARGET) $(OBJ);		\
	else							\
		echo "Creating $(NAME)";	\
		ar rc $(TARGET) $(OBJ);		\
	fi

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

re:	fclean all

.PHONY:all $(NAME) clean fclean re