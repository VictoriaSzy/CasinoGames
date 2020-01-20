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
  //printf("You are receiving a card!\n");
  p->hand[p->cardsInHand] = d->cards[d->cardsInDeck - 1];
  d->cards[d->cardsInDeck - 1].valid = 1 ;
  //printf("good with setting hand cards from deck\n");
  d->cardsInDeck-- ;
  p->cardsInHand++ ;
}
void fold(player * p, deck * d) {

}
void deal(player * p, deck * d) {
  //printf("deal is called\n");
  transferCard(p,d) ;
  //printf("first transfer is good\n");
  transferCard(p,d) ;
  //printf("second transfer is good\n");
  //printf("Added cards to player's hand\n");
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
void display2(int suit) {
  printf(" _____ \n") ;
  printf("|2    |\n") ;
  if (suit == 0) {
    printf("|  %s  |\n", HEART) ;
    printf("|     |\n") ;
    printf("|  %s  |\n", HEART) ;
  }
  if (suit == 1) {
    printf("|  %s  |\n", CLUB) ;
    printf("|     |\n") ;
    printf("|  %s  |\n", CLUB) ;
  }
  if (suit == 2) {
    printf("|  %s  |\n", DIAMOND) ;
    printf("|     |\n") ;
    printf("|  %s  |\n", DIAMOND) ;
  }
  if (suit == 3) {
    printf("|  %s  |\n", SPADE) ;
    printf("|     |\n") ;
    printf("|  %s  |\n", SPADE) ;
  }
  printf("|____Z|\n") ;
}
void display3(int suit) {
  printf(" _____ \n") ;
  printf("|3    |\n") ;
  if (suit == 0) {
    printf("| %s %s |\n", HEART, HEART) ;
    printf("|     |\n") ;
    printf("|  %s  |\n", HEART) ;
  }
  if (suit == 1) {
    printf("| %s %s |\n", CLUB, CLUB) ;
    printf("|     |\n") ;
    printf("|  %s  |\n", CLUB) ;
  }
  if (suit == 2) {
    printf("| %s %s |\n", DIAMOND, DIAMOND) ;
    printf("|     |\n") ;
    printf("|  %s  |\n", DIAMOND) ;
  }
  if (suit == 3) {
    printf("| %s %s |\n", SPADE, SPADE) ;
    printf("|     |\n") ;
    printf("|  %s  |\n", SPADE) ;
  }
  printf("|____E|\n") ;
}
void display4(int suit) {
  printf(" _____ \n") ;
  printf("|4    |\n") ;
  if (suit == 0) {
    printf("| %s %s |\n", HEART, HEART) ;
    printf("|     |\n") ;
    printf("| %s %s |\n", HEART, HEART) ;
  }
  if (suit == 1) {
    printf("| %s %s |\n", CLUB, CLUB) ;
    printf("|     |\n") ;
    printf("| %s %s |\n", CLUB, CLUB) ;
  }
  if (suit == 2) {
    printf("| %s %s |\n", DIAMOND, DIAMOND) ;
    printf("|     |\n") ;
    printf("| %s %s |\n", DIAMOND, DIAMOND) ;
  }
  if (suit == 3) {
    printf("| %s %s |\n", SPADE, SPADE) ;
    printf("|     |\n") ;
    printf("| %s %s |\n", SPADE, SPADE) ;
  }
  printf("|____h|\n") ;
}
void display5(int suit) {
  printf(" _____ \n") ;
  printf("|5    |\n") ;
  if (suit == 0) {
    printf("| %s %s |\n", HEART, HEART) ;
    printf("|  %s  |\n", HEART) ;
    printf("| %s %s |\n", HEART, HEART) ;
  }
  if (suit == 1) {
    printf("| %s %s |\n", CLUB, CLUB) ;
    printf("|  %s  |\n", CLUB) ;
    printf("| %s %s |\n", CLUB, CLUB) ;
  }
  if (suit == 2) {
    printf("| %s %s |\n", DIAMOND, DIAMOND) ;
    printf("|  %s  |\n", DIAMOND) ;
    printf("| %s %s |\n", DIAMOND, DIAMOND) ;
  }
  if (suit == 3) {
    printf("| %s %s |\n", SPADE, SPADE) ;
    printf("|  %s  |\n", SPADE) ;
    printf("| %s %s |\n", SPADE, SPADE) ;
  }
  printf("|____S|\n") ;
}
void display6(int suit) {
  printf(" _____ \n") ;
  printf("|6    |\n") ;
  if (suit == 0) {
    printf("| %s %s |\n", HEART, HEART) ;
    printf("| %s %s |\n", HEART, HEART) ;
    printf("| %s %s |\n", HEART, HEART) ;
  }
  if (suit == 1) {
    printf("| %s %s |\n", CLUB, CLUB) ;
    printf("| %s %s |\n", CLUB, CLUB) ;
    printf("| %s %s |\n", CLUB, CLUB) ;
  }
  if (suit == 2) {
    printf("| %s %s |\n", DIAMOND, DIAMOND) ;
    printf("| %s %s |\n", DIAMOND, DIAMOND) ;
    printf("| %s %s |\n", DIAMOND, DIAMOND) ;
  }
  if (suit == 3) {
    printf("| %s %s |\n", SPADE, SPADE) ;
    printf("| %s %s |\n", SPADE, SPADE) ;
    printf("| %s %s |\n", SPADE, SPADE) ;
  }
  printf("|____9|\n") ;
}
void display7(int suit) {
  printf(" _____ \n") ;
  printf("|7    |\n") ;
  if (suit == 0) {
    printf("| %s %s |\n", HEART, HEART) ;
    printf("|%s %s %s|\n", HEART, HEART, HEART) ;
    printf("| %s %s |\n", HEART, HEART) ;
  }
  if (suit == 1) {
    printf("| %s %s |\n", CLUB, CLUB) ;
    printf("|%s %s %s|\n", CLUB, CLUB, CLUB) ;
    printf("| %s %s |\n", CLUB, CLUB) ;
  }
  if (suit == 2) {
    printf("| %s %s |\n", DIAMOND, DIAMOND) ;
    printf("|%s %s %s|\n", DIAMOND, DIAMOND, DIAMOND) ;
    printf("| %s %s |\n", DIAMOND, DIAMOND) ;
  }
  if (suit == 3) {
    printf("| %s %s |\n", SPADE, SPADE) ;
    printf("|%s %s %s|\n", SPADE, SPADE, SPADE) ;
    printf("| %s %s |\n", SPADE, SPADE) ;
  }
  printf("|____L|\n") ;
}
void display8(int suit) {
  printf(" _____ \n") ;
  printf("|8    |\n") ;
  if (suit == 0) {
    printf("|%s %s %s|\n", HEART, HEART, HEART) ;
    printf("| %s %s |\n", HEART, HEART) ;
    printf("|%s %s %s|\n", HEART, HEART, HEART) ;
  }
  if (suit == 1) {
    printf("|%s %s %s|\n", CLUB, CLUB, CLUB) ;
    printf("| %s %s |\n", CLUB, CLUB) ;
    printf("|%s %s %s|\n", CLUB, CLUB, CLUB) ;
  }
  if (suit == 2) {
    printf("|%s %s %s|\n", DIAMOND, DIAMOND, DIAMOND) ;
    printf("| %s %s |\n", DIAMOND, DIAMOND) ;
    printf("|%s %s %s|\n", DIAMOND, DIAMOND, DIAMOND) ;
  }
  if (suit == 3) {
    printf("|%s %s %s|\n", SPADE, SPADE, SPADE) ;
    printf("| %s %s |\n", SPADE, SPADE) ;
    printf("|%s %s %s|\n", SPADE, SPADE, SPADE) ;
  }
  printf("|____8|\n") ;
}
void display9(int suit) {
  printf(" _____ \n") ;
  printf("|9    |\n") ;
  if (suit == 0) {
    printf("|%s %s %s|\n", HEART, HEART, HEART) ;
    printf("|%s %s %s|\n", HEART, HEART, HEART) ;
    printf("|%s %s %s|\n", HEART, HEART, HEART) ;
  }
  if (suit == 1) {
    printf("|%s %s %s|\n", CLUB, CLUB, CLUB) ;
    printf("|%s %s %s|\n", CLUB, CLUB, CLUB) ;
    printf("|%s %s %s|\n", CLUB, CLUB, CLUB) ;
  }
  if (suit == 2) {
    printf("|%s %s %s|\n", DIAMOND, DIAMOND, DIAMOND) ;
    printf("|%s %s %s|\n", DIAMOND, DIAMOND, DIAMOND) ;
    printf("|%s %s %s|\n", DIAMOND, DIAMOND, DIAMOND) ;
  }
  if (suit == 3) {
    printf("|%s %s %s|\n", SPADE, SPADE, SPADE) ;
    printf("|%s %s %s|\n", SPADE, SPADE, SPADE) ;
    printf("|%s %s %s|\n", SPADE, SPADE, SPADE) ;
  }
  printf("|____6|\n") ;
}
void display10(int suit) {
  printf(" _____ \n") ;
  if (suit == 0) {
    printf("|10 %s |\n", HEART) ;
    printf("|%s %s %s|\n", HEART, HEART, HEART) ;
    printf("|%s %s %s|\n", HEART, HEART, HEART) ;
    printf("|%s %s %s|\n", HEART, HEART, HEART) ;
  }
  if (suit == 1) {
    printf("|10 %s |\n", CLUB) ;
    printf("|%s %s %s|\n", CLUB, CLUB, CLUB) ;
    printf("|%s %s %s|\n", CLUB, CLUB, CLUB) ;
    printf("|%s %s %s|\n", CLUB, CLUB, CLUB) ;
  }
  if (suit == 2) {
    printf("|10 %s |\n", DIAMOND) ;
    printf("|%s %s %s|\n", DIAMOND, DIAMOND, DIAMOND) ;
    printf("|%s %s %s|\n", DIAMOND, DIAMOND, DIAMOND) ;
    printf("|%s %s %s|\n", DIAMOND, DIAMOND, DIAMOND) ;
  }
  if (suit == 3) {
    printf("|10 %s |\n", SPADE) ;
    printf("|%s %s %s|\n", SPADE, SPADE, SPADE) ;
    printf("|%s %s %s|\n", SPADE, SPADE, SPADE) ;
    printf("|%s %s %s|\n", SPADE, SPADE, SPADE) ;
  }
  printf("|___0I|\n") ;
}
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
  if (suit == 0) printf("|  %s  |\n", HEART) ;
  if (suit == 1) printf("|  %s  |\n", CLUB) ;
  if (suit == 2) printf("|  %s  |\n", DIAMOND) ;
  if (suit == 3) printf("|  %s  |\n", SPADE) ;
  printf("|     |\n") ;
  printf("|____V|\n") ;
}
void displayJack(int suit) {
  printf(" _____ \n") ;
  printf("|J  ww|\n") ;
  if (suit == 0) printf("| %s {)|\n", HEART) ;
  if (suit == 1) printf("| %s {)|\n", CLUB) ;
  if (suit == 2) printf("| %s {)|\n", DIAMOND) ;
  if (suit == 3) printf("| %s {)|\n", SPADE) ;
  printf("|   %% |\n") ;
  printf("|   %% |\n") ;
  printf("|__%%%%[|\n") ;
}
void displayQueen(int suit) {
  printf(" _____ \n") ;
  printf("|Q  ww|\n") ;
  if (suit == 0) printf("| %s {(|\n", HEART) ;
  if (suit == 1) printf("| %s {(|\n", CLUB) ;
  if (suit == 2) printf("| %s {(|\n", DIAMOND) ;
  if (suit == 3) printf("| %s {(|\n", SPADE) ;
  printf("|   %%%%|\n") ;
  printf("|  %%%%%%|\n") ;
  printf("|_%%%%%%O|\n") ;
}
void displayKing(int suit) {
  printf(" _____ \n") ;
  printf("|K  WW|\n") ;
  if (suit == 0) printf("| %s {)|\n", HEART) ; // HEARTS
  if (suit == 1) printf("| %s {)|\n", CLUB) ; // CLUBS
  if (suit == 2) printf("| %s {)|\n", DIAMOND) ; // DIAMONDS
  if (suit == 3) printf("| %s {)|\n", SPADE) ; // SPADES
  printf("|   %%%%|\n") ;
  printf("|  %%%%%%|\n") ;
  printf("|_%%%%%%>|\n") ;
}

void printCard(card c) {
  printf("value from printcard: %d\n", c.value) ;
  if (c.value == ACE) displayAce(c.suit) ;
  else if (c.value == 2) display2(c.suit) ;
  else if (c.value == 3) display3(c.suit) ;
  else if (c.value == 4) display4(c.suit) ;
  else if (c.value == 5) display5(c.suit) ;
  else if (c.value == 6) display6(c.suit) ;
  else if (c.value == 7) display7(c.suit) ;
  else if (c.value == 8) display8(c.suit) ;
  else if (c.value == 9) display9(c.suit) ;
  else if (c.value == 10) display10(c.suit) ;
  else if (c.value == JACK) displayJack(c.suit) ;
  else if (c.value == QUEEN) displayQueen(c.suit) ;
  else if (c.value == KING) displayKing(c.suit) ;
  else {
    // NOT GOOD!!
    printf("ERROR WITH IDENTIFYING VALUE OF A CARD!!\n") ;
  }
}

void printDeck(deck * d) {
  int i ;
  for (i = 0 ; i < 52 && (d->cards[i]).valid != 0 ; i++) {
    printCard(d->cards[i]) ;
  }
}

// ~~~~~~~~~~~~~~~~ GAME FUNCTION ~~~~~~~~~~~~~~~~
/* I think it should look like this
Dealer's cards:
 _____   _____
|6    | |     |
| ♦ ♦ | |     |
| ♦ ♦ | |     |
| ♦ ♦ | |     |
|____9| |_____|

Your cards:
 _____   _____
|6    | |8    |
| ♥ ♥ | |♦ ♦ ♦|
| ♥ ♥ | | ♦ ♦ |
| ♥ ♥ | |♦ ♦ ♦|
|____9| |____8|

You can hit or stand: 
*/
int play_blackjack(int money){
  // this handles actually playing
  printf("Let's begin! It's you and the dealer!\n\n") ;
  printf("\nYou currently have $%i\n", money) ;
  printf("The dealer has received their starting cards.\n") ;
  int bet; // let's start with a simple bet of $10

  //You should ask for an initial bet (I believe that is the only bet that is used)

  player p ;
  p.cardsInHand = 0 ;
  player dealer ;
  dealer.cardsInHand = 0 ;
  deck d = makedeck() ;
  deal(&dealer, &d) ;

  char command[128];
  while (strcmp(command, "stand") != 0){
    hit(p, d); //you make this
  }
  //after hitting it is the dealers turn to hit

  // then we see who won 


  //why don't you look at https://www.arkadium.com/games/blackjack/ to see how to play blackjack

}
int super_sleep(int milliseconds) {
	struct timespec ts ;
  ts.tv_sec = milliseconds / 1000 ;
  ts.tv_nsec = (milliseconds % 1000) * 1000000 ;
  return nanosleep(&ts, NULL) ;
}

int blackjack(int money) {
  char command[128] = "help" ;

	while (strcmp(command, "exit") != 0) {
		system("clear") ;
    printf("Woohoo! Let's play Blackjack!!\n") ;
    printf("You are given 2 cards. Try to get the highest sum without going over 21 (or \"busting\").\n") ;
    printf("Note: You currently have $%i\n", money) ;
		
    if (strcmp(command, "help") == 0) {
			printf("\nType commands to play. The commands are: \n") ;
			printf("\t-play\n\t  -Type \"play\" to insert your bet and get the first 2 cards that you are dealt\n\t-bet\n\t  -Type \"bet\" to change the amount of your bet\n\t-help\n\t-exit\n") ;
		}
    else if (strcmp(command, "play") == 0){
      money = play_blackjack(money);
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
  /*printf("Deck has been made! Here it is:\n");
  printDeck(&d) ;
  printf("*****************************************\n\n\n");*/
  shuffle(&d) ;
  /*printf("Deck has been shuffled! Here it is:\n");
  printDeck(&d) ;
  printf("*****************************************\n\n\n");*/
	// now onto the player
  player p ;
  p.cardsInHand = 0 ;
  //printf("deal is called\n");
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
  printf("The smallest sum of the dealer's cards is: %d\n", find_min_sum(&dealer)) ;
  printf("The largest sum of the dealer's cards is: %d\n", find_max_sum(&dealer)) ;
  printf("*****************************************\n") ;
  printf("Let's give the player another card!\n") ;
  hit(&p, &d) ;
  printCard(p.hand[0]) ;
  printCard(p.hand[1]) ;
  printCard(p.hand[2]) ;

  char response [100] ; // this will be used to hold the player's response to their options
  /*while (1) {
    // let's play a game
  }*/
  return 0 ;
}
