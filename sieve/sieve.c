//
// Created by Ben Cradick on 4/10/18.
//

#include <stdio.h>
#include <math.h>
#include <limits.h>


int main() {
    // We have no use for negative numbers when dealing with primality, so unsigned everything.
    // accounts for different character sizes

    const unsigned int numIndex = (100000/CHAR_BIT)+1;

    unsigned char primes[numIndex] = {0};
    double n = 100000;
    double squareN = sqrt(n);

    //pos = 1 is equivalent to a byte of CHAR_BIT length represented by '0..001'
    unsigned char pos;

    //squareN is the highest you need to check for
    unsigned int i;
    for(i = 2; i < squareN; i++){
        pos = 1;
        unsigned int j = i - 2;

        int index = j/CHAR_BIT;
        // -1 is to compensate for starting at 2, we start at 2 because by definition 1 may not be prime.
        unsigned int bit_pos = j%CHAR_BIT;
        if(bit_pos != 0) {
            pos <<= bit_pos;
        }
        while(index <= numIndex){

            //++variable was used where it wouldn't affect program logic, ++variable is faster than variable++
            //variable++ requires memory allocation/deallocation for the specified variable.
            int k;
            for(k = 0; k < i; ++k){

                if( pos != 128){
                    pos<<=1;
                }
                else{
                    pos = 1;
                    ++index;
                }




            }
            //flips bit at wherever pos' bit is.
            #ifdef DEBUG
            printf("%-10d%-10d%-10d%-10d%-10d%-10d\n", pos, index, numIndex, primes[index], i, ((int)squareN));
            #endif
            if(index <= numIndex){
            primes[index] |= pos;
            }
        }
    }

    pos = 1;
    int index = 0;
    int prints = 0;
    int k = 2;

    while (index <= numIndex) {


        if(pos !=(primes[index] & pos)){
            #ifndef DEBUG
            printf("%d\n", k);
            #endif
        }

        if(pos == 128) {
            pos = 1;
            if ((index) < numIndex) { index++; }


        }
        else if(k >= n){

            return 0;
        }
        else{pos<<=1;}

        ++k;
    }
}
