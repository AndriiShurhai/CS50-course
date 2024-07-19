#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main(void){

    int *numbers = malloc(sizeof(int) * 50);

    int size = 0;

    int capacity = 50;

    while (true){
        printf("Please type some number: ");
        int checking = scanf("%i", &numbers[size]);

        if (checking == EOF){
            break;
        }
        else if(checking != 1){
            numbers = realloc(numbers, sizeof(int) * size - 1);
            break;
        }
        size++;

        if (size == capacity){
            int new_capacity = capacity * 2;
            int *temp = realloc(numbers, sizeof(int) * new_capacity);
            if (temp == NULL){
                printf("Memory reallocation failed.\n");
                free(numbers);
                return 1;
            }
            numbers = temp;
            capacity = new_capacity;
        }
    }

    for (int i = 0; i < size; i++){
        printf("You inputted: %i\n", numbers[i]);
    }

    free(numbers);

    return 0;
}