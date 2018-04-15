#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


typedef enum { clubs, diamonds, hearts, spades} suit_t;
typedef struct
{
    unsigned int number  : 4;
    suit_t       suit    : 2;
} card_t;


int compare(const void *, const void *);
void printArray(card_t * deck);

int main(){
    //Get size for bit array initialize order to one more than that because integers are rounded down.
    const unsigned int ARR_SIZE = 52/CHAR_BIT;
    unsigned char order[ARR_SIZE + 1] = {};

    //seed randomness with time
    srand(((unsigned int)time(0)));

    //set bit array to 0
    memset(order, 0, sizeof(order));

    short k = 0;
    card_t deck[52];
    //initialize deck of cards to be brand new texas hold'em poker deck, there are different types of decks of cards
    while (k < 52) {
        for (suit_t i = clubs; i <= spades; i++) {
            for (unsigned int j = 1; j <= 13; j++) {
                deck[k].suit = i;
                deck[k].number = j;
                ++k;
            }
        }
    }

    //shuffle, really should do this step 7 times to get a better shuffle
    for(int i = 0; i < 52; i++){
        int r = rand()%52;
        //the binary index position represents r%52.
        //if r = 4 then r%52 = 4 that means starting pos will be 1<<=4 or 00001000
        int bit_pos = r%CHAR_BIT;
        int r_index = r/CHAR_BIT;
        //left most bit that can be flipped in order[ARR_SIZE]
        unsigned short last_index = 52%CHAR_BIT;
        unsigned char last_pos = 1;
        unsigned char pos = 1;

        // move pos and last pos to having the appropriate flipped bit.
        pos<<=bit_pos;
        last_pos<<=last_index;

        //while the bit is claimed
        while((pos&order[r_index]) > 0){
            //move to next bit
            pos <<=  1;
            // if bit is the last bit that can represent a card
            if(pos&last_pos && r_index==ARR_SIZE ){
                //reset the array index to the beginning increment r and hard cap it at 52
                pos = 1;
                r_index = 0;
                r++;
                r%=52;

            }
            //else the last << operator cleared the unsigned char to 00000000
            // increment everything and hard cap r at 52.
            else if(pos == 0) {
                pos = 1;
                r_index++;
                r++;
                r%=52;
            }
        }
        //swap positions
        order[r_index] |= pos;
        card_t temp = *deck;
        *deck = *(deck + r);
        *(deck + r) = temp;

    }

    printArray(deck);
    printf("\v");
    qsort(deck, 52, sizeof(card_t), compare);
    printArray(deck);
    printf("\v");

    //prints unsigned characters of order as integers, if the shuffle is staying withing bounds results will be
    //255 255 255 255 255 255 15 assuming standard byte size of 8 bits
    #ifdef DEBUG
        for(int i = 0; i <= ARR_SIZE; i++){
            printf("%d\n", order[i]);
        }
    #endif

    return 0;
}


int compare(const void * a, const void * b){
    //when you make jokes in your code that you know your prof won't get feelsbadman
    card_t *cardiA = (card_t *)a;
    card_t *cardiB = (card_t *)b;

    //returns the larger of the two numbers so qsort can do its magic.
    if(((int)cardiA->suit) > ((int)cardiB->suit)){return(1);}
    else if(((int)cardiA->suit) < ((int)cardiB->suit)){return(-1);}
    else if(((int)cardiA->number) > ((int)cardiB->number)){return(1);}
    else if(((int)cardiA->number) < ((int)cardiB->number)){return(-1);}
    else {return(1);}
}


void printArray(card_t * deck){
    for(unsigned short n = 0; n < 52; n++){
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
