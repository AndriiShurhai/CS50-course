#include<stdio.h>
#include<stdbool.h>

void bubble_sort(int array[]);

int main(void){

    int array[10];

    for (int i = 0; i < 10; i++){
        printf("Type number please: ");
        scanf("%i", &array[i]);
    }

    bubble_sort(array);

    for (int i = 0; i < 10; i++){
        printf("%i ", array[i]);
    }

}

void bubble_sort(int array[]){
    for (int i = 0; i < 10; i++){
        bool swapped = false;
        for (int j = 0; j < 10 - i - 1; j++){
            if(array[j] > array[j+1]){
                swapped = true;
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
        if (!swapped){
            break;
        }
    }
}