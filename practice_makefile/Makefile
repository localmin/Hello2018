# Makefile
.PHONY: all
all: jeki

jeki: jeki.o
		gcc -o jeki jeki.o

jeki.o: jeki.c
		gcc -c jeki.c

jeki.o: jeki.h 

.PHONY: clean
clean:
		rm -f jeki jeki.o 
