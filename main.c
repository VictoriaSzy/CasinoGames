#include "main.h"

SDL_Texture * load_cards_texture(SDL_Renderer * renderer) {
  SDL_Surface * cards_surface = SDL_LoadBMP("img/cards.bmp") ;
  if (cards_surface == NULL) {
    printf("Unable to load image %s! SDL Error: %s\n", "img/cards.bmp", SDL_GetError()) ;
    exit(EXIT_FAILURE) ;
  }
  SDL_Texture * cards_texture = SDL_CreateTextureFromSurface(renderer, cards_surface) ;
  SDL_FreeSurface(cards_surface) ;
  return cards_texture ;
}

void new_game() {
	deck * d ;
  card c ;
	int suit, x;
	// this first for loop adds the heart cards
	for (x = 0 ; x < 13 ; x++) {
		c.suit = 0 ;
		if (x < 10) c.value = x + 1 ;
		else {
			c.value = 10 ;
		}
		d->cards[x] = c ;
	}
	// this for loop adds the clubs
	for (x = 13 ; x < 26 ; x++) {
		c.suit = 1 ;
		if (x < 10) c.value = x + 1 ;
		else {
			c.value = 10 ;
		}
		d->cards[x] = c ;
	}
	// this for loop adds the diamonds
	for (x = 26 ; x < 39 ; x++) {
		c.suit = 2 ;
		if (x < 10) c.value = x + 1 ;
		else {
			c.value = 10 ;
		}
		d->cards[x] = c ;
	}
	// this for loop adds the spades
	for (x = 39 ; x < 52 ; x++) {
		c.suit = 3 ;
		if (x < 10) c.value = x + 1 ;
		else {
			c.value = 10 ;
		}
		d->cards[x] = c ;
	}
  shuffle(d) ;
}

int main(int argc, char const *argv[]) {
	//SDL_SetMainReady();

	printf("Let's get started!\n") ;
	SDL_Window * window;                    // Declare a pointer

	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow(
		"Games",                  // window title
		SDL_WINDOWPOS_UNDEFINED,           // initial x position
    SDL_WINDOWPOS_UNDEFINED,           // initial y position
    640,                               // width, in pixels
    480,                               // height, in pixels
		// Suggestion: use full screen width and height
		// http://lazyfoo.net/tutorials/SDL/02_getting_an_image_on_the_screen/index.php
    SDL_WINDOW_OPENGL                  // flags - see below
	);

	if (window == NULL) {
		// In the case that the window could not be made...
    printf("Could not create window: %s\n", SDL_GetError());
    return 1;
	}

	//The surface contained by the window
	SDL_Surface* gScreenSurface = NULL;
	gScreenSurface = SDL_GetWindowSurface( window );
	//The image we will load and show on the screen
	SDL_Surface* image = NULL;

	/*
	bool success = true; //Loading success flag
	//Load splash image
  image = SDL_LoadBMP( "02_getting_an_image_on_the_screen/hello_world.bmp" );
	if( image == NULL ) {
		printf( "Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError() );
    success = false;
	}*/



	// The window is open: could enter program loop here (see SDL_PollEvent())
	SDL_Delay(100000);  // Pause execution for 3000 milliseconds, for example
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
