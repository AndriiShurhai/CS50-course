#include<stdio.h>

int get_pyramid_height(void);
void build_pyramid(int height);

int main(void){
    int height = get_pyramid_height();
    build_pyramid(height);

    return 0;
}

int get_pyramid_height(void){
    int pyramid_height;
    int valid_integer = -1;
    char buffer[100];

    do{
        printf("Enter a valid number: ");
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            valid_integer = sscanf(buffer, "%d", &pyramid_height);
        }
    }while(valid_integer != 1 || pyramid_height <= 0 || pyramid_height > 8);

    return pyramid_height;
}

void build_pyramid(int height){
    for (int i = 0; i < height; i++){
        for (int j = 0; j < height - i - 1; j++){
            printf(" ");
        }
        
        for (int k = 0; k < i+1; k++){
            printf("#");
        }

        printf("  ");

        for (int k = 0; k < i+1; k++){
            printf("#");
        }

        printf("\n");
    }
}