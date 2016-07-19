CC=gcc
FLAGS=-lm
FLAGS+=-I .

test: distribution.o
	$(CC) $(FLAGS) distribution.o test.c -o test

distribution.o: distribution.c distribution.h
	$(CC) $(FLAGS) -c distribution.c

clean:
	rm -f *.o
