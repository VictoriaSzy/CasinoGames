#include "main.h"

int main(int argc, char const *argv[]) {
   char command[128];
  while (strcmp(command, "exit") != 0){
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
  	else {
  		printf("You entered: %s\n", command);
  		printf("You did not enter a valid command. Possible commands are: \n-blackjack\n-slot\n-roulette\n-exit\n");
  	}
  	printf("Enter you command: ");
  	fgets(command, 1024, stdin);
  	*strchr(command, '\n') = '\0';
  }
  return 0;
}
