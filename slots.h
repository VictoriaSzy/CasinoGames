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
  char reel1[10] ;
  char reel2[10] ;
  char reel3[10] ;
} SM ;

<<<<<<< HEAD
char spin(slot_machine slots) ;
=======
char * spin(SM * slot_machine) ;
>>>>>>> 4f76c707f017c90ccfaacb13c50b197d4e9e4976
int is_win(char * sym) ;
int slots_game(int money);
