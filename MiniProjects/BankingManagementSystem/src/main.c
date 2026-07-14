#include <stdio.h>
#include "../include/menu.h"
#include "../include/account.h"
#include "../include/transaction.h"

int main()
{
    int choice;

    while(1)
    {
        displayMenu();

        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                createAccount();
                break;

            case 2:
                depositMoney();
                break;

            case 3:
                withdrawMoney();
                break;

            case 4:
                checkBalance();
                break;

            case 5:
                searchAccount();
                break;

            case 6:
                displayAllAccounts();
                break;

            case 7:
                printf("\nThank You For Using Banking Management System.\n");
                return 0;

            default:
                printf("\nInvalid Choice!\n");
        }
    }

    return 0;
}
