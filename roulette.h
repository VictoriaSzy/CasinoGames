#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <string.h>
#include <errno.h>

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <dirent.h>

#include <math.h>
#include <signal.h>

//#define SDL_MAIN_HANDLED
//#include <SDL2/SDL.h>

#define WHEEL {'!', '@', '#', '$', '%', '^', '&', '*', '7', '?'}
#include "slots.h"
typedef struct{
	int nums[26];//24 + even and odd
	int amounts[26];
}bets;

int roulette_spin(int money) ;
int roulette_game(int money);
char bp(int num, int ballpos);
//int super_sleep(int milliseconds);
