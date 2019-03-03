## libfox_io
## File description:
## Master Makefile
##

SHELL		=	/bin/sh
SRCDIR		=	./source



all: 	io memory printf string tests
tests: 	io-tests memory-tests printf-tests string-tests
clean: 	io-clean memory-clean printf-clean string-clean
fclean: io-fclean memory-fclean printf-fclean string-fclean
re: 	io-re memory-re printf-re string-re tests
.PHONY: all tests clean fclean re



############################
##      input/output      ##
############################
io:
	@make --silent -C $(SRCDIR)/libfox_io
	@cp -t .		$(SRCDIR)/libfox_io/libfox_io.a
	@cp -t include  $(SRCDIR)/libfox_io/include/fox_io.h
io-tests:
	@if [ -e "$(SRCDIR)/libfox_io/tests_io" ];			\
	then												\
		$(SRCDIR)/libfox_io/tests_io;					\
	else												\
		make --silent -C $(SRCDIR)/libfox_io tests_io;	\
	fi
io-clean:
	@make --silent -C $(SRCDIR)/libfox_io	clean
io-fclean:
	@make --silent -C $(SRCDIR)/libfox_io	fclean
	@rm -f ./libfox_io.a
	@rm -f include/fox_io.h
io-re:
	@make --silent -C $(SRCDIR)/libfox_io	re
.PHONY: io io-tests io-clean io-fclean io-re


############################
##         memory         ##
############################
memory:
	@make --silent -C $(SRCDIR)/libfox_memory
	@cp -t .		$(SRCDIR)/libfox_memory/libfox_memory.a
	@cp -t include  $(SRCDIR)/libfox_memory/include/fox_memory.h
memory-tests:
	@if [ -e "$(SRCDIR)/libfox_memory/tests_memory" ];			\
	then														\
		$(SRCDIR)/libfox_memory/tests_memory;					\
	else														\
		make --silent -C $(SRCDIR)/libfox_memory tests_memory;	\
	fi
memory-clean:
	@make --silent -C $(SRCDIR)/libfox_memory	clean
memory-fclean:
	@make --silent -C $(SRCDIR)/libfox_memory	fclean
	@rm -f ./libfox_memory.a
	@rm -f include/fox_memory.h
memory-re:
	@make --silent -C $(SRCDIR)/libfox_memory	re
.PHONY: memory memory-tests memory-clean memory-fclean memory-re


############################
##          pintf         ##
############################
printf:
	@make --silent -C $(SRCDIR)/libfox_printf
	@cp -t .		$(SRCDIR)/libfox_printf/libfox_printf.a
	@cp -t include  $(SRCDIR)/libfox_printf/include/fox_printf.h
printf-tests:
	@echo "No printf test yet."
printf-clean:
	@make --silent -C $(SRCDIR)/libfox_printf	clean
printf-fclean:
	@make --silent -C $(SRCDIR)/libfox_printf	fclean
	@rm -f ./libfox_printf.a
	@rm -f include/fox_printf.h
printf-re:
	@make --silent -C $(SRCDIR)/libfox_printf	re
.PHONY: printf printf-tests printf-clean printf-fclean printf-re


############################
##         string         ##
############################
string:
	@make --silent -C $(SRCDIR)/libfox_string
	@cp -t .		$(SRCDIR)/libfox_string/libfox_string.a
	@cp -t include  $(SRCDIR)/libfox_string/include/fox_string.h
string-tests:
	@if [ -e "$(SRCDIR)/libfox_string/tests_string" ];			\
	then														\
		$(SRCDIR)/libfox_string/tests_string;					\
	else														\
		make --silent -C $(SRCDIR)/libfox_string tests_string;	\
	fi
string-clean:
	@make --silent -C $(SRCDIR)/libfox_string	clean
string-fclean:
	@make --silent -C $(SRCDIR)/libfox_string	fclean
	@rm -f ./libfox_string.a
	@rm -f include/fox_string.h
string-re:
	@make --silent -C $(SRCDIR)/libfox_string	re
.PHONY: string string-tests string-clean string-fclean string-re