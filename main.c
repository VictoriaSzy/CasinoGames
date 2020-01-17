#include "main.h"

/*
SDL_Texture * load_cards_texture(SDL_Renderer * renderer) {
  SDL_Surface * cards_surface = SDL_LoadBMP("img/cards.bmp") ;
  if (cards_surface == NULL) {
    printf("Unable to load image %s! SDL Error: %s\n", "img/cards.bmp", SDL_GetError()) ;
    exit(EXIT_FAILURE) ;
  }
  SDL_Texture * cards_texture = SDL_CreateTextureFromSurface(renderer, cards_surface) ;
  SDL_FreeSurface(cards_surface) ;
  return cards_texture ;
} */
void home_message(int money){
	system("clear");
	printf("You've entered the casino floor!!\n");
	printf("You currently have $%i dollars\n", money);
	printf("Possible commands are: \n\t-blackjack\n\t-slots\n\t-roulette\n\t-atm\n\t-help\n\t-exit\n");
}

int main(int argc, char const *argv[]) {
	/*
	SDL_Init(SDL_INIT_VIDEO);

	SDL_WM_SetCaption("SDL Test", "SDL Test");

	SDL_Surface* screen = SDL_SetVideoMode(640, 480, 0, 0);

	SDL_Surface* temp = SDL_LoadBMP("sdl_logo.bmp");

	SDL_Surface* bg = SDL_DisplayFormat(temp);

	SDL_FreeSurface(temp);

	SDL_Event event;
	int gameover = 0;

	while (!gameover)
	{
	if (SDL_PollEvent(&event)) {
	  switch (event.type) {
	    case SDL_QUIT:
	      gameover = 1;
	      break;
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

	SDL_BlitSurface(bg, NULL, screen, NULL);

	SDL_UpdateRect(screen, 0, 0, 0, 0);
	}

	SDL_FreeSurface(bg);

	SDL_Quit();
		*/
    //wait(10);
	////////// other things
	
	//printf("Welcome to the casino!!\n");
	char command[128];
	int money = 100;
	while (strcmp(command, "exit") != 0){
		system("clear");
		printf("Welcome to the casino!!\n");
		printf("Possible places to go to are: \n\t-blackjack\n\t-slots\n\t-roulette\n\t-atm\n\t-help\n\t-exit\n");

		printf("\nYou currently have $%i dollars\n", money);

		//printf("%i\n", strcmp(command, "exit"));
		//the game loop
		if (strcmp(command, "blackjack") == 0){
			//play blackjack
		}
		else if (strcmp(command, "slots") == 0){
			//play the slot machines
			money = slots_game(money);
			home_message(money);
		}
		else if (strcmp(command, "roulette") == 0){
			//play roulette
		}
		else if (strcmp(command, "count") == 0){
			
		}
		else if (strcmp(command, "help") == 0){
			system("clear");
			printf("You're in a casino\n");
			printf("Possible commands are: \n\t-blackjack\n\t-slots\n\t-roulette\n\t-atm\n\t-help\n\t-exit\n");
		}
		else if (strcmp(command, "") == 0){}
		else {
			printf("You entered: \"%s\"\n", command);
			printf("You did not enter a valid command. Possible commands are:  \n\t-blackjack\n\t-slots\n\t-roulette\n\t-atm\n\t-help\n\t-exit\n");
		}
		printf("\nYou decide to do over to the: ");
		fgets(command, 1024, stdin);
		*strchr(command, '\n') = '\0';
	}
	printf("\nYou have left the casino.\n");
	return 0;
}
