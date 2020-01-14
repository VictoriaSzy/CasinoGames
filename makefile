ifeq ($(DEBUG), true)
	CC = gcc -g
else
	CC = gcc
endif

all: blackjack.o main.o
	$(CC) -mcmodel=medium -Wl,--image-base -Wl,0x10000000 -I /usr/include/SDL2  -o program main.o -lSDL2

blackjack.o: blackjack.c blackjack.h
	$(CC) -c blackjack.c
main.o: main.c main.h
	$(CC) -c main.c
run:
	./program

clean:
	rm*.o
	rm*~
