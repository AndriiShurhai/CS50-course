#include<stdio.h>


const int SCORES_COUNT = 5;
void draw_chart(int scores[], int scores_count);

int main(void){
    int scores[SCORES_COUNT];
    for(int i = 0; i < SCORES_COUNT; i++){
        scanf("%i", &scores[i]);
    }
    draw_chart(scores, SCORES_COUNT);
    printf("Program is finished.");
}

void draw_chart(int scores[], int scores_count){
    for (int i = 0; i < scores_count; i++){
        for(int j = 0; j < scores[i]; j++){
            printf("#");
        }
        printf("\n");
    }
}

