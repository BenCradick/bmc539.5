#PHONE.C
phone.c takes command line input and filters out non digits and plugs the first 10 integers into the the standard
American format for telephone numbers (xxx)xxx-xxxx
The function works as so:
/*
 * Takes in a character input strips out all the non integer characters, grabs the first ten and puts them into
 * the format of a telephone standardized for the United States (xxx)xxx-xxxx
 * VOID __FORMAT__NUMBER__(INT__, CHAR__*)
 * Takes in a character input strips out all the non integer characters, grabs the first ten and puts them into
 * the format of a telephone standardized for the United States (xxx)xxx-xxxx
 * 1) Sets max character size of the array to 14 (10 digits + 3 format characters + 1 null terminator)
 * 2) while loop counts the total number of integers
 * 3) checks first if the next input character is past the null terminator
 * 4) checks if the digit is 0 if 0 writes ( character writes ) at character 4 and - and character 8.
 * increments digit on each
 * 5) checks if character is 0, if it is 0 then writes 0 to the phone number array, this is done as a seperate step
 * because isdigit returns 0 if it is not a digit and if it digit is 0. increments count and digit by one
 * 6) checks to see if character is digit, if digit writes it to array increments digit and count by one
 * 7) checks to see if character is not digit and that it is not '0' if so increments count.
 * 8) else statement acts as a debug checker, this code should never run but if it does it will tell us that something
 * is run.
 * 9) prints the phone number it was given in the correct format
 */