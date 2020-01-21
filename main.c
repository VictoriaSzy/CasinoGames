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
	printf("You've entered the casino floor!!\n") ;
	printf("You currently have $%i dollars\n", money) ;
	printf("Possible commands are: \n\t-blackjack\n\t-slots\n\t-roulette\n\t-atm\n\t-help\n\t-exit\n") ;
}

int main(int argc, char const *argv[]) {
	//printf("Welcome to the casino!!\n");
	char command[128] = "" ;
	int money = 500;
	int f = open("highscore", O_WRONLY | O_CREAT, 0644);
	write(f, &money, sizeof(int));
	close(f) ;
	while (strcmp(command, "exit") != 0){
		system("clear");
		printf("	                        88     \n                                \"\"   \n ,adPPYba, ,adPPYYba, ,adPPYba, 88 8b,dPPYba,   ,adPPYba,   \na8\"     \"\" \"\"     `Y8 I8[    \"\" 88 88P'   `\"8a a8\"     \"8a  \n8b         ,adPPPPP88  `\"Y8ba,  88 88       88 8b       d8  \n\"8a,   ,aa 88,    ,88 aa    ]8I 88 88       88 \"8a,   ,a8\"  \n `\"Ybbd8\"\' `\"8bbdP\"Y8 `\"YbbdP\"\' 88 88       88  `\"YbbdP\"\' \n");
		printf("\nWelcome to the casino!!\n");
		printf("Possible places to go to are: \n\t-blackjack\n\t-slots\n\t-roulette\n\t-atm\n\t-help\n\t-exit\n");

		printf("\nYou currently have $%i dollars\n", money) ;

		//printf("%i\n", strcmp(command, "exit"));
		//the game loop
		if (strcmp(command, "blackjack") == 0){
			//play blackjack
			money = blackjack(money) ;
			home_message(money) ;
		}
		else if (strcmp(command, "slots") == 0){
			//play the slot machines
			money = slots_game(money);
			home_message(money);
		}
		else if (strcmp(command, "roulette") == 0){
			//play roulette
			money = roulette_game(money);
			home_message(money);
		}
		else if (strcmp(command, "atm") == 0){
			system("clear");
			printf("You contemplate your existence as you walk toward the atm.\n") ;
			printf("You need more money. Or maybe you want more money. You know where this money will go.\n") ;
			printf("Did you really come here to give money to rich coporations?\n\n") ;
			super_sleep(1000);
			printf("The ATM cannot be used to get unlimited money.\n");
			printf("If you use the ATM you will either deposit money until you have $500 left or \n") ;
			printf("you will withdraw from your (unlimited) bank account until you have $500\n") ;
			printf("\nYou currently have $%i dollars\n", money) ;
			printf("\nDo you wish to continue? (y/n): ") ;
			fgets(command, 1024, stdin);
			*strchr(command, '\n') = '\0';
			if (strcmp(command, "y") == 0 || strcmp(command, "yes") == 0) {
				money = 500 ;
				printf("\nTranfering money...\n") ;
				super_sleep(1500) ;
			}
			else {
				printf("You decided to save your money\n") ;
			}
			home_message(money) ;
		}
		else if (strcmp(command, "help") == 0) {
			system("clear") ;
			printf("You're in a casino!\n") ;
			printf("Possible commands are: \n\t-blackjack\n\t-slots\n\t-roulette\n\t-atm\n\t-help\n\t-exit\n");
		}
		else if (strcmp(command, "") == 0) {
			printf("Hmmmmmm. Do you want to enter a command?\n") ;
		}
		else {
			system("clear") ;
			printf("You entered: \"%s\"\n", command) ;
			printf("You did not enter a valid command. Possible commands are:  \n\t-blackjack\n\t-slots\n\t-roulette\n\t-atm\n\t-help\n\t-exit\n") ;
		}
		f = open("highscore", O_RDONLY) ;
		int m = 0 ;
		read(f, &m, sizeof(int));
		close(f) ;
		printf("Currently, the most amount of money you have ever had is: %i (highscore)\n", m) ;
		if (money > m) {
			f = open("highscore", O_WRONLY, 0644);
			if (write(f, &money, sizeof(int)) == -1) printf("NOT GOOD. We can't write to the file!") ;
			close(f) ;
			printf("Congratulations your new highscore is: %i\n", money) ;
		}
		printf("\nEnter what you want to do (blackjack, slots, roulette, atm, help, exit): ") ;
		fgets(command, 1024, stdin) ;
		*strchr(command, '\n') = '\0' ;
	}
	printf("\nYou have left the casino. Thank you for your time.\n") ;
	return 0 ;
}
