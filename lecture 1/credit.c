#include<stdio.h>

long long get_user_card(void);
void check_valid(long long credit_card);

int main(void){
    long long credit_card = get_user_card();
    check_valid(credit_card);
}


long long get_user_card(void){
    long long credit_card_number;
    int valid_integer = -1;
    char buffer[100];

    do{
        printf("Enter a valid number: ");
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            valid_integer = sscanf(buffer, "%lld", &credit_card_number);
        }
    }while(valid_integer != 1 || credit_card_number < 0.0);

    return credit_card_number;
}

void check_valid(long long credit_card){
    int suma_of_multyplied_by_two = 0;
    int final_suma = 0;
    int i = 1;
    int first_number;

    while (credit_card > 0){
        if (i % 2 != 0){
            final_suma += credit_card % 10;
            credit_card /= 10;
        }

        else{
            int multyplied_by_two = (credit_card % 10) * 2;
            final_suma += multyplied_by_two % 10 + multyplied_by_two / 10;
            credit_card /= 10;
        }
        i+=1;

        if (credit_card >= 10 && credit_card <= 100){
            first_number = credit_card;
        }
    }
    i-=1;

    if (final_suma % 10 == 0){
        if (i == 13 || i == 16 && first_number/10 == 4){
            printf("VISA\n");
        }
        else if(i == 16 && first_number >= 51 && first_number <= 55){
            printf("MASTERCARD\n");
        }
        else if(i == 15 && first_number == 34 || first_number == 37){
            printf("AMEX\n");
        }
        else{
            printf("INVALID\n");
        }
    }
    else{
        printf("INVALID\n");
    }
}