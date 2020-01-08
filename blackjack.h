#include <stdlib.h>
#include <stdio.h>

// typedef structs mean that we won't have to type struct countless times in the return types of the functions
typedef struct {
  int suit ;
  int value ;
} card ;

typedef struct Deck {
  card * c ;
  struct Deck * next ;
} deck ;

typedef struct {
  deck * hand ;
  int min ;
  int max ;
} player ;
