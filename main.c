#include "main.h"
#include <SDL2/SDL.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
	printf("Initializing SDL.\n");

	/* Initialize defaults, Video and Audio */
	if((SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO)==-1)) {
			printf("Could not initialize SDL: %s.\n", SDL_GetError());
			exit(-1);
	}

	printf("SDL initialized.\n");

	printf("Quiting SDL.\n");

	/* Shutdown all subsystems */
	SDL_Quit();

	printf("Quiting....\n");

	exit(0);

	////////// other things
	/*
	printf("Welcome to the casino!!\n");
	printf("Possible commands are: \n-blackjack\n\t-slot\n\t-roulette\n\t-help\n\t-exit\n");
	char command[128];
	while (strcmp(command, "exit") != 0){
		system("clear");
		//printf("%i\n", strcmp(command, "exit"));
		//the game loop
		if (strcmp(command, "blackjack") == 0){
			//play blackjack
		}
		else if (strcmp(command, "slot") == 0){
			//play the slot machines
		}
		else if (strcmp(command, "roulette") == 0){
			//play roulette
		}
		else if (strcmp(command, "help") == 0){
			printf("Welcome to the casino!!\n");
			printf("Possible commands are: \n-blackjack\n\t-slot\n\t-roulette\n\t-help\n\t-exit\n");
		}
		else {
			printf("You entered: %s\n", command);
			printf("You did not enter a valid command. Possible commands are: \n\t-blackjack\n\t-slot\n\t-roulette\n\t-help\n\t-exit\n");
		}
		printf("Enter your command: ");
		fgets(command, 1024, stdin);
		*strchr(command, '\n') = '\0';
	}*/
	return 0;
	}
