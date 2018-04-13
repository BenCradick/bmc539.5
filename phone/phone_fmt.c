#include "phone_fmt.h"
#include <stdio.h>
#include <ctype.h>
/*
 * Takes in a character input strips out all the non integer characters, grabs the first ten and puts them into
 * the format of a telephone standardized for the United States (xxx)xxx-xxxx
 */

void formatNumber(int len, char input[len]){
    //1) Sets max character size of the array to 14 (10 digits + 3 format characters + 1 null terminator)
    char phoneNumber[14];
    int count = 0;
    int digits = 0;
    //2) while loop counts the total number of integers
    while(digits < 13){
        //3) checks first if the next input character is past the null terminator
        if(input[count] == '\0') {
            printf("Not enough digits for a complete number where entered\n need %d more numbers", (13 - digits));
            digits = 13;
        }
        //4) checks if the digit is 0 if 0 writes '(' character writes ')' at character 4 and '-' and character 8
        // increments digit on each
        else if(digits == 0){
            phoneNumber[0] = '(';
            digits++;
        }

        else if(digits == 4){
            phoneNumber[4] = ')';
            digits++;
        }

        else if(digits == 8){
            phoneNumber[8] = '-';
            digits++;
        }
        //5) checks if character is 0, if it is 0 then writes 0 to the phone number array, this is done as a seperate step
        //    because isdigit returns 0 if it is not a digit and if it digit is 0. increments count and digit by one
        else if(input[count] == '0'){
            phoneNumber[digits] = input[count];
            digits++;
            count++;
        }
        //6) checks to see if character is digit, if digit writes it to array increments digit and count by one
        else if(isdigit(input[count]) != 0){
            phoneNumber[digits] = input[count];
            count++;
            digits++;
        }
        //7) checks to see if character is not digit and that it is not '0' if so increments count.
        else if(!isdigit(input[count]) && input[count] != '0'){
            count++;
        }
        //8) else statement acts as a debug checker, this code should never run but if it does it will tell us that something
        //is run.
        else{
            printf("ending up here somehow");
        }
    }
    //9) prints the phone number it was given in the correct format
    printf("%s\n",phoneNumber);

}