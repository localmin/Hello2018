# Makefile
program = hello
objs = hello.c edajima.o 
CC = gcc
CFLAGS= -Wall -g 

$(hello): $(objs)
		$(CC) -o $@ $^ 

.SUFFIXES: .c .o

.c .o : 
	$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean:
		$(RM) $(program) $(objs) 
