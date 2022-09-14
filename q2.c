/*!
@file q.c
@author Timothy Wong
@course RSE1201
@week 4
@lab04
@section 2
@date 20/09/2022
@brief This file will print formatted strings in denominations divided into notes.
*//*_____________________________________________________________*/

#include <stdio.h>
//this function prints each denomination with the specified arguments given by function coins.
void print_line(int index, int cents, int value) {
    float dollars = (float) cents / 100;
    printf("| %-2d | %12.2f | %5d |\n", index, dollars, value);
}

//this function takes in the money in cents the user input, and loops the function print_line to print each denom.
void coins(int cents) {
    int arrMoney[] = {10000, 5000, 1000, 500, 200, 100, 50, 20, 10, 5, 1};
    int storeMoney[10000];

    printf("\n+----+--------------+-------+\n");
    printf("| #  | Denomination | Count |\n");
    printf("+----+--------------+-------+\n");
    for (int i = 0; i < 11; i++) { //array size is 11
        storeMoney[arrMoney[i]] = 0; //initialize value to 0
        while (cents >= arrMoney[i]) {
            storeMoney[arrMoney[i]] += 1;
            cents -= arrMoney[i];
        }
        print_line(i + 1, arrMoney[i], storeMoney[arrMoney[i]]);
    }
}
//main function
int main(void) {
    while (1) {
        int dollars, cents;
        printf("Please enter total value: ");
        if (scanf("%d.%d", &dollars, &cents) == 2) {
            if ((cents < 0) || (cents > 99)) {
                printf("Program ended\n");
                return 0;
            }
            if (dollars < 0) {
                printf("Program ended\n");
                return 0;
            }
            else {
            // Input is valid.
                coins(dollars * 100 + cents);
                printf("+----+--------------+-------+\n");
            }
        }
        else {
            printf("Program ended\n");
            return 0;
        }
    }
    
}