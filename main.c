#include "main.h"

int main(int argc, char const *argv[]) {
  command[128];
  while (strcmp(command, "exit") != 0){
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

  	fgets(command, 1024, stdin);
  }
  return 0;
}
