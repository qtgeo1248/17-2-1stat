ifeq ($(DEBUG), true)
	CC = gcc -g
else
	CC = gcc
endif

all: main.o
	gcc -o program main.o

main.o: main.c stat.h
	gcc -c main.c

run:
	./program

clean:
	rm *.o

memcheck:
	valgrind --leak-check=yes ./program
