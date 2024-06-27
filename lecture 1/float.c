#include<stdio.h>

int main(void){
    double x;
    double y;

    printf("Please type x: ");
    scanf("%f", &x);

    printf("Please type y: ");
    scanf("%f", &y);

    printf("x / y = %.50f\n", x / y);

    return 0;
}