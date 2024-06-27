#include<stdio.h>

int main(void){
    int first_number;
    int second_number;

    printf("Enter first number: ");
    scanf("%i", &first_number);

    printf("Enter second number: ");
    scanf("%i", &second_number);

    printf("a + b = %i\n", first_number + second_number);
    printf("a - b = %i\n", first_number - second_number);
    printf("a * b = %i\n", first_number * second_number);
    printf("a / b = %i\n", first_number / second_number);
    printf("a mod b = %i\n", first_number % second_number);

    printf("Program is finshed!");
}