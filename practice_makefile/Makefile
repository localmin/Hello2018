# Makefile
objs = hello.c edajima.o 
CC = gcc

hello: $(objs)
		$(CC) -o hello $(objs) 

hello.o: hello.c 
		$(CC) -c hello.c 

edajima.o: edajima.c 
		$(CC) -c edajima.c 


.PHONY: clean
clean:
		$(RM) -f hello $(objs) 
