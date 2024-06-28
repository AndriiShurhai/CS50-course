#include<stdio.h>

void insertion_sort(int array[10]);

int main(void){

    int array[10];

    for (int i = 0; i < 10; i++){
        printf("Type number please: ");
        scanf("%i", &array[i]);
    }

    insertion_sort(array);

    for (int i = 0; i < 10; i++){
        printf("%i ", array[i]);
    }

}

void insertion_sort(int array[10]){
    for (int i = 1; i < 10; i++){
        int key = array[i];
        int j = i - 1;

        while(j >= 0 && array[j] > key){
            array[j+1] = array[j];
            j--;
        }

        array[j+1] = key;
    }
}