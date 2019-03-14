## libfox_io
## File description:
## Master Makefile
##

SHELL  =	/bin/sh
MAKE   = 	make --silent -C
RM     =	rm -f
CP     =	cp -t
SRCDIR =	./source


.DEFAULT_GOAL := all
all:    graph io memory string tests
tests:  graph-tests io-tests memory-tests string-tests
clean:  graph-clean io-clean memory-clean string-clean
fclean: graph-fclean io-fclean memory-fclean string-fclean
re:     graph-re io-re memory-re string-re tests
.PHONY: all tests clean fclean re

############################
##         Graph          ##
############################
graph:
	@$(MAKE)  $(SRCDIR)/libfox_graph
	@$(CP)    .        $(SRCDIR)/libfox_graph/libfox_graph.a
	@$(CP) 	  include  $(SRCDIR)/libfox_graph/include/fox_graph.h
graph-tests:
	@if [ -e "$(SRCDIR)/libfox_graph/tests_graph" ];	\
	then							\
		  $(SRCDIR)/libfox_graph/tests_graph;		\
	else							\
		  $(MAKE) $(SRCDIR)/libfox_graph tests_graph;	\
	fi
graph-clean:
	@$(MAKE)  $(SRCDIR)/libfox_graph clean
graph-fclean:
	@$(MAKE)  $(SRCDIR)/libfox_graph fclean
	@$(RM)    ./libfox_graph.a
	@$(RM)    include/fox_graph.h
graph-re:
	@$(MAKE)  $(SRCDIR)/libfox_graph re
.PHONY: graph graph-tests graph-clean graph-fclean graph-re

############################
##      input/output      ##
############################
io:
	@$(MAKE)  $(SRCDIR)/libfox_io
	@$(CP)    .        $(SRCDIR)/libfox_io/libfox_io.a
	@$(CP)    include  $(SRCDIR)/libfox_io/include/fox_io.h
io-tests:
	@if [ -e "$(SRCDIR)/libfox_io/tests_io" ];			\
	then								\
		  $(SRCDIR)/libfox_io/tests_io;				\
	else								\
		  $(MAKE) $(SRCDIR)/libfox_io tests_io;			\
	fi
io-clean:
	@$(MAKE) $(SRCDIR)/libfox_io	clean
io-fclean:
	@$(MAKE) $(SRCDIR)/libfox_io	fclean
	@$(RM) ./libfox_io.a
	@$(RM) include/fox_io.h
io-re:
	@$(MAKE) $(SRCDIR)/libfox_io	re
.PHONY: io io-tests io-clean io-fclean io-re


############################
##         memory         ##
############################
memory:
	@$(MAKE) $(SRCDIR)/libfox_memory
	@$(CP) .		$(SRCDIR)/libfox_memory/libfox_memory.a
	@$(CP) include  $(SRCDIR)/libfox_memory/include/fox_memory.h
memory-tests:
	@if [ -e "$(SRCDIR)/libfox_memory/tests_memory" ];		\
	then								\
		$(SRCDIR)/libfox_memory/tests_memory			\
	else								\
		$(MAKE) $(SRCDIR)/libfox_memory tests_memory;		\
	fi
memory-clean:
	@$(MAKE) $(SRCDIR)/libfox_memory	clean
memory-fclean:
	@$(MAKE) $(SRCDIR)/libfox_memory	fclean
	@$(RM) ./libfox_memory.a
	@$(RM) include/fox_memory.h
memory-re:
	@$(MAKE) $(SRCDIR)/libfox_memory	re
.PHONY: memory memory-tests memory-clean memory-fclean memory-re


############################
##         string         ##
############################
string:
	@$(MAKE) $(SRCDIR)/libfox_string
	@$(CP) 	.		$(SRCDIR)/libfox_string/libfox_string.a
	@$(CP) 	include  $(SRCDIR)/libfox_string/include/fox_string.h
string-tests:
	@if [ -e "$(SRCDIR)/libfox_string/tests_string" ];		\
	then								\
		$(SRCDIR)/libfox_string/tests_string;			\
	else								\
		$(MAKE) $(SRCDIR)/libfox_string tests_string;		\
	fi
string-clean:
	@$(MAKE) $(SRCDIR)/libfox_string	clean
string-fclean:
	@$(MAKE) $(SRCDIR)/libfox_string	fclean
	@$(RM) ./libfox_string.a
	@$(RM) include/fox_string.h
string-re:
	@$(MAKE) $(SRCDIR)/libfox_string	re
.PHONY: string string-tests string-clean string-fclean string-re
