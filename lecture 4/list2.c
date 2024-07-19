#include<stdio.h>

#include<node.h>

int main(void){
    // Memory for numbers
    Node *numbers = NULL;

    while(true){
        int number;
        printf("Please type some number: ");
        int check_valid = scanf("%i", &number);

        if (check_valid == EOF){
            return 0;
        }

        else if (check_valid != 1){
            return 1;
        }

        // Alocate space for numbers
        Node *n = malloc(sizeof(Node));

        if (!n){
            return 1;
        }

        // Add number to list
        n->number = number;
        n->next = NULL;

        if (numbers){
            for (Node *ptr = numbers; ptr != NULL; ptr = ptr->next){
                if (!ptr->next){
                    ptr->next = n;
                    break;
                }
            }
        }
        else{
            numbers = n;
        }
    }
}