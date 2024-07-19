#include<stdio.h>
#include<stdlib.h>

#include "struct.h"

int get_students_amount(void);
void display_students(student *students, int students_amount);

int main(void){
    int students_amount = get_students_amount();
    
    student *students_list = malloc(students_amount * sizeof(student));
    if (students_list == NULL){
        printf("Memory allocation failed\n");
    }

    for (int i = 0; i < students_amount; i++){
        students_list[i].name = malloc(50 * sizeof(char));
        students_list[i].dorm = malloc(50 * sizeof(char));

        if (students_list[i].name == NULL || students_list[i].dorm == NULL){
            printf("Memory allocation failed on student.\n");
            for (int j = 0; j <= i; j++){
                free(students_list[j].name);
                free(students_list[j].dorm);
            }
            free(students_list);
            return 1;
        }
        printf("Please type student name: ");
        scanf("%s", students_list[i].name);

        printf("Please type student dorm: ");
        scanf("%s", students_list[i].dorm);
    }

    display_students(students_list, students_amount);

    for (int j = 0; j <= students_amount; j++){
        free(students_list[j].name);
        free(students_list[j].dorm);
    }
    free(students_list);
}


int get_students_amount(void){
    int amount;

    printf("Please type how many students are there: ");
    scanf("%i", &amount);

    return amount;
}

void display_students(student *students, int students_amount){
    printf("\n");
    for (int i = 0; i < students_amount; i++){
        printf("Student %i:\nName: %s\nDorm: %s\n", i+1, students[i].name, students[i].dorm);
        printf("---------------------------------\n");
    }
}