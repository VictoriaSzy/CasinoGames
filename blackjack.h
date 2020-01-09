#include <stdlib.h>
#include <stdio.h>

// typedef structs mean that we won't have to type struct countless times in the return types of the functions

// this is the struct for a single card
typedef struct {
  int suit ; // either a heart, diamond, club, or spade
  int value ; // A will be worth either 1 or 11 and the face cards (J, Q, K) will be worth 10
} card ;

// this is the struct for the player/dealer - we'll keep track of their hand like this
typedef struct {
  card [] hand ; // we'll know the exact cards the player has
  int min ; // the smallest sum of the player's cards
  int max ; // the largest sum of the player's cards
} player ;

// Here are the functions:
/*deck * split(deck * d) ;
deck * mix(deck * d) ;*/
void printCard(card * c) ;
void printDeck(deck * d) ;
