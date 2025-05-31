#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

// Written by Huevo - 01 June 2025
// This program is for testing boolean algebra functions
// and outputting a truth table.

// At the moment, you can only write the function manually
// into the source code. The far right column will display
// the function output. You can write your boolean data as
// "input[0]" to represent your first boolean. Write your 
// booleans like "!input[0]" to flip a bit, or represent a
// NOT function.
// Be sure to compile the program with "-lm" if you get a
// "undefined reference to `pow'" error. Ignore the cast
// warning.

bool* flip_bit(bool* input, int size);
bool* alg_function(bool* input, int size);

bool* alg_function(bool* input, int size){
    //This is the function you wanna edit
    return (bool*)(!input[1] * ((!input[2] * 1) + (!input[0] * input[3])));
}

bool* flip_bit(bool* input, int size){
    bool* temp = input;
    bool carry = true;
    int i = size - 1;
    //Add one
    while(i > -1 && carry){
        switch(temp[i]){
            case 0:
                temp[i] = !temp[i];
                carry = !carry;
                break;
            case 1:
                temp[i] = !temp[i];
                i--;
                break;
        }
    }
    return temp;
}

int main(){
    int vars = 0;
    printf("Boolean Algebra and Function Checker\nWritten by Huevo\n");
    printf("Be sure to edit the alg_function beforehand.\n\n");
    printf("The far right column will display your function output.\n");
    printf("How many booleans?: ");
    scanf("%d", &vars);
    bool* bits = malloc(vars + 1 * sizeof(bool));
    for(int i = 0; i < vars + 1; i++) bits[i] = 0; //Set all bits to 0
    for(int i = pow(2, vars); i > 0; i--){
	bits[4] = alg_function(bits, vars);
        for(int j = 0; j < vars + 1; j++) printf("%d,", bits[j]);
        printf("\n");
        bits = flip_bit(bits, vars);
    }
    return 1;
}
