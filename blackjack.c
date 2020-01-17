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

int find_sum(player * p) {
  int x ;
  int sum = 0 ;
  for (x = 0 ; x < (p->cardsInHand) ; x++) {
    card c = p->hand[x] ;
    sum += c.value ;
  }
  return sum ;
}
void transferCard(player * p, deck * d) {
  printf("transfer is called\n");
  p->hand[p->cardsInHand] = d->cards[d->cardsInDeck - 1];
  d->cards[d->cardsInDeck - 1].valid = 1 ;
  printf("good with setting hand cards from deck\n");
  d->cardsInDeck-- ;
  p->cardsInHand++ ;
}
void fold(player * p, deck * d) {

}
void deal(player * p, deck * d) {
  printf("deal is called\n");
  transferCard(p,d) ;
  printf("first transfer is good\n");
  transferCard(p,d) ;
  printf("second transfer is good\n");
  printf("Added cards to player's hand\n");
  p->sum = find_sum(p) ;
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
      /*
      d.cards[x].suit = suit ;
      d.cards[x].value = x + 1 ;*/
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

/*void hit(player * p) {
  if (player->sum > 21) {
    printf("You cannot hit because you are over 21! You have busted!\n") ;
  }
}*/

// ~~~~~~~~~~~~~~~~ PRINTING FUNCTIONS ~~~~~~~~~~~~~~~~
void printCard(card c) {
  // We start with printing the value
  printf("value from printcard: %d\n",c.value);
  if (c.value > ACE && c.value < JACK) printf("%d", c.value) ;
  else if (c.value == ACE) printf("A") ;
  else if (c.value == JACK) printf("J") ;
  else if (c.value == QUEEN) printf("Q") ;
  else if (c.value == KING) printf("K") ;
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
    /*if ((d->cards[i]).suit == 0) {
      printf("%d of HEARTS\n", (d->cards[i]).value) ;
    }
    else if ((d->cards[i]).suit == 1) {
      printf("%d of CLUBS\n", (d->cards[i]).value) ;
    }
    else if ((d->cards[i]).suit == 2) {
      printf("%d of DIAMONDS\n", (d->cards[i]).value) ;
    }
    else if ((d->cards[i]).suit == 3) {
      printf("%d of SPADES\n", (d->cards[i]).value) ;
    }
    else {
      printf("The suit of the card has an issue!!\n") ;
    }*/
  }
}

int main() {
  deck d ; // we are creating the deck
  //printf("*****************************************\n\n\n");
  d = makedeck() ;
  printf("Deck has been made!\n");
  printDeck(&d) ;
  printf("*****************************************\n\n\n");
  shuffle(&d) ;
  printf("Deck has been shuffled\n");
  printDeck(&d) ;
  printf("*****************************************\n\n\n");
	// now onto the player
  player p ;
  p.cardsInHand = 0 ;
  deal(&p, &d) ;
  player dealer ;
  deal(&dealer, &d) ;
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
