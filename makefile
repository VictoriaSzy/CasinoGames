ifeq ($(DEBUG), true)
	CC = gcc -g
else
	CC = gcc
endif

all blackjack.o main.o:
	$(CC) -o program main.o

blackjack.o: blackjack.c blackjack.h
	$(CC) -c .c
main.o: main.c main.h
	$(CC) -c main.c
run:
	./program

clean:
	rm*.o
	rm*~
