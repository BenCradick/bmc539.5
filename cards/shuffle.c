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

void printArray(card_t *);

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

    //shuffles the deck
    for(unsigned short m; m < 52; m++){
        int r = rand()%52;
        card_t temp = *deck;
        *deck = *(deck + r);
        *(deck + r) = temp;
    }
    printArray(deck);
    printf("\v");
    qsort(deck, 52 , sizeof(card_t), compare);
    printArray(deck);
}

int compare(const void * a, const void * b){
    //when you make jokes in your code that you know your prof won't get feelsbadman
    card_t *cardiA = (card_t *)a;
    card_t *cardiB = (card_t *)b;

    //returns the larger of the two numbers so qsort can do its magic.
    if(((int)cardiA->number) > ((int)cardiB->number)){return(1);}
    else if(((int)cardiA->number) < ((int)cardiB->number)){return(-1);}
    else {return(1);}
}

void printArray(card_t * deck){
    for(unsigned short n; n < 52; n++){
        //converts suite type to human readable form that corresponds with the enumerated type.
        switch(deck[n].suit) {
            case 0 :
                printf("%-16s%d\n", "Clubs", deck[n].number);
                break;
            case 1:
                printf("%-16s%d\n", "Diamonds", deck[n].number);
                break;
            case 2:
                printf("%-16s%d\n", "Hearts", deck[n].number);
                break;
            case 3:
                printf("%-16s%d\n", "Spades", deck[n].number);
                break;
            default:
                printf("Joker");
        }
    }
}