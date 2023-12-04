#include <stdio.h>
#include <stdbool.h>

#define FILENAME "input.txt"
#define SYMBOLS "-#$%&*/@+="

/*  Function to validate the user input and guarantee that 
    they only enter integers    */
int validateInput() {
    int input;
    char character;
    bool invalid = true;

    while (invalid) {
        if(scanf("%d%c", &input, &character) != 2 || character != '\n') {
            printf("ERROR: Invalid input. Please enter an integer: ");

            while ((getchar()) != '\n');
        }
        else {
            invalid = false;
        }
    }
    
    return input;
}

/*  Main function       */
int main() {
    int choice;

    printf("1. Return sum of part numbers\n\n");

    choice = validateInput();
}