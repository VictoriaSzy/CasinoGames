#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// typedef structs mean that we won't have to type struct countless times in the return types of the functions

// this is the struct for a single card
typedef struct {
  int suit ; // either a heart (0), club (1), diamond (2), or spade (3)
  int value ; // A will be worth either 1 or 11 and the face cards (J, Q, K) will be worth 10
  int valid ; // whether we can use it or not: 0 represents ok, 1 is no bueno
} card ;

typedef struct {
  card cards [52] ;
  int cardsInDeck ;
} deck ;

// this is the struct for the player/dealer - we'll keep track of their hand like this
typedef struct {
  card hand [12] ; // we'll know the exact cards the player has
  int cardsInHand;
  int min_sum ; // the smallest sum of the player's cards
  int max_sum ; // the largest sum of the player's cards
} player ;

// Here are the functions:
void printCard(card c) ;
void printDeck(deck * d) ;
int find_min_sum(player * p) ;
int find_max_sum(player * p) ;
void shuffle(deck * d) ;
void transferCard(player * p, deck * d) ;
void deal(player * p, deck * d) ;
deck makedeck() ;
void fold(player * p, deck * d) ;
void hit(player *p, deck * d) ;
int blackjack(int money) ;
void displayCard(int num) ;
void displayAce(int suit) ;
void displayJack(int suit) ;
void displayQueen(int suit) ;
void displayKing(int suit) ;
