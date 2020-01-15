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

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

#define reel 

char * spin(slot * s);
int is_win(char * sym);
