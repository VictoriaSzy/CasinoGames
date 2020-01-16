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
other three of a kinds get | x1
?17 | x0
*/

/*

I was thinking we just show the animation of the slot machine in sdl after you type in your bet
*/

int super_sleep(int milliseconds){
	struct timespec ts;
  ts.tv_sec = milliseconds / 1000;
  ts.tv_nsec = (milliseconds % 1000) * 1000000;
  return nanosleep(&ts, NULL);
}

char * spin(SM * slm, int bet) {
  int v1, v2, v3;
  v1 = 1;//rand() % 4 + 1;
	v2 = 1;//rand() % 4 + 1;
	v3 = 1;//rand() % 4 + 1;

	slm->p1 = rand() % 10; 
	slm->p2 = rand() % 10; 
	slm->p3 = rand() % 10; 

	int spins = rand() % 10 + 12;
  for (int i = 0; i < spins; i++){
  	system("clear");
  	printf(" SLOT MACHINE       \n");
  	printf("  ___________       \n");
  	printf(" | $ SLOTS $ |      \n");
  	printf(" |   _____   |      \n");

  	//printf(" |  |%c|%c|%c|  | O\n", slm->reel1[(slm->p1+2)%10], slm->reel2[(slm->p2+2)%10], slm->reel3[(slm->p3+2)%10]);
  	printf(" |  |%c|%c|%c|  | O\n", slm->reel1[(slm->p1+1)%10], slm->reel2[(slm->p2+1)%10], slm->reel3[(slm->p3+1)%10]);
  	printf(" |->|%c|%c|%c|<-| |\n", slm->reel1[slm->p1], slm->reel2[slm->p2], slm->reel3[slm->p3]);
  	printf(" |  |%c|%c|%c|  | |\n", slm->reel1[slm->p1 == 0 ? 9 : slm->p1-1], slm->reel2[slm->p2 == 0 ? 9 : slm->p2-1], slm->reel3[slm->p3 == 0 ? 9 : slm->p3-1]);
   	//printf(" |  |%c|%c|%c|  | |\n", slm->reel1[slm->p1 == 1 ? 9 : slm->p1-2], slm->reel2[slm->p2 == 1 ? 9 : slm->p2-2], slm->reel3[slm->p3 == 1 ? 9 : slm->p3-2]);
 	
  	printf(" |===========|=#      \n");
  	printf(" |Betting: $%i        \n", bet);
  	slm->p1 += v1; slm->p1 = slm->p1 % 10;
  	slm->p2 += v2; slm->p2 = slm->p2 % 10;
  	slm->p3 += v3; slm->p3 = slm->p3 % 10;
  	super_sleep(80);
  }
  return NULL ;
}

int is_win(char * sym) {
  return 0 ;
}
int slots_game(int money) {}
int main(int money) {
  printf("It's time to play with the Slot Machines!\n") ;
  printf("Match three numbers to win the amount you bet.\n") ;
  printf("Match all three numbers to win 10 times the amount you bet!\n") ;
  printf("Have fun!\n") ;
	
  SM slot_machine = {{'!', '@', '#', '$', '%', '^', '&', '*', '7', '?'},{'&', '7', '#', '@', '%', '^', '!', '*', '?', '$'},{ '$', '#', '!', '%', '&', '@', '*', '7', '?', '^'}};
  for (int i = 0; i < 10; i++){
  	printf("%c\n",slot_machine.reel1[i]);
  }
  char command[128] = "help";
  int bet = 10;
	while (strcmp(command, "exit") != 0){
		system("clear");
		if (strcmp(command, "play") == 0){
			srand(time(0));
			spin(&slot_machine, bet);
		}
		else if (strcmp(command, "bet") == 0){
			//play the slot machines
		}
		else if (strcmp(command, "help") == 0){
			printf("Type in commands to play. The Commands are: \n");
			printf("\t-play\n\t  -Type \"play\" to insert your bet and pull the lever on the slot machine\n\t-bet\n\t  -Type \"bet\" use to change your bet\n\t-help\n\t-exit\n");
		}
		else {
			printf("You entered: %s\n", command);
			printf("You did not enter a valid command. Possible commands are: \n\t-play\n\t-bet\n\t-help\n\t-exit\n");
		}
		printf("Enter your command: ");
		fgets(command, 1024, stdin);
		*strchr(command, '\n') = '\0';
	}
  return money ;
}
