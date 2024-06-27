#include<stdio.h>
#include<math.h>

float get_customer_cash(void);
int calculate_change(float cash);

int main(void){
    float cash = get_customer_cash();
    int minimum_coins_required = calculate_change(cash);
    printf("%i", minimum_coins_required);
}

float get_customer_cash(void){
    float cash;
    int valid_integer = -1;
    char buffer[100];

    do{
        printf("Enter a valid number: ");
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            valid_integer = sscanf(buffer, "%f", &cash);
        }
    }while(valid_integer != 1 || cash < 0.0);

    return cash;
}

int calculate_change(float cash){
    int coins = round(cash * 100);
    int minimum_coins_required = 0;
    int cents[4] = {25, 10, 5, 1};

    for (int i = 0; i < 4; i++){
        minimum_coins_required += coins / cents[i];
        coins %= cents[i];
    }

    return minimum_coins_required;
}

