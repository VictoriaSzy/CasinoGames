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

char spin(slot_machine slots) {
  int x = rand() % 10 ;
  strcpy(REEL[x], slots.reel1) ;
}

int is_win(char * sym) {
  return 0 ;
}

int main() {
  printf("It's time to play with the Slot Machines!\n") ;
  printf("Match two numbers to win the amount you bet.\n") ;
  printf("Match all three numbers to win 10 times the amount you bet!\n") ;
  printf("Have fun!\n") ;

  printf("\n\nEnter the amount you want to bet: ") ;
  scanf() ;
  return 0 ;
}
