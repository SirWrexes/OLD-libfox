##
## EPITECH PROJECT, 2019
## libfox_printf
## File description:
## Slave Makefile
##

SHELL		=	/bin/sh
CC			?=	gcc

############
NAME		=	printf
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
PSRC		+=	$(PDIR)/fox_printf.c
PSRC		+=	$(PDIR)/global_n.c
PSRC		+=	$(PDIR)/va_args.c
PSRC		+=	$(PDIR)/va_args_value.c
PSRC		+=	$(PDIR)/libtools/foxpf_nbsize.c
PSRC		+=	$(PDIR)/libtools/foxpf_strlen.c
PSRC		+=	$(PDIR)/printers/integer/fox_putnbr.c
PSRC		+=	$(PDIR)/printers/integer/printer_picker_integer.c
PSRC		+=	$(PDIR)/printers/other/fox_putc.c
PSRC		+=	$(PDIR)/printers/other/fox_puts.c
PSRC		+=	$(PDIR)/printers/other/printer_picker_other.c
PSRC		+=	$(PDIR)/printers/unsigned/fox_putunbr.c
PSRC		+=	$(PDIR)/printers/unsigned/fox_putunbr_base.c
PSRC		+=	$(PDIR)/printers/unsigned/printer_picker_unsigned.c
 #
TSRC		+=	$(TDIR)/
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