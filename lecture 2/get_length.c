#include<stdio.h>

int get_length(char name[]);

int main(void){
    char name[100]; 

    printf("Tell me your name please: ");
    scanf("%100s", &name);

    int length = get_length(name);
    printf("The length of your name: %i", length);
}

int get_length(char name[]){
    int n = 0;

    while(name[n] != '\0'){
        n++;
    }

    return n;
}