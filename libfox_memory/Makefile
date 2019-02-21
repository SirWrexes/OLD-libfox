##
## EPITECH PROJECT, 2019
## libfox_memory
## File description:
## lib Makefile
##

NAME		=	libfox_memory.a

SHELL		=	/bin/sh

CC			?=	gcc

ROOT		=	libfox_memory
SRCDIR		+=	src
INCDIR		+=	include

VPATH		=	$(SRCDIR):$(INCDIR)

SRC			+=	$(SRCDIR)/fox_allocbytes.c
SRC			+=	$(SRCDIR)/fox_calloc.c
SRC			+=	$(SRCDIR)/fox_memcpy.c
SRC			+=	$(SRCDIR)/fox_memset.c
SRC			+=	$(SRCDIR)/fox_realloc.c
SRC			+=	$(SRCDIR)/cleanup/fox_autoclose.c
SRC			+=	$(SRCDIR)/cleanup/fox_autofree.c

OBJ			=	$(SRC:.c=.o)

CDEBUG		=	-g3

#CFLAGS		+=	$(CDEBUG)
CFLAGS		+=	-Wall -Wextra
CFLAGS		+=	-Werror
CFLAGS		+=	-iquote$(INCDIR) -iquote../libfox_macro/include

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
	@echo "Creating symlink in libfox/ root"
	@cd ..; ln -s $(ROOT)/$(NAME)

clean:
	@echo "fox_memory: Deleting object files"
	@rm -f $(OBJ)
	@echo "fox_memory: Deleting temp files"
	@rm -f *~
	@echo "fox_memory: Deleting test binaries"
	@rm -f a.out

fclean: clean
	@echo "fox_memory: Deleting $(NAME)"
	@rm -f $(NAME)
	@echo "fox_memory: Deleting symlink"
	@rm -f ../$(NAME)

re:	fclean all

.PHONY:all tests_run clean fclean re