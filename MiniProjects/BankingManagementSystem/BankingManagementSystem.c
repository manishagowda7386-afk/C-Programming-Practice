/*
-------------------------------------------------------
Project : Banking Management System
Language: C

Author  : Manisha TM

Version : 1.0
-------------------------------------------------------
*/

#include <stdio.h>

void displayMenu();

int main()
{
    int choice;

    while (1)
    {
        displayMenu();

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nCreate Account feature is under development.\n");
                break;

            case 2:
                printf("\nDeposit feature is under development.\n");
                break;

            case 3:
                printf("\nWithdraw feature is under development.\n");
                break;

            case 4:
                printf("\nBalance Enquiry feature is under development.\n");
                break;

            case 5:
                printf("\nThank you for using Banking Management System.\n");
                return 0;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}

void displayMenu()
{
    printf("\n====================================\n");
    printf("   BANKING MANAGEMENT SYSTEM\n");
    printf("====================================\n");
    printf("1. Create Account\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Check Balance\n");
    printf("5. Exit\n");
    printf("====================================\n");
}
