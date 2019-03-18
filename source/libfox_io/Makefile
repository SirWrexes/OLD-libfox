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
ROOT		:=	.
PINC		:=	$(ROOT)/include
PDIR		:=	$(ROOT)/src
 #
TROOT		:=	$(ROOT)/tests
TINC		+=	$(TROOT)/include
TDIR		+=	$(TROOT)/src
 #
######
VPATH		=	$(PDIR):$(PINC):$(TDIR):$(TINC):$(TEMPDIR)
############

############
PSRC		+=	$(PDIR)/fox_printf.c
PSRC		+=	$(PDIR)/fox_putc.c
PSRC		+=	$(PDIR)/fox_putint.c
PSRC		+=	$(PDIR)/fox_putllong.c
PSRC		+=	$(PDIR)/fox_putnpc.c
PSRC		+=	$(PDIR)/fox_putnps.c
PSRC		+=	$(PDIR)/fox_puts.c
PSRC		+=	$(PDIR)/fox_putuint.c
PSRC		+=	$(PDIR)/fox_putuint_base.c
PSRC		+=	$(PDIR)/fox_putullong.c
PSRC		+=	$(PDIR)/fox_putullong_base.c
PSRC		+=	$(PDIR)/fox_printf/global_n.c
PSRC		+=	$(PDIR)/fox_printf/printer_picker_integer.c
PSRC		+=	$(PDIR)/fox_printf/printer_picker_other.c
PSRC		+=	$(PDIR)/fox_printf/printer_picker_unsigned.c
PSRC		+=	$(PDIR)/fox_printf/va_args.c
PSRC		+=	$(PDIR)/fox_printf/va_args_value.c
PSRC		+=	$(DIR_MATH)/$(PDIR)/fox_nbsize.c
PSRC		+=	$(DIR_STRING)/$(PDIR)/fox_strlen.c
 #
TSRC		+=	$(TDIR)/test_fox_putc.c
TSRC		+=	$(TDIR)/test_fox_putint.c
TSRC		+=	$(TDIR)/test_fox_puts.c
TSRC        +=	$(TDIR)/fox_printf/test_global_n.c
TSRC		+=	$(DIR_MATH)/$(TDIR)/test_fox_nbsize.c
TSRC		+=	$(DIR_STRING)/$(TDIR)/test_fox_strlen.c
############

############
OBJ			=	$(PSRC:.c=.o)
DEP			=	$(OBJ:.o=.d)
.PRECIOUS	=	$(DEP)
-include $(DEP)
############

############
include ../.includes
CFLAGS		+=	$(INCLUDES)
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
		ar ru $@ $^;		\
	else					\
		echo "Creating $@";	\
		ar rc $@ $^;		\
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
	@gcovr -sb

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

.PHONY:all clean fclean re $(TESTS)