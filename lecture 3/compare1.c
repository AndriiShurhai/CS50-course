#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool compare_strings(char *string1, char *string2);

int main(void){
    char first_word[101];  // Allocate space for the strings
    char second_word[101];

    printf("Please type first word: ");
    scanf("%100s", first_word);  // No need for '&' since first_word is an array

    printf("Please type second word: ");
    scanf("%100s", second_word);  // No need for '&' since second_word is an array

    if(compr(first_word, second_word) == 0){
        printf("These are the same\n");
    }
    else{
        printf("These are different\n");
    }

    return 0;  // Return 0 to indicate successful execution
}

bool compare_strings(char *string1, char *string2){
    if (strlen(string1) != strlen(string2)){
        return false;
    }

    int length = strlen(string1);
    for (int i = 0; i < length; i++){
        if (string1[i] != string2[i]){
            return false;
        }
    }

    return true;
}
