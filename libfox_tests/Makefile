##
## EPITECH PROJECT, 2019
## libfox_tests
## File description:
## lib Makefile
##

NAME		=	libfox_UT

SHELL		=	/bin/sh

CC			=	gcc

ROOT		=	libfox_tests
TSRC		=	src
TINC		=	include
LINC		=	../libfox_headers


########### IO
# -- INFO
NAME_IO		=	io_tests
PSRC_IO		=	../libfox_io/src
PINC_IO		=	../libfox_io/include
TSRC_IO		=	$(TSRC)/io
# -- SOURCES
SRC_IO		+=	$(PSRC_IO)/fox_putc.c
SRC_IO		+=	$(PSRC_IO)/fox_putint.c
SRC_IO		+=	$(PSRC_IO)/fox_puts.c
SRC_IO		+=	$(PSRC_IO)/libtools/fox_nbsize.c
SRC_IO		+=	$(PSRC_IO)/libtools/fox_strlen.c
# -- TESTS
SRC_IO		+=	$(TSRC_IO)/test_fox_putc.c
###########

BINS		+=	$(NAME_IO)

CFLAGS		+=	-Wall -Wextra
CFLAGS		+=	-Werror
CFLAGS		+=	--coverage
INCDIR		+=	-iquote $(TINC)
INCDIR		+=	-iquote ../libfox_macro/include
INCDIR		+=	-iquote $(PINC_IO)
INCDIR		+=	-iquote $(LINC)
LDLIBS		=	-lcriterion

all: $(NAME_IO) gcovr

$(NAME_IO) :
	$(CC) $(INCDIR) $(CFLAGS) $(LDLIBS) -o $(NAME_IO) $(SRC_IO)
	@./$(NAME_IO)

gcovr:
	-gcovr

clean:
	@echo "fox_tests: Deleting temp files"
	@rm -f *~
	@echo "fox_tests: Deleting coverage files"
	@rm -f **.gc*

fclean: clean
	@echo "fox_tests: Deleting test binaries"
	@rm -f $(BINS)

re:	fclean all

.PHONY: gcovr all clean fclean re