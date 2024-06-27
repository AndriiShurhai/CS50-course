#include<stdio.h>

int get_positive_number(void);

int main(void){

    int start_count = get_positive_number();
    int finish_count = get_positive_number();

    for (int i = start_count; i < finish_count; i++){
        printf("%i\n", i);
    }

    return 0;
}

int get_positive_number(void){
    int positive_number;

    do{
        printf("Please type some positive number: ");
        scanf("%i", &positive_number);
    }while(positive_number <= 0);

    return positive_number;
}