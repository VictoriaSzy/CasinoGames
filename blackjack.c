#include "blackjack.h"

#define ACE 1
#define JACK 11
#define QUEEN 12
#define KING 13

void printCard(card * c) {
  // We start with printing the value
  if (c->value > ACE && c->value < JACK) {
    printf("%d", c->value) ;
  }
  else if (c->value == ACE) {
    printf("A") ;
  }
  else if (c->value == JACK) {
    printf("J") ;
  }
  else if (c->value == QUEEN) {
    printf("Q") ;
  }
  else if (c->value == KING) {
    printf("K") ;
  }
  else if (c->value > ACE && c->value < JACK) {
    printf("%d",c->value) ;
  }
  else {
    // NOT GOOD!!
    printf("ERROR WITH IDENTIFYING VALUE OF A CARD!!\n") ;
  }

  // And now we print out the suit
  if (c->suit == 1) {
    printf(" of HEARTS") ;
  }
  else if (c->suit == 2) {
    printf(" of DIAMONDS") ;
  }
  else if (c->suit == 3) {
    printf(" of CLUBS") ;
  }
  else if (c->suit == 4) {
    printf(" of SPADES") ;
  }
  else {
    // NOT GOOD!
    printf("ERROR WITH IDENTIFYING SUIT OF A CARD!!\n") ;
  }
}
int main() {
  deck * d ; // this will be our deck
  // here are our 2 players for the moment
  player p ;
  player dealer ;
  char response [100] ; // this will be used to hold the player's response to their options

  return 0 ;
}
