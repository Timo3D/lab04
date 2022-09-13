#include <stdio.h>

void print_line(int index, int cents, int value) {
// TODO: provide proper implementation later
    float dollars = (float) cents / 100;
    printf("| %-2d | %12.2f | %5d |\n", index, dollars, value);
}
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
int main(void) {
    int dollars, cents;
    int test1, test2;
    printf("Please enter total value: ");
    if (scanf("%d.%d", &dollars, &cents) == 2) {
        if ((cents < 0) || (cents > 99)) {
            printf("The cents part specified must be between 0...99 (inclusive).\n"); return 0;
        }
        if (dollars < 0) {
            printf("The dollars part specified must be non-negative.\n"); return 0;
        }
        else {
        // Input is valid.
            coins(dollars * 100 + cents);
            printf("+----+--------------+-------+\n");
        }
    }
    else {
        printf("You did not type in the correct format in terms of dollars and cents.\n");
    }
}