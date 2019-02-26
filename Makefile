## libfox_io
## File description:
## Master Makefile
##

SHELL		=	/bin/sh

all: io memory printf all-tests
all-tests: io-tests memory-tests printf-tests
all-clean: io-clean memory-clean printf-clean tests_run-clean
all-fclean: io-fclean memory-fclean printf-fclean
all-re: io-re memory-re printf-re
.PHONY: all all-tests all-clean all-fclean all-re

io:
	@make -C libfox_io
io-tests:
	@if [ -e "libfox_io/tests_io" ];	\
    then								\
    	libfox_io/tests_io;				\
    else								\
    	make -C libfox_io tests_io;		\
    fi
io-clean:
	@make -C libfox_io		clean
io-fclean:
	@make -C libfox_io		fclean
io-re:
	@make -C libfox_io		re
.PHONY: io io-tests io-clean io-fclean io-re

memory:
	@make -C libfox_memory
memory-tests:
	@if [ -e "libfox_memory/tests_memory" ];	\
	then										\
		libfox_memory/tests_memory;				\
	else										\
		make -C libfox_memory tests_memory;		\
	fi
memory-clean:
	@make -C libfox_memory	clean
memory-fclean:
	@make -C libfox_memory	fclean
memory-re:
	@make -C libfox_memory	re
.PHONY: memory memory-tests memory-clean memory-fclean memory-re

printf:
	@make -C libfox_printf
printf-tests:
	@echo "No printf test yet."
printf-clean:
	@make -C libfox_printf	clean
printf-fclean:
	@make -C libfox_printf	fclean
printf-re:
	@make -C libfox_printf	re
.PHONY: printf printf-tests printf-clean printf-fclean printf-re
