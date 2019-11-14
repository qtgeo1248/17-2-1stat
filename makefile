ifeq ($(DEBUG), true)
	CC = gcc -g
else
	CC = gcc
endif

all: main.o
	$(CC) -o program main.o

main.o: main.c
	$(CC) -c main.c

run:
	./program

clean:
	rm *.o

memcheck:
	valgrind --leak-check=yes ./program
