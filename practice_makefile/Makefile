# Makefile
program = hello
objs = hello.c edajima.o 
CC = gcc
CFLAGS= -Wall -g 

$(hello): $(objs)
		$(CC) -o $@ $^ 

hello.o: hello.c 
		$(CC) $(CFLAGS) -c $< 

edajima.o: edajima.c 
		$(CC) $(CFLAGS) -c $< 

.PHONY: clean
clean:
		$(RM) $(program) $(objs) 
