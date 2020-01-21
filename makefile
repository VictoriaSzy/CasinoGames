ifeq ($(DEBUG), true)
	CC = gcc -g
else
	CC = gcc
endif

#ifeq ($(MAC_OS), true)
#	CC = gcc
#else
#	CC = gcc -mcmodel=medium -Wl,--image-base -Wl,0x10000000
#endif

#all: blackjack.o main.o
#	$(CC) -I /usr/include/SDL2  -o program main.o -lSDL2

all: slots.o main.o roulette.o blackjack.o
	$(CC) -o program main.o slots.o roulette.o blackjack.o

blackjack.o: blackjack.c blackjack.h
	$(CC) -c blackjack.c

roulette.o: roulette.c roulette.h
	$(CC) -c roulette.c

slots.o: slots.c slots.h
	$(CC) -c slots.c

main.o: main.c main.h
	$(CC) -c main.c

run:
	./program

clean:
	rm*.o
	rm*~
