#include <stdio.h>
#include <stdlib.h>

int main(void){
    char s[100];
    char t[100];

    printf("Please type some word: ");
    scanf("%99s", s);  // Limit input to 99 characters to avoid buffer overflow

    printf("Please type some word: ");
    scanf("%99s", t);  // Limit input to 99 characters to avoid buffer overflow

    printf("s: %p\n", (void *)s);
    printf("t: %p\n", (void *)t);

    return 0;  // Return 0 to indicate successful execution
}
