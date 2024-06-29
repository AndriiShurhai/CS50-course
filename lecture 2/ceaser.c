#include<stdio.h>
#include<string.h>
#include<ctype.h> 


int get_int(char number[]);
void cipher_message(char message[], int key);

int main(int argc, char *argv[]){
    char message[100];

    if (argc != 2){
        printf("Usage: ./casear key");
        return 1;
    }

    int key = get_int(argv[1]);

    if (key == -1){
        printf("Usage ./casear key");
        return 1;
    }

    printf("Please enter a meassage you want to cipher: ");
    fgets(message, sizeof(message), stdin);

    printf("ciphertext: ");
    cipher_message(message, key);

    return 0;
}

int get_int(char number[]){
    int len = strlen(number);
    int result = 0;

    for (int i = 0; i < len; i++){
        if (!isdigit(number[i])){
            return -1;
        }
    }

    for (int i = 0; i < len; i++){
        result = result * 10 + (number[i] - '0');
    }

    return result;
}

void cipher_message(char message[], int key){
    int len = strlen(message);

    for (int i = 0; i < len; i++){
        if (isalpha(message[i])){
            char offset = islower(message[i]) ? 'a' : 'A';
            message[i] = (message[i] - offset + key) % 26 + offset;
        }
    }

    for (int i = 0; i < len; i++){
        printf("%c", message[i]);
    }
}