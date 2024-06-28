#include<stdio.h>

void selection_sort(int array[]);

int main(void){

    int array[10];

    for (int i = 0; i < 10; i++){
        printf("Type number please: ");
        scanf("%i", &array[i]);
    }

    selection_sort(array);

    for (int i = 0; i < 10; i++){
        printf("%i ", array[i]);
    }

}

void selection_sort(int array[]){
    for (int i = 0; i < 10 - 1; i++){
        int smallest_number = array[i];
        int smallest_index = i;
        for (int j = i + 1; j < array[i]; j++){
            if (array[j] < smallest_number){
                smallest_number = array[j];
                smallest_index = j;
            }
        }
        int temp = array[i];
        array[i] = smallest_number;
        array[smallest_index] = temp;
    }
}