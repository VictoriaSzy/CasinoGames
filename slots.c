#include "slots.h"
/* functionality
3 slots
10 symbols per reel
! @ # $ % ^ & * 7 ?
players spin three to see if they get any combinations

777 | x100
$$$ | x10
@@@ | x3
### | x2
?17 | x0
*/

/*

I was thinking we just show the animation of the slot machine in sdl after you type in your bet
*/

char * spin(SM * slot_machine) {
  for (int i = 0; i < 10)
  return NULL ;
}

int is_win(char * sym) {
  return 0 ;
}

int slots_game(int money) {
  printf("It's time to play with the Slot Machines!\n") ;
  printf("Match three numbers to win the amount you bet.\n") ;
  printf("Match all three numbers to win 10 times the amount you bet!\n") ;
  printf("Have fun!\n") ;

  SM slot_machine = {{'!', '@', '#', '$', '%', '^', '&', '*', '7', '?'},{'!', '@', '#', '$', '%', '^', '&', '*', '7', '?'},{'!', '@', '#', '$', '%', '^', '&', '*', '7', '?'}};
  char command[128];
  int bet;
	while (strcmp(command, "exit") != 0){
		system("clear");
		if (strcmp(command, "play") == 0){
			spin(&slot_machine);
		}
		else if (strcmp(command, "bet") == 0){
			//play the slot machines
		}
		else if (strcmp(command, "help") == 0){
			printf("\t-play\nType \"play\" to pull the lever on the slot machine\n\t-bet\nType \"bet\" to change your bet\n\t-\n\t-help\n\t-exit\n");
		}
		else {
			printf("You entered: %s\n", command);
			printf("You did not enter a valid command. Possible commands are: \n\t-play\n\t-bet\n\t-\n\t-help\n\t-exit\n");
		}
		printf("Enter your command: ");
		fgets(command, 1024, stdin);
		*strchr(command, '\n') = '\0';
	}

  return 0 ;
}
