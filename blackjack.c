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
#define JACK 10
#define QUEEN 11
#define KING 12

// ~~~~~~~~~~~~~~~~ SUM & ACTION FUNCTIONS ~~~~~~~~~~~~~~~~

int find_sum(card * hand) {
  int x ;
  int sum = 0 ;
  for (x = 0 ; (hand[x]).valid == 0 ; x++) {
    card c = hand[x] ;
    sum += c.value ;
  }
  return sum ;
}
void transferCard(player * p, deck * d) {
  p.hand[p.cardsInHand - 1] = d->cards[d->cardsInDeck - 1];
  d->cardsInDeck-- ;
  p->cardsInHand++ ;
}
void deal(player * p, deck * d) {
  transferCard(p,d) ;
  transferCard(p,d) ;
  printf("Added cards to player's hand\n");
  p->sum = find_sum(p->hand) ;
}
// ~~~~~~~~~~~~~~~~ FUNCTIONS FOR SHUFFLING ~~~~~~~~~~~~~~~~

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

/*void hit(player * p) {
  if (player->sum > 21) {
    printf("You cannot hit because you are over 21! You have busted!\n") ;
  }
}*/

// ~~~~~~~~~~~~~~~~ PRINTING FUNCTIONS ~~~~~~~~~~~~~~~~
void printCard(card c) {
  if (c.valid != 0) {
    printf("This is not a valid card! It has been nulled from a previous action!\n") ;
  }
  else {
    // We start with printing the value
    if (c.value > ACE && c.value < JACK) printf("%d", c.value) ;
    else if (c.value == ACE) printf("A") ;
    else if (c.value == JACK) printf("J") ;
    else if (c.value == QUEEN) printf("Q") ;
    else if (c.value == KING) printf("K") ;
    else if (c.value > ACE && c.value < JACK) printf("%d", c.value) ;
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
}

void printDeck(deck * d) {
  int i ;
  for (i = 0 ; i < (d->cardsInDeck) ; i++) {
    printCard(d->cards[i]) ;
    printf(" ") ;
  }
}

int main() {
  deck * d ; // we are creating the deck
  card c ;
	int suit, x ;
	// this first for loop adds the heart cards
  printf("We have created a deck\n");
	for (x = 0 ; x < 13 ; x++) {
		c.suit = 0 ;
		if (x < 10) c.value = x + 1 ;
		else {
			c.value = 10 ;
		}
    c.valid = 0 ;
		d->cards[x] = c ;
	}
  printf("Heart cards are added\n");
	// this for loop adds the clubs
	for (x = 13 ; x < 26 ; x++) {
		c.suit = 1 ;
		if (x < 10) c.value = x + 1 ;
		else {
			c.value = 10 ;
		}
    c.valid = 0 ;
		d->cards[x] = c ;
	}
  printf("Club cards are added\n");
	// this for loop adds the diamonds
	for (x = 26 ; x < 39 ; x++) {
		c.suit = 2 ;
		if (x < 10) c.value = x + 1 ;
		else {
			c.value = 10 ;
		}
    c.valid = 0 ;
		d->cards[x] = c ;
	}
  printf("Diamond cards are added\n");
	// this for loop adds the spades
	for (x = 39 ; x < 52 ; x++) {
		c.suit = 3 ;
		if (x < 10) c.value = x + 1 ;
		else {
			c.value = 10 ;
		}
    c.valid = 0 ;
		d->cards[x] = c ;
	}
  printf("Spade cards are added\n");
  shuffle(d) ;
  printf("Shuffling is successful\n");
	d->cardsInDeck = 52 ;
  printf("Successfully added number of cards in deck\n");
	// now onto the player
  player * p ;
  deal(p, d) ;
	player * dealer ; // now onto the dealer
  deal(dealer, d) ;
  printCard(p->hand[0]) ;
  printCard(p->hand[1]) ;
  printf("The sum of the player's cards is: %d\n", p->sum) ;
  printCard(dealer->hand[0]) ;
  printCard(dealer->hand[1]) ;
  printf("The sum of the dealer's cards is: %d\n", dealer->sum) ;

  char response [100] ; // this will be used to hold the player's response to their options
  /*while (1) {
    // let's play a game
  }*/
  return 0 ;
}
