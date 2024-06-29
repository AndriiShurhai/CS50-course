#include<stdio.h>
#include<string.h>
#include<ctype.h> 


int get_int(char number[]);
void cipher_message(char message[], char keyword[]);

int main(int argc, char *argv[]){
    char message[100];

    if (argc != 2){
        printf("Usage: ./vigenere key");
        return 1;
    }

    char *keyword = argv[1];

    for (int i = 0; i < strlen(keyword); i++){
        if (!isalpha(keyword[i])){
            printf("Usage: ./vigenere key");
            return 1;
        }
    }

    printf("Please enter a meassage you want to cipher: ");
    fgets(message, sizeof(message), stdin);

    printf("ciphertext: ");
    cipher_message(message, keyword);

    return 0;
}


void cipher_message(char message[], char keyword[]){
    int message_len = strlen(message);
    int key_len = strlen(keyword);
    int key_index = 0;

    for (int i = 0; i < message_len; i++){

        if (isalpha(message[i])){
            char offset_message = islower(message[i]) ? 'a' : 'A';
            char offset_key = islower(keyword[key_index]) ? 'a' : 'A';
            int key = (keyword[key_index] - offset_key);
            message[i] = (message[i] - offset_message + key) % 26 + offset_message;
            key_index = (key_index + 1) % key_len;
        }
    }

    for (int i = 0; i < message_len; i++){
        printf("%c", message[i]);
    }
}