# Makefile
program = jeki 
objs = jeki.o
CC = gcc
CFLAGS= -Wall -g 

.SUFFIXES : .c .o 

.PHONY : all
all : depend $(program)

$(program): $(objs)
		$(CC) -o $(program) $^ 


.c .o : 
	$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean:
		$(RM) $(program) $(objs) depend.inc 

.PHONY : depend
depend : $(objs:.o=.c)
		-@ $(RM) depend.inc
		-@ for i in $^; do\
				cpp -MM $$i | sed "s/\ [_a-zA-Z0-9][_a-zA-Z0-9]*\.c//g">>depend.inc;\
		done

-include depend.inc
