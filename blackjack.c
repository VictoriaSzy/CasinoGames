#include "blackjack.h"
//Using SDL and standard IO
//#include <SDL.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

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
    printf("Value being added: %d\n", (p->hand[x]).value) ;
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
    printf("Value being added: %d\n", (p->hand[x]).value) ;
  }
  return sum ;
}
void transferCard(player * p, deck * d) {
  printf("You are receiving a card!\n");
  p->hand[p->cardsInHand] = d->cards[d->cardsInDeck - 1];
  d->cards[d->cardsInDeck - 1].valid = 1 ;
  printf("good with setting hand cards from deck\n");
  d->cardsInDeck-- ;
  p->cardsInHand++ ;
}
void fold(player * p, deck * d) {

}
void deal(player * p, deck * d) {
  //printf("deal is called\n");
  transferCard(p,d) ;
  printf("first transfer is good\n");
  transferCard(p,d) ;
  printf("second transfer is good\n");
  printf("Added cards to player's hand\n");
  p->min_sum = find_min_sum(p) ;
  printf("The min sum: %d\n", p->min_sum);
  p->max_sum = find_max_sum(p) ;
  printf("The max sum: %d\n", p->max_sum);
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
      //printf("Card value: %d, Card suit: %d\n", d.cards[x].value, d.cards[x].suit) ;
  	}
  }
  d.cardsInDeck = 52 ;
  /*printf("Cards in deck: %d\n", d.cardsInDeck);
  for (int i = 0; i < 52; i++){
    printf("Card value: %d  Card suit: %d\n", d.cards[i].value, d.cards[i].suit);
  }*/
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
void displayCard(int num) {
  printf(" _____ \n") ;
  printf("|%d    |\n", num) ;
  printf("|  \xE2\x99\xA0  |\n") ;
  printf("|     |\n") ;
  printf("|  \xE2\x99\xA0  |\n") ;
  printf("|____Z|\n") ;
  // ALSO NEED TO CORRECT BOTTOM OF CARD FOR EACH NUM AND THE QUANTITY OF THE SUIT
}

void displayAce(int suit) {
  printf(" _____ \n") ;
  printf("|A _  |\n") ;
  printf("|     |\n") ;
  printf("|     |\n") ;

  ////////// NOT DONE HERE YET!!!!!!!!!!!!
  ////////// NOT DONE HERE YET!!!!!!!!!!!!
  ////////// NOT DONE HERE YET!!!!!!!!!!!!
  ////////// NOT DONE HERE YET!!!!!!!!!!!!
  ////////// NOT DONE HERE YET!!!!!!!!!!!!
  ////////// NOT DONE HERE YET!!!!!!!!!!!!
  ////////// NOT DONE HERE YET!!!!!!!!!!!!
}
void displayJack(int suit) {
  printf(" _____ \n") ;
  printf("|J  ww|\n") ;
  if (suit == 0) printf("| \xE2\x99\xA5 {)|\n") ; // HEARTS
  if (suit == 1) printf("| \xE2\x99\xA3 {)|\n") ; // CLUBS
  if (suit == 2) printf("| \xE2\x99\xA6 {)|\n") ; // DIAMONDS
  if (suit == 3) printf("| \xE2\x99\xA0 {)|\n") ; // SPADES
  printf("|   % |\n") ;
  printf("|   % |\n") ;
  printf("|__%%[|\n") ;
}
void displayQueen(int suit) {
  printf(" _____ \n") ;
  printf("|Q  ww|\n") ;
  if (suit == 0) printf("| \xE2\x99\xA5 {(|\n") ; // HEARTS
  if (suit == 1) printf("| \xE2\x99\xA3 {(|\n") ; // CLUBS
  if (suit == 2) printf("| \xE2\x99\xA6 {(|\n") ; // DIAMONDS
  if (suit == 3) printf("| \xE2\x99\xA0 {(|\n") ; // SPADES
  printf("|   %%|\n") ;
  printf("|  %%%|\n") ;
  printf("|_%%%O|\n") ;
}
void displayKing(int suit) {
  printf(" _____ \n") ;
  printf("|K  WW|\n") ;
  if (suit == 0) printf("| \xE2\x99\xA5 {)|\n") ; // HEARTS
  if (suit == 1) printf("| \xE2\x99\xA3 {)|\n") ; // CLUBS
  if (suit == 2) printf("| \xE2\x99\xA6 {)|\n") ; // DIAMONDS
  if (suit == 3) printf("| \xE2\x99\xA0 {)|\n") ; // SPADES
  printf("|   %%|\n") ;
  printf("|  %%%|\n") ;
  printf("|_%%%>|\n") ;
}

void printCard(card c) {
  // We start with printing the value
  printf("value from printcard: %d\n", c.value) ;
  if (c.value > ACE && c.value < JACK) displayCard(c.value) ;
  else if (c.value == ACE) displayAce(c.suit) ;
  else if (c.value == JACK) displayJack(c.suit) ;
  else if (c.value == QUEEN) displayQueen(c.suit) ;
  else if (c.value == KING) displayKing(c.suit) ;
  else {
    // NOT GOOD!!
    printf("ERROR WITH IDENTIFYING VALUE OF A CARD!!\n") ;
  }
  // And now we print out the suit
  if (c.suit == 0) printf(" of HEARTS\n") ;
  else if (c.suit == 2) printf(" of DIAMONDS\n") ;
  else if (c.suit == 1) printf(" of CLUBS\n") ;
  else if (c.suit == 3) printf(" of SPADES\n") ;
  else {
    // NOT GOOD!
    printf("ERROR WITH IDENTIFYING SUIT OF A CARD!!\n") ;
  }
}

void printDeck(deck * d) {
  int i ;
  for (i = 0 ; i < 52 && (d->cards[i]).valid != 0 ; i++) {
    printCard(d->cards[i]) ;
  }
}

// ~~~~~~~~~~~~~~~~ GAME FUNCTION ~~~~~~~~~~~~~~~~

/*
int super_sleep(int milliseconds) {
	struct timespec ts ;
  ts.tv_sec = milliseconds / 1000 ;
  ts.tv_nsec = (milliseconds % 1000) * 1000000 ;
  return nanosleep(&ts, NULL) ;
}*/

int blackjack(int money) {
  printf("Woohoo! Let's play Blackjack!!\n") ;
  printf("You are given 2 cards. Try to get the highest sum without going over 21 (or \"busting\").\n") ;
  printf("Note: You currently have $%i\n", money) ;

  char command[128] = "help" ;
  int bet = 10 ; // let's start with a simple bet of $10

  player p ;
  p.cardsInHand = 0 ;
  player dealer ;
  dealer.cardsInHand = 0 ;
  deck d = makedeck() ;
  printf("Let's begin! It's you and the dealer!\n\n") ;
  printf("\nYou currently have $%i\n", money) ;
  printf("The dealer has received their starting cards.\n") ;
  deal(&dealer, &d) ;

	while (strcmp(command, "exit") != 0) {
		system("clear") ;
    if (money - bet >= 0) {

    }
    else {
      if (strcmp(command, "new game") == 0) {
        /* if the user types in new game, we'll check if their bet is ok first
        if the user is able to make a new game with that bet, the dealer will get new cards and so will the player
        we will have to clear the system again
        */
        if (money - bet < 0) {
          printf("You do not have enough money to make this bet!\n") ;
  				printf("Visit the atm from the main casino floor to get more money!\n") ;
        }
        else {
          // the user is able to make the bet
        }

        deal(&dealer, &d) ;
      }
    }
    printf("Here are the dealer's cards:\n") ;
    deal(&dealer, &d) ;

		if (strcmp(command, "hit") == 0) {
			if (money - bet >= 0) {
				srand(time(0)) ;
        hit(&p,&d) ;
				/*spin(&slot_machine, bet) ;
				money += is_win(&slot_machine) * bet ;*/

				printf("\nYou currently have $%i dollars\n", money) ;
			}
      else {
				printf("You do not have enough money to make this bet!\n") ;
				printf("Visit the atm from the main casino floor to refill.\n") ;
			}
		}
		else if (strcmp(command, "hit" == 0)) {

    }
    else if (strcmp(command, "bet") == 0) {
			printf("Your current bet is $%i\n", bet) ;
			printf("Enter the amount you want to bid: ") ;
			char newBid[1000] ;
			fgets(newBid, 1000, stdin) ;
			* strchr(newBid, '\n') = '\0' ;
			bet = atoi(newBid) ;
		}
		else if (strcmp(command, "help") == 0) {
			printf("\nType commands to play. The commands are: \n") ;
			printf("\t-play\n\t  -Type \"play\" to insert your bet and get the first 2 cards that you are dealt\n\t-bet\n\t  -Type \"bet\" to change the amount of your bet\n\t-help\n\t-exit\n") ;
		}
		else {
			printf("You entered: \"%s\"\n", command) ;
			printf("This isn't a valid command. Possible commands include: \n\t-play\n\t-bet\n\t-help\n\t-exit\n") ;
		}
		printf("\nType in what you want to do: ") ;
		fgets(command, 1024, stdin) ;
		*strchr(command, '\n') = '\0' ;
	}
	printf("\nYou are leaving Blackjack!\n") ;
	//super_sleep(800) ;
  return money ;
}

int main() {
  deck d ; // we are creating the deck
  //printf("*****************************************\n\n\n");
  d = makedeck() ;
  printf("Deck has been made! Here it is:\n");
  printDeck(&d) ;
  printf("*****************************************\n\n\n");
  shuffle(&d) ;
  printf("Deck has been shuffled! Here it is:\n");
  printDeck(&d) ;
  printf("*****************************************\n\n\n");
	// now onto the player
  player p ;
  p.cardsInHand = 0 ;
  printf("deal is called\n");
  deal(&p, &d) ;
  printf("Here are the player's cards:\n");
  printCard(p.hand[0]) ;
  printCard(p.hand[1]) ;
  printf("The smallest sum of the player's cards is: %d\n", find_min_sum(&p));
  printf("The largest sum of the player's cards is: %d\n", find_max_sum(&p));
  printf("Moving onto the dealer\n");
  player dealer ;
  deal(&dealer, &d) ;
  printf("Here are the dealer's cards:\n");
  printCard(dealer.hand[0]) ;
  printCard(dealer.hand[1]) ;
  printf("The smallest sum of the dealer's cards is: %d\n", find_min_sum(&dealer));
  printf("The largest sum of the dealer's cards is: %d\n", find_max_sum(&dealer));
  printf("*****************************************\n\n\n");
  printf("Let's give the player another card!\n");
  hit(&p, &d) ;
  printCard(p.hand[0]) ;
  printCard(p.hand[1]) ;
  printCard(p.hand[2]) ;
	/*player dealer ; // now onto the dealer
  dealer.cardsInHand = 0 ;
  deal(&dealer, &d) ;
  printf("able to deal\n");
  printf("value: %d\n", (p.hand[0]).value);
  printCard(p.hand[0]) ;
  printf("printed first card!!\n\n");
  printCard(p.hand[1]) ;
  printf("The sum of the player's cards is: %d\n", p.sum) ;
  printCard(&(dealer.hand[0])) ;
  printCard(&(dealer.hand[1])) ;
  printf("The sum of the dealer's cards is: %d\n", dealer.sum) ;*/

  char response [100] ; // this will be used to hold the player's response to their options
  /*while (1) {
    // let's play a game
  }*/
  return 0 ;
}
