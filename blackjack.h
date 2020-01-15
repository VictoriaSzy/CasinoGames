#include <stdlib.h>
#include <stdio.h>

// typedef structs mean that we won't have to type struct countless times in the return types of the functions

// this is the struct for a single card
typedef struct {
  int suit ; // either a heart (1), club (2), diamond (3), or spade (4)
  int value ; // A will be worth either 1 or 11 and the face cards (J, Q, K) will be worth 10
} card ;

typedef struct {
  card cards [52] ;
  int cardsInDeck ;
} deck ;

// this is the struct for the player/dealer - we'll keep track of their hand like this
typedef struct {
  card hand [52] ; // we'll know the exact cards the player has
  int sum ; // the sum of the player's cards
} player ;

// Here are the functions:
void printCard(card * c) ;
void printDeck(deck * d) ;
