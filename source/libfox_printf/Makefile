##
## EPITECH PROJECT, 2018
## libfox_printf
## File description:
## lib Makefile
##

NAME		=	libfox_printf.a

SHELL		=	/bin/sh

CC			?=	gcc

SRCDIR		+=	src
INCDIR		+=	include

VPATH		=	$(SRCDIR):$(INCDIR)

SRC			+=	$(SRCDIR)/fox_printf.c
SRC			+=	$(SRCDIR)/global_n.c
SRC			+=	$(SRCDIR)/va_args.c
SRC			+=	$(SRCDIR)/va_args_value.c
SRC			+=	$(SRCDIR)/libtools/fox_nbsize.c
SRC			+=	$(SRCDIR)/libtools/fox_strlen.c
SRC			+=	$(SRCDIR)/printers/integer/fox_putnbr.c
SRC			+=	$(SRCDIR)/printers/integer/printer_picker_integer.c
SRC			+=	$(SRCDIR)/printers/other/fox_putc.c
SRC			+=	$(SRCDIR)/printers/other/fox_puts.c
SRC			+=	$(SRCDIR)/printers/other/printer_picker_other.c
SRC			+=	$(SRCDIR)/printers/unsigned/fox_putunbr.c
SRC			+=	$(SRCDIR)/printers/unsigned/fox_putunbr_base.c
SRC			+=	$(SRCDIR)/printers/unsigned/printer_picker_unsigned.c

OBJ			=	$(SRC:.c=.o)

CDEBUG		=	-g3

#CFLAGS		+=	$(CDEBUG)
CFLAGS		+=	-Wall -Wextra
CFLAGS		+=	-Werror
CFLAGS		+=	-iquote$(INCDIR)

all:	$(NAME)

$(NAME):	$(OBJ)
	@if [ -e $(NAME) ];				\
	then							\
		echo "Updating fox_printf";	\
		ar ru $(NAME) $(OBJ);		\
	else							\
		echo "Creating fox_printf";	\
		ar rc $(NAME) $(OBJ);		\
	fi

clean:
	@echo "fox_printf: Deleting object files"
	@rm -f $(OBJ)
	@echo "fox_printf: Deleting temp files"
	@rm -f *~
	@echo "fox_printf: Deleting test binaries"
	@rm -f a.out

fclean:clean
	@echo "fox_printf: Deleting $(NAME)"
	@rm -f $(NAME)

re:	fclean all

.PHONY:all tests_run clean fclean re