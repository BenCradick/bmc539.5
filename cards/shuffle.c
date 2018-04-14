#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef enum { clubs, diamonds, hearts, spades} suit_t;
typedef struct
{
    unsigned int number  : 4;
    suit_t       suit    : 2;
} card_t;

int compare(const void *, const void *);

int main(){
    card_t deck[52];
    srand(time(0));
    int k = 0;
    while (k < 52) {
        for (suit_t i = 0; i <= 3; i++) {
            for (unsigned int j = 1; j <= 13; j++) {
                deck[k].suit = i;
                deck[k].number = j;
                ++k;
            }
        }
    }

    for(unsigned short m; m < 52; m++){
        int r = rand()%52;
        card_t temp = *deck;
        *deck = *(deck + r);
        *(deck + r) = temp;
    }
    qsort(deck, 52 , sizeof(card_t), compare);
    for(unsigned short n; n < 52; n ++){
        printf("%d\t%d\n", deck[n].suit, deck[n].number);
    }
}

int compare(const void * a, const void * b){
    //when you make jokes in your code that you know your prof won't get feelsbadman
    card_t *cardiA = (card_t *)a;
    card_t *cardiB = (card_t *)b;

    if(((int)cardiA->number) > ((int)cardiB->number)){return(1);}
    else if(((int)cardiA->number) < ((int)cardiB->number)){return(-1);}
    else {return(1);}
}
