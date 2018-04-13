//
// Created by Ben Cradick on 4/10/18.
//

#include <stdio.h>
#include <math.h>
void

int main() {
    // We have no use for negative numbers when dealing with primality, so unsigned everything.
    // accounts for different character sizes
    unsigned short numIndex = 100000/CHAR_BIT;
    unsigned char primes[numIndex] = {};
    unsigned long n = 100000;
    unsigned short squareN = sqrt(n);
    //initialize all bits to 0
    for(int i = 0; i < numIndex; ++i){
        primes[i]=0;
    }
    //pos = 1 is equivalent to a byte of CHAR_BIT length represented by '0..001'
    unsigned char pos = 1;
    //squareN is the highest you need to check for
    for(int i = 2; i < squareN; ++i){
        int index = i/CHAR_BIT;
        // -1 is to compensate for starting at 2, we start at 2 because by definition 1 may not be prime.
        int bit_pos = i%CHAR_BIT - 1;
        while(index < numIndex){
            //flips bit at wherever pos' bit is.
            primes[index] |= pos;
            //++variable was used where it wouldn't affect program logic, ++variable is faster than variable++
            //variable++ requires memory allocation/deallocation for the specified variable.
            for(int k = 0; k < i; ++i){
                pos<<=1;
                if(pos == 0){
                    pos = 1;
                    ++index;
                }
            }
        }
    }

    for (int k = 2; k < n; ++k) {


        }
    }
