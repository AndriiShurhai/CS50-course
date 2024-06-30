#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<ctype.h>

int main(void){
    char first_word[100];  // Array to hold the input string

    printf("Please type some word: ");
    scanf("%99s", first_word);  // Read input string with a maximum of 99 characters

    // Allocate memory for copied_word based on the length of first_word
    char *copied_word = malloc((strlen(first_word) + 1) * sizeof(char));
    if (copied_word == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;  // Exit with error code
    }

    // Copy the string
    strcpy(copied_word, first_word);

    if(strlen(copied_word) >= 1){
        copied_word[0] = toupper(copied_word[0]);
    }

    printf("Copied word: %s\n", copied_word);
    printf("Original word: %s\n", first_word);

    // Free the allocated memory
    free(copied_word);

    return 0;
}
