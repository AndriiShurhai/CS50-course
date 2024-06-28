#include<stdio.h>
#include<string.h>
#include<ctype.h>

void change_letters_version1(char name[]);
void change_letters_version2(char name[]);

int main(int argc, string argv[]){
    char name[100];

    printf("Please type your name: ");
    scanf("%100s", &name);

    printf("Version 1:\n");
    change_letters_version1(name);
    
    printf("Version 2: \n");
    change_letters_version2(name);
}


void change_letters_version1(char name[]){
    int n = strlen(name);

    for(int i = 0; i < n; i++){
        if (name[i] >= 'a' && name[i] <= 'z'){
            name[i] = name[i] - ('a' - 'A');
        }
        else{
            name[i] = name[i] + ('a' - 'A');
        }
        printf("%c %i\n", name[i], name[i]);
    }
}

void change_letters_version2(char name[]){
    int n = strlen(name);

    for(int i = 0; i < n; i++){
        if (islower(name[i])){
            name[i] = toupper(name[i]);
        }
        else{
            name[i] = tolower(name[i]);
        }
        printf("%c %i\n", name[i], name[i]);
    }
}