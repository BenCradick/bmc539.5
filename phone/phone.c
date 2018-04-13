//Ben Cradick
//cs2750 Pa5
//November 19 2017
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "phone_fmt.h"


//TODO: COMMENT EVERYTHING
int main(){
    char phoneNumber[200];
    int len;
    printf("\nPlease enter a 10 digit phone number(3 digit area code + 7 digit phone number):\t");
    //used fgets instead of scanf so I could limit the number of characters input to 200 and avoid buffer overflow
    fgets(phoneNumber, 200, stdin);
    //checks that you didn't enter too many characters
    if (phoneNumber[strlen(phoneNumber)-1] != '\n') {
        int len = 0;
        while (fgetc(stdin) != '\n') {
            len++;
        }
        if(len > 0){
            printf("Too many characters entered into the field\n");
        }
    }
    //caps ender of input string with null terminator
    else{
        phoneNumber[strlen(phoneNumber)-1] = '\0';
    }
    //sets len the the length of the input character array
    len = (int)strlen(phoneNumber);
    formatNumber(len, phoneNumber);




}

