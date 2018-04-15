# bmc539.5

This is the fifth project for cs 2750

### Sieve
This is a C implementation of the Sieve of Eratosthenes using unsigned character arrays to hold the number line. 
Simply type make in the subdirectory to build the executable sieve which can be run by typing ./sieve

### Phone
Converts an input stream containing numbers and letters to the (xxx)xxx-xxxx phoen number format, there is a test script
written in bash that feeds the executable random inputs. 

### Shuffle
Cards implements a deck of cards as a typedef card_t. An array of card_t is used to represent all the cards in a standard 52 card poker deck.
Print outs are converted to a human readable format and data is output in neat columns.

### Sb
Does the same thing as shuffle but using a bit vector, and no position, also no position is reused.
In sb make has 3 options. make, make clean, and make debug.
make clean cleans out any files make had generated.
make debug forces the -DDEBUG flag in gcc and activates an \#ifdef \#endif statement.
