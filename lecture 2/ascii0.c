#include<stdio.h>
#include<string.h>

void display_chars(char name[]);

int main(void){
    char name[100];

    printf("Please enter your name: ");
    scanf("%100s", &name);
    display_chars(name);
    printf("Program is finished\n");
}

void display_chars(char name[]){
    int n = strlen(name);

    for(int i = 0; i < n; i++){
        printf("%c %i\n", name[i], name[i]);
    }
}