#define _XOPEN_SOURCE
#include<unistd.h>
#include<stdio.h>
#include<crypt.h>


int main(int argc, char *argv[]){
    if (argc != 2){
        printf("Usage: ./crack hash");
        return 1;
    }

    char *hash = argv[1];
    char *salt = "XX";
    char *password = crypt(hash, salt);

    printf("%s", password);
}