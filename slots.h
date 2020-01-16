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

#define REEL {'!', '@', '#', '$', '%', '^', '&', '*', '7', '?'}
typedef struct {
  char reel1[11] ;
  char reel2[11] ;
  char reel3[11] ;
  int p1; //where we are on the reel
  int p2;
  int p3;
} SM ;

char * spin(SM * slot_machine) ;
int is_win(char * sym) ;
int slots_game(int money);
int super_sleep(int milliseconds);