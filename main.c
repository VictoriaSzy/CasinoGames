#include "main.h"

int main(int argc, char const *argv[]) {
	//SDL_SetMainReady();

	printf("UHH idk\n");
	SDL_Window * window;                    // Declare a pointer

    SDL_Init(SDL_INIT_VIDEO); 

    window = SDL_CreateWindow(
        "An SDL2 window",                  // window title
        SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        640,                               // width, in pixels
        480,                               // height, in pixels
        SDL_WINDOW_OPENGL                  // flags - see below
    );

    if (window == NULL) {
        // In the case that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    // The window is open: could enter program loop here (see SDL_PollEvent())

    SDL_Delay(3000);  // Pause execution for 3000 milliseconds, for example

    // Close and destroy the window
    SDL_DestroyWindow(window);

    // Clean up
    SDL_Quit();

    //wait(10);
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
