#include<stdio.h>

int main(void){
    char first_word[100];
    char second_word[100];

    printf("Please type first word: ");
    scanf("%s", &first_word);

    printf("Please type second word: ");
    scanf("%s", &second_word);

    if (first_word == second_word){
        printf("same words");
    }
    else{
        printf("different words");
    }

}