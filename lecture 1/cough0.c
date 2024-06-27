#include<stdio.h>

void cough(int n);

int main(void){
    int n;
    
    printf("Type number of coughs: ");
    scanf("%i", &n);

    cough(n);
}

void cough(int n){
    for (int i = 0; i < n; i++){
        printf("cough\n");
    }
}