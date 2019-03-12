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
PSRC		+=	$(PDIR)/printers/integer/fpf_putnbr.c
PSRC		+=	$(PDIR)/printers/integer/printer_picker_integer.c
PSRC		+=	$(PDIR)/printers/other/fpf_putc.c
PSRC		+=	$(PDIR)/printers/other/fpf_puts.c
PSRC		+=	$(PDIR)/printers/other/printer_picker_other.c
PSRC		+=	$(PDIR)/printers/unsigned/fpf_putunbr.c
PSRC		+=	$(PDIR)/printers/unsigned/fpf_putunbr_base.c
PSRC		+=	$(PDIR)/printers/unsigned/printer_picker_unsigned.c
PSRC		+=	$(DIR_MATH)/src/fox_nbsize.c
PSRC		+=	$(DIR_STRING)/src/fox_strlen.c
 #
TSRC		+=	$(TDIR)/
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
 #
TRFLAGS		+=	--always-succeed --timeout 5
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
	@./$(TESTS) $(TRFLAGS)
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

.PHONY:all $(NAME) clean fclean re $(TESTS)