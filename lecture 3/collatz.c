#include<stdio.h>

int collatz_recursion(int n);

int main(void){
    int n;

    printf("Please type some number: ");
    scanf("%i", &n);
    
    int steps_takes = collatz_recursion(n);
    printf("The number of steps to turn your number into one: %i", steps_takes);

}

int collatz_recursion(int n){
    printf("%i\n", n);
    if (n == 1){
        return 0;
    }
    if (n % 2 == 0){
        return 1 + collatz_recursion(n / 2);
    }
    else{
        return 1 + collatz_recursion(n * 3 + 1);
    }
}