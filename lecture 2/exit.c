#include<stdio.h>

int main(int argc, char *argv[]){
    if (argc != 2){
        printf("Missing command-line argument\n");
        return 1;
    }

    printf("Hello, %s, nice to meet you.\n", argv[1]);
    return 0;
}