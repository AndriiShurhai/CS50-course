#include<stdio.h>

int main(void){
    char name[30];

    printf("Type your name please: ");
    scanf("%s", &name);
    printf("hello, %s", name);
}