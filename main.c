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

int main(int argc, char const *argv[]) {
	SDL_Init(SDL_INIT_VIDEO);

	/* set the title bar */
	SDL_WM_SetCaption("SDL Test", "SDL Test");

	/* create window */
	SDL_Surface* screen = SDL_SetVideoMode(640, 480, 0, 0);

	/* load bitmap to temp surface */
	SDL_Surface* temp = SDL_LoadBMP("sdl_logo.bmp");

	/* convert bitmap to display format */
	SDL_Surface* bg = SDL_DisplayFormat(temp);

	/* free the temp surface */
	SDL_FreeSurface(temp);

	SDL_Event event;
	int gameover = 0;

	/* message pump */
	while (!gameover)
	{
	/* look for an event */
	if (SDL_PollEvent(&event)) {
	  /* an event was found */
	  switch (event.type) {
	    /* close button clicked */
	    case SDL_QUIT:
	      gameover = 1;
	      break;

	    /* handle the keyboard */
	    case SDL_KEYDOWN:
	      switch (event.key.keysym.sym) {
	        case SDLK_ESCAPE:
	        case SDLK_q:
	          gameover = 1;
	          break;
	      }
	      break;
	  }
	}

	/* draw the background */
	SDL_BlitSurface(bg, NULL, screen, NULL);

	/* update the screen */
	SDL_UpdateRect(screen, 0, 0, 0, 0);
	}

	/* free the background surface */
	SDL_FreeSurface(bg);

	/* cleanup SDL */
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
