#include<stdio.h>

int binary_search(int array[], int target);

int main(void){
    int array[10];
    int target;
    int binary_search_result;

    for (int i = 0; i < 10; i++){
        printf("Type number please: ");
        scanf("%i", &array[i]);
    }

    printf("Please choose target to find in array");
    scanf("%i", &target);

    binary_search_result = binary_search(array, target);

    if (binary_search_result != -1){
        printf("Target is found! Your target located at the position of %i\n", binary_search_result + 1);
    }
    else{
        printf("Target is not found! Your target is not located in the array!\n");
    }

}


int binary_search(int array[], int target){
    int left = 0;
    int right = 9;

    while(left <= right){
        int middle = (left + right) / 2;
        
        if (array[middle] == target){
            return middle;
        }

        if (array[middle] < target){
            left = middle + 1;
        }
        else{
            right = middle - 1;
        }
    }

    return -1;
}