#include<stdio.h>

void swap(int *a, int *b);

int main(void){
    int x;
    int y;

    printf("Please type some number: ");
    scanf("%i", &x);
    printf("Please type some number: ");
    scanf("%i", &y);

    printf("your numbers now: %i %i\n", x, y);
    swap(&x, &y);
    printf("your numbers after swapping: %i %i\n", x, y);
}


void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}