#include "blackjack.h"

#define SPADE   "\xE2\x99\xA0"
#define CLUB    "\xE2\x99\xA3"
#define HEART   "\xE2\x99\xA5"
#define DIAMOND "\xE2\x99\xA6"

#define ACE 1
#define JACK 11
#define QUEEN 12
#define KING 13

// ~~~~~~~~~~~~~~~~ SUM & ACTION FUNCTIONS ~~~~~~~~~~~~~~~~

int find_min_sum(player * p) {
  int x ;
  int sum = 0 ;
  for (x = 0 ; x < (p->cardsInHand) ; x++) {
    if ((p->hand[x]).value > 10) sum += 10 ;
    else {
      sum += (p->hand[x]).value ;
    }
    //printf("Value being added: %d\n", (p->hand[x]).value) ;
  }
  return sum ;
}
int find_max_sum(player * p) {
  int x ;
  int sum = 0 ;
  for (x = 0 ; x < (p->cardsInHand) ; x++) {
    if ((p->hand[x]).value > 10) sum += 10 ;
    else if ((p->hand[x]).value == 1) sum += 11 ;
    else {
      sum += (p->hand[x]).value ;
    }
    //printf("Value being added: %d\n", (p->hand[x]).value) ;
  }
  return sum ;
}
void transferCard(player * p, deck * d) {
  p->hand[p->cardsInHand] = d->cards[d->cardsInDeck - 1] ;
  p->min_sum = find_min_sum(p) ;
  p->max_sum = find_max_sum(p) ;
  d->cards[d->cardsInDeck - 1].valid = 1 ;
  d->cardsInDeck-- ;
  p->cardsInHand++ ;
}
void fold(player * p, deck * d) {

}
void deal(player * p, deck * d) {
  transferCard(p,d) ;
  transferCard(p,d) ;
  p->min_sum = find_min_sum(p) ;
  //printf("The min sum: %d\n", p->min_sum);
  p->max_sum = find_max_sum(p) ;
  //printf("The max sum: %d\n", p->max_sum);
}

void hit(player * p, deck * d) {
  transferCard(p,d) ;
}

// ~~~~~~~~~~~~~~~~ FUNCTIONS FOR SHUFFLING ~~~~~~~~~~~~~~~~

deck makedeck() {
  deck d ;
  int suit, x ;
  for (int suit = 0 ; suit < 4 ; suit++) {
    for (x = 0 ; x < 13 ; x++) {
      card * c = calloc(sizeof(card), 1) ;
  		c->suit = suit ;
  		c->value = x + 1 ;
      c->valid = 0 ;
  		d.cards[x + 13 * suit] = *c ;
  	}
  }
  d.cardsInDeck = 52 ;
  return d ;
}

void shuffle(deck * d) {
  for (int i = 0; i < 100 ; i++) {
		int x, y ;
		x = rand() % 52 ;
		y = rand() % 52 ;
		card tmp = d->cards[x] ;
		d->cards[x] = d->cards[y] ;
		d->cards[y] = tmp ;
	}
}

// ~~~~~~~~~~~~~~~~ PRINTING FUNCTIONS ~~~~~~~~~~~~~~~~
// source of ascii art: https://www.asciiart.eu/miscellaneous/playing-cards
/*i did system clear like what u did in slots. then display the 2 cards originally and the new one right next to them
are you sure it works?
I was thinking of a bunch of strings the length of the card and just adding more to the strings if you hit
let me test it in the main now */
// this will display only the second dealer's card
void beginDisplayDealer(player * dealer) {
  int num = dealer->hand[1].value ;
  int suit = dealer->hand[1].suit ;
  printf(" _____      _____     \n") ;
  // ROW 2
  if (num == ACE) printf("|*****|    |A    |    \n") ;
  else if (num > 1 && num < 10) printf("|*****|    |%d    |    \n", num) ;
  else if (num == 10) {
    if (suit == 0) printf("|*****|    |10 %s |    \n", HEART) ;
    if (suit == 1) printf("|*****|    |10 %s |    \n", CLUB) ;
    if (suit == 2) printf("|*****|    |10 %s |    \n", DIAMOND) ;
    if (suit == 3) printf("|*****|    |10 %s |    \n", SPADE) ;
  }
  else if (num == JACK) printf("|*****|    |J  ww|    \n") ;
  else if (num == QUEEN) printf("|*****|    |Q  ww|    \n") ;
  else if (num == KING) printf("|*****|    |K  WW|    \n") ;
  // ROW 3
  if (num == ACE) printf("|*****|    |     |    \n") ;
  else if (num == 2 || num == 3) {
    if (suit == 0) printf("|*****|    |  %s  |    \n", HEART) ;
    if (suit == 1) printf("|*****|    |  %s  |    \n", CLUB) ;
    if (suit == 2) printf("|*****|    |  %s  |    \n", DIAMOND) ;
    if (suit == 3) printf("|*****|    |  %s  |    \n", SPADE) ;
  }
  else if (num > 3 && num < 8) {
    if (suit == 0) printf("|*****|    | %s %s |    \n", HEART, HEART) ;
    if (suit == 1) printf("|*****|    | %s %s |    \n", CLUB, CLUB) ;
    if (suit == 2) printf("|*****|    | %s %s |    \n", DIAMOND, DIAMOND) ;
    if (suit == 3) printf("|*****|    | %s %s |    \n", SPADE, SPADE) ;
  }
  else if (num > 7 && num < JACK) {
    if (suit == 0) printf("|*****|    |%s %s %s|    \n", HEART, HEART, HEART) ;
    if (suit == 1) printf("|*****|    |%s %s %s|    \n", CLUB, CLUB, CLUB) ;
    if (suit == 2) printf("|*****|    |%s %s %s|    \n", DIAMOND, DIAMOND, DIAMOND) ;
    if (suit == 3) printf("|*****|    |%s %s %s|    \n", SPADE, SPADE, SPADE) ;
  }
  else if (num == JACK) {
    if (suit == 0) printf("|*****|    | %s {)|    \n", HEART) ;
    if (suit == 1) printf("|*****|    | %s {)|    \n", CLUB) ;
    if (suit == 2) printf("|*****|    | %s {)|    \n", DIAMOND) ;
    if (suit == 3) printf("|*****|    | %s {)|    \n", SPADE) ;
  }
  else if (num == QUEEN) {
    if (suit == 0) printf("|*****|    | %s {(|    \n", HEART) ;
    if (suit == 1) printf("|*****|    | %s {(|    \n", CLUB) ;
    if (suit == 2) printf("|*****|    | %s {(|    \n", DIAMOND) ;
    if (suit == 3) printf("|*****|    | %s {(|    \n", SPADE) ;
  }
  else if (num == KING) {
    if (suit == 0) printf("|*****|    | %s {)|    \n", HEART) ;
    if (suit == 1) printf("|*****|    | %s {)|    \n", CLUB) ;
    if (suit == 2) printf("|*****|    | %s {)|    \n", DIAMOND) ;
    if (suit == 3) printf("|*****|    | %s {)|    \n", SPADE) ;
  }
  // ROW 4
  if (num == ACE || num == 3 || num == 5) {
    if (suit == 0) printf("|*****|    |  %s  |    \n", HEART) ;
    if (suit == 1) printf("|*****|    |  %s  |    \n", CLUB) ;
    if (suit == 2) printf("|*****|    |  %s  |    \n", DIAMOND) ;
    if (suit == 3) printf("|*****|    |  %s  |    \n", SPADE) ;
  }
  else if (num == 2 || num == 4) printf("|*****|    |     |    \n") ;
  else if (num == 6 || num == 8) {
    if (suit == 0) printf("|*****|    | %s %s |    \n", HEART, HEART) ;
    if (suit == 1) printf("|*****|    | %s %s |    \n", CLUB, CLUB) ;
    if (suit == 2) printf("|*****|    | %s %s |    \n", DIAMOND, DIAMOND) ;
    if (suit == 3) printf("|*****|    | %s %s |    \n", SPADE, SPADE) ;
  }
  else if (num == 7 || num == 9 || num == 10) {
    if (suit == 0) printf("|*****|    |%s %s %s|    \n", HEART, HEART, HEART) ;
    if (suit == 1) printf("|*****|    |%s %s %s|    \n", CLUB, CLUB, CLUB) ;
    if (suit == 2) printf("|*****|    |%s %s %s|    \n", DIAMOND, DIAMOND, DIAMOND) ;
    if (suit == 3) printf("|*****|    |%s %s %s|    \n", SPADE, SPADE, SPADE) ;
  }
  else if (num == JACK) printf("|*****|    |   %% |    \n") ;
  else if (num == QUEEN) printf("|*****|    |   %%%%|    \n") ;
  else if (num == KING) printf("|*****|    |   %%%%|    \n") ;
  // ROW 5
  if (num == ACE) printf("|*****|    |     |    \n") ;
  else if (num == 2 || num == 3) {
    if (suit == 0) printf("|*****|    |  %s  |    \n", HEART) ;
    if (suit == 1) printf("|*****|    |  %s  |    \n", CLUB) ;
    if (suit == 2) printf("|*****|    |  %s  |    \n", DIAMOND) ;
    if (suit == 3) printf("|*****|    |  %s  |    \n", SPADE) ;
  }
  else if (num >= 4 && num < 8) {
    if (suit == 0) printf("|*****|    | %s %s |    \n", HEART, HEART) ;
    if (suit == 1) printf("|*****|    | %s %s |    \n", CLUB, CLUB) ;
    if (suit == 2) printf("|*****|    | %s %s |    \n", DIAMOND, DIAMOND) ;
    if (suit == 3) printf("|*****|    | %s %s |    \n", SPADE, SPADE) ;
  }
  else if (num >= 8 && num < JACK) {
    if (suit == 0) printf("|*****|    |%s %s %s|    \n", HEART, HEART, HEART) ;
    if (suit == 1) printf("|*****|    |%s %s %s|    \n", CLUB, CLUB, CLUB) ;
    if (suit == 2) printf("|*****|    |%s %s %s|    \n", DIAMOND, DIAMOND, DIAMOND) ;
    if (suit == 3) printf("|*****|    |%s %s %s|    \n", SPADE, SPADE, SPADE) ;
  }
  else if (num == JACK) printf("|*****|    |   %% |    \n") ;
  else if (num == QUEEN) printf("|*****|    |  %%%%%%|    \n") ;
  else if (num == KING) printf("|*****|    |  %%%%%%|    \n") ;
  // ROW 6
  if (num == ACE) printf("|*****|    |____V|    \n") ;
  else if (num == 2) printf("|*****|    |____Z|    \n") ;
  else if (num == 3) printf("|*****|    |____E|    \n") ;
  else if (num == 4) printf("|*****|    |____h|    \n") ;
  else if (num == 5) printf("|*****|    |____S|    \n") ;
  else if (num == 6) printf("|*****|    |____9|    \n") ;
  else if (num == 7) printf("|*****|    |____L|    \n") ;
  else if (num == 8) printf("|*****|    |____8|    \n") ;
  else if (num == 9) printf("|*****|    |____6|    \n") ;
  else if (num == 10) printf("|*****|    |___0I|    \n") ;
  else if (num == JACK) printf("|*****|    |__%%%%[|    \n") ;
  else if (num == QUEEN) printf("|*****|    |_%%%%%%O|    \n") ;
  else if (num == KING) printf("|*****|    |_%%%%%%>|    \n") ;
}
// this will display all of the player's cards on the same lines
void displayCards(player * p) {
  int x = p->cardsInHand ;
  int i, num, suit ;
  for (i = 0 ; i < x ; i++) { // row 1
    printf(" _____     ") ;
  }
  printf("\n") ;
  for (i = 0 ; i < x ; i++) { // row 2
    num = p->hand[i].value ;
    suit = p->hand[i].suit ;
    if (num < 10 && num > 1) printf("|%d    |    ", num) ;
    if (num == 10) {
      if (suit == 0) printf("|10 %s |    ", HEART) ;
      if (suit == 1) printf("|10 %s |    ", CLUB) ;
      if (suit == 2) printf("|10 %s |    ", DIAMOND) ;
      if (suit == 3) printf("|10 %s |    ", SPADE) ;
    }
    if (num == ACE) printf("|A    |    ") ;
    if (num > 10 && num <= KING) {
      if (num == JACK) printf("|J  ww|    ") ;
      else if (num == QUEEN) printf("|Q  ww|    ") ;
      else if (num == KING) printf("|K  WW|    ") ;
    }
  }
  printf("\n") ;
  for (i = 0 ; i < x ; i++) { // row 3
    num = p->hand[i].value ;
    suit = p->hand[i].suit ;
    if (num == ACE) printf("|     |    ") ;
    if (num == 2 || num == 3) {
      if (suit == 0) printf("|  %s  |    ", HEART) ;
      if (suit == 1) printf("|  %s  |    ", CLUB) ;
      if (suit == 2) printf("|  %s  |    ", DIAMOND) ;
      if (suit == 3) printf("|  %s  |    ", SPADE) ;
    }
    if (num > 3 && num < 8) {
      if (suit == 0) printf("| %s %s |    ", HEART, HEART) ;
      if (suit == 1) printf("| %s %s |    ", CLUB, CLUB) ;
      if (suit == 2) printf("| %s %s |    ", DIAMOND, DIAMOND) ;
      if (suit == 3) printf("| %s %s |    ", SPADE, SPADE) ;
    }
    if (num > 7 && num < JACK) { // 8, 9, and 10 have 3 of the suit in this row
      if (suit == 0) printf("|%s %s %s|    ", HEART, HEART, HEART) ;
      if (suit == 1) printf("|%s %s %s|    ", CLUB, CLUB, CLUB) ;
      if (suit == 2) printf("|%s %s %s|    ", DIAMOND, DIAMOND, DIAMOND) ;
      if (suit == 3) printf("|%s %s %s|    ", SPADE, SPADE, SPADE) ;
    }
    if (num == JACK) {
      if (suit == 0) printf("| %s {)|    ", HEART) ;
      if (suit == 1) printf("| %s {)|    ", CLUB) ;
      if (suit == 2) printf("| %s {)|    ", DIAMOND) ;
      if (suit == 3) printf("| %s {)|    ", SPADE) ;
    }
    if (num == QUEEN) {
      if (suit == 0) printf("| %s {(|    ", HEART) ;
      if (suit == 1) printf("| %s {(|    ", CLUB) ;
      if (suit == 2) printf("| %s {(|    ", DIAMOND) ;
      if (suit == 3) printf("| %s {(|    ", SPADE) ;
    }
    if (num == KING) {
      if (suit == 0) printf("| %s {)|    ", HEART) ;
      if (suit == 1) printf("| %s {)|    ", CLUB) ;
      if (suit == 2) printf("| %s {)|    ", DIAMOND) ;
      if (suit == 3) printf("| %s {)|    ", SPADE) ;
    }
  }
  printf("\n") ;
  for (i = 0 ; i < x ; i++) { // row 4
    num = p->hand[i].value ;
    suit = p->hand[i].suit ;
    if (num == ACE || num == 3 || num == 5) {
      if (suit == 0) printf("|  %s  |    ", HEART) ;
      if (suit == 1) printf("|  %s  |    ", CLUB) ;
      if (suit == 2) printf("|  %s  |    ", DIAMOND) ;
      if (suit == 3) printf("|  %s  |    ", SPADE) ;
    }
    if (num == 2 || num == 4) printf("|     |    ") ;
    if (num == 6 || num == 8) {
      if (suit == 0) printf("| %s %s |    ", HEART, HEART) ;
      if (suit == 1) printf("| %s %s |    ", CLUB, CLUB) ;
      if (suit == 2) printf("| %s %s |    ", DIAMOND, DIAMOND) ;
      if (suit == 3) printf("| %s %s |    ", SPADE, SPADE) ;
    }
    if (num == 7 || num == 9 || num == 10) {
      if (suit == 0) printf("|%s %s %s|    ", HEART, HEART, HEART) ;
      if (suit == 1) printf("|%s %s %s|    ", CLUB, CLUB, CLUB) ;
      if (suit == 2) printf("|%s %s %s|    ", DIAMOND, DIAMOND, DIAMOND) ;
      if (suit == 3) printf("|%s %s %s|    ", SPADE, SPADE, SPADE) ;
    }
    if (num == JACK) printf("|   %% |    ") ;
    if (num == QUEEN) printf("|   %%%%|    ") ;
    if (num == KING) printf("|   %%%%|    ") ;
  }
  printf("\n") ;
  for (i = 0 ; i < x ; i++) { // row 5
    num = p->hand[i].value ;
    suit = p->hand[i].suit ;
    if (num == ACE) printf("|     |    ") ;
    if (num == 2 || num == 3) {
      if (suit == 0) printf("|  %s  |    ", HEART) ;
      if (suit == 1) printf("|  %s  |    ", CLUB) ;
      if (suit == 2) printf("|  %s  |    ", DIAMOND) ;
      if (suit == 3) printf("|  %s  |    ", SPADE) ;
    }
    if (num >= 4 && num < 8) {
      if (suit == 0) printf("| %s %s |    ", HEART, HEART) ;
      if (suit == 1) printf("| %s %s |    ", CLUB, CLUB) ;
      if (suit == 2) printf("| %s %s |    ", DIAMOND, DIAMOND) ;
      if (suit == 3) printf("| %s %s |    ", SPADE, SPADE) ;
    }
    if (num >= 8 && num < JACK) {
      if (suit == 0) printf("|%s %s %s|    ", HEART, HEART, HEART) ;
      if (suit == 1) printf("|%s %s %s|    ", CLUB, CLUB, CLUB) ;
      if (suit == 2) printf("|%s %s %s|    ", DIAMOND, DIAMOND, DIAMOND) ;
      if (suit == 3) printf("|%s %s %s|    ", SPADE, SPADE, SPADE) ;
    }
    if (num == JACK) printf("|   %% |    ") ;
    if (num == QUEEN) printf("|  %%%%%%|    ") ;
    if (num == KING) printf("|  %%%%%%|    ") ;
  }
  printf("\n") ;
  for (i = 0 ; i < x ; i++) { // row 6
    num = p->hand[i].value ;
    suit = p->hand[i].suit ;
    if (num == ACE) printf("|____V|    ") ;
    if (num == 2) printf("|____Z|    ") ;
    if (num == 3) printf("|____E|    ") ;
    if (num == 4) printf("|____h|    ") ;
    if (num == 5) printf("|____S|    ") ;
    if (num == 6) printf("|____9|    ") ;
    if (num == 7) printf("|____L|    ") ;
    if (num == 8) printf("|____8|    ") ;
    if (num == 9) printf("|____6|    ") ;
    if (num == 10) printf("|___0I|    ") ;
    if (num == JACK) printf("|__%%%%[|    ") ;
    if (num == QUEEN) printf("|_%%%%%%O|    ") ;
    if (num == KING) printf("|_%%%%%%>|    ") ;
  }
  printf("\n") ;
}

// ~~~~~~~~~~~~~~~~ GAME FUNCTION ~~~~~~~~~~~~~~~~
int play_blackjack(int money, int bet) {
  // this handles actually playing
  printf("Let's begin! It's you and the dealer!\n") ;
  printf("The dealer has received their starting cards.\n") ;
  player p ;
  p.cardsInHand = 0 ;
  player dealer ;
  dealer.cardsInHand = 0 ;
  deck d = makedeck() ;
  int rr = rand() % 25 ;
  for (int x = 0 ; x < rr ; x++) {
    // shuffle the deck a random amount of times
    shuffle(&d) ;
  }
  deal(&dealer, &d) ;
  printf("Dealer:\n") ;
  beginDisplayDealer(&dealer) ;
  printf("\n") ;
  char command[128] ;
  deal(&p, &d) ;
  printf("Your cards:\n") ;
  displayCards(&p) ;
  printf("Smallest Sum: %d\nLargest Sum: %d\n", find_min_sum(&p), find_max_sum(&p)) ;
  printf("\nType in what you want to do (hit or stand): ") ;
  fgets(command, 1024, stdin) ;
  * strchr(command, '\n') = '\0' ;
  while (strcmp(command, "stand") != 0) {
    if (strcmp(command, "exit") == 0 || strcmp(command, "surrender") == 0) return money - bet ; // surrender
    hit(&p, &d) ;
    if (find_min_sum(&p) > 21) {
      printf("You have BUSTED!\n") ;
      printf("***************************************************************************\n") ;
      printf("***************************************************************************\n") ;
      printf("Dealer: \n") ;
      displayCards(&dealer) ;
      printf("Smallest Sum: %d\nLargest Sum: %d\n",find_min_sum(&dealer), find_max_sum(&dealer)) ;
      printf("\nYou:\n") ;
      displayCards(&p) ;
      printf("Sum: %d\n\nYou have BUSTED!\n", find_min_sum(&p)) ;
      money -= bet ;
      return money ;
    }
    printf("***************************************************************************\n") ;
    printf("***************************************************************************\n") ;
    printf("Dealer:\n") ;
    beginDisplayDealer(&dealer) ;
    printf("\n") ;
    printf("Your cards: \n") ;
    displayCards(&p) ;
    printf("Smallest Sum: %d\nLargest Sum: %d\n", find_min_sum(&p), find_max_sum(&p)) ;
    printf("\nType in what you want to do (hit or stand): ") ;
		fgets(command, 1024, stdin) ;
		* strchr(command, '\n') = '\0' ;
  }
  printf("***************************************************************************\n") ;
  printf("***************************************************************************\n") ;
  printf("Dealer:\n") ;
  //after hitting it is the dealers turn to hit
  displayCards(&dealer) ;
  printf("Smallest Sum: %d\nLargest Sum: %d\n", find_min_sum(&dealer), find_max_sum(&dealer)) ;
  printf("Your cards: \n") ;
  displayCards(&p) ;
  printf("Smallest Sum: %d\nLargest Sum: %d\n", find_min_sum(&p), find_max_sum(&p)) ;
  while (dealer.max_sum < 16) {
    hit(&dealer, &d) ; // just make it hit if the sum is less than 16
    printf("***************************************************************************\n") ;
    printf("***************************************************************************\n") ;
    printf("Dealer:\n") ;
    displayCards(&dealer) ;
    printf("Smallest Sum: %d\nLargest Sum: %d\n", find_min_sum(&dealer), find_max_sum(&dealer)) ;
  }
  if (find_min_sum(&dealer) > 21) {
    printf("The dealer has busted.\n") ;
    if (find_min_sum(&p) > 21) {
      printf("Both you and the dealer busted!\n") ;
      return money ;
    }
    else {
      money += (bet * 2) ;
      printf("Congratulations! You won!!\n") ;
      return money ;
    }
  }
  else {
    // the dealer has not busted!
    int d_sum ;
    int p_sum ;
    if (find_max_sum(&dealer) > find_min_sum(&dealer) && find_max_sum(&dealer) < 22) d_sum = find_max_sum(&dealer) ;
    else {
      d_sum = find_min_sum(&dealer) ;
    }
    if (find_max_sum(&p) > find_min_sum(&p) && find_max_sum(&p) < 22) p_sum = find_max_sum(&p) ;
    else {
      p_sum = find_min_sum(&p) ;
    }
    if (d_sum > p_sum) {
      // dealer wins, player loses
      printf("The dealer won! You lost! Better luck next time!\n") ;
      money -= bet ;
      return money ;
    }
    else if (p_sum > d_sum) {
      // player wins, dealer loses
      printf("You are the winner! Congratulations!\n") ;
      money += (bet * 2) ;
      return money ;
    }
    else {
      // there's a tie so no one wins
      printf("This has been a tie!\n") ;
      return money ;
    }
  }
  return money ;
}

int super_sleep(int milliseconds) {
	struct timespec{
    int tv_sec;
    int tv_nsec;
  } ts ;
  ts.tv_sec = milliseconds / 1000 ;
  ts.tv_nsec = (milliseconds % 1000) * 1000000 ;
  return nanosleep(&ts, NULL) ;
}

int blackjack(int money) {
  char command[128] = "help" ;
  int bet = 10 ;
	while (strcmp(command, "exit") != 0) {
		system("clear") ;
    printf("Woohoo! Let's play Blackjack!!\n") ;
    printf("You are given 2 cards. Try to get the highest sum without going over 21 (or \"busting\").\n") ;
    printf("Note: You currently have $%i\n", money) ;
    if (strcmp(command, "help") == 0) {
			printf("\nType commands to play. The commands are: \n") ;
			printf("      -play\n            - Type \"play\" to insert your bet and get the first 2 cards that you are dealt\n") ;
      printf("      -bet\n            - Type \"bet\" to change the amount of your bet\n            - Just try to type in a negative bet and see what happens\n") ;
      printf("      -help\n            - This information shows up!\n") ;
      printf("      -exit\n            - This will allow you to leave Blackjack!\n\n") ;
      printf("**When you are playing, you can enter \"hit\" or \"stand.\"\n") ;
		}
    else if (strcmp(command, "bet") == 0) {
      printf("Your current bet is $%i\n", bet) ;
      printf("Please enter the amount you would like to bet: ") ;
      char newBid[1000] ;
			fgets(newBid, 1000, stdin) ;
			*strchr(newBid, '\n') = '\0' ;
			bet = atoi(newBid) ;
			if (bet < 0 || bet > money) {
				printf("Nice Try\n") ;
        printf("We guess you want to go all in? So, your new bet is now all of the money you have!\n") ;
        bet = money ;
			}
    }
    else if (strcmp(command, "play") == 0) {
      money = play_blackjack(money, bet) ;
    }
		else {
			printf("You entered: \"%s\"\n", command) ;
			printf("This isn't a valid command. Possible commands include: \n\t-play\n\t-bet\n\t-help\n\t-exit\n") ;
		}
		printf("\nType in what you want to do (play, bet, help, exit): ") ;
		fgets(command, 1024, stdin) ;
		*strchr(command, '\n') = '\0' ;
	}
	printf("\nYou are leaving Blackjack!\n") ;
	//super_sleep(800) ;
  return money ;
}
int main(int argc, char const * argv[]) {
  /*player p ;
  p.cardsInHand = 0 ;
  player dealer ;
  dealer.cardsInHand = 0 ;
  deck d = makedeck() ;
  shuffle(&d) ;
  deal(&dealer, &d) ;
  deal(&p, &d) ;
  printf("Dealer:\n") ;
  beginDisplayDealer(&dealer) ;
  printf("\n") ;
  displayCards(&p) ;*/
  blackjack(100) ;
  return 0 ;
}
