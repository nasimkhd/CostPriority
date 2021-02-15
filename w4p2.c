/*
    ==================================================
    Workshop #4 (Part-2):
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
    double monthliIncome, sum = 0, itemCost[10];
    double itemCost_min = 100.00;
    int  Continue = 1, wishList = 0;
    char prompt[10];
    int priority[10], i;
    int choice, year, month, p = 0;
    double totalPriority = 0;
    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n\n");

    while (Continue) {
        printf("Enter your monthly NET income: $");
        scanf("%lf", &monthliIncome);
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

    Continue = 1;
    while (Continue) {

        printf("How do you want to forecast your wish list?\n");
        printf("1. All items (no filter)\n");
        printf("2. By priority\n");
        printf("0. Quit / Exit\n");
        printf("Selection: ");
        scanf(" %d", &choice);
        month = (((int)(sum / monthliIncome)) % 12) + 1;
        year = ((int)(sum / monthliIncome)) / 12;
        if (choice > 2 || choice < 0) {
            printf("\nError: Invalid menu selection.\n\n");
        }
        else if (choice == 1) {
            printf("\n====================================================\n");
            printf("Filter: All items\n");
            printf("Amount: $%1.2lf\n", sum);
            printf("Forecast: %d years, %d months\n", year, month);
            printf("NOTE: Financing options are available on some items.\n      You can likely reduce the estimated months.\n");
            printf("====================================================\n\n");
        }
        else if (choice == 2) {

            printf("\nWhat priority do you want to filter by? [1 - 3]: ");
            scanf("%d", &p);
            if (p > 3 || p < 1) {
                printf("Error: Value must be between 1 and 3\n");
            }
            else
            {
                totalPriority = 0;
                int financeOption = 0;
                for (i = 0; i < wishList; i++) {
                    if (priority[i] == p) {
                        totalPriority += itemCost[i];
                        if (prompt[i] == 'y')
                            financeOption = 1;
                    }
                }
                month = (((int)(totalPriority / monthliIncome)) % 12) + 1;
                year = ((int)(totalPriority / monthliIncome)) / 12;
                printf("\n====================================================\n");
                printf("Filter:    by priority (%d)\n", p);
                printf("Amount:    $%1.2lf\n", totalPriority);
                printf("Forecast:  %d years, %d months\n", year, month);
                if (financeOption) {
                    printf("NOTE: Financing options are available on some items.\n      You can likely reduce the estimated months.\n");
                }
                printf("====================================================\n\n");
            }
        }
        else if (choice == 0)

            Continue = 0;
    }
    printf("\nBest of luck in all your future endeavours!\n");
    return 0;
}

   
