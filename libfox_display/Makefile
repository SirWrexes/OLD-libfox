##
## EPITECH PROJECT, 2018
## libfox_printf
## File description:
## lib Makefile
##

NAME		=	libfox_display.a

SHELL		=	/bin/sh

CC			?=	gcc

ROOT		=	libfox_display
SRCDIR		+=	src
INCDIR		+=	include

VPATH		=	$(SRCDIR):$(INCDIR)

SRC			+=	$(SRCDIR)/fox_putc.c
SRC			+=	$(SRCDIR)/fox_putint.c
SRC			+=	$(SRCDIR)/fox_puts.c
SRC			+=	$(SRCDIR)/libtools/fox_nbsize.c
SRC			+=	$(SRCDIR)/libtools/fox_strlen.c

OBJ			=	$(SRC:.c=.o)

CDEBUG		=	-g3

#CFLAGS		+=	$(CDEBUG)
CFLAGS		+=	-Wall -Wextra
CFLAGS		+=	-Werror
CFLAGS		+=	-iquote$(INCDIR)

all: $(NAME)

$(NAME): $(OBJ)
	@if [ -e $(NAME) ];				\
	then							\
		echo "Updating fox_display";\
		ar ru $(NAME) $(OBJ);		\
	else							\
		echo "Creating fox_display";\
		ar rc $(NAME) $(OBJ);		\
	fi
	@echo "Creating symlink in libfox/ root"
	@cd ..; ln -s $(ROOT)/$(NAME)

clean:
	@echo "fox_display: Deleting object files"
	@rm -f $(OBJ)
	@echo "fox_display: Deleting temp files"
	@rm -f *~
	@echo "fox_display: Deleting test binaries"
	@rm -f a.out

fclean: clean
	@echo "fox_display: Deleting $(NAME)"
	@rm -f $(NAME)
	@echo "fox_display: Deleting symlink"
	@rm -f ../$(NAME)

re:	fclean all

.PHONY:all tests_run clean fclean re