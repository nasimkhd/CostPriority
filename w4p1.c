/*
    ==================================================
    Workshop #4 (Part-1):
    ==================================================
    Name   : Nasim Khodapanah
    ID     : 131929200
    Email  : nkhodapanah@myseneca.ca
    Section: NGG
*/

#include <stdio.h>
#define wishList_Min 1
#define wishList_Max 10

int main(void) {
    const float monthlyIncome_min = 500.00, monthlyIncome_max = 400000.00;
    float monthliIncome;
    double itemCost[10], itemCost_min = 100.00, sum = 0;
    int  Continue = 1, wishList = 0;
    char prompt[10];
    int priority[10], i;
    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n\n");

    while (Continue) {
        printf("Enter your monthly NET income: $");
        scanf("%f", &monthliIncome);

        if (monthliIncome < monthlyIncome_min) {
            printf("ERROR: You must have a consistent monthly income of at least $%.2f\n\n", monthlyIncome_min);
        }
        else if (monthliIncome > monthlyIncome_max) {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $%.2f\n\n", monthlyIncome_max);
        }
        else
        {
            Continue = 0;
        }
    }
    Continue = 1;
    while (Continue) {
        printf("\nHow many wish list items do you want to forecast?: ");
        scanf("%d", &wishList);

        if (wishList < 1 || wishList > 10) {
            printf("ERROR: List is restricted to between %d and %d items.\n", wishList_Min, wishList_Max);
        }
        else {
            Continue = 0;
        }
    }
    for (i = 0; i < wishList; i++) {
        printf("\nItem-%d Details:\n", i + 1);

        Continue = 1;
        while (Continue) {
            printf("   Item cost: $");
            scanf("%lf", &itemCost[i]);

            if (itemCost[i] < itemCost_min)
            {
                printf("      ERROR: Cost must be at least $%.2f\n", itemCost_min);
            }
            else
            {
                Continue = 0;
            }
        }
        Continue = 1;
        while (Continue) {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &priority[i]);

            if (priority[i] > 3 || priority[i] < 1) {
                printf("      ERROR: Value must be between 1 and 3\n");
            }
            else {
                Continue = 0;
            }
        }
        Continue = 1;

        while (Continue) {
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &prompt[i]);

            if (prompt[i] == 'n' || prompt[i] == 'y') {
                Continue = 0;
            }
            else
            {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            }
        }
    }

    printf("\nItem Priority Financed        Cost");
    printf("\n---- -------- -------- -----------\n");
    for (i = 0; i < wishList; i++) {
        printf("%3d  %5d    %5c    %11.2lf\n", i + 1, priority[i], prompt[i], itemCost[i]);
        sum += itemCost[i];
    }
    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n\n", sum);
    printf("Best of luck in all your future endeavours!");
    return 0;
}