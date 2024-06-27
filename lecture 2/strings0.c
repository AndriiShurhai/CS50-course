#include<stdio.h>
#include<string.h>

void write_chars(char text[]);

int main(void){
    char text[200];

    printf("Please write some word: ");
    scanf("%s", &text);
    write_chars(text);
}

void write_chars(char text[]){
    int length = strlen(text);

    printf("Output: \n");
    for (int i = 0; i < length; i++){
        printf("%c\n", text[i]);
    }
}