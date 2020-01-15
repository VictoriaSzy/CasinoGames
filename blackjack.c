#include "blackjack.h"
//Using SDL and standard IO
//#include <SDL.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

#define ACE 1
#define JACK 11
#define QUEEN 12
#define KING 13

// ~~~~~~~~~~~~~~~~ FUNCTIONS FOR SHUFFLING ~~~~~~~~~~~~~~~~

void shuffle(deck * d) {
  for (int i = 0; i < 50 ; i++) {
		int x, y ;
		x = rand() % 52 ;
		y = rand() % 52 ;

		card tmp = d->cards[x] ;
		d->cards[x] = d->cards[y] ;
		d->cards[y] = tmp ;
	}
}

void hit(player * p) {
  if (player->sum > 21) {
    printf("You cannot hit because you are over 21! You have busted!\n", );
  }
}



// ~~~~~~~~~~~~~~~~ PRINTING FUNCTIONS ~~~~~~~~~~~~~~~~
void printCard(card * c) {
  // We start with printing the value
  if (c->value > ACE && c->value < JACK) printf("%d", c->value) ;
  else if (c->value == ACE) printf("A") ;
  else if (c->value == JACK) printf("J") ;
  else if (c->value == QUEEN) printf("Q") ;
  else if (c->value == KING) printf("K") ;
  else if (c->value > ACE && c->value < JACK) printf("%d",c->value) ;
  else {
    // NOT GOOD!!
    printf("ERROR WITH IDENTIFYING VALUE OF A CARD!!\n") ;
  }

  // And now we print out the suit
  if (c->suit == 1) printf(" of HEARTS") ;
  else if (c->suit == 2) printf(" of DIAMONDS") ;
  else if (c->suit == 3) printf(" of CLUBS") ;
  else if (c->suit == 4) printf(" of SPADES") ;
  else {
    // NOT GOOD!
    printf("ERROR WITH IDENTIFYING SUIT OF A CARD!!\n") ;
  }
}

void printDeck(deck * d) {
  int i ;
  for (i = 0 ; i < (d->cardsInDeck) ; i++) {
    printCard(d->cards[i]) ;
    printf(" ") ;
  }
}

int main() {
  card deck [52] ; // this will be the deck of cards used for the game
  // here are our 2 players for the moment
  player p ;
  player dealer ;
  char response [100] ; // this will be used to hold the player's response to their options

  return 0 ;
}
