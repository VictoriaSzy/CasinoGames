ifeq ($(DEBUG), true)
	CC = gcc -g
else
	CC = gcc
endif

all: blackjack.o main.o
	$(CC) main.o -o program -I include -L lib -l SDL2-2.0.10

blackjack.o: blackjack.c blackjack.h
	$(CC) -c blackjack.c
main.o: main.c main.h
	$(CC) -c main.c
run:
	./program

clean:
	rm*.o
	rm*~
