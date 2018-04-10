//
// Created by Ben Cradick on 4/10/18.
//

#include <stdio.h>
#include <math.h>

int main() {
    int primes[100001] = {};
    int n = 100000;
    double squareN = sqrt((double)n);
    int start = 2;
    for(int i = 0; i <= n; i++){
        primes[i] = 1;
    }

    for(int i = 2; i < squareN; i++){
        if(primes[i] == 1){
            for (int j = i; j * i <= n; j++) {
                primes[j*i] = 0;
            }
        }

    }

    for (int k = 2; k < n; ++k) {
        if (primes[k] == 1) {
            printf("%d\n", k);
        }
    }
}